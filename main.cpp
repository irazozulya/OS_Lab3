#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <deque>
#include <list>
#include <mutex>
using namespace std;

class Process {
private:
    clock_t start_time;
    int time;
    int ch_time;
    int id;
public:
    Process(int, int);
    int run();
    int get_id();
    void start();
    void end();
    void set_ch_time(int);
};

class MFQS {

public:
    MFQS();
    void add(Process *);
    void run();
    bool working;
    double time = 0;
private:
    clock_t wait_time = 0;

    mutex _lock;
    list<std::deque <Process *> > queue;

};


int main() {
    srand(time(NULL));
    int intensive = 5;
    MFQS * mfqs = new MFQS;
    int count_of_processes = 10;
    vector<Process *> processes(count_of_processes);
    thread thr([&mfqs](){ mfqs->run();});
    thread add_processes([&processes, &mfqs, &intensive, &count_of_processes](){
        for (int i  = 0; i < count_of_processes; i++){
            processes[i] = new Process(rand()%32 + 1, i + 1);
            mfqs->add(processes[i]);
            this_thread::sleep_for(chrono::milliseconds(intensive));
        }
    });
    thr.join();
    add_processes.join();
    cout << "Wait time for " << count_of_processes << " processes with intensive " << intensive << "ms per process is " << mfqs->time << endl;
    return 0;
}

Process::Process(int time, int id) {
    if (id >= 0 && time >= 0) {
        this->id = id;
        this->time = time;
        this->ch_time = time;
    }
}

int Process::run() {
    return time;
}

int Process::get_id() {
    return id;
}

void Process::start() {

    cout << "\tStart process " << id << "\n";
    start_time = clock();
    this_thread::sleep_for(std::chrono::milliseconds(ch_time));
    clock_t running_time = clock() - start_time;
    cout << "\tEnd process " << id << " with running time " << running_time << "\n\n";
}

void Process::set_ch_time(int new_time) {
    ch_time = new_time;
}

MFQS::MFQS() {
    for (int i = 0; i < 32; i++) {
        queue.emplace_back(deque <Process *> ());
    }
}

void MFQS::add(Process * process) {
    _lock.lock();
    if (process != nullptr) {
        if (!queue.empty()) {
            queue.front().push_back(process);
        }
    }
    _lock.unlock();
}

void MFQS::run() {
    int numb_of_processes = 10;
    while (numb_of_processes != 0) {
        clock_t curr_wait = 0;
        clock_t start = clock();
        if (!queue.front().empty()) {
            working = true;
            int time = 8;
            int index = 0;
            for (auto it = queue.begin(); it != queue.end(); ++it) {
                if (!it->empty()) {
                    std::cout << "Queue №" << index + 1 << "\n";
                    for (auto process : *it) {
                        if (process->run() > time) {
                            if (it != queue.end()) {
                                process->set_ch_time(process->run() - time);
                                this_thread::sleep_for(std::chrono::milliseconds(time));
                                (++it)->push_back(process);
                                (--it)->pop_front();
                                cout << "\tProcess " << process->get_id() << " with the execution time: " << process->run() << " is in a queue with execution time: "<< time << "\n";
                            }
                        } else {
                            cout << "\n\tProcess " << process->get_id() << " with the execution time: " << process->run() << "\n";
                            process->start();
                            numb_of_processes--;
                            it->pop_front();
                        }
                    }
                    index++;
                    time *= 2;
                }
            }
        } else {
            working = false;
            curr_wait = clock() - start;
            wait_time += curr_wait;
        }
    }
    time = (double (wait_time))/(CLOCKS_PER_SEC/1000);
}