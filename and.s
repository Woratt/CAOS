    .text
    .global main
main:
    pushl %ebp
    movl  %esp, %ebp

    call readi32

    and $1, %eax

    call writei32

    call finish 
