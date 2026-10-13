/*
 * function: SCRCMD_POKEMON_FLD_GetDeliveryNpcId
 * address:  0x021B6DE4
 * packet:   pkt_ov021_021B6DE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_POKEMON_FLD_FindDeliveryMmdl  0x021B6E24  thumb ov021
 *   FLDMMDL_GetObjId  0x0216D588  thumb ov010
 *   SCRCMD_POKEMON_FLD_FindDeliveryNpcObjId  0x021B6E68  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_POKEMON_FLD_FindDeliveryMmdl(void *);
extern u16 FLDMMDL_GetObjId(void *);
extern int SCRCMD_POKEMON_FLD_FindDeliveryNpcObjId(int a);

u16 SCRCMD_POKEMON_FLD_GetDeliveryNpcId(void *a, void *b)
{
    void *t;
    int r;

    t = SCRCMD_POKEMON_FLD_FindDeliveryMmdl(a);
    if (t != 0) {
        return FLDMMDL_GetObjId(t);
    }
    r = SCRCMD_POKEMON_FLD_FindDeliveryNpcObjId((int)b);
    if (r >= 0) {
        return r;
    }
    return 0;
}
