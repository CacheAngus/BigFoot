import csv

#get in the csv values and put them into an x and y value
def _importstart_csv(filestart):
    start = []

    #get the values from the csv file
    with open(filestart, 'rt', encoding='utf-8') as csvfile:
        startimport = csv.reader(csvfile, delimiter='\n')
        for row in startimport:
            num = float(row[0])
            start.append(num)
    return start
def _importfinish_csv(fileend):
    finish = []
    with open(fileend, 'rt', encoding='utf-8') as csvfile:
        finishimport = csv.reader(csvfile, delimiter='\n')
        for row in finishimport:
            num = float(row[0])
            finish.append(num)
    return finish


starting = _importstart_csv('start1.csv')
ending = _importfinish_csv('finish1.csv')

flight = []
#make them into a tuple
for i in range (0, len(starting)-1):
    times = [starting[i], ending[i]]
    flight.append(times)
print(flight)
