/*
 * function: func_020819B8
 * address:  0x020819B8
 * packet:   pkt_020819B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MATHi_CRC16InitTable  0x020819B8  arm
 */

typedef unsigned short u16;
typedef unsigned long u32;

void func_020819B8(u16 *table, u16 poly)
{
    u32 r;
    u32 i;
    u32 j;

    for (i = 0; i < 0x100; i++) {
        r = i << 8;
        for (j = 0; j < 8; j++) {
            if (r & 0x8000)
                r = (r << 1) ^ poly;
            else
                r <<= 1;
        }
        table[i] = r;
    }
}
