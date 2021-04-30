#Constant propagation
import re
import operator
				
f1 = open("out3.txt","w")
print("\nConstant Propogation"+"\n"+"__________________________")
with open("out2.txt","r") as f:
    content = f.read().splitlines()

sym_val={}

def check_int(str1):
	try:
		string_int = int(str1)
		return 1

	except ValueError:
		return 0

def check_key(str1):
	try:
		a=sym_val[str1]
		return 1

	except KeyError:
		return 0

for i in range(len(content)):
        cont=content[i].split(" ")
        #print(cont)
        if cont[0]=="":
               continue
        elif cont[1] in ["="]:
                if len(cont)==3:
                        #print(3,cont)
                        if (check_int(cont[2])==1):
                                
                                sym_val[cont[0]]=int(cont[2])
                                
                                print(" ".join(cont))
                                #print(cont)
                                f1.write(" ".join(cont)+"\n")
                                
                        else:
                                if (check_key(cont[2])==1):
                                        
                                        a=sym_val[cont[2]]
                                        
                                        cont[2]=str(a)
                                print(" ".join(cont))
                                f1.write(" ".join(cont)+"\n")
                elif (len(cont)==5):
                        #print(5,cont)
                        if (check_key(cont[2])==1):
                                a=sym_val[cont[2]]
                                cont[2]=str(a)
                                        
                        if (check_key(cont[4])==1):
                                b=sym_val[cont[4]]
                                cont[4]=str(b)

                        print(" ".join(cont))
                        f1.write(" ".join(cont)+"\n")
                else:
                        print(content[i])
                        f1.write(content[i]+"\n")
                
        else:
                print(content[i])
                f1.write(content[i]+"\n")


f.close()
f1.close()

