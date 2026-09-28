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
 * sdk:      MATHi_CRC8Update (libmath.TWL.HYB.a crc.o)
 *
 * symbols:
   (none)
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

void func_02081980(MATHCRC8Table *table, u8 *context, void *input, u32 length)
{
    u32 r, i;
    u8 *data;

    r = *context;
    data = (u8 *)input;
    for (i = 0; i < length; i++)
    {
        r = table->table[(r ^ *data) & 0xFF];
        data++;
    }
    *context = (u8)r;
}
