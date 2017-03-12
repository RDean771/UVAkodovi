import sys
for unos in sys.stdin:
    if unos=="0 0 0 0\n":
        break
    else:
        unos=unos.replace('\n',"")
        n=0
        unos=unos.split(" ")
        for i in range (0,4):
            unos[i]=int(unos[i])
        (H,U,D,F)=(unos[0],unos[1],unos[2],unos[3])
        visina=0
        while True:
            n=n+1
            if U-(((n-1)*(F/100)*U))<=0:
                visina-=D
            else:
                visina=visina+(U-(((n-1)*(F/100)*U)))-D
            if visina < 0:
                print("failure on day {}".format(n))
                break
            if visina+D > H:
                print("success on day {}".format(n))
                break