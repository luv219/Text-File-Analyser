# Text-File-Analyser
A utility that reads a text file and provides statistics about its content.

Here is a clean and professional **`README.md`** file for your **Text File Analyzer in C** project:

---

```markdown
# 📄 Text File Analyser (C Language)

A C-based utility that reads a text file and provides detailed statistics about its content.  
Perfect for beginner-level file I/O practice and text processing.

---

## ✅ Features

- 📊 Counts:
  - Total characters
  - Total words
  - Total lines

- 🔤 Character frequency (including symbols, digits, spaces)

- 📝 Word frequency (case-insensitive)

- 📚 Simple CLI-based interface

---

## 🛠 Requirements

- C Compiler (e.g., GCC)
- A `.txt` file to analyse

---

## 📂 File Structure

```

text-file-analyzer/
├── text\_analyzer.c       # Main program file
├── README.md             # Project documentation
└── sample.txt            # (Optional) Sample text input

````

---

## ⚙️ How to Compile and Run

### 🧑‍💻 Linux / WSL / Git Bash

```bash
gcc text_analyzer.c -o analyser
./analyzer
````

### 🖥️ Windows (MinGW / Code::Blocks)

```bash
gcc text_analyzer.c -o analyzer.exe
analyzer.exe
```

---

## 📥 Input Example

You'll be prompted to enter the path to a `.txt` file, such as:

```
Enter file name to analyze: sample.txt
```

---

## 📌 Sample Output

```
--- File Statistics ---
Total Characters: 127
Total Words     : 23
Total Lines     : 4

--- Character Frequency ---
'a': 12
'e': 18
' ': 25
...

--- Word Frequency ---
'the': 4
'cat': 2
'jumped': 1
...
```

---

## 🧠 Concepts Used

* File I/O in C (`fopen`, `fgetc`)
* String manipulation (`strcmp`, `strcpy`, `tolower`)
* Structures and arrays
* Character classification (`isalnum`, `isprint`)
* Word frequency logic

---

## 📦 Future Enhancements (Optional)

* Sentence and paragraph detection
* Sorting output (by frequency)
* Export results to CSV or JSON
* Graphical mode using `ncurses`

---

## 👨‍🎓 Project Info

* **Language**: C (C99 standard)
* **Level**: Beginner to Intermediate
* **Author**: \[Your Name]
* **Use Case**: Academic submission / Personal utility

---

Let me know and I’ll prepare it!
```
