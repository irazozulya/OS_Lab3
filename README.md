# OS_Lab3

MFQS (MULTILEVEL FEEDBACK QUEUE SHEDULING )

 ## Common setup

 Clone the repo and install the dependencies.

 ```bash
 git clone https://github.com/irazozulya/OS_Lab3
 ```

 ## Installation

 Use Visual Studio to compile and start the project.
 

 ## Usage

 The program is used for CPU sheduling.
 
 
 ## Theory
 A multilevel queue with inverse connections assumes that applications are subject to certain conditions can move between queues. The initial search processes are purchased at 0, where each of them is given a quantum time equal to 8 ms. These processes, which did not have time to complete this time, move for 1. 
 Processes from queue 1 begin to be processed only when queue 0 becomes empty. These processes that were not performed in queue 1 (q = 16 ms) move to space 2. Processes from queue 2 will be processed only yesterday case if queues 0 and 1 become empty.
 The considered strategy is the most universal and is combined in power structures of all previously discussed strategies: FIFO, SJF, Round Robin.
 ![The sheduling scheme](https://github.com/irazozulya/OS_lab2/blob/main/2.png)
 
 
 ## Examples
 
 Adding and handling the process:<br />
 ![The first picture](https://github.com/irazozulya/OS_Lab3/blob/main/1.png)
 
 ###Graph of dependency of the time average form the process adding intensive
 ![The graph](https://github.com/irazozulya/OS_Lab3/blob/main/3.png)

 ## Functions
Process(int, int) is used for creating a Process class object<br />
int run() is used for getting the Process required<br />
int get_id() is used for getting the Process id<br />
void start() is used for starting the Process<br />
void set_ch_time(int) is used for setting the ch_time<br />
MFQS() is used for creating a MFQS class object<br />
void add(Process *) is used for adding the Process<br />
void run() is used for running the queues<br />
int main() is used for starting the program<br />

 ## Version

 OS_Lab3 Version 1.0 22/12/2020
 

 ## Author

 - **Iryna Zozulia** - [irazozulya](https://github.com/irazozulya)


 ## Architecture

 main.cpp - the main file ;

 ## License

 [MIT license](https://choosealicense.com/licenses/mit/)

