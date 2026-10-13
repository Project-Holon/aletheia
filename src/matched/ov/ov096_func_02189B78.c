/*
 * function: func_02189B78
 * address:  0x02189B78
 * packet:   pkt_ov096_02189B78
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   VM_Jump  0x020113B0  thumb
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_CalcMoveTypeEffectiveness  0x021C7DAC  thumb  ov093
 *
 * Lever: the second parameter is a struct pointer; with an int base the
 * loop-invariant b+0xbc/b+0xc0 addresses were hoisted and b spilled.
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct { u8 p0[0x38]; int f38; u8 p1[0x58]; u8 f94; u8 p2[0x1b]; int fb0, fb4, fb8; u8 *fbc, *fc0; int fc4; } Obj;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
struct Cur;
struct QG;
extern void VM_Jump(struct Cur *c, u32 v);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_SERVER_FLOW_CalcMoveTypeEffectiveness(u8 *p, int a, int b, int c);

int func_02189B78(struct Cursor *a, Obj *b) {
    int r;
    int i;
    int c6;
    int c7;
    int c2;
    r = VM_GetU32(a);
    for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc); i++) {
        c6 = BTL_POKEPARAM_GetMoveId(b->fbc, (u8)i);
        c7 = BTL_POKEPARAM_GetPokeId(b->fbc);
        c2 = BTL_POKEPARAM_GetPokeId(b->fc0);
        if ((u32)(BTL_SERVER_FLOW_CalcMoveTypeEffectiveness((u8 *)b->fb4, c7, c2, c6) - 4) <= 1) {
            VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + r);
            break;
        }
    }
    return b->fc4;
}
