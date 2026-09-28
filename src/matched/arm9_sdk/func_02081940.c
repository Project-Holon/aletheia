/*
 * function: func_02081940
 * address:  0x02081940
 * packet:   pkt_02081940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MATHi_CRC8InitTable  0x02081940  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    u8 table[0x100];
} MATHCRC8Table;

void func_02081940(MATHCRC8Table *table, u8 poly)
{
    u32 r;
    u32 i;
    u32 j;

    for (i = 0; i < 0x100; i++) {
        r = i;
        for (j = 0; j < 8; j++) {
            if (r & 0x80)
                r = (r << 1) ^ poly;
            else
                r <<= 1;
        }
        table->table[i] = r;
    }
}
