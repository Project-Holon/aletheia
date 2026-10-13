/*
 * function: FIELD_PLAYER_GetFrontGridPos
 * address:  0x021A3460
 * packet:   pkt_021A3460
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
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELD_PLAYER_GetGridPosInDir  0x021A330C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern u32 FIELD_PLAYER_GetGridPosInDir(u32, u32, u32, u32, u32);

int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d)
{
return FIELD_PLAYER_GetGridPosInDir(a, FLDMMDL_GetDirDisp(FIELD_PLAYER_GetMmdl((u8 *)a)), b, c, d);
}

