/*
 * function: MATHi_CRC8InitTable
 * address:  0x02081940
 * packet:   pkt_02081940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MATHi_CRC8InitTable (libmath.TWL.HYB.a crc.o)
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

void MATHi_CRC8InitTable(MATHCRC8Table *table, u8 poly)
{
    u32 r, i, j;

    for (i = 0; i < 256; i++)
    {
        r = i;
        for (j = 0; j < 8; j++)
        {
            if (r & 0x80)
            {
                r = (r << 1) ^ poly;
            }
            else
            {
                r <<= 1;
            }
        }
        table->table[i] = (u8)r;
    }
}
