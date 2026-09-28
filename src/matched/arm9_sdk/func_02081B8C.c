/*
 * function: func_02081B8C
 * address:  0x02081B8C
 * packet:   pkt_02081B8C
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

extern void MATHi_CRC16Update(const u16 *table, u16 *context, const u8 *input, u32 length);

u16 func_02081B8C(const u16 *table, const u8 *data, u32 dataLength)
{
    u16 context;

    context = 0xffff;
    MATHi_CRC16Update(table, &context, data, dataLength);
    return context;
}
