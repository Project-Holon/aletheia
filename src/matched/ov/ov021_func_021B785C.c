/*
 * function: PDW_POSTMAN_SetMysteryReceived
 * address:  0x021B785C
 * packet:   pkt_ov021_021B785C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub after PDW_POSTMAN_FindMysteryCard; called by SCRCMD_POKEMON_FLD_HandleMysteryGift.
 *
 * symbols:
 *   MYSTERY_DATA_SetCardReceived  0x0200A13C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void MYSTERY_DATA_SetCardReceived(u8 *p, u32 i);

void PDW_POSTMAN_SetMysteryReceived(u8 *p, u32 i)
{
    MYSTERY_DATA_SetCardReceived(p, i);
}
