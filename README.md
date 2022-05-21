# Philosophers

**Philosophers** (represented by parts of a program) sit around a table, with a big plate of spaghetti at its center. They each have a fork, but they need two forks to eat ; so they need to borrow their neighbor's fork to eat.

# Rules
- Each philosopher should be a thread.
- One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher.
- To avoid philosophers duplicating forks, I should protect the forks state with a mutex for each of them.

# Execute
- The Two Programs Take The Following Arguments:
  - **number_of_philosophers**: is the number of philosophers and also the number of forks.
  - **time_to_die**: is in milliseconds, if a philosopher doesn’t start eating **’time_to_die’** milliseconds after starting their last meal or the beginning of the simulation, it dies.
  - **time_to_eat**: is in milliseconds and is the time it takes for a philosopher to eat. During that time they will need to keep the two forks.
  - **time_to_sleep**: is in milliseconds and is the time the philosopher will spend sleeping.
  - **number_of_times_each_philosopher_must_eat**: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the
simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.

**Example**: Without **number_of_times_each_philosopher_must_eat** Argument `./philo 4 500 200 200`</br>
**Example**: With **number_of_times_each_philosopher_must_eat** Argument `./philo 7 310 100 100 7`

<img width="736" alt="Screen Shot 2022-05-21 at 4 04 49 PM" src="https://user-images.githubusercontent.com/105823790/169655331-c9215260-1096-4af9-ba3d-0705566e3aa9.png">



[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
