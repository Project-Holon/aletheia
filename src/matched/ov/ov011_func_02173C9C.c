/*
 * function: func_02173C9C
 * address: 0x02173C9C
 * packet: pkt_ov011_02173C9C
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
typedef struct { u32 w[4]; } Rec16_02173C9C;

void func_02173C9C(int a, int b, Rec16_02173C9C *src, u8 *p)
{
    *(Rec16_02173C9C *)(p + 0x914) = *src;
}
