import os

tab_size = 4
rstrip_lines = True
root = "./"
suffixes = [".py"]
excluded = []

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

def put_tab(line):
    while len(line)%tab_size:
        line+=" "
    return line

def parse_line(line):
    output = ""
    while len(line) > 0:
        if line[0] == '\t':
            output = put_tab(output+" ")
        else:
            output += line[0]
        line = line[1:]
    if rstrip_lines:
        output = output.rstrip()
    return output

def parse_file(fileAdr):
    f = open(fileAdr, 'rt')
    output = ""
    lines = f.readlines()
    f.close()
    f = open(fileAdr, 'wt')
    for line in lines:
        f.write(parse_line(line)+'\n')
    f.close()

def do_the_job():
    flist = fileList(root, suffixes, excluded)
    print("File list:")
    print("========")
    for f in flist: print(f)
    print("========")
    print("proceed? [y/n]")
    if input() == "y":
        print("...")
        for addr in flist: parse_file(addr)
        print("done")
    else:
        print("dupa")

do_the_job()
