import sys
for unos in sys.stdin:
    unos=unos.replace("\n","")
    if unos=="-1 -1":
        break
    else:
        unos=unos.split(" ")
        (a,b)=(int(unos[0]),int(unos[1]))
        rez1=max(a,b)-min(a,b)
        rez2=min(a,b)-max(a,b)+100
        print("{}".format(min(rez1,rez2)))
    