[bits 64]
[org 0x4b2c5f]

push rax
push rdi
push rsi
push rdx
push rcx

mov rdi, 0x400000  ; 0xabcd1234
mov rsi, (0xa9560 | 0xfff) + 1
mov rdx, 7  ; RWX
mov rax, 10
syscall

mov rdi, 0x4004f0
mov rsi, rdi
mov rcx, 0xa9560

cld
decodeit:
  lodsb
  xor al,0xe2
  xor al,0xb3
  xor al,0xa5
  xor al,0xc2

  stosb
  loop decodeit

pop rcx
pop rdx
pop rsi
pop rdi
pop rax

push 0x400a70
ret

