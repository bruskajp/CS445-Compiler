	.file "indsa.p"
	movl	-8(%rbp), %r10d
	movl	$13, %r10d
	movl	%r10d, -8(%rbp)
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$28, %rsp
	addq	$28, %rsp
	movl	$0, %eax
	popq	%rbp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
