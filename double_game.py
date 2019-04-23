import random
import string
print("Enter the number of rounds you would like to take....")
n=int(input())
score=0;no=n
while(n):
    n-=1
    a=list(string.ascii_letters)
    card1=[0]*5
    card2=[0]*5
    pos1=random.randint(0,4)
    pos2=random.randint(0,4)
    samesym=random.choice(a)
    a.remove(samesym)
    if(pos1==pos2):
        card1[pos1]=samesym
        card2[pos1]=samesym
    else:
        card1[pos1]=samesym
        card2[pos2]=samesym
        card1[pos2]=random.choice(a)
        a.remove(card1[pos2])
        card2[pos1]=random.choice(a)
        a.remove(card2[pos1])
    for i in range(5):
        if(i!=pos1 and i!=pos2):
            card1[i]=random.choice(a)
            a.remove(card1[i])
            card2[i]=random.choice(a)
            a.remove(card2[i])
        
    print(card1)
    print(card2)
    print("Enter the positions of commom elements")
    t=[int(i) for i in input().split()]
    print("CORRECT ANSWER " if(t[0]==pos1+1 and t[1]==pos2+1) else "WRONG ANSWER ")
    if(t[0]==pos1+1 and t[1]==pos2+1):
      score+=1
print("\n\n\n\t\t\tGame Over......")
print("\n\t\t\t Your score = ",score,"/",no)
      
        
    
