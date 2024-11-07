# Dining Philosophers Problem

## Overview

The **Dining Philosophers Problem** is a classic synchronization problem in computer science, used to demonstrate the challenges of concurrent access to shared resources. The problem involves philosophers sitting around a table, alternating between thinking and eating. Philosophers need two forks to eat, and forks are shared between neighbors. The goal is to avoid deadlock and starvation while ensuring fair access to resources.

## Problem Description

- **Philosophers**: Represented by threads, philosophers alternate between thinking and eating.
- **Forks**: Each philosopher requires two forks to eat. Forks are shared resources between neighboring philosophers.
- **States**:
  - **Thinking**: The philosopher is thinking and not using any forks.
  - **Eating**: The philosopher is eating, requiring two forks.
  - **Sleeping**: The philosopher is sleeping and drop all forks.

### Challenges:
1. **Deadlock**: All philosophers may pick up one fork at the same time, waiting indefinitely for the second fork, leading to a deadlock.
2. **Starvation**: Some philosophers may never get a chance to eat if forks are not fairly distributed.

## Solution

This implementation uses **threads** and **mutexes** to safely manage shared resources (forks) and prevent deadlock and starvation.

### Key Concepts:
- **Mutexes**: Used to protect fork access, ensuring that only one philosopher can pick up a fork at a time.
- **Deadlock Prevention**: Philosophers pick up the left fork first and the right fork next, preventing circular wait conditions that can cause deadlock.

## instalation

```bash
git clone https://github.com/ahmedelqori/Dining_Philosophers.git

cd philo

make

./philo 4 410 200 200
```