#ifndef __RC4_H
#define __RC4_H


#include <stdint.h>


typedef struct
{
    uint8_t	i;
    uint8_t	j;
    uint8_t S[256];
}rc4_ctx;


void rc4_init(rc4_ctx *ctx, uint8_t *key, uint32_t keylen);
void rc4_crypt(rc4_ctx *ctx, uint8_t *in, uint32_t inlen, uint8_t *out);


#endif //__RC4_H
