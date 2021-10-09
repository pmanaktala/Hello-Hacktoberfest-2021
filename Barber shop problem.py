from threading import Thread
import threading
import time
import random



barber_wakeup = 1                                    #Barber is asleep and waiting for customer
customers_sem = threading.Semaphore(0)
barber_sem = threading.Semaphore(0)
mutex = threading.Semaphore(1)                         #For barber chair which is a shared resource.


class BarberShop:
    waiting_customers = []

    def __init__(self, barber, total_chairs):
        self.barber = barber
        self.total_chairs = total_chairs

    def barberWorking(self):
        t_barber = Thread(target=self.inBarberRoom)
        t_barber.start()

    def enter_barber_shop(self, customer):
        print("\n{} enters the shop and looks for an empty chair".format(customer))
        mutex.acquire()                                  #When a customer arrives, he executes customer procedure the customer
                                                         # acquires the mutex for entering the critical region,
                                                         #if another customer enters thereafter,
                                                         #the second one will not be able to anything until the first one has released the mutex. 
        if len(self.waiting_customers) < self.total_chairs:
            print("\n{} finds an empty chair".format(customer))
            self.waiting_customers.append(customer)
            global barber_wakeup                         #Customer can wakeup the barber who is asleep.
            while barber_wakeup:
                customers_sem.release()                  #Customer arrives.
                print("\n{} wakesup the barber".format(customer))
                barber_wakeup = 0                        #Barber is awake.
            print("\n{} takes a waiting chair.".format(customer))
            mutex.release()                              # customer after sitting on waiting seat is releasing the lock
            print("\n{} waits for barber's call".format(customer))
            barber_sem.acquire()        
            Customer.getHairCut(self, customer)          #Customer is having a haircut.
        else:                                                            #Waiting room is full
            mutex.release()
            Customer.balk(self, customer)

                   
    def inBarberRoom(self):
        while True:
            if len(self.waiting_customers) == 0:          #No customers to be served in waiting room.    
                global barber_wakeup
                print("Barber is sleeping and waiting for customer to wake him up")
                barber_wakeup = 1                         #Barber is asleep.
                customers_sem.acquire()                   #No customer in the shop.
               
            if len(self.waiting_customers) > 0:           #Customers are waiting in the room

                mutex.acquire()                           #When a customer arrives, he executes customer procedure the customer
                                                          #acquires the mutex for entering the critical region,
                                                          #if another customer enters thereafter,
                                                          #the second one will not be able to anything until the first one has released the mutex. 
                  
                cust = self.waiting_customers[0]          #Barber calls the customer
                print("\nBarber calls {} for haircut".format(cust))

                del self.waiting_customers[0]
                barber_sem.release()                      #Barber is now ready to work
                mutex.release()                           #Barber unlock the barber's chair so customer can sit on the chair
                self.barber.cutHair(cust)

class Barber:
    def cutHair(self, customer):
        print("\nBarber is cutting {}'s hair.".format(customer))
        time.sleep(2)
        print("\n{} is leaving the shop".format(customer))

    

class Customer:
    def __init__(self, name):
        self.name = name

    def getHairCut(self, customer):
        print("\n{} is having haircut".format(customer))
        time.sleep(2)

    def balk(self, customer):
        print("\nWaiting Room is full, therefore, {} leaves shop without hair cutting".format(customer))
        
if __name__ == '__main__':
    global customer_list
    customers_list = []
    barber = Barber()
    customer = Customer(customers_list)
    barberShop = BarberShop(barber, 1)                      # 1Seat in shop 
    barberShop.barberWorking()                          
    
    customers_list.append(Customer('Ibrahim'))
    customers_list.append(Customer('Leena'))
    customers_list.append(Customer('jay'))
   
    
    while len(customers_list) > 0:
        c = customers_list.pop()
        t = threading.Thread(target=barberShop.enter_barber_shop,args=(c.name,))# customers are entering in shop after random seconds from 1 to 5
        time.sleep(random.randint(1,2))
        t.start()