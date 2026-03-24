    .global main
main:
    call readi32
    jc end
    jmp *jmptab(, %eax, 4)

read_to_stack:
    call readi32
    pushl %eax 
    jmp main

pop_and_add:
    popl %eax
    addl %eax, (%esp)
    jmp main

top_of_stack:
    mov (%esp), %eax
    call writei32
    jmp main

pop_from_stack:
    pop %eax
    jmp main

end:
    call finish

jmptab:
    .int read_to_stack, pop_and_add, top_of_stack, pop_from_stack
