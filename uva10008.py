lines=int(input())
d={}
slova="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for i in range(0,lines):
    recenica=input().upper()
    for slovo in recenica:
        if slovo in slova:
            d[slovo]=d.get(slovo,0)+1
L=[]
for key in d:
    L.append([d[key],key])
L.sort(reverse=True)
for i in range(0,len(L)-1):
    for j in range(i+1,len(L)):
        if L[i][0]==L[j][0]:
            if L[i][1]>L[j][1]:
                temp=L[i][1]
                L[i][1]=L[j][1]
                L[j][1]=temp
for i in range(0,len(L)):
    print("{} {}".format(L[i][1],L[i][0]))