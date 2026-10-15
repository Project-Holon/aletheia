/*
 * function: MATH_CalcCRC16
 * address:  0x02081B64
 * packet:   pkt_02081B64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MATH_CalcCRC16 (libmath.TWL.HYB.a crc.o)
 *
 * symbols:
 *   MATHi_CRC16UpdateRev  0x02081A80  arm
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

extern void MATHi_CRC16UpdateRev(MATHCRC16Table *table, u16 *context, void *input, u32 length);

u16 MATH_CalcCRC16(MATHCRC16Table *table, void *data, u32 dataLength)
{
    u16 context = 0;

    MATHi_CRC16UpdateRev(table, &context, data, dataLength);
    return context;
}
