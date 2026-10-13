/*
 * function: SCRCMD_FLDMMDL_GetPlayerMmdl
 * address:  0x021B1E74
 * packet:   pkt_021B1E74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * SCRCMD_WORK_GetOccupyInfo (0x0215A5EC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 SCRCMD_WORK_GetOccupyInfo(u32);
extern void *FLDMMDL_SysSearchPlayer(void *a0);

int SCRCMD_FLDMMDL_GetPlayerMmdl(u32 a)
{
return (int)FLDMMDL_SysSearchPlayer((void *)SCRCMD_WORK_GetOccupyInfo(a));
}

