; args order: rdi, rsi, rdx, rcx
; int	ft_list_size(t_list *begin_list);

section		.text
global		_ft_list_size

_ft_list_size:
	mov		rax, 0

loop:
	cmp		rdi, 0
	je		return
	mov		rdi, [rdi + 8]
	inc		rax
	jmp		loop

return:
	ret
