/*
 * function: SCRCMD_FLDMMDL_UnpauseAllMmdls
 * address:  0x021B1BE8
 * packet:   pkt_021B1BE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * SCRCMD_WORK_GetMmdlSys (0x0215A5EC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_WORK_GetMmdlSys  0x0215A5EC  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 SCRCMD_WORK_GetMmdlSys(u32, u32, u32, u32);
extern u32 *FLDMMDL_SysResumeMove(void *c);

int SCRCMD_FLDMMDL_UnpauseAllMmdls(u32 a, u32 b, u32 c, u32 d)
{
return (int)FLDMMDL_SysResumeMove((void *)SCRCMD_WORK_GetMmdlSys(a, b, c, d));
}

