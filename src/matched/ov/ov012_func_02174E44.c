/*
 * function: func_02174E44
 * address: 0x02174E44
 * packet: pkt_ov012_02174E44
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
void func_02174E44(int n, int b, int c, u8 *p);

void func_02174E44(int n, int b, int c, u8 *p)
{
    u8 *w = *(u8 **)(p + 0x355c);
    if (w != 0) {
        u8 *q = w + n;
        q[0xd8] = 1;
        q[0xd4] = 0;
    }
}
