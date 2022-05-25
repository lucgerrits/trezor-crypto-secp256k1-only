GCC_TOOLS_PATH=gcc

OPTFLAGS = -O2

main: main.c
	@echo "uECC"
	$(GCC_TOOLS_PATH) $(OPTFLAGS) -I. main.c -o main

# uECC: uECC.c
# 	$(GCC_TOOLS_PATH) $(OPTFLAGS) -c -I. uECC.c

# sha256: sha256.c
# 	$(GCC_TOOLS_PATH) $(OPTFLAGS) -c -I. sha256.c

# byte_order: byte_order.c
# 	$(GCC_TOOLS_PATH) $(OPTFLAGS) -c -I. byte_order.c