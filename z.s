    .global main
main:
    call readi32

    mov %eax, %edx

    call readi32

    imul %edx, %edx

    sub %eax, %edx

    add $5, %edx

    mov %edx, %eax

    call writei32
    call finish

