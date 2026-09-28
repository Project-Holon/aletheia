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
 * sdk:      MATH_CalcCRC16CCITT (libmath.TWL.HYB.a crc.o)
 *
 * symbols:
 *   MATHi_CRC16Update  0x02081A40  arm
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

extern void MATHi_CRC16Update(MATHCRC16Table *table, u16 *context, void *input, u32 length);

u16 func_02081B8C(MATHCRC16Table *table, void *data, u32 dataLength)
{
    u16 context = 0xFFFF;

    MATHi_CRC16Update(table, &context, data, dataLength);
    return context;
}
