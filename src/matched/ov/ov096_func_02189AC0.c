/*
 * function: TR_AI_CmdJumpIfPartyDamage
 * address:  0x02189AC0
 * packet:   pkt_ov096_02189AC0
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   VM_Jump  0x020113B0  thumb
 *   TR_AI_GetSlotPoke  0x0218A308  thumb  ov096
 *   TR_AI_GetBestDamage  0x0218A390  thumb  ov096
 *   BTL_MAIN_GetSlotClientIdThunk  0x021B8DE4  thumb  ov093
 *   BTL_SIDE_GetSlotOfClientThunk  0x021B9AF8  thumb  ov093
 *   BTL_MAIN_GetPositionsPerClientThunk  0x021B99B8  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *
 * Lever: the second parameter is a struct pointer (see 02189B78).
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct { u8 p0[0x38]; int f38; u8 p1[0x58]; u8 f94; u8 p2[0x1b]; int fb0, fb4; char *fb8; u8 *fbc, *fc0; int fc4; } Obj;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
struct Cur;
extern void VM_Jump(struct Cur *c, u32 v);
extern u8 *TR_AI_GetSlotPoke(void *, u32);
extern u32 TR_AI_GetBestDamage(u8 *a, u8 *b, u8 *c, int d);
extern u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);
extern char *BTL_SIDE_GetSlotOfClientThunk(char *p, int i);
extern int BTL_MAIN_GetPositionsPerClientThunk(void *pp, unsigned int b);
struct Q1;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_POKEPARAM_IsFainted(void *);

int TR_AI_CmdJumpIfPartyDamage(struct Cursor *a, Obj *b) {
    int c;
    int x;
    int r4;
    char *r7;
    u8 *r6;
    u32 base;
    c = VM_GetU32(a);
    x = VM_GetU32(a);
    r4 = BTL_MAIN_GetSlotClientIdThunk((char *)b->fb0, b->f94);
    r7 = BTL_SIDE_GetSlotOfClientThunk(b->fb8, r4);
    r4 = BTL_MAIN_GetPositionsPerClientThunk((void *)b->fb0, r4);
    base = TR_AI_GetBestDamage((u8 *)((int)b), b->fbc, b->fc0, c);
    for (; r4 < BTL_SLOT_GetCount((struct Q1 *)r7); r4++) {
        r6 = TR_AI_GetSlotPoke(r7, (u8)r4);
        BTL_POKEPARAM_GetPokeId(r6);
        if (BTL_POKEPARAM_IsFainted(r6) == 0) {
            if (TR_AI_GetBestDamage((u8 *)((int)b), r6, b->fc0, c) > base) {
                VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + x);
                break;
            }
        }
    }
    return b->fc4;
}
