# 🍝 Philosophers: A Multithreading & Synchronization Study

## 📖 Project Overview

**Philosophers** is a systems programming project at **42 School** that tackles the classic [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem). The objective is to design a robust, concurrent simulation where multiple threads (philosophers) must share limited resources (forks) without falling into deadlocks, race conditions, or starvation.

The problem describes philosophers sitting at a round table with a single fork between each pair. To eat, a philosopher must acquire two forks. This simple premise hides complex synchronization challenges that are central to modern OS design and parallel computing.

---

## 🚀 Key Technical Highlights

- **Concurrency Paradigms**: Implemented two distinct versions—**Multi-threading** (using Mutexes) and **Multi-processing** (using Semaphores)—demonstrating versatility in system resource management.
- **Deadlock Prevention**: Engineered a deterministic resource-acquisition strategy (resource hierarchy) to break the **Circular Wait** condition.
- **Race Condition Mitigation**: Isolated all shared state transitions (eating, status updates, death checks) behind fine-grained mutexes to ensure 100% thread safety and data integrity.
- **Real-time Monitoring**: Developed a non-intrusive monitoring system that tracks the health of all philosophers without introducing significant performance overhead or timing drifts.

---

## 🛠️ Stack & Tools

- **Language**: C (ANSI C / C99)
- **Concurrency**: POSIX Threads (`pthread`), Process Management (`fork`, `waitpid`)
- **Synchronization**: Mutexes (`pthread_mutex_t`), Semaphores (`sem_t`)
- **System**: Unix/Linux Systems Programming, Signal Handling
- **Performance**: High-precision timers, Logic optimization for minimal context switching

---

## 📐 Implementation Architecture

### 1. Threaded Implementation (`philo/`)
In this version, each philosopher is represented as a **thread**.
- **Forks as Mutexes**: Each physical fork is represented by a mutex. A philosopher must lock two specific mutexes (left and right) to start eating.
- **Shared Memory**: All threads share the same address space. Global state (like the "simulation exit" flag) is protected by a dedicated mutex.
- **Resource Ranking**: Deadlocks are prevented by ensuring philosophers always pick up the lower-indexed fork first, breaking the symmetry.

### 2. Process Implementation (`philo_bonus_UNGRADED/`)
This version uses **independent processes** for each philosopher.
- **Forks as Semaphores**: A global semaphore represents the pool of available forks.
- **IPC**: Uses named semaphores (`sem_open`) to coordinate state across process boundaries.
- **Robustness**: Processes are isolated; if the death monitor detects a starvation event, it terminates all child processes via signals (`SIGKILL`).

---

## 🧠 Engineering Challenges & Solutions

### 1. The Accuracy of Time
**Challenge**: Standard `usleep()` is not guaranteed to be precise and can vary based on CPU scheduling and system load.
**Solution**: Implemented a custom "perfect sleep" function that calculates the remaining time in a tight loop with micro-sleep increments, ensuring sub-millisecond precision even on low-performance environments.

### 2. Avoiding Global Bottlenecks
**Challenge**: Using a single global mutex for all logging and state updates causes a massive bottleneck, turning a parallel simulation into a sequential one.
**Solution**: Implemented **fine-grained locking**. Distinct mutexes protect the "last meal" timestamp, the "is dead" status, and the forks, allowing non-conflicting philosophers to act truly in parallel.

### 3. The "Double-Check" Death Monitor
**Challenge**: A philosopher might die exactly as they are updating their "last meal" time, creating a race condition for the monitor.
**Solution**: Synchronized the "last meal" updates and the monitor's check using a per-philosopher mutex, guaranteeing that the monitor always has a consistent view of the philosopher's state.

---

## 🎮 How to Run

### Compilation
```bash
# Build the threaded version
cd philo && make
```

### Execution
The program accepts the following parameters:
```bash
./philo [philos_count] [ms_to_die] [ms_to_eat] [ms_to_sleep] [meals_limit(opt)]
```

**Example (5 philosophers, 800ms to die, 200ms eat/sleep):**
```bash
./philo 5 800 200 200
```

---

## 📜 License
Developed as part of the 42 Core Curriculum.
