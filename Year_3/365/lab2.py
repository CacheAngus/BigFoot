#365 Lab2 
#Cache Angus, 20000629


#could get user input and 
 #length = input('Length of Array:')

mell = 0
arrayer = []
#changes to make to it include the l, the r, the return apparently, and checking to see if we are given left and right or just use them for the recursion
 #everytime findSum is called, put the values of the values kept
def findArray(arrayinput, left, current, right):
    "this is to fun the greatest sum"
    sm =0
    lsm = -10000 #try and garuntee that the first number is greater than this original number
    subarray1 = []
    
    for i in range(current, left-1, -1): #start at your midpoint and move to the left
        sm = sm + arrayinput[i]
        
        if (sm > lsm):
            lsm = sm
            subarray1.insert(i,arrayinput[i])

    sm = 0
    rsm = -1000

    for i in range(current+1, right+1):
        sm = sm + arrayinput[i]

        if (sm > rsm):
            rsm = sm
            subarray1.insert(i,arrayinput[i])
        
    
    return subarray1

def findSum(arrayinput, left, current, right):
    "this is to fun the greatest sum"
    sm =0
    lsm = -10000 #try and garuntee that the first number is greater than this original number
    subarray1 = []
    
    for i in range(current, left-1, -1): #start at your midpoint and move to the left
        sm = sm + arrayinput[i]
        
        if (sm > lsm):
            lsm = sm
            

    sm = 0
    rsm = -1000

    for i in range(current+1, right+1):
        sm = sm + arrayinput[i]

        if (sm > rsm):
            rsm = sm
            
    
    
    return lsm + rsm
    

#def findArray(arrayinput, left, current, right):
    #"this is to fun the greatest sum"
    #sm =0
   # lsm = -10000 #try and garuntee that the first number is greater than this original number
    #subarray1 = []
   # for i in range(current, left-1, -1): #start at your midpoint and move to the left
   #     sm = sm + arrayinput[i]
        

      #  if (sm > lsm):
          #  lsm = sm
         #   subarray1.insert(i,arrayinput[i])
    #sm = 0
    #rsm = -1000

    #for i in range(current+1, right+1):
     #   sm = sm + arrayinput[i]
     #   subarray1.insert(i,arrayinput[i])

      #  if (sm > rsm):
       #     rsm = sm
      #  subarray1.insert(i,arrayinput[i])
   # return subarray1

def actualMaxArrayVal(arrayinput, left, right):
   
    current = (left + right) // 2 #this truncates the value so it is the middle 
    
    #if there is no max sum then just print the biggest number
    if(left == right) :
        return arrayinput[left]
    #else more than one element
    

    # do the recursion with your new left and rights continuously, then find the sum of these left and rights and current
    return max(actualMaxArrayVal(arrayinput, left, current),
               actualMaxArrayVal(arrayinput, current+1, right),
               findSum(arrayinput, left, current, right))

def actualMaxArray(arrayinput, left, right):
    
    current = (left + right) // 2 #this truncates the value so it is the middle 
    
    #if there is no max sum then just print the biggest number
    if(left == right) :
        return arrayinput
    #get the array Length and then keep the longest one to return
    
    array = findArray(arrayinput, left, current, right)
    maxer = len(array)
    
    if(maxer > mell):
        mell = maxer
        arrayer = array
        return array
       
    else:
        return arrayer
   
    
   
    
    # do the recursion with your new left and rights continuously, then find the sum of these left and rights and current
    
    #print the numbers that got that


inputArray = [1, 2, -2, 4, -1]
n = len(inputArray)

maximum = actualMaxArrayVal(inputArray, 0, n-1)
maximum_array = actualMaxArray(inputArray, 0, n-1)
print("The maximum value is", maximum)
print("The max array is:", maximum_array)


    




   
