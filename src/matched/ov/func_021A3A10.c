/*
 * function: FIELD_PLAYER_CORE_GetFormSlot
 * address:  0x021A3A10
 * packet:   pkt_021A3A10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FIELD_PLAYER_GetFormSlotOfObjCode  0x021A31D0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 FLDMMDL_GetObjCode(void *p);
extern int FIELD_PLAYER_GetFormSlotOfObjCode(u16 id);
extern void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);

int FIELD_PLAYER_CORE_GetFormSlot(u32 a)
{
return FIELD_PLAYER_GetFormSlotOfObjCode(FLDMMDL_GetObjCode(FIELD_PLAYER_CORE_GetMmdl((u8 *)a)));
}

