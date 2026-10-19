/*
 * function: TR_AI_CmdSwitchOnMoveEffectSequence
 * address:  0x02189FC0
 * packet:   pkt_ov096_02189FC0
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   VM_Jump  0x020113B0  thumb
 *   TR_AI_CmdEnd  0x021895AC  thumb  ov096
 *   TR_AI_GetMoveParam  0x0218A378  thumb  ov096
 */
#include "../include/Obj00005.h"
#include "../include/Obj13669.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
struct Cur;
extern void VM_Jump(struct Cur *c, u32 v);
extern int TR_AI_CmdEnd(u8 *, u8 *);
extern int TR_AI_GetMoveParam(u8 *, int, int);

int TR_AI_CmdSwitchOnMoveEffectSequence(struct Cursor *a, u8 *b)
{
    int t;
    int u;
    int w;
    u16 *base;
    int m;
    int flag;
    t = VM_GetU32(a);
    u = VM_GetU32(a);
    w = VM_GetU32(a);
    base = (u16 *)(*(u8 * *)&((struct Obj00005 *)a)->f14 + w);
    flag = 0;
    if (t == 0) {
        m = TR_AI_GetMoveParam(b, ((struct Obj13669 *)b)->f2, 0x1c) * 2;
        if (m / 2 > u)
            flag = 1;
    } else {
        flag = 1;
    }
    if (flag == 1)
        return TR_AI_CmdEnd((u8 *)a, b);
    VM_Jump((struct Cur *)a, (u32)((u8 *)base + (base[m] | (base[m + 1] << 16))));
    return ((struct Obj13669 *)b)->fC4;
}
