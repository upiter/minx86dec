; NEC V20/V30 test code
org 0

_start:
	db	0x0F,0x20		; NASM doesn't know ADD4S
	db	0x0F,0xFF,34		; NASM doesn't know this either (BRKEM)
	db	0x0F,0x2D,0xF8		; BRKCS AX NASM doesn't know this either (BRKCS)
	db	0x63,34			; BRKN
	db	0xF1,34			; BRKS
	db	0x0F,0xE0,34		; BRKXA
	db	0x0F,0x12,0xC0		; CLEAR1 AL,CL
	db	0x0F,0x12,0xC1		; CLEAR1 CL,CL
	db	0x0F,0x12,0xC2		; CLEAR1 DL,CL
	db	0x0F,0x13,0xC0		; CLEAR1 AX,CL
	db	0x0F,0x13,0xC1		; CLEAR1 CX,CL
	db	0x0F,0x13,0xC2		; CLEAR1 DX,CL
	db	0x0F,0x1A,0xC0,4	; CLEAR1 AL,4
	db	0x0F,0x1A,0xC1,5	; CLEAR1 CL,5
	db	0x0F,0x1A,0xC2,6	; CLEAR1 DL,6
	db	0x0F,0x1B,0xC0,7	; CLEAR1 AX,7
	db	0x0F,0x1B,0xC1,3	; CLEAR1 CX,3
	db	0x0F,0x1B,0xC2,2	; CLEAR1 DX,2
	db	0x0F,0x26		; CMP4S
	db	0x0F,0x33,0xC0		; EXT AL,AL
	db	0x0F,0x33,0xC3|(1<<3)	; EXT BL,CL
	db	0x0F,0x3B,0xC0,5	; EXT AL,5
	db	0x0F,0x3B,0xC3,7	; EXT BL,7
	db	0x66,0xC0		; ???
	db	0x67,0xC3		; ???
	db	0x0F,0x31,0xC0		; INS AL,AL
	db	0x0F,0x31,0xC3|(1<<3)	; INS BL,CL
	db	0x0F,0x39,0xC0,5	; INS AL,5
	db	0x0F,0x39,0xC3,7	; INS BL,7
	db	0x0F,0x16,0xC0		; NOT1 AL,CL
	db	0x0F,0x16,0xC1		; NOT1 CL,CL
	db	0x0F,0x16,0xC2		; NOT1 DL,CL
	db	0x0F,0x17,0xC0		; NOT1 AX,CL
	db	0x0F,0x17,0xC1		; NOT1 CX,CL
	db	0x0F,0x17,0xC2		; NOT1 DX,CL
	db	0x0F,0x1E,0xC0,4	; NOT1 AL,4
	db	0x0F,0x1E,0xC1,5	; NOT1 CL,5
	db	0x0F,0x1E,0xC2,6	; NOT1 DL,6
	db	0x0F,0x1F,0xC0,7	; NOT1 AX,7
	db	0x0F,0x1F,0xC1,3	; NOT1 CX,3
	db	0x0F,0x1F,0xC2,2	; NOT1 DX,2
	db	0x64
	lodsb				; REPNC LODSB
	db	0x65
	stosb				; REPC STOSB
	db	0x0F,0x28,0xC0		; ROL4 AL
	db	0x0F,0x28,0xC3		; ROL4 BL
	db	0x0F,0x2A,0xC1		; ROR4 CL
	db	0x0F,0x2A,0xC2		; ROR4 DL
	db	0x0F,0x14,0xC0		; SET1 AL,CL
	db	0x0F,0x14,0xC1		; SET1 CL,CL
	db	0x0F,0x14,0xC2		; SET1 DL,CL
	db	0x0F,0x15,0xC0		; SET1 AX,CL
	db	0x0F,0x15,0xC1		; SET1 CX,CL
	db	0x0F,0x15,0xC2		; SET1 DX,CL
	db	0x0F,0x1C,0xC0,4	; SET1 AL,4
	db	0x0F,0x1C,0xC1,5	; SET1 CL,5
	db	0x0F,0x1C,0xC2,6	; SET1 DL,6
	db	0x0F,0x1D,0xC0,7	; SET1 AX,7
	db	0x0F,0x1D,0xC1,3	; SET1 CX,3
	db	0x0F,0x1D,0xC2,2	; SET1 DX,2
	db	0x0F,0x10,0xC0		; TEST1 AL,CL
	db	0x0F,0x10,0xC1		; TEST1 CL,CL
	db	0x0F,0x10,0xC2		; TEST1 DL,CL
	db	0x0F,0x11,0xC0		; TEST1 AX,CL
	db	0x0F,0x11,0xC1		; TEST1 CX,CL
	db	0x0F,0x11,0xC2		; TEST1 DX,CL
	db	0x0F,0x18,0xC0,4	; TEST1 AL,4
	db	0x0F,0x18,0xC1,5	; TEST1 CL,5
	db	0x0F,0x18,0xC2,6	; TEST1 DL,6
	db	0x0F,0x19,0xC0,7	; TEST1 AX,7
	db	0x0F,0x19,0xC1,3	; TEST1 CX,3
	db	0x0F,0x19,0xC2,2	; TEST1 DX,2
	db	0x0F,0x22		; SUB4S
	db	0x0F,0x92		; FINT
	db	0x0F,0x25		; MOVSPA
	db	0x0F,0x95,0xF8		; MOVSPB AX

	; TODO: BITCLR [http://impactstudiopro.com/videos/20120619-0930-gd.php]

	nop
	lea	bx,[si+3]
	lea	cx,[bx+di+33h]
	mov	ax,es
	mov	ds,ax
	mov	bx,cs
	mov	cs,bx
	mov	cx,ds
	mov	dx,ss
	mov	[di],es
	mov	[si],ds
	test	ax,bx
	test	si,cx
	test	cl,bh
	test	[di],bx
	test	[si+bx+43],cx
	xchg	bl,dl
	xchg	[si],cl
	xchg	[di],si
	cmp	bl,44h
	cmp	bx,2446h
	cmp	byte [bx+3],35h
	cmp	word [bp-3],2244h
	cmp	word [di],62h
	mov	ah,dh
	mov	bl,[si+bx+3]
	mov	si,[di+bx+34h]
	inc	ax
	inc	bx
	inc	cx
	inc	dx
	inc	si
	inc	di
	inc	bp
	inc	sp
	dec	sp
	dec	bp
	dec	di
	dec	si
	dec	dx
	dec	cx
	dec	bx
	dec	ax
	push	ax
	push	bx
	push	cx
	push	dx
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	jo	j2
j2:	jno	j2
	ja	j2
	jz	j2
	xchg	ax,bx
	xchg	ax,cx
	xchg	ax,dx
	xchg	ax,si
	mov	al,13h
	mov	bl,44h
	mov	dh,11h
	mov	si,2456h
	mov	bp,2222h
	daa
	das
	aaa
	aas
	add	al,ah
	add	cl,bh
	add	bl,byte [345h]
	add	byte [123h],dh
	adc	bh,byte [bx+si]
	sub	si,word [si]
	sub	di,word [bp+di+0x1234]
	add	al,12h
	add	ax,1245h
	mov	al,[1234h]
	mov	ax,[5050h]
	mov	[1111h],al
	mov	[5421h],ax
	mov	ax,[cs:3]
	mov	[ss:4444h],ax
	push	cs
	push	es
	pop	cs
	pop	ds

	mov	cr0,eax
	mov	cr0,ebx
	mov	eax,cr0
	mov	cr2,eax
	mov	eax,cr2
	mov	dr0,eax
	mov	eax,dr0
	mov	dr3,eax
	mov	eax,dr3
	mov	tr0,eax
	mov	eax,tr0
	mov	tr3,eax
	mov	eax,tr3

	salc
	icebp
	umov	eax,ebx
	umov	[edi],ebx
	umov	esi,[edi]
	umov	al,cl
	umov	ah,[esi]

	nop
	nop
	nop
	db	0x0F,0x05	; 286 loadall

	nop
	nop
	nop
	db	0x0F,0x07	; 386 loadall

