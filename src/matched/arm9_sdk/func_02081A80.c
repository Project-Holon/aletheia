/*
 * function: func_02081A80
 * address:  0x02081A80
 * packet:   pkt_02081A80
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MATHi_CRC16UpdateRev (libmath.TWL.HYB.a crc.o)
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

void func_02081A80(MATHCRC16Table *table, u16 *context, void *input, u32 length)
{
    u32 r, i;
    u8 *data;

    r = *context;
    data = (u8 *)input;
    for (i = 0; i < length; i++)
    {
        r = (r >> 8) ^ table->table[(r ^ *data) & 0xFF];
        data++;
    }
    *context = (u16)r;
}
