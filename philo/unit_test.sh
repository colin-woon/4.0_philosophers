make
make clean

# ./philo
# ./philo 1 2 3 4 5 6

# ./philo 201 410 200 200
# ./philo asd 410 200 200
# ./philo 200 asd 200 200
# ./philo 200 410 asd 200
# ./philo 200 410 200 asd
# ./philo -123 410 200 200
# ./philo 200 -123 200 200
# ./philo 200 410 -123 200
# ./philo 200 410 200 -123
# ./philo 0 410 200 200 5
# ./philo 0 410 200 200

# ./philo 1abc00 410 200 100
# ./philo 100 4abc10 200 100
# ./philo 100 410 2abc00 100
# ./philo 100 410 200 10abca0

# ./philo 100 410 200 100
# ./philo 100 410 200 100 231


echo "The philosopher should not eat and should die."
./philo 1 800 200 200
echo "No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times."
./philo 5 800 200 200 7
echo "One philosopher should die."
./philo 4 310 200 100
# echo "No philosopher should die."
# ./philo 4 410 200 200
# echo "No philosopher should die."
# ./philo 5 800 200 200


# 1. Check if there is one thread per philosopher
# Review Code: Look for a loop that creates threads for each philosopher:

# 2. Check if there is only one fork per philosopher
# Test: Confirm the number of mutexes created matches the number of philosophers:

# 3. Check if there is a mutex per fork and it's used to check/change fork value
# Review Code: Look for mutex locks and unlocks around fork access:

# 4. Check outputs are never mixed up, output should be a philo grabs both forks then eat and sleep without being interrupted by another philo
# Review Code: Ensure a mutex is used for writing to standard output:
# Test: Deliberately introduce small sleep intervals before and after printing:

# 5. Check how the death of a philosopher is verified
# Review Code: Check the monitoring logic for each philosopher. Typically, a separate thread or routine continuously checks if a philosopher's last meal time has exceeded the time to die
# Verify Mutex: Ensure the check and modification of a philosopher's state are protected by a mutex:

# Deadlock Scenario
# Test: Lock a mutex twice

# Data Race
# Test: Will happen if lock_eat_routine is unlocked after waiting instead of before waiting as there is another mutex being used in the waiting function, causing synchronization issues

# Synchronization Issue:
# Test: Mutex lock last meal time after creating threads in routine function, then run with valgrind to see the inconsistency
