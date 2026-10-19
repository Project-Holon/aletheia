/*
 * function: TR_AI_CmdIfHasMoveWithPower
 * address:  0x02188BB0
 * packet:   pkt_ov096_02188BB0
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: b is a pointer to a Conn struct (fields fbc, fc4) so the b+0xbc
 *   address is not CSE'd across the calls (the original re-adds it each time);
 *   TR_AI_GetMoveParam's second parameter is int (no truncation before the bl).
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   VM_Jump  0x020113B0  thumb
 *   TR_AI_GetMoveParam  0x0218A378  thumb  ov096
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0xbc];
    u8 *fbc;
    u8 padC0[4];
    int fc4;
} Conn;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
struct Cur;
struct QG;
extern void VM_Jump(struct Cur *c, u32 v);
extern int TR_AI_GetMoveParam(Conn *, int, int);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);

int TR_AI_CmdIfHasMoveWithPower(struct Cursor *a, Conn *b)
{
    int m;
    int i;

    m = VM_GetU32(a);
    for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc); i++) {
        if (TR_AI_GetMoveParam(b, BTL_POKEPARAM_GetMoveId(b->fbc, (u8)i), 3) != 0)
            break;
    }
    if (i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc))
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + m);
    return b->fc4;
}
