from os import linesep

file_list = ["p.py"]

def clear_file(filename):
	'''
	Funkcja usuwa białe znaki z końca linii we wskazanym pliku.
	'''
	new_lines = []
	with open(filename, 'rt') as ifile:
		lines = ifile.readlines()
		for (index, line) in enumerate(lines):
			newline = line.rstrip()
			if newline != line.rstrip(linesep):
				print "{}: {}".format(index+1, repr(line))
			new_lines.append(newline)
	with open(filename, 'wt') as ofile:
		for line in new_lines:
			ofile.write(line+linesep)

for f in file_list:
	clear_file(f)
