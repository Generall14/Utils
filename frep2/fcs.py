import os

# Zwraca listę adresów plików zgodnych z wartościami:
# root - adres bazowy z trórego rekurencyjnie będą przeszukiwane pliki
# suffixes - lista stringów określających siffixy plików jakie mają być przyjęte
#          - do listy plików
# excludePatterns - lista stringów, jeżeli adres pliku będzie zawierał którykolwiek
#                 - z zawartych tu wyrażeń to zostanie zignorowany
def fileList(root, suffixes, excludePatterns=[]):
	files = []
	for f in os.scandir(root):
		if f.is_dir():
			files += fileList(f.path, suffixes, excludePatterns)
		else:
			excluded = False
			for val in excludePatterns:
				if val in f.path:
					excluded = True
					break
			if excluded:
				continue
			for val in suffixes:
				if f.path.endswith(val):
					files.append(f.path)
					break
	return files

class Founded:
	def __init__(self, adr, line, text, what):
		self.adr = adr
		self.line = line
		self.text = text
		self.what = what
	def __str__(self):
		return "[{0}: {1}/{2}] {3}".format(self.what, self.adr, self.line, self.text)

# Zwraca listę obiektów founded reprezentujących znalezione frazy w pliku
# fileAdr - adres pliku do przeszukania
# toFind - lista wyrażeń od wyszukania
def searchFile(fileAdr, toFind):
	founds = []
	f = open(fileAdr, 'r')
	counter = 0
	for line in f.readlines():
		counter += 1
		for find in toFind:
			if find in line:
				founds.append(Founded(fileAdr, counter, line.rstrip(), find))
	f.close()
	return founds

def findAndShow(toFind, root, suffixes, excludePatterns=[]):
	for f in fileList(root, suffixes, excludePatterns):
		for res in searchFile(f, toFind):
			print(res)
