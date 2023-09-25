#include "rc4.h"

void rc4_init(rc4_ctx *ctx, uint8_t *key, uint32_t keylen)
{
    uint32_t i = 0;
    uint32_t j = 0;

    for (i = 0; i < 256; i++)
    {
        ctx->S[i] = i;
    }

    for (i = 0; i < 256; i++)
    {
        j = (j + ctx->S[i] + key[i % keylen]) % 256;

        ctx->S[i] = ctx->S[i] ^ ctx->S[j];
        ctx->S[j] = ctx->S[i] ^ ctx->S[j];
        ctx->S[i] = ctx->S[i] ^ ctx->S[j];
    }

    ctx->i = 0;
    ctx->j = 0;
}

void rc4_crypt(rc4_ctx *ctx, uint8_t *in, uint32_t inlen, uint8_t *out)
{
    uint32_t i = 0;
    uint32_t v = 0;

    for(i = 0; i < inlen; i++)
    {
        ctx->i = (ctx->i + 1) % 256;
        ctx->j = (ctx->j + ctx->S[ctx->i]) % 256;

        ctx->S[ctx->i] = ctx->S[ctx->i] ^ ctx->S[ctx->j];
        ctx->S[ctx->j] = ctx->S[ctx->i] ^ ctx->S[ctx->j];
        ctx->S[ctx->i] = ctx->S[ctx->i] ^ ctx->S[ctx->j];

        v = (ctx->S[ctx->i] + ctx->S[ctx->j]) % 256;
        out[i] = in[i] ^ ctx->S[v];
    }
}
