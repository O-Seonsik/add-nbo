#include <stdint.h>
#include <netinet/in.h>
#include <stdio.h>

uint32_t getByte(char* dir){
    uint8_t buffer[4];
    FILE *fp = fopen(dir, "r");
    fread(buffer, sizeof(char), 4, fp);
    uint32_t* p = reinterpret_cast<uint32_t*>(buffer);
    fclose(fp);
    return *p;
}

int main(int argc, char *argv[]) {
    int x = htonl(getByte(argv[1]));
    int y = htonl(getByte(argv[2]));
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", x, x, y, y, x+y, x+y);

    return 0;
}
