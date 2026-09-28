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
 * sdk:      MATH_CalcCRC8 (libmath.TWL.HYB.a crc.o)
 *
 * symbols:
 *   MATHi_CRC8Update  0x02081980  arm
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

extern void MATHi_CRC8Update(MATHCRC8Table *table, u8 *context, void *input, u32 length);

u8 func_02081B3C(MATHCRC8Table *table, void *data, u32 dataLength)
{
    u8 context = 0;

    MATHi_CRC8Update(table, &context, data, dataLength);
    return context;
}
