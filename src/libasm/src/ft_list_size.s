; int	ft_list_size(t_list *begin_list);

; Mesaures the length of the list.
;
; Received arguments:
; t_list **begin_list - pointer to the first element of the chain list.
; Return value:
; Size of the list, int.


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
