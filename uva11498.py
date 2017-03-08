while True:
    unos=input()
    if unos=='0':
        break
    else:
        unos=int(unos)
        for i in range(0,unos+1):
            koor=input()
            L=koor.split(" ")
            if i==0:
                (x0,y0)=(int(L[0]),int(L[1]))
            else:
                if int(L[0])==x0 or int(L[1])==y0:
                    print("divisa")
                else:
                    if int(L[0])>x0:
                        if int(L[1])>y0:
                            print("NE")
                        else:
                            print("SE")
                    else:
                        if int(L[1])>y0:
                            print("NO")
                        else:
                            print("SO")