#Constant propagation
with open("out4.txt","r") as f:
    content = f.read().splitlines() 

print("\n")
print("After dead code elimination - ")
print("------------------------------")
#print(content)
assign=[]
stat=[]
l=[]

for i in range(len(content)):
    cont=content[i].split(" ")
    flag=0
    for j in range(len(cont)):
        if (cont[j] in ["if","goto","PRINT",":","not","==","<=","<",">",">="]):
            flag=1

    if flag==1:
        stat.append(i)

    else:
        assign.append(i)
#print(stat)
#print(assign)
for i in assign:
    assi=content[i].split(" ")
    #print(assi)
    for j in stat:
        #print(assi[0])
        stmt=content[j].split(" ")
        #print(stmt)
        if assi[0] in stmt:
            l.append(i)
l=l+stat
l.sort()
l=set(l)
for i in l:
    print(content[i])
        
f.close()
