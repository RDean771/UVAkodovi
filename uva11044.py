testcases=input()
for i in range(0,int(testcases)):
    dimenzije=input()
    dimenzije=dimenzije.split(" ")
    print("{}".format((int(dimenzije[0])//3)*(int(dimenzije[1])//3)))
    
    