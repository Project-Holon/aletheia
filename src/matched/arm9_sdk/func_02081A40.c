/*
 * function: func_02081A40
 * address:  0x02081A40
 * packet:   pkt_02081A40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MATHi_CRC16Update  0x02081A40  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

void func_02081A40(const u16 *table, u16 *context, const u8 *input, u32 length)
{
    u32 r;
    u32 i;
    const u8 *data;

    r = *context;
    data = input;
    for (i = 0; i < length; i++) {
        r = table[((r >> 8) ^ *data++) & 0xff] ^ (r << 8);
    }
    *context = r;
}
