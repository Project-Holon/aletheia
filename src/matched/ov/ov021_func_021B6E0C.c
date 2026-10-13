/*
 * function: SCRCMD_POKEMON_FLD_CheckDeliveryNpcLoaded
 * address:  0x021B6E0C
 * packet:   pkt_ov021_021B6E0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_POKEMON_FLD_FindDeliveryMmdl  0x021B6E24  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_POKEMON_FLD_FindDeliveryMmdl(void *);

u16 SCRCMD_POKEMON_FLD_CheckDeliveryNpcLoaded(void *a)
{
    return SCRCMD_POKEMON_FLD_FindDeliveryMmdl(a) != 0 ? 1 : 0;
}
