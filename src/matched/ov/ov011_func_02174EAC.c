/*
 * function: INTRUDE_COMM_ApplyPlayerBeacon
 * address:  0x02174EAC
 * packet:   pkt_ov011_02174EAC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02008494  0x02008494  thumb
 *   func_020127AC  0x020127AC  thumb
 *   func_02082D44  0x02082D44  arm
 *   GAME_DATA_SetSlotFlag  0x02012BA4  thumb
 *   INTRUDE_COMM_StorePlayerRecord  0x02174F54  thumb ov011
 *   func_02039338  0x02039338  arm
 *   GAME_COMM_PushPlayerMessage  0x020266D4  thumb
 *
 * Blocker: byte-correct; 0x02008494 is an unlabelled arm9 Thumb thunk
 * (ldr r3,=target; movs r2,#0x20; bx r3), no witness outside the range.
 * Verified C for the leaf: void func_02008494(u8 *a, int b) style thunk;
 * needs the integrator's arm9 leaf filed to promote this to EXACT.
 */
#include "../include/Obj00269.h"

typedef unsigned char u8;

typedef struct Q {
    u8 lo : 6;
    u8 hi : 2;
} Q;

struct Rec44;
struct SaveBlock;
struct Sub0200852CObj;
struct Sub24;
unsigned int func_02026478(void *obj);
struct Rec44 *func_02012950(struct Sub24 *p, unsigned int i);
unsigned int func_02008530(const struct Sub0200852CObj *obj);
void func_02008494(void *src, void *dst);
void *func_020127AC(struct SaveBlock *p, unsigned int idx);
void func_02082D44(u8 *a, int b, int c);
struct BigObj;
void GAME_DATA_SetSlotFlag(struct BigObj *p, int i, u8 v);
struct Ent;
void INTRUDE_COMM_StorePlayerRecord(u8 *p, int idx, const struct Ent *src, int arg);
typedef unsigned short u16;
typedef unsigned int   u32;
u16 func_02039338(void);
void GAME_COMM_PushPlayerMessage(u32 a, u32 b);

void INTRUDE_COMM_ApplyPlayerBeacon(u8 *p, int idx, u8 *q)
{
    int x;
    int ctx;
    int a;
    int flag;

    ctx = func_02026478((void *)(((struct Obj00269 *)p)->f4));
    flag = 0;
    a = (int)func_02012950((struct Sub24 *)ctx, idx);
    if (p[0x8FB] & (1 << idx)) {
        x = func_02008530((const struct Sub0200852CObj *)a);
        if (x == func_02008530((const struct Sub0200852CObj *)q)) {
            goto skip;
        }
    }
    flag = 1;
skip:
    func_02008494(q, (void *)a);
    func_02082D44(q + 0x20, (int)func_020127AC((struct SaveBlock *)ctx, idx), 0x10);
    GAME_DATA_SetSlotFlag((struct BigObj *)ctx, idx, ((Q *)(q + 0x4A))->hi);
    INTRUDE_COMM_StorePlayerRecord(p, idx, (const struct Ent *)(q + 0x30), 1);
    p[0x8FB] |= (u8)(1 << idx);
    if (flag == 1 && idx != func_02039338()) {
        GAME_COMM_PushPlayerMessage(((struct Obj00269 *)p)->f4, idx);
    }
}
