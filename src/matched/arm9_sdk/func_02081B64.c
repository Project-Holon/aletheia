/*
 * function: func_02081B64
 * address:  0x02081B64
 * packet:   pkt_02081B64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MATHi_CRC16UpdateRev  0x02081A80  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern void MATHi_CRC16UpdateRev(const u16 *table, u16 *context, const u8 *input, u32 length);

u16 func_02081B64(const u16 *table, const u8 *data, u32 dataLength)
{
    u16 context;

    context = 0;
    MATHi_CRC16UpdateRev(table, &context, data, dataLength);
    return context;
}
