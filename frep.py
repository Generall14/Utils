from os import system
from os import listdir, path
import re

#==================== USTAWIANE PARAMETRY DZIAŁANIA: ======================
#r'rys. <font color="blue"><b><em>([a-z0-9]{1,2})</em></b></font>'
#określa zadanie (find - wyszukiwanie, rep - zamiana)
toDo = "find"
#Dane do zmiany ( (src1, dst1), (src2, dst2), ... ) !minimum dwie pary, bo tak!
chdata = (('#include', '#include'),
        ("impossibletext", "impossibletext"))
#Dane do wyszukania (find1, find2, ... ) !minimum dwa elementy!
fdata = ("UCA0RXBUF", "impossibletext")
#Katalog startowy
root = "C:\\Users\\wkogut\\Documents\\temp\msp\\"
#Sufiks plików, dla pustego stringa wyszukuje wszystkie
sfilter = ".s43"
#==========================================================================

newLine="\n"
dirSep="/"
#Funkcja wykrywa wszystkie pliki zgodne z rozszerzeniem suff w katalogu dirAdress oraz w jego
#podfolderach, zwraca tablicę filesp pełnych adresów
def recEntry(dirAdress, filesp, suff=""):
	if not path.exists(dirAdress):
		print("\r\nFatal error!!! Nie istnieje adres {0}{1}".format(dirAdress, newLine))
		system("pause")
		quit()

	entry = listdir(dirAdress)
	for f in entry:
		if path.isdir(dirAdress+f):
			recEntry(dirAdress+f+dirSep, filesp, suff)
		else:
			if f.endswith(suff):
				filesp.append(path.abspath(dirAdress+f))
	return

#Funkcja podmienia wzorce chdata w pliku fileAdres, zwraca wystąpienia
def repFile(fileAdres, chdatap):
	count = []

	ifile = open(fileAdres, 'r')
	tempData = ifile.read()
	ifile.close()

	for cstr in chdatap:
		(tempData, ccount) = re.subn(cstr[0], cstr[1], tempData)
		if ccount > 0:
			count.append(cstr[0])

	ofile = open(fileAdres, 'w')
	ofile.write(tempData)
	ofile.close()
	return count

#Funkcja poszukuje wzorce fdata w pliku fileAdres, zwraca wystąpienia
def findFile(fileAdres, fdatap):
	count = []

	ifile = open(fileAdres, 'r')
	tempData = ifile.read()
	ifile.close()

	for cstr in fdatap:
		res = re.search(cstr, tempData)
		if res:
			count.append(cstr)
	return count

#================================================================

#Tworzenie listy plików:
print("Rekurencyjne poszukiwanie plików *{0}...".format(sfilter))
files = []
recEntry(root, files, sfilter)
if not files:
	print("Brak zgodnych plikow, nothing to do here..."+newLine)
	system("pause")
	quit()
print("...done, odnaleziono {0} plików{1}".format(len(files), newLine))

#Przetwarzanie
if toDo=="find":#Poszukiwanie
	print("Poszukiwanie wyrażeń:")
	for wz in fdata:
		print("\t\""+wz+"\"")
	print("Progress...")
	for wfile in files:
		ti = findFile(wfile, fdata)
		if ti:
			print(str(ti) + " in " + wfile)
	print("...done")
elif toDo=="rep":#Zamiana
	print("Poszukiwanie i podmiana wzorców:")
	for wz in chdata:
		print("\t\""+wz[0]+"\"  ->  \""+wz[1]+"\"")
	print("Progress...")
	for wfile in files:
		ti = repFile(wfile, chdata)
	if ti:
		print(str(ti) + " in " + wfile)
	print("...done")
else:
	print("Brak zdefiniowanych rozkazów (toDo="+toDo+")")

system("pause")
