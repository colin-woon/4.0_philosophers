#include "philo.h"

void TEST_check_initialization(t_table *table);
void print_table(t_table *table);
void print_philo(t_philo *philo);

void TEST_check_initialization(t_table *table)
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
	printf("Time to Die: %d\n", table->die_at);
	printf("Time to Eat: %d\n", table->eat_at);
	printf("Time to Sleep: %d\n", table->sleep_at);
	printf("Meals Needed: %d\n", table->meals_needed);
	printf("Is Exit: %d\n", table->is_exit);
	printf("Lock Is Exit: %p\n", (void*)&table->lock_is_exit);
}

void print_philo(t_philo *philo)
{
	printf("Philosopher Initialization:\n");
	printf("ID: %d\n", philo->id);
	printf("Meals Ate: %d\n", philo->meals_ate);
	printf("Forks: [%d, %d]\n", philo->fork[0], philo->fork[1]);
	printf("Last Meal: %ld\n", philo->last_meal);
	// printf("Lock Last Meal: %p\n", (void*)&philo->lock_last_meal);
	printf("Table: %p\n", (void*)philo->table);
}
