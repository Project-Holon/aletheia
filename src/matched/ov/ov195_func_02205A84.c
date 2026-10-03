/*
 * function: func_02205A84
 * address:  0x02205A84
 * packet:   pkt_02205A84
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   d_02208D1C    0x02208D1C data ov195 a4
 */

typedef unsigned int   u32;
extern void func_020403F4(u32 i);
extern char d_02208D1C[];

void func_02205A84(void)
{
    unsigned int i;
    for (i = 0; i < 6; i++)
    {
        unsigned int v = *(unsigned int *)(d_02208D1C + i * 0x2c);
        if (v >= 4)
        {
            func_020403F4(v & 0xff);
        }
    }
}
