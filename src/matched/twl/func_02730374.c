/*
 * function: MI_GetWramBankMaster_C
 * address: 0x02730374
 * packet: pkt_twl_02730374
 * region: twl
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/twl/unit_0273034C.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned int u32;

u32 MI_GetWramBankMaster_C(u32 a)
{
    return *(u8 *)(a + 0x0400404C) & 3;
}
