/*
 * function: func_02081AC0
 * address:  0x02081AC0
 * packet:   pkt_02081AC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MATHi_CRC32InitTableRev  0x02081AC0  arm
 */

typedef unsigned long u32;

void func_02081AC0(u32 *table, u32 poly)
{
    u32 r;
    u32 i;
    u32 j;

    for (i = 0; i < 0x100; i++) {
        r = i;
        for (j = 0; j < 8; j++) {
            if (r & 1)
                r = (r >> 1) ^ poly;
            else
                r >>= 1;
        }
        table[i] = r;
    }
}
