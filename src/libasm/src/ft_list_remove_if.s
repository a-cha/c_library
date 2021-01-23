; void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

; Removes a node of the list containing the same data as data_ref.
;
; Received arguments:
; t_list **begin_list - pointer to the first element of the chain list.
; void *data_ref - pointer to reference data, using for comparison.
; int (*cmp)() - pointer to function, whitch compares node's data with data_ref.


section		.text
extern _free
global		_ft_list_remove_if

_ft_list_remove_if:
; check if first elem should remove (and remove it)
is_first:
	push	rdi
	mov		rdi, [rdi]			; rdi = *begin_list
	cmp		rdi, 0				; if the list is over
	je		clean_stack
	mov		rdi, [rdi]			; rdi = begin_list->data
	push	rdx					; save all occupied registers
	call	rdx
	pop		rdx					; turn back all registers
	pop		rdi
	cmp		rax, 0
	jne		is_further			; if result of cmp func != 0
	mov		rcx, [rdi]			; rcx = *begin_list
	mov		r10, [rcx + 8]		; r10 = begin_list->next
	mov		[rdi], r10			; *begin_list = begin_list->next
	push	rdi					; save all registers
	push	rsi
	push	rdx
	push	rcx
	mov		rdi, rcx
	call	_free				; free node
	pop		rcx
	pop		rdx
	pop		rsi
	pop		rdi
	jmp		is_first

; check if other elements should remove
is_further:
	mov		rdi, [rdi]			; rdi = *begin_list

loop:
	mov		rcx, [rdi + 8]		; rcx = begin_list->next
	cmp		rcx, 0				; if the list is over
	je		return
	push	rdi
	mov		rdi, [rcx]			; rdi = begin_list->next->data
	push	rcx					; save all occupied registers
	push	rdx
	call	rdx
	pop		rdx					; turn back all registers
	pop		rcx
	pop		rdi
	cmp		rax, 0
	je		remove_elem			; if result of cmp func == 0
	mov		rdi, [rdi + 8]		; begin_list = begin_list->next
	jmp		loop

; remove elem
remove_elem:
	mov		r10, [rcx + 8]		; r10 = begin_list->next->next
	mov		[rdi + 8], r10		; begin_list->next = begin_list->next->next
	push	rdi					; save all registers
	push	rsi
	push	rdx
	push	rcx
	mov		rdi, rcx
	call	_free				; free node
	pop		rcx
	pop		rdx
	pop		rsi
	pop		rdi
	jmp		loop

clean_stack:
	pop		rdi

return:
	ret
