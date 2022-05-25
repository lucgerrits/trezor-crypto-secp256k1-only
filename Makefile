GCC_TOOLS_PATH=cc

OPTFLAGS = -O2 -g \
            -std=gnu99 \
            -Wall 
OBJS=sha2.o memzero.o ecdsa.o rfc6979.o hmac.o hmac_drbg.o bignum.o rand.o secp256k1.o

main: main.c $(OBJS)
	@echo "Main"
	$(GCC_TOOLS_PATH) $(OPTFLAGS) main.c $(OBJS) -o main

sha2: sha2.c
	$(GCC_TOOLS_PATH) $(OPTFLAGS) -c sha2.o

memzero: memzero.c
	$(GCC_TOOLS_PATH) $(OPTFLAGS) -c memzero.o

bignum: bignum.c
	$(GCC_TOOLS_PATH) $(OPTFLAGS) -c bignum.o

ecdsa: ecdsa.c
	$(GCC_TOOLS_PATH) $(OPTFLAGS) -c ecdsa.o

rfc6979: rfc6979.c
	$(GCC_TOOLS_PATH) $(OPTFLAGS) -c rfc6979.o

hmac: hmac.c
	$(GCC_TOOLS_PATH) $(OPTFLAGS) -c hmac.o

hmac_drbg: hmac_drbg.c
	$(GCC_TOOLS_PATH) $(OPTFLAGS) -c hmac_drbg.o

rand: rand.c
	$(GCC_TOOLS_PATH) $(OPTFLAGS) -c rand.o

secp256k1: secp256k1.c
	$(GCC_TOOLS_PATH) $(OPTFLAGS) -c secp256k1.o



clean:
	rm -f main
	rm -f *.o