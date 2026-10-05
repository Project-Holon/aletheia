/*
 * function: func_021D7810
 * address:  0x021D7810
 * packet:   pkt_021D7810
 * region:   ov131
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;

typedef struct
{
    u8 pad[0x94];
    u8 ring[5];
    u8 f99;
    u8 f9a;
} Ring;

void func_021D7810(int unused, Ring *p, int mode)
{
    if (mode == 1)
    {
        u8 v = p->f99;
        p->ring[p->f9a] = v;
        p->f99 = 0;
        p->f9a = (u8)(p->f9a + 1);
        if (p->f9a >= 5)
            p->f9a = 0;
    }
    p->f99 = (u8)(p->f99 + 1);
}
