    .global main
main:
    mov var, %eax
    call writei32

    mov $33, %eax
    mov %eax, var

    call writei32

    call finish

.data
var:
    .int 42
     
