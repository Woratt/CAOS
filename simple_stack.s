.global main
main:
   call readi32
   
   push %eax

   call readi32

   popl %ebx

   addl %ebx, %eax

   call writei32

   call finish
 
