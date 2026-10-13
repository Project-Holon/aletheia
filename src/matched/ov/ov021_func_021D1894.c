/*
 * function: SCRCMD_MMDL_ICA_Start
 * address:  0x021D1894
 * packet:   pkt_ov021_021D1894
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ICA_ANIME_CreateWithStreamBuffer  0x0201147C  thumb
 *   SCRCMD_MMDL_ICA_ApplyFrame  0x021D1988  thumb  ov021
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04301.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *ICA_ANIME_CreateWithStreamBuffer(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
struct Vec3;
extern void SCRCMD_MMDL_ICA_ApplyFrame(u32 a, u32 b, struct Vec3 *c);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);

void SCRCMD_MMDL_ICA_Start(u8 *p, u32 n)
{
    ((struct Obj04301 *)p)->f184 = (u32)ICA_ANIME_CreateWithStreamBuffer(((struct Obj04301 *)p)->f19C, 0xCB, n, 10, (u32)(p + 4), 0x180);
    p[0x19A] = 1;
    p[0x199] = n;
    SCRCMD_MMDL_ICA_ApplyFrame(((struct Obj04301 *)p)->f184, ((struct Obj04301 *)p)->f0, (struct Vec3 *)(p + 0x18C));
    FLDMMDL_SetMoveBit((void *)(((struct Obj04301 *)p)->f0), 0x8000);
}
