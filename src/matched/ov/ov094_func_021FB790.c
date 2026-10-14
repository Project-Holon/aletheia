/*
 * function: BTLV_EFFVM_CmdStartClactMoveShort
 * address:  0x021FB790
 * packet:   pkt_ov094_021FB790
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFECT_GetClact  0x021F86F0  thumb  ov094
 *   BTLV_CLACT_StartMoveShort  0x02201CD0  thumb  ov094
 */
#include "../include/Obj21669.h"
typedef short s16;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFECT_GetClact(void);
extern void BTLV_CLACT_StartMoveShort(char *o, int idx, int c, s16 *p, int s1, int s2, int s3);

int BTLV_EFFVM_CmdStartClactMoveShort(struct Cursor *a, char *b)
{
    s16 arr[2];
    int t0, t1, t3, t4, t5;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    arr[0] = VM_GetU32(a);
    arr[1] = VM_GetU32(a);
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    BTLV_CLACT_StartMoveShort((char *)BTLV_EFFECT_GetClact(), *(int *)(b + t0 * 4 + 0xcc), t1, arr, t3, t4, t5);
    return ((struct Obj21669 *)b)->f23C;
}
