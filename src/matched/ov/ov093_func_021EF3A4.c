/*
 * function: BTL_MSG_BuildMoveEffectA
 * address:  0x021EF3A4
 * packet:   pkt_ov093_021EF3A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of BTL_MSG_BuildMoveEffectB (partial sum in a named local, x added last).
 *
 * symbols:
 *   BTL_MSG_SetPokeName  0x021EED00  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8CE8  0x021B8CE8  thumb  ov093
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201F250  0x0201F250  thumb
 *   gBtlMsgState     0x021F6398  data  ov093  a4
 *   d_021F63D8     0x021F63D8  data  ov093  a4
 */

#include "../include/G_ov093_021F6398.h"
#include "../include/G_H.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u8 pad[0x10];
    u16 f10;
    u8 pad2[6];
    u16 f18;
    u16 f1a;
} H;

typedef struct {
    int f0;
    u32 f4;
    int f8;
    int fc;
} P;

extern struct G_ov093_021F6398 gBtlMsgState;
extern struct H d_021F63D8;
struct WordSet;
extern u8 func_021B8DDC(u32 x);
extern int func_021B8CE8(int a, int b, int c);
extern void *BTL_MAIN_GetCompetitor(void ***p);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void BTL_MSG_SetPokeName(u8 a, u32 b);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

void BTL_MSG_BuildMoveEffectA(u32 a, u32 b, P *p)
{
    u8 idx;
    int sel;
    int x;
    u8 k;
    u32 pos;

    idx = p->f8 - 1;
    sel = 0;
    if (p->fc >= 3)
        sel = 2;
    if (p->fc == 2)
        sel = 1;
    b = (u16)(b + (u16)(sel * 0x15));
    k = p->f0;
    if (d_021F63D8.f18 == 0
        && func_021B8CE8(gBtlMsgState.f00, (u8)gBtlMsgState.f54, func_021B8DDC(k)) != 0) {
        if (BTL_MAIN_GetCompetitor((void ***)gBtlMsgState.f00) == 0 || (int)BTL_MAIN_GetCompetitor((void ***)gBtlMsgState.f00) == 4)
            x = 1;
        else
            x = 2;
    } else {
        x = 0;
    }
    BTL_MSG_SetPokeName(p->f0, 0);
    func_0201EF40((void *)gBtlMsgState.f08, 1, p->f4);
    pos = b + idx * 3;
    MSGDATA_ReadString((void *)gBtlMsgState.t[1], (u16)(pos + x), (void *)gBtlMsgState.f0c);
    func_0201F250((void *)gBtlMsgState.f08, (void *)a, (void *)gBtlMsgState.f0c);
}
