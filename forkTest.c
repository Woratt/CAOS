#include <stdio.h>
#include <unistd.h>

int main()
{
  printf("Hello World! << %d\n", getpid());
  pid_t pid = fork();

  if(pid == 0){
    char *path = "/Users/admin/Downloads/education/fork_var_change";
        
        // Масив аргументів: ім'я програми, потім інші аргументи, в кінці NULL
        char *args[] = {path, NULL}; 
        
        // Масив оточення: зазвичай передаємо NULL, якщо не міняємо змінні
        char *env[] = {NULL};

        printf("Дитина (PID %d) запускає нову програму...\n", getpid());
        
        execve(path, args, env);

        // Якщо ми дійшли сюди, значить execve не спрацював
        perror("execve failed");
        _exit(1);
  }else{
    printf("Main Program"); 
  }
  //while(1){
  //  printf("[%d] pid returned after fork: %d, parent pid: %d\n", getpid(),
  //     pid, getppid());
  //  sleep(10);
  //}
  return 0;
}

