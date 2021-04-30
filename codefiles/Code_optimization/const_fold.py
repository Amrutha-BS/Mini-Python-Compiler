#Constant propagation
import re
import operator
				
f1 = open("out4.txt","w")
print("\nConstant Folding"+"\n"+"__________________________")
with open("out3.txt","r") as f:
    content = f.read().splitlines()


def check_int(str1):
	try:
		string_int = int(str1)
		return 1

	except ValueError:
		return 0

for i in range(len(content)):
        cont=content[i].split(" ")
        if cont[0]=="":
               continue
        elif len(cont)==5:
                if ((cont[1] in ["="]) & (cont[3] in ["+","-","*","/"])):
                        if ((cont[3] in ["+"]) & (check_int(cont[2])==1) & (check_int(cont[4])==1)):
                                a=int(cont[2])
                                b=int(cont[4])
                                c=a+b
                                d=str(c)
                                print(cont[0],"=",str(c))
                                f1.write(cont[0]+"="+d+"\n")

                        if ((cont[3] in ["-"]) & (check_int(cont[2])==1) & (check_int(cont[4])==1)):
                                a=int(cont[2])
                                b=int(cont[4])
                                c=a-b
                                d=str(c)
                                print(cont[0],"=",str(c))
                                f1.write(cont[0]+"="+d+"\n")

                        if ((cont[3] in ["*"]) & (check_int(cont[2])==1) & (check_int(cont[4])==1)):
                                a=int(cont[2])
                                b=int(cont[4])
                                c=a*b
                                d=str(c)
                                print(cont[0],"=",str(c))
                                f1.write(cont[0]+"="+d+"\n")

                        if ((cont[3] in ["/"]) & (check_int(cont[2])==1) & (check_int(cont[4])==1)):
                                a=int(cont[2])
                                b=int(cont[4])
                                c=a/b
                                d=str(c)
                                print(cont[0],"=",str(c))
                                f1.write(cont[0]+"="+d+"\n")

        else:
                print(content[i])
                f1.write(content[i]+"\n")
                                
f.close()
f1.close()

