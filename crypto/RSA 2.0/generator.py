from Crypto.Util.number import getPrime, bytes_to_long, long_to_bytes
from Crypto.PublicKey import RSA
from secret import flag

p = getPrime(1024)
q = getPrime(1024)

e = 112

m = bytes_to_long(flag)

c = pow(m, e, p*q)

print('p =', p)
print('q =', q)
print('e =', e)
print('c =', c)
