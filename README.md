# Philosophers

Philosophers is a project of the mandatory part of the cursus. It's only made in C and the main goal was to understand how threads works in language C and use them to solve a logical problem. The simulation will stop if all philosophers have eaten enough or if one philosopher die.

# Execute
- The programs reauires the following arguments:
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
