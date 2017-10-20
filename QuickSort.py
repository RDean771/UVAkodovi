def quicksort(lista):
    if len(lista)==0:
        return []
    else:
        prvi=lista[0]
        manjiodx=[y for y in lista if y < prvi and y!=prvi]
        vecijednakix=[z for z in lista if z >= prvi and z!=prvi]
        L= quicksort(manjiodx)
        R= quicksort(vecijednakix)
        L.append(prvi)
        L.extend(R)
        return L
if __name__=="__main__":
    print (quicksort ([3, 1, 2,-2, 5, 7, 9]))