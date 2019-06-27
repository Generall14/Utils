import fcs
#=== Dane wejściowe ====================

# katalog przeszukiwania
root = "../"

# lista suffixów plików jakie będą przeszukane
suffixes = [".py"]

# lista wyrażeń które dyswalifikują plik z przeszukiwania
excluded = []

# Lista wyrażeń do wyszukania
toFind = ["import", "def"]

#=======================================

fcs.findAndShow(toFind, root, suffixes, excluded)
