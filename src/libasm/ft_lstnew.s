; args order: rdi, rsi, rdx, rcx
; t_list	*ft_lstnew(void *content);

extern _malloc

section		.text
global		_ft_lstnew

_ft_lstnew:
	push	rdi
	mov		rdi, 16
	call	_malloc
	cmp		rax, 0
	je		return
	pop		rdi
	mov		[rax], rdi
	mov		dword [rax + 8], 0

return:
	ret
