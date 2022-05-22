# Philosophers

This project focuses on solving the dining philosophers problem - in computer science it is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.


* One or more philosophers are sitting at a round table either eating, either thinking, either sleeping. While they are eating, they do not think or sleep; while thinking they don’t eat or sleep; and, of course, while sleeping, they do not eat or think.
* The philosophers sit at a circular table with a large bowl of spaghetti in the center.
* There are some forks on the table. Serving and eating spaghetti with a single fork is very inconvenient, so the philosophers will eat with two forks, one for each hand.
* Each time a philosopher finishes eating, they will drop their forks and start sleeping. Once they have finished sleeping, they will start thinking. The simulation stops when a philosopher dies.
* Every philosopher needs to eat and they should never starve.
* Philosophers don’t speak with each other.
* Philosophers don’t know when another philosopher is about to die.
* Philosophers avoid death.
* Each philosopher is thread.
* One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher.
* To avoid philosophers duplicating forks, there is forks state protection with a mutex for each of them.
* Any change of status of a philosopher will be written as follows (with X replaced with the philosopher number and timestamp_in_ms the current timestamp in milliseconds):
  * timestamp_in_ms X some_action



# Execute
- The programs reauires the following arguments:
  - **number_of_philosophers**: is the number of philosophers and also the number of forks.
  - **time_to_die**: is in milliseconds, if a philosopher doesn’t start eating **’time_to_die’** milliseconds after starting their last meal or the beginning of the simulation, it dies.
  - **time_to_eat**: is in milliseconds and is the time it takes for a philosopher to eat. During that time they will need to keep the two forks.
  - **time_to_sleep**: is in milliseconds and is the time the philosopher will spend sleeping.
  - **number_of_times_each_philosopher_must_eat**: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the
simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.

**Example**: Without **number_of_times_each_philosopher_must_eat** Argument `./philo 5 500 200 200`</br>
**Example**: With **number_of_times_each_philosopher_must_eat** Argument `./philo 7 310 100 100 7`

<img width="736" alt="Screen Shot 2022-05-21 at 4 04 49 PM" src="https://user-images.githubusercontent.com/105823790/169655331-c9215260-1096-4af9-ba3d-0705566e3aa9.png">



[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
