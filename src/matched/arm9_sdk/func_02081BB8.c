/*
 * function: func_02081BB8
 * address:  0x02081BB8
 * packet:   pkt_02081BB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   MATHi_CRC32UpdateRev  0x02081B00  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

extern void MATHi_CRC32UpdateRev(const u32 *table, u32 *context, const u8 *input, u32 length);

u32 func_02081BB8(const u32 *table, const u8 *data, u32 dataLength)
{
    u32 context;

    context = 0xffffffff;
    MATHi_CRC32UpdateRev(table, &context, data, dataLength);
    return ~context;
}
