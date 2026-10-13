/*
 * function: SCRCMD_FLDMMDL_CheckAnimeTasksDone
 * address:  0x021B16DC
 * packet:   pkt_021B16DC
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
 *   SCRCMD_WORK_CheckAnimeTasks  0x0215A6FC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 SCRCMD_WORK_CheckAnimeTasks(u32, u32, u32, u32);

int SCRCMD_FLDMMDL_CheckAnimeTasksDone(u32 a, u32 b, u32 c, u32 d)
{
if (SCRCMD_WORK_CheckAnimeTasks(b, b, c, d) == 0) {
    return 1;
}
return 0;
}

