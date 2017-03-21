import sys
def sumdigits(n):
    suma=0
    while n!=0:
        suma=suma+(n%10)
        n=n//10
    return suma
for unos in sys.stdin:
    unos=unos.replace("\n","")
    if unos=="0":
        break
    else:
        unos=int(unos)
        rj=unos
        while sumdigits(rj)>=0:
            rj=sumdigits(rj)
            if rj>=0 and rj<10:
                break
        print(rj)
            
        