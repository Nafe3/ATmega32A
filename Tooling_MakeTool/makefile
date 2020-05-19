include config.mk

allObjs = $(allSrcs:.c=.o)
allDeps = $(allSrcs:.c=.d)

$(FinalTargetName) : CFLAG = 
$(allObjs): CFLAG = -c
$(allDeps): CFLAG = -MM

$(FinalTargetName) : $(allObjs) 
	@$(CC) $(CFLAG) $^ -o $@ 
	@cmd /K "progress.bat"
	@cmd /C "python progress.py" 13

$(allObjs) : %.o : %.c 
	@$(CC) $(CFLAG) $< -o $@
	@cmd /K "progress.bat"
	@cmd /C "python progress.py" 13

$(allDeps) : %.d : %.c | Dependencies
	@$(CC) $(CFLAG) $< -o $@
	@cmd /c 'copy /y $@ Dependencies\'
	@cmd /K "progress.bat"
	@cmd /C "python progress.py" 13

Dependencies:
	@mkdir $@
	@cmd /K "progress.bat"
	@cmd /C "python progress.py" 13

.PHONY: clean link onlyCompile depend all

clean: 
	cmd /c 'DEL /Q $(FinalTargetName) $(allObjs) $(allDeps) Dependencies\*'
	echo 0 > Progress.txt

link: 
	@$(CC) $(CFLAG) $(allObjs) -o $(FinalTargetName)
	
onlyCompile: $(allObjs)
	
depend: $(allDeps)

all: $(allDeps) 
	$(MAKE) $(FinalTargetName)
	@echo 0 > Progress.txt