import streamlit as st
import subprocess
import os
import tempfile

st.set_page_config(page_title="Huffman Compressor", layout="centered")

# ---------- STYLE ----------
st.markdown("""
<style>
.stApp {
    background-color: lavender;
}

/* Upload box styling */
div[data-testid="stFileUploader"] {
    padding: 30px;
    border-radius: 12px;
    text-align: center;
    background-color: Violet;
}

/* 🔥 Hide ONLY helper text safely */
div[data-testid="stFileUploader"] small {
    display: none;
}

/* Button styling */
.stButton>button {
    background-color: #9400D3;
    color: white;
    border-radius: 8px;
    height: 45px;
    width: 100%;
}
</style>
""", unsafe_allow_html=True)

# ---------- UI ----------
st.title("Huffman File Compressor")
st.header("Upload your file")

option = st.radio("Choose Option", ["Compress", "Decompress"])

# Custom label (instead of default one)
st.markdown("### Drag & drop or click below")

uploaded_file = st.file_uploader(
    "",   # 🔥 empty label removes default text
    type=["txt", "bin", "huff"]
)

# ---------- FILE HANDLING ----------
if uploaded_file:

    temp_dir = tempfile.gettempdir()
    input_path = os.path.join(temp_dir, uploaded_file.name)

    # Save file
    with open(input_path, "wb") as f:
        f.write(uploaded_file.getbuffer())

    original_size = os.path.getsize(input_path)

    st.info(f"Uploaded: {uploaded_file.name}")
    st.write(f"Size: {original_size} bytes")

    output_file = st.text_input("Enter output file name")

    if st.button("Run"):

        if not output_file:
            st.error("Please enter output file name")
            st.stop()

        # Correct extension handling
        if option == "Compress":
            if not output_file.endswith(".huff"):
                output_file += ".huff"
        else:
            if not output_file.endswith(".txt"):
                output_file += ".txt"

        try:
            process = subprocess.Popen(
                ["huffman.exe"],
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
            )

            if option == "Compress":
                inputs = f"1\n{input_path}\n{output_file}\n3\n"
            else:
                inputs = f"2\n{input_path}\n{output_file}\n3\n"

            out, err = process.communicate(inputs)

        except Exception as e:
            st.error(f"Error: {e}")
            st.stop()

        st.success("Done!")

        # ---------- OUTPUT ----------
        if os.path.exists(output_file):

            new_size = os.path.getsize(output_file)

            col1, col2 = st.columns(2)

            with col1:
                st.metric("Original Size", f"{original_size} bytes")

            with col2:
                st.metric("Processed Size", f"{new_size} bytes")

            if option == "Compress":
                ratio = (new_size / original_size) * 100
                st.metric("Compression Ratio", f"{ratio:.2f}%")

            with open(output_file, "rb") as f:
                st.download_button("Download File", f, file_name=output_file)

        else:
            st.error("Output file not found")
