/*
 * function: func_02081B3C
 * address:  0x02081B3C
 * packet:   pkt_02081B3C
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

extern void MATHi_CRC8Update(const u8 *table, u8 *context, const u8 *input, u32 length);

u8 func_02081B3C(const u8 *table, const u8 *data, u32 dataLength)
{
    u8 context;

    context = 0;
    MATHi_CRC8Update(table, &context, data, dataLength);
    return context;
}
