cases=int(input())
for i in range(0,cases):
    linija=input()
    L=linija.split(" ")
    if float(L[0])> float(L[1]):
        print(">")
    elif float(L[0])==float(L[1]):
        print("=")
    else:
        print("<")