#include "philo.h"

void TEST_CHECK_INIT(t_table *table);
void print_table(t_table *table);
void print_philo(t_philo *philo);

void TEST_CHECK_INIT(t_table *table)
{
	int	i;

	i = 0;
	print_table(table);
	while (i < table->total_philos)
		print_philo(&table->philo[i++]);
}

void print_table(t_table *table)
{
	printf("Table Initialization:\n");
	printf("Timer: %ld\n", table->timer);
	printf("Total Philosophers: %d\n", table->total_philos);
	printf("Time to Die: %d\n", table->time_to_die);
	printf("Time to Eat: %d\n", table->time_to_eat);
	printf("Time to Sleep: %d\n", table->time_to_sleep);
	printf("Meals Needed: %d\n", table->meals_needed);
	printf("Is Exit: %d\n", table->is_exit);
	printf("Lock Is Exit: %p\n", (void*)&table->lock_is_exit);
}

void print_philo(t_philo *philo)
{
	printf("Philosopher Initialization:\n");
	printf("ID: %d\n", philo->id);
	printf("Meals Ate: %d\n", philo->meals_required);
	printf("Forks: [%d, %d]\n", philo->fork[0], philo->fork[1]);
	printf("Last Meal: %ld\n", philo->last_meal);
	// printf("Lock Last Meal: %p\n", (void*)&philo->lock_eat_routine);
	printf("Table: %p\n", (void*)philo->table);
}
