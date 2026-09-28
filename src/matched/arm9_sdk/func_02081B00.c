/*
 * function: func_02081B00
 * address:  0x02081B00
 * packet:   pkt_02081B00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MATHi_CRC32UpdateRev  0x02081B00  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

void func_02081B00(const u32 *table, u32 *context, const u8 *input, u32 length)
{
    u32 r;
    u32 i;
    const u8 *data;

    r = *context;
    data = input;
    for (i = 0; i < length; i++) {
        r = table[(r ^ *data++) & 0xff] ^ (r >> 8);
    }
    *context = r;
}
