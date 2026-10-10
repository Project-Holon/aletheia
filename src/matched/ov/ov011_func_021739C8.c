/*
 * function: func_021739C8
 * address: 0x021739C8
 * packet: pkt_ov011_021739C8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov011/unit_02173658.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned int u32;
void func_021739C8(int a, int b, int c, u8 *p);

void func_021739C8(int a, int b, int c, u8 *p)
{
    u32 *w = (u32 *)(p + 0x940);
    *w = (*w & 0x7fffffff) | 0x80000000;
}
