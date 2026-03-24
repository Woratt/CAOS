    .global main
main:
    call   readi32
    
    mov     %eax, %edx

    call    readi32

    add     %edx, %eax

    call    writei32

    call    finish 
