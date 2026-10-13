/*
 * function: func_021CA748
 * address:  0x021CA748
 * packet:   pkt_ov093_021CA748
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The listing extent (172 bytes) runs on into func_021CA7C4 and func_021CA7D4,
 * which are filed separately.
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_IsTransformed  0x021D6D54  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupIn  0x021C5A1C  thumb  ov093
 *   BTL_POKEPARAM_ChangeForm  0x021D66D8  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupOut  0x021C5A34  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Q {
    u32 lo : 23;
    u32 f : 1;
    u32 hi : 8;
    u8 pad4[0];
};

extern u8 *func_021B9934(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
struct R5;
extern int BTL_POKEPARAM_IsTransformed(struct R5 *p);
extern int func_021D59B4(u8 *p, int k);
extern void BTL_SERVER_FLOW_PushAbilityPopupIn(u8 *p, u8 *a);
extern void BTL_POKEPARAM_ChangeForm(void *m, int v);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
struct Msg;
extern int func_021C99A0(void *w, const struct Msg *m);
extern void BTL_SERVER_FLOW_PushAbilityPopupOut(u8 *p, u8 *a);

int func_021CA748(u8 *p, const struct Q *q)
{
    u8 t;
    void *m = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, ((u8 *)q)[4]);
    if (!BTL_POKEPARAM_IsFainted(m) && !BTL_POKEPARAM_IsTransformed(m)) {
        t = func_021D59B4(m, 0x13);
        if (t != ((u8 *)q)[5]) {
            if (q->f) BTL_SERVER_FLOW_PushAbilityPopupIn(p, m);
            BTL_POKEPARAM_ChangeForm(m, ((u8 *)q)[5]);
            BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x4f, ((u8 *)q)[4], ((u8 *)q)[5]);
            func_021C99A0(p, (const struct Msg *)((u8 *)q + 8));
            if (q->f) BTL_SERVER_FLOW_PushAbilityPopupOut(p, m);
            return 1;
        }
    }
    return 0;
}
