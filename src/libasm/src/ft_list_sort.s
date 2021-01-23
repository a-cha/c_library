; void	ft_list_sort(t_list **begin_list, int (*cmp)());

; Sorts the received list.
;
; Received arguments:
; t_list **begin_list - pointer to the first element of the chain list.
; int (*cmp)() - pointer to function, whitch compares data of two nodes.


section		.text
global		_ft_list_sort

; rdi - pointer to first elem, rsi - pointer to second elem
_ft_list_sort:
	mov		r10, rsi			; pointer to cmp function
	mov		r9, 1				; flag
	mov		rcx, [rdi]
;	push	rdi
mov rdx, rdi
	cmp		rcx, 0				; check is there a 1st elem
	je		clean_stack
	mov		rsi, [rcx + 8]
	cmp		rsi, 0				; check is there a 2nd elem
	je		clean_stack

again:
;	pop		rdx					; pointer to pointer to 1st elem
;	mov rax, [rdx]
;	ret
	cmp		r9, 0				; flag == 0 - there are no changes, exit
	je		return
	mov		rdi, [rdx]			; pointer to 1st elem
;	mov		rdi, [rdx]			; pointer to 1st elem
;	push	rdx
	mov		rsi, [rdi + 8]		; pointer to 2nd elem
	mov		r9, 0
	call loop

again1:
	cmp		r9, 0				; flag == 0 - there are no changes, exit
	je		return
	mov		rdi, [rdx]			; pointer to 1st elem
;pop rdx
mov rax, rdi
ret
;	push	rdx
	mov		rsi, [rdi + 8]		; pointer to 2nd elem
mov rax, rsi
ret
	mov		r9, 0

loop:
	push rdx
	push	rdi
	push	rsi
	push	r10
	push	r9
	call	r10
	pop		r9
	pop		r10
	pop		rsi
	pop		rdi
	pop	rdx
;	mov rax, rsi
;	ret
	cmp		rax, 0
	jg		change

continue:
;	mov rax, rdi
;	ret
	mov		rdi, [rdi + 8]
;	mov rax, rdi
;	ret
	mov		rsi, [rsi + 8]
;	mov rax, rsi
;	ret
	cmp		rsi, 0
;je		return
	je		again
	jmp		loop

change:
push rdx
	mov		rdx, [rdi]			; first->data
	mov		r9, [rsi]			; second->data
	mov		[rdi], r9			; change data
	mov		[rsi], rdx
pop rdx
	mov		r9, 1				; set flag
;	mov rax, rsi
;	ret
	jmp		continue

clean_stack:
	pop		rdi

return:
	ret
