import threading
from myThread import myThread

thread = myThread(1, "Thread-1", 1) # Create new threads
thread.start() # Start new Threads

while True:
    cmd = input("")
    # username = input("Enter username:")