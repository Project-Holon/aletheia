/*
 * function: func_021CEEB8
 * address: 0x021CEEB8
 * packet: pkt_ov093_021CEEB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 b/d retain the spilled reload and narrow only at the u8 call;
 *        enum same retains the early ternary truncation.
 * symbols:
 *   BTL_CLIENT_SumSlotFlagsBeforeCurrent 0x021CF448 thumb ov093
 *   func_021CEFFC 0x021CEFFC thumb ov093
 *   func_021E9D04 0x021E9D04 thumb ov093
 *   BTL_CLIENT_PollTimeLimitAndSetSub 0x021CE0BC thumb ov093
 *   func_021E9E70 0x021E9E70 thumb ov093
 *   func_021E9E80 0x021E9E80 thumb ov093
 *   func_021EA01C 0x021EA01C thumb ov093
 *   func_021EA044 0x021EA044 thumb ov093
 *   func_021EA030 0x021EA030 thumb ov093
 *   func_021EA04C 0x021EA04C thumb ov093
 *   BTL_CLIENT_SetSlotFlag 0x021CF430 thumb ov093
 *   BTL_ACTION_SetItem 0x021D8358 thumb ov093
 *   func_021EA058 0x021EA058 thumb ov093
 *   BTL_CALC_GetMonParamWithHeap 0x021D805C thumb ov093
 *   BTL_CLIENT_SetSlotLinkWord 0x021CF37C thumb ov093
 *   BTL_CLIENT_SetSubFn 0x021CE150 thumb ov093
 *   func_021CF220 0x021CF220 thumb ov093
 *   func_021CE4D0 0x021CE4D0 thumb ov093
 *   func_021CE3C8 0x021CE3C8 thumb ov093
 */
#include "../include/Obj00967.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { VALUE_ZERO, VALUE_ONE } Value;
extern u8 BTL_CLIENT_SumSlotFlagsBeforeCurrent(u8 *);
extern u32 func_021CEFFC(u8 *);
extern void func_021E9D04(void *, int, int, int, u32, u32);
struct QV;
extern int BTL_CLIENT_PollTimeLimitAndSetSub(u8 *p, void *q);
extern void func_021E9E70(u8 *p);
extern int func_021E9E80(u8 *p);
extern u16 func_021EA01C(u8 *p);
extern u8 func_021EA044(struct QV *p);
extern u8 func_021EA030(u8 *p);
extern u8 func_021EA04C(u8 *p);
extern void BTL_CLIENT_SetSlotFlag(u8 *, u32, u32);
extern void BTL_ACTION_SetItem(u32 *p, u32 id, u32 sub, u32 val);
extern void func_021EA058(char *p);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern void BTL_CLIENT_SetSlotLinkWord(u8 *, u32, u32);
extern void BTL_CLIENT_SetSubFn(u8 *p, void *q);
extern u32 func_021CF220(u8 *p, int *st);
extern int func_021CE4D0(u8 *p, u32 *st);
extern int func_021CE3C8(u8 *p, int *state);

static inline u8 same_index(u8 *p)
{
    return p[0x11d] == p[0x11f] ? 1 : 0;
}

u32 func_021CEEB8(u8 *p, int *st)
{
    u32 a, c, z;
    u16 b, d;
    Value same;
    u32 flag;
    switch (*st) {
    case 0:
        a = BTL_CLIENT_SumSlotFlagsBeforeCurrent(p);
        same = same_index(p);
        flag = (u8)func_021CEFFC(p);
        func_021E9D04(((struct Obj00967 *)p)->f54, p[0x1aa], p[0x1ab], a, same, flag);
        ++*st;
        break;
    case 1:
        z = 0;
        if (BTL_CLIENT_PollTimeLimitAndSetSub(p, 0)) {
            func_021E9E70(((struct Obj00967 *)p)->f54);
            *st = 2;
            return z;
        }
        if (func_021E9E80(((struct Obj00967 *)p)->f54)) {
            a = func_021EA01C(((struct Obj00967 *)p)->f54);
            b = func_021EA044(((struct Obj00967 *)p)->f54);
            if (a && b != 6) {
                c = func_021EA030(((struct Obj00967 *)p)->f54);
                d = func_021EA04C(((struct Obj00967 *)p)->f54);
                if (p[0x1ab] >= c) p[0x1ab] = p[0x1ab] - c;
                else {
                    p[0x1ab] = z;
                    c = p[0x1ab];
                }
                BTL_CLIENT_SetSlotFlag(p, p[0x11d], c);
                BTL_ACTION_SetItem(((struct Obj00967 *)p)->fC, a, (u8)b, (u8)d);
                func_021EA058(((struct Obj00967 *)p)->f54);
                if (BTL_CALC_GetMonParamWithHeap((void *)a, 0xf) == 4) p[0x1b2] |= 4;
                BTL_CLIENT_SetSlotLinkWord(p, p[0x11d], a);
                BTL_CLIENT_SetSubFn(p, (void *)((u32)func_021CF220));
            } else BTL_CLIENT_SetSubFn(p, (void *)((u32)func_021CE4D0));
        }
        break;
    case 2:
        if (func_021E9E80(((struct Obj00967 *)p)->f54)) BTL_CLIENT_SetSubFn(p, (void *)((u32)func_021CE3C8));
        break;
    }
    return 0;
}
