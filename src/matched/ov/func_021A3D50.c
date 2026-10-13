/*
 * function: FIELD_PLAYER_CORE_ChangeToFormSlot
 * address:  0x021A3D50
 * packet:   pkt_021A3D50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetSex  0x021A398C  thumb  ov021
 *   FIELD_PLAYER_GetFormObjCode  0x021A3190  thumb  ov021
 *   FIELD_PLAYER_CORE_ChangeToObjCode  0x021A3D08  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 FIELD_PLAYER_GetFormObjCode(int i, int j);
extern u32 FIELD_PLAYER_CORE_GetSex(u8 *p);
extern int FIELD_PLAYER_CORE_ChangeToObjCode(u8 *p, u32 v);

int FIELD_PLAYER_CORE_ChangeToFormSlot(u32 a, u32 b)
{
return FIELD_PLAYER_CORE_ChangeToObjCode((u8 *)a, FIELD_PLAYER_GetFormObjCode(FIELD_PLAYER_CORE_GetSex((u8 *)a), b));
}

