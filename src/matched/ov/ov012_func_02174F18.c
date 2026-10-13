/*
 * function: COLOSSEUM_RecvFinish
 * address: 0x02174F18
 * packet: pkt_ov012_02174F18
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov012/colosseum.c and filed here.
 */

typedef unsigned char u8;
void COLOSSEUM_RecvFinish(int n, int b, int c, u8 *p);

void COLOSSEUM_RecvFinish(int n, int b, int c, u8 *p)
{
    u8 *w = *(u8 **)(p + 0x355c);
    if (w != 0) {
        u8 *q = w + n;
        q[0x162] = 1;
    }
}
