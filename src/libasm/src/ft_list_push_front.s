; args order: rdi, rsi, rdx, rcx
; void	ft_list_push_front(t_list **begin_list, void *data);

extern _ft_lstnew

section		.text
global		_ft_list_push_front

_ft_list_push_front:
	push	rdi
	mov		rdi, rsi
	call	_ft_lstnew			; now new lst in rax
	pop		rdi
	cmp		rax, 0
	je		return
	mov		rdx, [rdi]			; rdx - temporary for *begin_list
	mov		[rax + 8], rdx
	mov		[rdi], rax

return:
	ret
