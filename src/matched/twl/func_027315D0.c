/*
 * function: PM_GetAutoExit
 * address: 0x027315D0
 * packet: pkt_twl_027315D0
 * region: twl
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/twl/unit_02731590.c and filed here.
 *
 * symbols:
 *   d_020A8724 0x020A8724 data twl
 */

typedef unsigned int u32;
extern u32 d_020A8724[];

u32 PM_GetAutoExit(void)
{
    return d_020A8724[1];
}
