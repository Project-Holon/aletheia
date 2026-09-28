/*
 * function: func_02081980
 * address:  0x02081980
 * packet:   pkt_02081980
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MATHi_CRC8Update  0x02081980  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

void func_02081980(const u8 *table, u8 *context, const u8 *input, u32 length)
{
    u32 r;
    u32 i;
    const u8 *data;

    r = *context;
    data = input;
    for (i = 0; i < length; i++) {
        r ^= *data++;
        r = table[r & 0xff];
    }
    *context = r;
}
