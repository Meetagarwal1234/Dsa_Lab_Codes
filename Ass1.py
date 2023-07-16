ht=[-1]*10
def hash(key,max):
    return key%max

def solve(key,max):
    rem=hash(key,max);
    if(ht[rem]==-1):
        ht[rem]=key;
    else:
        flag=0
        for i in range(rem,max):
            if ht[i]==-1:
                flag=1
                ht[i]=key
                break
        if(flag==0):
            for i in range(0,pos):
                if(ht[i]==-1):
                    flag=1
                    ht[i]=key
                    break
    

def display():
    for i in range(0,max):
        print(i," ",ht[i],"\n")
ch=0
max=int(input())
while(ch!=3):
    print("1.Insert\n")
    print("2.Display\n")
    print("3.Exit\n")
    print("Enter your choice")
    n=int(input())
    if(n==1):
        print("Enter key")
        key=int(input())
        solve(key,max)
    elif (n==2):
        display()
    else:
        break
    