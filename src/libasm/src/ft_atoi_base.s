; args order: rdi, rsi, rdx, rcx
; int	ft_atoi_base(char *str, char *base);

extern _ft_strlen

section		.text
global		_ft_atoi_base

_ft_atoi_base:
; check if both args exist and not empty
	cmp		rdi, 0
	je		error
	cmp		rsi, 0
	je		error
	cmp		byte[rdi], 0
	je		error
	cmp		byte[rsi], 0
	je		error
; calculation of base
	call	base					; now the base is in r10
	cmp		rax, 2
	jl		error					; if the base < 2
; check if the base is valid
	call	check_base
	cmp		byte [rsi + rcx], 0		; is the base valid?
	jne		error
; skip space symbols (ht, nl, vt, np, cr, space)
	dec		rdi
	call	skip
; check and save sign
	call	sign					; now the sign is in rcx
; the major part
	jmp		atoi

; calculation of base
base:
	push	rdi
	mov		rdi, rsi
	call	_ft_strlen
	mov		r10, rax
	pop		rdi
	ret


; check if base is valid
check_base:
    mov		rcx, -1					; counter
    mov		dl, 47					; reference symbol
    jmp		loop_base

change_symb:
	mov		dl, 64
	dec		rcx
	jmp		loop_symb

subst:
	sub		dl, 32

loop_symb:
	inc		rcx
	inc		dl
	cmp		byte [rsi + rcx], 0
	je		return
	cmp		byte [rsi + rcx], dl	; check upcase
	je		loop_symb
	add		dl, 32
	cmp		byte [rsi + rcx], dl	; check lowercase
	je		subst
	jmp		error

loop_base:
	inc		rcx
	inc		dl
	cmp		byte [rsi + rcx], 0
	je		return
	cmp		rcx, 10
	je		change_symb				; if base is higher than 10
	cmp		byte [rsi + rcx], dl
	je		loop_base
	jmp		error


; skip space symbols
skip:
	inc		rdi
	mov		dl, byte[rdi]
	cmp		dl, 9
	je		skip
	cmp		dl, 10
	je		skip
	cmp		dl, 11
	je		skip
	cmp		dl, 12
	je		skip
	cmp		dl, 13
	je		skip
	cmp		dl, 32
	je		skip
	ret


; check sign
sign:
	mov		rcx, 1					; default value of sign
	cmp		dl, 43					; sign '+'?
	je		return
	cmp		dl, 45					; sign '-'?
	je		sign_minus
	dec		rdi
	ret

sign_minus:
    mov		rcx, -1					; set sign as minus
	ret


; main loop
; the next registers are occupied now:
; rax - return value
; rdi - str
; rsi - base (char *)
; r10 - base (int)
; rcx - sign
atoi:
	mov		rax, 0					; result
	mov		rdx, 0					; current symbol in str

loop:
	inc		rdi
	mov		dl, byte [rdi]
	call	in_base
	cmp		r9, -1
	je		end
	imul	rax, r10
	sub		dl, 48
	add		rax, r9
	jmp		loop

end:
	imul	rax, rcx
	ret


; check if current symbol is in the base range
in_base:
	mov		r9, -1					; counter

loop_in_base:
	inc		r9
	cmp		byte [rsi + r9], 0		; is the base over?
	je		not_in_base
	cmp		dl, byte [rsi + r9]
	jne		loop_in_base
	ret

not_in_base:
	mov		r9, -1
	ret


; auxiliary marks
error:
	mov		rax, 0

return:
	ret
