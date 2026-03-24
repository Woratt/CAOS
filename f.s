.global process_data
process_data:
    pushl %ebp
    movl %esp, %ebp
    pushl %ebx
    pushl %esi
    pushl %edi

    movl 8(%ebp), %ebx
    movl 12(%ebp), %esi

    xorl %edx, %edx
    xorl %eax, %eax

cicle:
    cmpl %edx, %esi
    je end
    
    movl (%ebx, %edx, 4), %edi
    cmpl 16(%ebp), %edi
    jle zero_digit
    
    leal (%edi, %edi, 2), %ecx
    leal 1(%edi, %ecx, 2), %edi
  
    movl %edi, (%ebx, %edx, 4)

    cmpl $100, %edi
    jl increment

    incl %eax
    jmp increment

zero_digit:
    xorl %edi, %edi
    movl %edi, (%ebx, %edx, 4)

increment:
    incl %edx
    jmp cicle

end:
   popl %edi
   popl %esi
   popl %ebx
   movl %ebp, %esp
   popl %ebp
   ret 
