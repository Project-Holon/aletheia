/*
 * function: MIi_SetWramBankMaster_B
 * address: 0x0273025C
 * packet: pkt_twl_0273025C
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

void MIi_SetWramBankMaster_B(u32 a, u32 v)
{
    *(u8 *)(a + 0x04004044) = (*(u8 *)(a + 0x04004044) & ~3) | v;
}
