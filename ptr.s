	.file "indsa.p"
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	-8(%rbp), %r10d
	movl	$8, %r10d
	movl	%r10d, -8(%rbp)
	movl	-4(%rbp), %r10d
	leal	-8(%rbp), %r11d
	movl	%r11d, %r10d
	movl	%r10d, -4(%rbp)
	movl	-8(%rbp), %r10d
	
	movl	-4(%rbp), %r11d
	movl	(%r11d), %r10d

	movl	%r10d, -8(%rbp)
	movl	-8(%rbp), %r10d
	movl	%r10d, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addq	$16, %rsp
	movl	$0, %eax
	popq	%rbp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
