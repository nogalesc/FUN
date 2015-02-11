# FUN
Random things I write

## Understanding Template Format 
The template format consists of three parts:

1. A folder inside common with the name the template is to use (e.g. ieeeconf).
2. One LaTeX file inside that folder called setup.tex, which contains all the LaTeX code before the content itself. Uses the same set up variable definitions as previous MMD files (e.g. \myauthor, \mytitle, etc.).
3. One LaTeX file inside the folder called footer.tex, which contains the LaTeX code after the content itself. This is typically the bibliography command, which can be adapted from other templates (the only usual change is to the \bibliographystyle command).
