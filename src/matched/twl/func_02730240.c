/*
 * function: MIi_SetWramBankMaster_A
 * address: 0x02730240
 * packet: pkt_twl_02730240
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

void MIi_SetWramBankMaster_A(u32 a, u32 v)
{
    *(u8 *)(a + 0x04004040) = (*(u8 *)(a + 0x04004040) & ~1) | v;
}
