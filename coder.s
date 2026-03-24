    .text 
    .global main
main:
    pushl %ebp
    movl %esp, %ebp

    call readi32

    testl $1, %eax
    jz is_even

is_odd:
    xorl  %eax, %eax
    add $7, %eax
    jmp limit    

is_even:
    shll $2, %eax
    addl $10, %eax

limit:
    cmpl $50, %eax
    jl write_less_50

    movl $50, %eax
    call writei32
    
    jmp end

write_less_50:
    call writei32

end:
    call finish
