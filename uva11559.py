while True:
    unos=input()
    if not unos:
        break
    else:
        L=unos.split(" ")
        for i in range(0,4):
            L[i]=int(L[i])
        minimum=L[1]
        for j in range(0,2*L[2]):
            if j%2==0:
                cijena=int(input())
            else:
                    kreveti=input()
                    L2=kreveti.split(" ")
                    for l in range(0,len(L2)):
                        L2[l]=int(L2[l])
                    for kreveti in L2:
                        if L[0]<=kreveti:
                            if cijena*L[0] < minimum:
                                minimum=cijena*L[0]
        if minimum < L[1]:
            print(minimum)
        else:
            print("stay home")
                            