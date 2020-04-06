#include <stdint.h> //for uint8_t
#include <stdio.h> // for printf
#include <stdlib.h> //for exit
#include <arpa/inet.h> //for ntohl


void usage() {
    printf("syntax : add_nbo <file1> <file2>\n");
    printf("sample : add_nbo a.bin c.bin\n");
}

uint32_t add_nbo(char *argv) {
    uint32_t a;
    FILE *f;

    f = fopen(argv, "rb");
    if(f != NULL) {
        fread(&a, 4, 1, f);
        a = ntohl(a);
        return a;
    }
    else {
        printf("Error\n");
        return -1;
    }
    fclose(f);
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        usage();
        return -1;
    }

    uint32_t f1, f2, result;
    f1 = add_nbo(argv[1]);
    f2 = add_nbo(argv[2]);
    result = f1+f2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", f1, f1, f2, f2, result, result);
}
