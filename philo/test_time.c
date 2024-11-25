#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int main() {
    time_t	start_time;
    time_t	end_time;
	time_t	timer;

	start_time = get_time_in_ms();
	usleep(2000000);
	end_time = get_time_in_ms();
	timer = end_time - start_time;

    printf("Elapsed time: %ld microseconds\n", timer);

    return 0;
}
