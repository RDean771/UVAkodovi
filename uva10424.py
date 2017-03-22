import sys
def funkcija(broj):
    rezultat=0
    while broj:
        rezultat=rezultat+broj%10
        broj=broj//10
    return rezultat
for ime1 in sys.stdin:
    ime1=ime1.replace("\n","")
    if ime1=="":
        break
    else:
        abeceda="abcdefghijklmnopqrstuvwxyz"
        ABECEDA="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        ime2=input()
        modime1=""
        modime2=""
        for znak in ime1:
            if znak in abeceda or znak in ABECEDA:
                modime1+=znak
        for znak in ime2:
            if znak in abeceda or znak in ABECEDA:
                modime2+=znak
        modime1=modime1.upper()
        modime2=modime2.upper()
        d={'A':1,'B':2,'C':3,'D':4,'E':5,'F':6,'G':7,'H':8,\
       'I':9,'J':10,'K':11,'L':12,'M':13,'N':14,'O':15,\
       'P':16,'Q':17,'R':18,'S':19,'T':20,'U':21,'V':22,\
       'W':23,'X':24,'Y':25,'Z':26}
        sum1=0
        sum2=0
        for slovo in modime1:
            sum1+=d[slovo]
        for slovo in modime2:
            sum2+=d[slovo]
        rj1=float(sum1)
        rj2=float(sum2)
        while rj1 >=10 or rj2>=10:
            rj1=funkcija(rj1)
            rj2=funkcija(rj2)
        print("%.2f"%((min(rj1,rj2)/max(rj1,rj2))*100),end=" ")
        print("%")
       