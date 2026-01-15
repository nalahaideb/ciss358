import os
#orders elements in chapter_list for assignment in the main.tex file 
def xyz(element):
    #i want these up front
    if 'chap' not in element:
        return len(element) - 100

    n = element[element.find('chap') + 4:element.find('.tex')]
    return int(n)
dir_ = os.getcwd() + "/chaps"
f = os.listdir(dir_)
chaps = os.getcwd() + "/chapters.tex"
if not os.path.isfile(chaps):
    print("making new chapters.tex file")
    os.system("touch %s" % chaps)
chaps = open(chaps, "w")
chapter_list = []
for i in f:
    instr = "\\input{chaps/%s}\n" % i
    if '~' not in instr:
        chapter_list.append(i)
        #chaps.write(instr)
        #print(i)
    else:
        print("ignoring temp file %s" % instr)
chapter_list.sort(key=xyz)
for i in chapter_list:
    instr = "\\input{chaps/%s}\n" % i
    chaps.write(instr)
