/*
 * function: FIELDMAP_CalcCameraPitchScale
 * address:  0x02189A80
 * packet:   pkt_ov021_02189A80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_GetViewPitchPtr  0x0218ED3C  thumb  ov021
 *   d_020A1B38     0x020A1B38  data  a2
 */
#include "../include/Obj19508.h"

extern short d_020A1B38[];
typedef unsigned char  u8;
extern u8 *FIELD_CAMERA_GetViewPitchPtr(u8 *p);

int FIELDMAP_CalcCameraPitchScale(char *p)
{
    unsigned short *q = (short unsigned int *)FIELD_CAMERA_GetViewPitchPtr(((struct Obj19508 *)p)->f10);
    int i = (*q >> 4) * 2 + 1;
    int s = d_020A1B38[i];
    long long v;
    int r;

    if (s < 0)
        s = -s;
    v = ((long long)s << 14) + 0x800;
    r = (int)(v >> 12) - 0x4000;
    if (r < -0x2000)
        r = -0x2000;
    return r;
}
