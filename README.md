# Philosopher - Dîner des philosophes

One or more philosophers are seated around a round table, in the center of which, there is a plate of spaghetti. They can either eat, sleep or think. Each philosopher can only perform one action at a time. Each time a philosopher finishes eating, he puts down his forks and begins to sleep for a defined time. When he wakes up, he thinks until forks are available so he can eat. And so on, until one of them dies of hunger.

<img width="549" alt="Capture d’écran, le 2022-01-21 à 16 08 02" src="https://user-images.githubusercontent.com/79991066/150600352-ddb5e6a4-08aa-44d0-934a-dc96812e5104.png">


## Contraintes : 
  - chaque philosophe n'a qu'**une seule fourchette à protéger par un MUTEX**
  - **chaque philosophe est représenté par un THREAD**
  - pour **manger**, un philosophe a besoin de **deux fourchettes**
  - il y a un **temps défini** pour manger et dormir
  - les philosophes ne peuvent pas se parler entre eux
  - si un philosphe ne mange pas assez rapidemment, il **risque de mourir** !

## **Programme et arguments**
### **./philo [nb_de_philo] [time_to_die] [time_to_eat] [time_to_sleep] [nb_time_must_eat]**
####   - ***number_of_philosopher*** : is the number of philosophers and also the number of forks;
####   - ***time_to_die***: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after           starting their last meal or the beginning of the simulation, it dies;
####   - ***time_to_eat***: is in milliseconds and is the time it takes for a philosopher to eat. During that time they will need to keep the two forks;
####   -  ***time_to_sleep***: is in milliseconds and is the time the philosopher will spend sleeping;
####   -  ***number_of_times_each_philosopher_must_eat***: **argument is optional**, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.

Any change of status of a philosopher must be written as follows: timestamp_in_ms X action
![philo_test_AdobeCreativeCloudExpress-2](https://user-images.githubusercontent.com/79991066/150593804-6939de67-7af9-4670-936f-b2a4c9ee293e.gif)

## Understanding THREADS & MUTEX
Multithreading allows your program to run several things at the same time. **BUT** all of the threads will have access to the same piece of memory, and will be able to read and write the same variable **AT THE SAME TIME**. To avoid threads to change the same variable at the same time, you must protect it with a **MUTEX**.

Imagine two cars want to pass down the same narrow stretch of road. To prevent an accident, you can add traffic signals. Those traffic signals prevent the cars from getting access to a shared resource (the road) at the same time. It's the same things with threads, the traffic signals would be the mutex.

- #include <pthread.h>
- flag lpthread to compile

**In this project, each philosopher must be a thread and each fork must be protected by a mutex.**

## How does it works ?
- One main structure t_game which contains all the shared variables, *i.e.* whose values are the same for each philosophers (game_over, time...);
- An other structure t_philo which contains all the specific variables for each philosophers (id, meal_counter...).

## Using a waiting queue
Since philosophers can't talk to each other, they won't know if one of them is about to starving to death. So, to avoid a quicker thread to eat more often, we can use a queue. It means that we prioritize odd numbers, so 1 and 3 would eat, go back to the queue, 5 and 2 would eat, then go back to the queue, then 4 and 1 would eat ...

## Handle the time
`int gettimeofday(struct timeval *tp, struct timezone *tz);`
The timeval structure represents a calendar time. It has two members:
  - tv_sec : number of second since the epoch
  - tv_usec : additionnal ms after number of second calculation since the epoch.

The timezone structure should be set to NULL.

To get the timestamp in milliseconds : `long time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);`

Carefull, a philosopher could die while he is sleeping ! So, you may need to create your own usleep function, where you can check if he's still alive. It means for example:
```
while (time_now - start_time_of_action < time_to_eat)
{
  dead_checker;
  usleep(250);
}
```
So, as long as the present time minus the time that has elapsed since the action began is inferior of the time needed to eat, the philosophers would wake up every 250 microseconds and check if he's still alive. 
