/*
 * function: FIELD_PLAYER_CORE_CheckPlainModel
 * address:  0x021A3B78
 * packet:   pkt_ov021_021A3B78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
typedef unsigned short u16;
u16 FLDMMDL_GetObjCode(void *p);

int FIELD_PLAYER_CORE_CheckPlainModel(u8 *p)
{
    int r = FLDMMDL_GetObjCode(FIELD_PLAYER_CORE_GetMmdl(p));

    if (r == 1 || r == 4)
        return 1;
    return 0;
}
