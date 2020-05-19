import sys
from progressBar import progressBar

def Func_ProgBar(Progress):
	if len (sys.argv) > 1 :
		f=open('Progress.txt','r')  
		num = f.read()
		
		prog = progressBar(maxValue = int (sys.argv[1]))
		prog.updateAmount(int(num))
		prog.draw()
		print("")
		f.close()

	else :

		print ('usage: progress.py MAXSIZE')

if __name__ == '__main__':
	Func_ProgBar("Progress.txt")
