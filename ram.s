	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	subl	$24, %esp
	movl	$0, -4(%ebp)
	movl	$5, -8(%ebp)
	movl	$6, -12(%ebp)
	movl	$7, -16(%ebp)
	movl	-8(%ebp), %eax
	addl	-12(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	addl	-16(%ebp), %eax
	movl	%eax, -24(%ebp)
	xorl	%eax, %eax
	addl	$24, %esp
	popl	%ebp
	retl
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
