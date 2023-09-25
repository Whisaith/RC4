#include <stdio.h>
#include <string.h>
#include "rc4.h"

int main(int argc, char *argv[])
{
    rc4_ctx rc4_encrypt;
    rc4_ctx rc4_decrypt;

    uint8_t key[] = "12345678";

    char buff1[] = "Hello Rc4";
    char buff2[] = "You are a simple and efficient stream encryption";

    rc4_init(&rc4_encrypt, key, strlen(key));
    rc4_init(&rc4_decrypt, key, strlen(key));

    rc4_crypt(&rc4_encrypt, buff1, strlen(buff1), buff1);
    printf("buff1 encrypt: %s\n", buff1);

    rc4_crypt(&rc4_decrypt, buff1, strlen(buff1), buff1);
    printf("buff1 decrypt: %s\n", buff1);

    printf("===================================================\n");

    rc4_crypt(&rc4_encrypt, buff2, strlen(buff2), buff2);
    printf("buff2 encrypt: %s\n", buff2);

    rc4_crypt(&rc4_decrypt, buff2, strlen(buff2), buff2);
    printf("buff1 decrypt: %s\n", buff2);

    return 0;
}
