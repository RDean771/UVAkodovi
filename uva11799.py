cases=int(input())
for i in range(0,cases):
    unos=input()
    L=unos.split(" ")
    for j in range(0,len(L)):
        L[j]=int(L[j])
    L.sort()
    print("Case {}: {}".format(i+1,L[-1]))