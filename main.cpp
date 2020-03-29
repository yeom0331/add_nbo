#include <stdint.h> //for uint8_t
#include <stdio.h> // for printf
#include <stdlib.h> //for exit
#include <arpa/inet.h> //for ntohl

void add_nbo() {
    uint32_t a, b, result;
    FILE *f1, *f2;

    f1 = fopen("/home/yeom/temp/c/add_nbo/f1.bin", "rb");
    f2 = fopen("/home/yeom/temp/c/add_nbo/f2.bin", "rb");
    if(f1 == NULL || f2 == NULL)
    {
        printf("error\n");
        exit(1);
    }

    fread(&a, 4, 1, f1);
    fread(&b, 4, 1, f2);

    a = ntohl(a);
    b = ntohl(b);
    result = a+b;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, result, result);
    fclose(f1);
    fclose(f2);
}

int main() {
    add_nbo();
}
