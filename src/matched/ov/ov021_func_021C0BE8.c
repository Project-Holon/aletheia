/*
 * function: EVENT_RECOVERY_PlacePartyBall
 * address:  0x021C0BE8
 * packet:   pkt_ov021_021C0BE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BUTTON_MAN_MakeRotMtxXYZ  0x020520FC  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   sPartyRecoveryBallOffsets     0x021DA0E0  data  a4
 *   FIELD_BUILDMODEL_CreateNodeFromBlock  0x0218C7F0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00959.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Mtx33;
extern void BUTTON_MAN_MakeRotMtxXYZ(int a, int b, int c, struct Mtx33 *m);
extern void func_0207C9D0(u8 *a, u8 *b, int *c);
extern u8 sPartyRecoveryBallOffsets;
struct Blk;
extern u8 *FIELD_BUILDMODEL_CreateNodeFromBlock(u8 *owner, u32 x, struct Blk *src);
extern void func_020061E4(u32 se);

void EVENT_RECOVERY_PlacePartyBall(u8 *p)
{
    struct {
        int pos[3];
        int scale[3];
        int mtx[9];
    } s;
    u32 i;

    i = p[0x15];
    if (p[0x14] > i) {
        s.scale[0] = 0x1000;
        s.scale[1] = 0x1000;
        s.scale[2] = 0x1000;
        BUTTON_MAN_MakeRotMtxXYZ(0, 0, 0, (struct Mtx33 *)s.mtx);
        func_0207C9D0(p + 8, &sPartyRecoveryBallOffsets + i * 12, s.pos);
        *(u32 *)(p + 0x1c + i * 4) = (u32)FIELD_BUILDMODEL_CreateNodeFromBlock((u8 *)(((struct Obj00959 *)p)->f18), 0x62, (struct Blk *)(&s));
        p[0x15]++;
        func_020061E4(0x568);
    }
}
