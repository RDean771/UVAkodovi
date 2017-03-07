def dec2bin(M):
    rj=int(bin(M)[2:len(bin(M))])
    return rj
def ones(broj):
    sol=0
    broj=str(broj)
    for znam in broj:
        if znam=='1':
            sol=sol+1
    return sol
def hex2bin(broj):
    rj=""
    broj=str(broj)
    for znam in broj:
        if znam=='0':
            rj+="0000"
        elif znam=='1':
            rj+="0001"
        elif znam=='2':
            rj+="0010"
        elif znam=='3':
            rj+="0011"
        elif znam=='4':
            rj+="0100"
        elif znam=='5':
            rj+="0101"
        elif znam=='6':
            rj+="0110"
        elif znam=='7':
            rj+="0111"
        elif znam=='8':
            rj+="1000"
        else:
            rj+="1001"
    return int(rj)
br=int(input())
for i in range(0,br):
    M=int(input())
    X1=dec2bin(M)
    b1=ones(X1)
    X2=hex2bin(M)
    b2=ones(X2)
    print("{} {}".format(b1,b2))
    