testcases=int(input())

for i in range (0,testcases):
    input()
    if i!=0:
        print()
    stupci=int(input())
    listdist=[]
    for j in range(stupci,0,-1):
        koordinate=input()
        koordinate=koordinate.split(" ")
        (pocetak,kraj)=(int(koordinate[0]),int(koordinate[1]))
        listdist.append(abs(pocetak-kraj))
    flag=True
    for j in range(1,len(listdist)):
        if listdist[j]!=listdist[0]:
            flag=False
    if flag==True:
        print("yes")
    else:
        print("no")