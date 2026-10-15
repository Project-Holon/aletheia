/*
 * function: MATHi_CRC16InitTable
 * address:  0x020819B8
 * packet:   pkt_020819B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MATHi_CRC16InitTable (libmath.TWL.HYB.a crc.o)
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

void MATHi_CRC16InitTable(MATHCRC16Table *table, u16 poly)
{
    u32 r, i, j;

    for (i = 0; i < 256; i++)
    {
        r = i << 8;
        for (j = 0; j < 8; j++)
        {
            if (r & 0x8000)
            {
                r = (r << 1) ^ poly;
            }
            else
            {
                r <<= 1;
            }
        }
        table->table[i] = (u16)r;
    }
}
