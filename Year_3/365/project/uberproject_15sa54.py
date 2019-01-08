import csv

import networkx as nx


#to do_find how much time is needed between when the request is sent
#and when its recieved and if the car is available or not
#thi sis going to require a greedy solution that checks if
#the cars are in use or not due to request time and end times
#to tell when they are used you do dijriskas to find the shortest root to destinaiton
#dijriskas is also used when you do getting to the new request
#part of the greddy algs is checking when a new car needs to be added
#another part of the algorithm is using a timer of sorts

nx.dijriskas()
G =nx.Graph

waiting =[]


#got requests
#change this back and then transfer this part to netwrok

with open('requests.csv', 'rb') as csvfile:

    for line in csv.readfile.readlines():
        array = line.split(',')
        first_item = array[0]
    num_col = len(array)
    csvfile.seek(0)

    reader = csv.reader(csvfile,delimiter='')
    cols = [0,1,2]
    for row in reader:
        request = list(row[i] for i in cols)



#got network, first get them in lists then add them to the graph
with open('network.csv') as csvfile:
    network = csv.reader(csvfile, quoting=csv.QUOTE_NONE)
    for line in network:
        G.add_nodes_from(line)


#have to map out the different locations