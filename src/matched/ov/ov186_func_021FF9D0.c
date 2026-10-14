/*
 * packet: pkt_ov186_021FF9D0
 * function: BR_NET_StepSearchVideos
 * address: 0x021FF9D0
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_RequestSearchVideos 0x021D68EC thumb ov125
 *   func_02034714 0x02034714 arm
 *   BR_NET_SetStep 0x021FFB68 thumb ov186
 *   BR_NET_StepWaitRequest 0x021FF8E4 thumb ov186
 *   gBrNetAssertString 0x02200D98 data a1
 */
#include "../include/Obj08337.h"
extern int GDS_RAP_RequestSearchVideos(char *, int, unsigned, int, unsigned char);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void BR_NET_SetStep(char *, int);
extern void BR_NET_StepWaitRequest(void *, int, int);
extern const char gBrNetAssertString[];
void BR_NET_StepSearchVideos(char *p, int unused, char *q)
{
    if (!GDS_RAP_RequestSearchVideos(q, ((struct Obj08337 *)q)->f5B0, ((struct Obj08337 *)q)->f5B4, ((struct Obj08337 *)q)->f5B2, ((struct Obj08337 *)q)->f5B3))
        func_02034714(gBrNetAssertString, 0, gBrNetAssertString);
    BR_NET_SetStep(p, (int)BR_NET_StepWaitRequest);
}
