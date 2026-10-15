/*
 * function: MATH_CalcCRC32
 * address:  0x02081BB8
 * packet:   pkt_02081BB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MATH_CalcCRC32 (libmath.TWL.HYB.a crc.o)
 *
 * symbols:
 *   MATHi_CRC32UpdateRev  0x02081B00  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct MATHCRC8Table
{
    u8 table[256];
} MATHCRC8Table;

typedef struct MATHCRC16Table
{
    u16 table[256];
} MATHCRC16Table;

typedef struct MATHCRC32Table
{
    u32 table[256];
} MATHCRC32Table;

extern void MATHi_CRC32UpdateRev(MATHCRC32Table *table, u32 *context, void *input, u32 length);

u32 MATH_CalcCRC32(MATHCRC32Table *table, void *data, u32 dataLength)
{
    u32 context = ~0;

    MATHi_CRC32UpdateRev(table, &context, data, dataLength);
    return ~context;
}
