/*
 * function: func_021761C4
 * address: 0x021761C4
 * packet: pkt_ov011_021761C4
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov011/unit_02175C40.c and filed here.
 */

typedef unsigned char u8;
typedef struct { int d[13]; } B34;
void func_021761C4(u8 *p, u8 *s);

void func_021761C4(u8 *p, u8 *s)
{
    u8 v = s[0];
    p[0x1a3] = v;
    if (v == 1)
        *(B34 *)(p + 0x78) = *(B34 *)(s + 4);
}
