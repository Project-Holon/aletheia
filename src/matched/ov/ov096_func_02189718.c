/*
 * function: TR_AI_CmdJumpIfFlashFireActive
 * address:  0x02189718
 * packet:   pkt_ov096_02189718
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   VM_Jump  0x020113B0  thumb
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetPoke  0x0218A2FC  thumb  ov096
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 */
#include "../include/Obj00005.h"
#include "../include/Obj21969.h"

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
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);

int TR_AI_CmdJumpIfFlashFireActive(struct Cursor *a, int b) {
    int r7;
    int r6;
    u8 *t;
    u8 s;
    r7 = VM_GetU32(a);
    r6 = VM_GetU32(a);
    s = TR_AI_GetPosition((u8 *)b, r7);
    t = TR_AI_GetPoke((u8 *)b, s);
    if (BTL_POKEPARAM_TestContFlag((struct UtilWork *)t, 13)) {
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + r6);
    }
    return ((struct Obj21969 *)b)->fC4;
}
