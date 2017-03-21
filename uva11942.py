N=int(input())
print("Lumberjacks:")
for i in range(0,N):
    unos=input()
    unos=unos.split(" ")
    for j in range(0,10):
        unos[j]=int(unos[j])
    unos1=unos[0:10]
    unos1.sort()
    unos2=unos[0:10]
    unos2.sort(reverse=True)
    if unos1==unos or unos2==unos:
        print("Ordered")
    else:
        print("Unordered")