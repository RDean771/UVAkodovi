testcases=int(input())
for i in range (0,testcases):
    if i!=0:
        print()
    L=[]
    if i==0:
        input()
    indeksi=(input()).split(" ")
    for j in range(0,len(indeksi)):
        indeksi[j]=int(indeksi[j])
    elementi=(input()).split(" ")
    if i!=testcases-1:
        input()
    for j in range(0,len(elementi)):
        L.append([indeksi[j],elementi[j]])
    L.sort()
    for j in range(0,len(L)):
        print(L[j][1])
        