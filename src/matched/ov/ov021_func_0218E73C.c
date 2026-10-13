/*
 * function: FIELD_CAMERA_SolveTrackMode
 * address:  0x0218E73C
 * packet:   pkt_ov021_0218E73C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_CAMERA_PullTargetFromTrace  0x0218E284  thumb
 *   FIELD_CAMERA_PullEyeFromTrace  0x0218E298  thumb
 *   FIELD_CAMERA_SolveTargetMode  0x0218E358  thumb
 *   FIELD_CAMERA_SolveEyeMode  0x0218E404  thumb
 */
#include "../include/Obj00428.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void FIELD_CAMERA_PullTargetFromTrace(u8 *a);
extern int FIELD_CAMERA_PullEyeFromTrace(u8 *a);
extern void FIELD_CAMERA_SolveTargetMode(u8 *a);
extern void FIELD_CAMERA_SolveEyeMode(u8 *a);

void FIELD_CAMERA_SolveTrackMode(u8 *a)
{
    u32 s = ((struct Obj00428 *)a)->f14;
    if (s == 0) {
        FIELD_CAMERA_PullTargetFromTrace(a);
        FIELD_CAMERA_SolveTargetMode(a);
    } else if (s == 1) {
        FIELD_CAMERA_PullEyeFromTrace(a);
        FIELD_CAMERA_SolveEyeMode(a);
    }
}
