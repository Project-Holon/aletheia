/*
 * function: TR_AI_CmdJumpIfAllMovesUsed
 * address:  0x021899DC
 * packet:   pkt_ov096_021899DC
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   VM_Jump  0x020113B0  thumb
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetPoke  0x0218A2FC  thumb  ov096
 *   BTL_POKEPARAM_CountUsedMoves  0x021D5478  thumb  ov093
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 */
#include "../include/Obj00005.h"
#include "../include/Obj21972.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
struct Cur;
struct QG;
struct Work;
extern void VM_Jump(struct Cur *c, u32 v);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
extern u8 BTL_POKEPARAM_CountUsedMoves(struct Work *p);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);

int TR_AI_CmdJumpIfAllMovesUsed(struct Cursor *a, int b) {
    int r4;
    int r7;
    u8 t;
    u8 *s;
    r4 = VM_GetU32(a);
    r7 = VM_GetU32(a);
    t = TR_AI_GetPosition((u8 *)b, r4);
    s = TR_AI_GetPoke((u8 *)b, t);
    if (BTL_POKEPARAM_CountUsedMoves((struct Work *)s) >= BTL_POKEPARAM_GetMoveCount((struct QG *)s) && BTL_POKEPARAM_GetMoveCount((struct QG *)s) > 1) {
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + r7);
    }
    return ((struct Obj21972 *)b)->fC4;
}
