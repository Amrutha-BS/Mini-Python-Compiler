with open("out0.txt","r") as f:
    content = f.read().splitlines()

f1 = open("out2.txt","w")

print("\n")
print("copy propogation - ")
print("------------------------------")


l=[]
l1=[]
p=[]

for i in range(len(content)):
        cont=content[i].split(" ")
        flag=0
        if cont=='':
                p.append(i)
        for j in range(len(cont)):
            
                if (cont[j] in ['+','-','*','/'] ):
                        flag=1
                
                if(cont[j] in ["goto"]):
                        check=i
                        l1.append(i)
                
        if flag==1:
            l.append(i)

        else:
            l1.append(i)

if check-2 in l:
    l.remove(check-2)
    l1.append(check-2)
    l1.append(check-1)
    
    
for i in l:
    cont1=content[i].split(" ")
    cont2=content[i+2].split(" ")
    cont1[0]=cont2[0]
    content[i]=" ".join(cont1)

for i in l:
    l1.remove(i+2)
    
l=l+l1
l.sort()
l=set(l)
for i in l:
    print(content[i])
    f1.write(content[i]+"\n")
    
f1.close()
f.close()
