    .global main
main:
    call readi32
    cmp $-1, %eax
    jz fin

    mov %eax, %ebx
    call readi32
    mov %eax, %edx

   # mov $arr, %edi
   # shl $2, %ebx
   # add %ebx, %edi
    mov arr(, %ebx, 4), %eax

    #mov (%edi), %eax
    call writei32

    #mov %edx, (%edi) 
    mov %edx, arr(, %ebx, 4)    

    jmp main    
fin:
   call finish

.data
arr:
    .skip 200*4, 0
