OPEN = xdg-open
PDF = pdflatex --shell-escape --halt-on-error --interaction=nonstopmode -file-line-error $@.tex && \
	pdflatex --shell-escape $@.tex --interaction=batchmode && \
	pdflatex --shell-escape $@.tex --interaction=batchmode && \
	pythontex main.tex && \
        makeindex $@.idx && \
        pdflatex --shell-escape $@.tex --interaction=batchmode && \
        $(OPEN) $@.pdf;
LATEXRM = rm -f \
        main.aux main.ilg main.log main.idx main.ind main.out \
        main.py.err main.py.out \
        comment.cut comment.err comment.out \
        latex.py
main:
	python input_chaps.py
	touch main.idx
	$(PDF)
	$(LATEXRM)
	o main.pdf
c:
	$(LATEXRM)
view:
	$(OPEN) main.pdf
v:
	$(OPEN) main.pdf
