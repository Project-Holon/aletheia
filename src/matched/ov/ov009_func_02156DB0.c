/*
 * function: func_02156DB0
 * address: 0x02156DB0
 * packet: pkt_ov009_02156DB0
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov009/dwc_rap_p07.c and filed here.
 *
 * symbols:
 *   g_021A8264 0x021A8264 data ov009 a4
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
void func_02156DB0(u32 v);
extern u8 *g_021A8264;

void func_02156DB0(u32 v)
{
    g_021A8264[0x7a3] = v;
}
