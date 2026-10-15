/*
 * function: EVENT_RECOVERY_PlaceBall
 * address:  0x021C09B0
 * packet:   pkt_ov021_021C09B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BUTTON_MAN_MakeRotMtxXYZ  0x020520FC  arm
 *   VEC_Add  0x0207C9D0  arm
 *   FIELD_BUILDMODEL_CreateNodeFromBlock  0x0218C7F0  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   sRecoveryBallOffsets  0x021DA098  data  ov021  a4
 */
#include "../include/Obj00707.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Mtx33;
extern void BUTTON_MAN_MakeRotMtxXYZ(int ax, int ay, int az, struct Mtx33 *dst);
extern void VEC_Add(u8 *dst, u8 *src, int *v);
struct Blk;
extern u8 *FIELD_BUILDMODEL_CreateNodeFromBlock(u8 *owner, u32 x, struct Blk *src);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u8 sRecoveryBallOffsets[];

void EVENT_RECOVERY_PlaceBall(u8 *p)
{
    struct { int out[3]; int scale[3]; int mat[9]; } s;
    u32 i;

    i = p[0x15];
    if (p[0x14] > i) {
        s.scale[0] = 0x1000;
        s.scale[1] = 0x1000;
        s.scale[2] = 0x1000;
        BUTTON_MAN_MakeRotMtxXYZ(0, 0, 0, (struct Mtx33 *)s.mat);
        VEC_Add(p + 8, sRecoveryBallOffsets + i * 12, s.out);
        *(u32 *)(p + 0x1c + i * 4) = (u32)FIELD_BUILDMODEL_CreateNodeFromBlock((u8 *)(((struct Obj00707 *)p)->f18), 0x62, (struct Blk *)s.out);
        p[0x15] = p[0x15] + 1;
        GFL_USE_PlaySeDefaultVolume(0x568);
    }
}
