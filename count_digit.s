.global count_digits
count_digits:
    pushl %ebp
    movl %esp, %ebp

    mov 8(%ebp), %edx

    xor %eax, %eax

cycle:
    cmpb $0, (%edx)
    je end

    cmpb $'0', (%edx)
    jl increment

    cmpb $'9', (%edx)
    jg increment

    xor %ecx, %ecx
    movb (%edx), %cl
    subb $'0', %cl
    addl %ecx, %eax

increment:
    incl %edx
    jmp cycle 

end:
    movl %ebp, %esp
    popl %ebp

    ret  

    

