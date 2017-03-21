T=int(input())
for i in range(0,T):
    L=[]
    for j in range(0,10):
        stranica=input()
        stranica=stranica.split(" ")
        L.append([int(stranica[1]),stranica[0]])
    maximum=L[0][0]
    for j in range(0,10):
        if L[j][0]>maximum:
            maximum=L[j][0]
    print("Case #{}:".format(i+1))
    for j in range(0,len(L)):
        if L[j][0]==maximum:
            print("{}".format(L[j][1]))
        