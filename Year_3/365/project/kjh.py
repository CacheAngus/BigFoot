import csv
import random
from numpy import genfromtxt
import networkx as nx
import matplotlib.pyplot as plt

#Cache Angus - 20000629
#15sa54-Net ID



#got network, first get them in lists then add them to the graph, the street map doesnt change
network = genfromtxt('network.csv', delimiter=',')
G = nx.from_numpy_array(network)
g = plt.figure(1)
pos = nx.spring_layout(G)  # positions for all nodes

nx.draw_networkx_nodes(G, pos, node_size=700)
nx.draw_networkx_edges(G, pos, width=1, edge_color='k')
nx.draw_networkx_labels(G, pos, font_size=20, font_family='monospace')

plt.axis('off')


#get the requests


#creare a list of list, like a dict, of cars with availability, location, and time shortest path time as their params
cars = [[0,1,0],[0,1,0]]
#check what happens when more cars are added
carsMore = [[[0, 1, 0], [0, 1, 0]],
        [[0, 1, 0], [0, 1, 0], [0, 1, 0]],
        [[0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0]],
        [[0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0]],
        [[0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0]],
        [[0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0]],
        [[0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0], [0, 1, 0]]]


#the overall algorithm is within this function-it takes in the request file and then outputs the waiting time
#It also determines things like which cars are picking up, the path they take
#as well as what passengers get picked up in what order, and graphs it

def waiting_time(networks, requests, cars=None):
    car = 0
    minTime = 100000 #ensure that the first min time is less than

    #for chosing the car to use
    if cars==None:
        #assume 2 cars
        cars = [[0,1,0],[0,1,0]]

    time_waiting = 0
    time = []
    loc = []
    dest = []

    # get the different values from the request files
    with open(requests, 'r') as csvfile:
        req = csv.reader(csvfile, delimiter=',')
        for line in req:
            time.append(float(line[0]))
            loc.append(float(line[1]))
            dest.append(float(line[2]))

    #get how many requests there are
    alltimes = len(time)

    #iterate through all of the times requested, get car behavoir
    for i in range(0, alltimes):
    # after that, find the dijkstras distance from the cars to find closest and use this to determine time
        #compare cars
        for c in cars:
            c[2] = nx.dijkstra_path_length(networks, c[1]-1, loc[i]-1, weight='weight')
            #c[2] = nx.dijkstra_path_length(networks, c[1] - 1, loc[i] - 1, weight='weight')
            if time[i]> c[0]:
                c[0] = time[i] #this is checking for the time spent waiting and whether or not the car had to wait to be finished its last drop off


    #now we need to chose the car with the smallest waiting time!
        numcars = len(cars)

        for lowest in range(0,numcars):
            wait = cars[lowest][0] + cars[lowest][2]
            if wait < minTime:
             car = lowest
             minTime = wait

    #when dropping passenger off
        if cars[car][0] > time[i]:
            additional = minTime - time[i] #checks if there is a delay when the car is not ready immediately
        else:
             additional = cars[car][2] #simply the length of the trip to the start

    #Find the shortest distance between the start and end locations
        trip_time = nx.dijkstra_path_length(networks, loc[i] - 1, dest[i] - 1, weight='weight')

    #reasssign the the car chosen's available times(the end of getting there and the shortest pathtime) and new location of car
        cars[car][0] += cars[car][2] + trip_time
        cars[car][1] = dest[i]

        time_waiting += additional

    return time_waiting


#find the waiting time
finalTime = waiting_time(G, 'requests.csv', cars)
print(finalTime)


#When checking on the behavoir of cars when number changes
multiCars = []
for i in carsMore:
    multiCars.append(waiting_time(G, 'requests.csv', i))
print(multiCars)
label = nx.spring_layout(G)
nx.draw_networkx_labels(G, label, font_size=15, font_family='monospace')
xNumbers = [2,3,4,5,6,8,10]
d = plt.figure(2)
plt.plot(xNumbers,multiCars,'-rD')
plt.ylabel('Time Waiting')
plt.xlabel("Number of Cars")

