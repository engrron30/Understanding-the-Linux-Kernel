//#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

/* CRC-32 (IEEE 802.3) table generation and compute function */
static uint32_t crc32_table[256];

static void crc32_init(void)
{
    uint32_t poly = 0xEDB88320U;
    for (uint32_t i = 0; i < 256; ++i) {
        uint32_t crc = i;
        for (int j = 0; j < 8; ++j) {
            if (crc & 1)
                crc = (crc >> 1) ^ poly;
            else
                crc >>= 1;
        }
        crc32_table[i] = crc;
    }
}

uint32_t crc32(const uint8_t *data, size_t len)
{
    uint32_t crc = ~0U;
    while (len--)
        crc = (crc >> 8) ^ crc32_table[(crc ^ *data++) & 0xFF];
    return ~crc;
}

/* test */
/*int main(void)
{
    crc32_init();
    const char *s = "The quick brown fox jumps over the lazy dog";
    uint32_t c = crc32((const uint8_t*)s, strlen(s));
    //printf("CRC32: 0x%08x\n", c); 		//expected 0x414fa339 for that string
    return 0;
}*/

