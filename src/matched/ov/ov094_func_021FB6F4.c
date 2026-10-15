/*
 * function: BTLV_EFFVM_CmdLoadClactAtPoke
 * address:  0x021FB6F4
 * packet:   pkt_ov094_021FB6F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * (pt is 3 words: the third is unused padding that sets the 0x30 frame)
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFVM_ResolveSlotKey  0x021FCF2C  thumb  ov094
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_MCSS_GetSlotPosition  0x021FF3F4  thumb  ov094
 *   BTLV_EFFECT_GetClact  0x021F86F0  thumb  ov094
 *   BTLV_CLACT_LoadActorSimple  0x02201AF8  thumb  ov094
 *   NNS_G3dWorldPosToScrPos  0x0206DF3C  arm
 */
#include "../include/Obj21668.h"
typedef short s16;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFVM_ResolveSlotKey(int a, int b);
extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_MCSS_GetSlotPosition(void *obj, void *out, int idx);
extern int BTLV_EFFECT_GetClact(void);
extern int BTLV_CLACT_LoadActorSimple(int a, int b, int c, s16 d, s16 e, int f, int g);
extern void NNS_G3dWorldPosToScrPos(int *p, int *q, int *r);

int BTLV_EFFVM_CmdLoadClactAtPoke(struct Cursor *a, char *b)
{
    int pt[3];
    int o1, o2;
    int t0, t1, t2, t3, t4, t5, t6;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = BTLV_EFFVM_ResolveSlotKey((int)a, VM_GetU32(a));
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    t6 = VM_GetU32(a);
    BTLV_MCSS_GetSlotPosition((void *)BTLV_EFFECT_GetMcss(), pt, t2);
    pt[0] += t3;
    pt[1] += t4;
    NNS_G3dWorldPosToScrPos(pt, &o1, &o2);
    *(int *)(b + t0 * 4 + 0xcc) =
        BTLV_CLACT_LoadActorSimple(BTLV_EFFECT_GetClact(), 0x5f, t1, o1, o2, t5, t6);
    return ((struct Obj21668 *)b)->f23C;
}
