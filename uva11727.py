cases=int(input())
for i in range(0,cases):
    place=input()
    L=place.split(" ")
    L.sort()
    print("Case {}: {}".format(i+1,int(L[1])))