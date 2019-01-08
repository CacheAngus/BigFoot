#365 Lab2 
#Cache Angus, 20000629


#changes to make to it include the l, the r, the return apparently, and checking to see if we are given left and right or just use them for the recursion
 #everytime findSum is called, put the values of the values kept

def findSum(arrayinput, left, current, right):
    "this is to fun the greatest sum"
    sm =0
    lsm = -10000 #try and garuntee that the first number is greater than this original number
    
    lpos = 0
    for i in range(current, left-1, -1): #start at your midpoint and move to the left
        sm = sm + arrayinput[i]
        
        if (sm > lsm):
            lsm = sm
            lpos = i

    sm = 0
    rsm = -1000
    rpos = 0
    for i in range(current+1, right+1):
        sm = sm + arrayinput[i]

        if (sm > rsm):
            rsm = sm
            rpos = i+1
            
    
    
    return lsm + rsm, (lpos, rpos)
    
def actualMaxArrayVal(arrayinput, left, right):
   
    current = (left + right) // 2 #this truncates the value so it is the middle 
    
    #if there is no max sum then just print the biggest number
    if(left == right) :
        return arrayinput[left], (left, right)
    #else more than one element
    

    # do the recursion with your new left and rights continuously, then find the sum of these left and rights and current
    return max(actualMaxArrayVal(arrayinput, left, current),
               actualMaxArrayVal(arrayinput, current+1, right),
               findSum(arrayinput, left, current, right)) 
   
    
    # do the recursion with your new left and rights continuously, then find the sum of these left and rights and current
    
   


inputArray = [-1, 4, -2, 4, -1]
n = len(inputArray)

maximum, maximum_array_Range = actualMaxArrayVal(inputArray, 0, n-1)
array = []
for i in range(maximum_array_Range[0], maximum_array_Range[1]):
    array.insert(i, inputArray[i])

print("The maximum value is", maximum)
print("The max array is:", array)



    




   
