    .global main
main:
    call readi32
    
    mov %eax, %edx
    
    call readi32
    
    cmpl %edx, %eax
    
    je is_equal
    jl is_less
    jg is_biger

is_equal:
    jmp end

is_less:
    mov %edx, %eax
    call writei32
    jmp end

is_biger:
    call writei32
    jmp end

end:
    call finish
