/*
 * function: SCRCMD_POKEMON_FLD_GetGiftItemReceiveType
 * address:  0x021B7020
 * packet:   pkt_ov021_021B7020
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_POKEMON_FLD_IsLibertyPassGift  0x021B6EB0  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int SCRCMD_POKEMON_FLD_IsLibertyPassGift(u32 *o, int k);

int SCRCMD_POKEMON_FLD_GetGiftItemReceiveType(void *a, void *b, u8 *c)
{
    if (SCRCMD_POKEMON_FLD_IsLibertyPassGift((u32 *)c, c[0xB3]) == 1) {
        return 4;
    }
    return 3;
}
