import sys
for unos in sys.stdin:
    unos=unos.replace("\n","")
    if unos=="0 0 0 0":
        break
    else:
        rj=1080
        brojevi=unos.split(" ")
        for i in range(0,4):
            brojevi[i]=int(brojevi[i])
            if brojevi[i]==0:
                brojevi[i]+=40
                
        (pocetak,broj1,broj2,broj3)=(brojevi[0],brojevi[1],brojevi[2],brojevi[3])
        if(pocetak-broj1)< 0:
            rj=rj+9*((pocetak-broj1)+40)
        else:
            rj=rj+9*(pocetak-broj1)
        if(broj2-broj1)< 0:
            rj=rj+9*((broj2-broj1)+40)
        else:
            rj=rj+9*(broj2-broj1)
        if(broj2-broj3)< 0:
            rj=rj+9*((broj2-broj3)+40)
        else:
            rj=rj+9*(broj2-broj3)
        print("{}".format(rj))
        