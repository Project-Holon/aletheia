/*
 * function: func_02730278
 * address: 0x02730278
 * packet: pkt_twl_02730278
 * region: twl
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/twl/unit_02730210.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned int u32;

void func_02730278(u32 a, u32 v)
{
    *(u8 *)(a + 0x0400404C) = (*(u8 *)(a + 0x0400404C) & ~3) | v;
}
