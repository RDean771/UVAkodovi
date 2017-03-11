import sys
for line in sys.stdin:
    if line=='\n':
        break
    else:
        L=line.split(" ")
        L[3]=L[3].replace('\n','')
        for i in range(0,4):
            L[i]=int(L[i])
        minimum=L[1]
        for j in range(0,2*L[2]):
            if j%2==0:
                cijena=input()
                cijena=cijena.replace('\n','')
                cijena=int(cijena)
            else:
                kreveti=input()
                L2=kreveti.split(" ")
                L2[-1]=L2[-1].replace('\n','')
                for l in range(0,len(L2)):
                    L2[l]=int(L2[l])
                for kreveti in L2:
                    if L[0]<=kreveti:
                        if cijena*L[0] < minimum:
                            minimum=cijena*L[0]
                            break
        if minimum < L[1]:
            print(minimum)
        else:
            print("stay home")
    
                             