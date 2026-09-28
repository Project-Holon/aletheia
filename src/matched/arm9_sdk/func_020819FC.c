/*
 * function: func_020819FC
 * address:  0x020819FC
 * packet:   pkt_020819FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MATHi_CRC16InitTableRev  0x020819FC  arm
 */

typedef unsigned short u16;
typedef unsigned long u32;

void func_020819FC(u16 *table, u16 poly)
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
