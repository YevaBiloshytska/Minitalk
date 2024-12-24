#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// void handler(int signum) {
//     if (signum == SIGUSR1) {
//         printf("Получен сигнал SIGUSR1\n");
//     } else if (signum == SIGUSR2) {
//         printf("Получен сигнал SIGUSR2\n");
//     }
// }

// int main() {
//     // Установим обработчики для сигналов
//     signal(SIGUSR1, handler);
//     signal(SIGUSR2, handler);

//     // Ожидаем сигналов
//     while (1) {
//         pause();  // Ожидаем поступление сигналов
//     }

//     return 0;
// }

// int main(void) {
//   pid_t pid;

//   pid = getpid();
//   printf("The process ID is %d\n", pid);

//   return 0;
// }


// int main(void) {
//     printf("Entering pause...\n");
//     pause();
//     printf("Exiting pause.\n");
//     return 0;
// }

// int main(void) {
//     printf("Sleeping for 500000 microseconds...\n");
//     usleep(500000);
//     printf("Done sleeping.\n");
//     return 0;
// }


void signal_handler(int signum) 
{
  printf("Received SIGINT!%i\n", signum);
  exit(0);
}

int main() 
{
  // Set the signal handler for the SIGINT and SIGTERM signals
  // to the signal_handler function
  
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);

  while (1) {
    // Do some work here...
  }

  return 0;
}