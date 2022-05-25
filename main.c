#include <stdio.h>
#include "./sha2.h"
#include "ecdsa.h"
#include "options.h"
#include "secp256k1.h"

unsigned char private[32] = {0xec, 0x3c, 0x16, 0x15, 0x97, 0xb1, 0x19, 0x99, 0x8a, 0xd8, 0x82, 0x2a, 0xcb, 0x2b, 0x11, 0x23, 0x40, 0x5e, 0x85, 0xc7, 0x57, 0x7e, 0x5e, 0x8a, 0xbd, 0x67, 0x8a, 0xd8, 0xc2, 0x38, 0x3f, 0x2c}; //{0x22, 0xa4, 0x7f, 0xa0, 0x9a, 0x22, 0x3f, 0x2a, 0xa0, 0x79, 0xed, 0xf8, 0x5a, 0x7c, 0x2d, 0x4f, 0x87, 0x20, 0xee, 0x63, 0xe5, 0x02, 0xee, 0x28, 0x69, 0xaf, 0xab, 0x7d, 0xe2, 0x34, 0xb8, 0x0c};
unsigned char public[64] = {0};
unsigned char hash[32] = {0xcb, 0xab, 0xe5, 0xc7, 0x8b, 0x28, 0x0e, 0x3c, 0x1a, 0x63, 0x03, 0xaa, 0xe8, 0x58, 0x9d, 0xdf, 0xf0, 0x1e, 0xa1, 0xf7, 0xa8, 0x7f, 0x79, 0x5e, 0x4e, 0x26, 0x81, 0x1d, 0x05, 0xf9, 0x0c, 0x3e}; //{0x3f, 0x0a, 0x37, 0x7b, 0xa0, 0xa4, 0xa4, 0x60, 0xec, 0xb6, 0x16, 0xf6, 0x50, 0x7c, 0xe0, 0xd8, 0xcf, 0xa3, 0xe7, 0x04, 0x02, 0x5d, 0x4f, 0xda, 0x3e, 0xd0, 0xc5, 0xca, 0x05, 0x46, 0x87, 0x28};
unsigned char sig[64] = {0};
unsigned char new_hash[32];

void print_array(unsigned char *table, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%02x", table[i]);
    }
    printf("\n");
}

int main()
{
    print_array(private, sizeof(private));
    print_array(hash, sizeof(hash));

    SHA256_CTX sha256_ctx;
    sha256_Init(&sha256_ctx);
    sha256_Update(&sha256_ctx, (uint8_t *)"manon", 5);
    sha256_Final(&sha256_ctx, (uint8_t *)new_hash);
    print_array(new_hash, sizeof(hash));

    const ecdsa_curve * curve = &secp256k1;
    ecdsa_sign_digest(curve, private, new_hash, sig, 0, 0);
    print_array(sig, sizeof(sig));

    return 0;
}