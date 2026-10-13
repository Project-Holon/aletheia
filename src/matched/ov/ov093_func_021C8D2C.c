/*
 * function: func_021C8D2C
 * address:  0x021C8D2C
 * packet:   pkt_ov093_021C8D2C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_SERVER_FLOW_IsHpRecoverUnneeded  0x021C3370  thumb  ov093
 *   BTL_SERVER_FLOW_CheckHealBlocked  0x021C3394  thumb  ov093
 *   BTL_SERVER_FLOW_ApplyHpRecover  0x021C33E8  thumb  ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupIn  0x021C5A1C  thumb  ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupOut  0x021C5A34  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *func_021B9934(char *p, int i);
struct Msg;
extern int BTL_SERVER_FLOW_IsHpRecoverUnneeded(u8 *p, void *q);
extern int BTL_SERVER_FLOW_CheckHealBlocked(u8 *p, u8 *q, int r);
extern void BTL_SERVER_FLOW_ApplyHpRecover(int a, int b, int c);
extern void BTL_SERVER_FLOW_PushAbilityPopupIn(u8 *p, u8 *a);
extern void BTL_SERVER_FLOW_PushAbilityPopupOut(u8 *p, u8 *a);
extern int func_021C99A0(void *w, const struct Msg *m);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    u16 h4; u8 b6; u8 b7; u16 h8; u16 ha;
} Ent;

u8 func_021C8D2C(int p, const Ent *e, int c)
{
    u8 r = 0;
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)e->idx);
    int b = (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b6);

    if (BTL_SERVER_FLOW_IsHpRecoverUnneeded((u8 *)p, (void *)b) == 0) {
        if (e->fl)
            BTL_SERVER_FLOW_PushAbilityPopupIn((u8 *)p, a);
        if (e->b7 == 0) {
            r = !BTL_SERVER_FLOW_CheckHealBlocked((u8 *)p, (u8 *)b, 1);
        } else {
            r = 1;
        }
        if (r) {
            BTL_SERVER_FLOW_ApplyHpRecover(p, b, e->h4);
            if ((u8)e->ha)
                func_021C99A0((void *)p, (void *)&e->h8);
            else if (c)
                BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x38c, e->b6, c, 0xffff0000);
        }
        if (e->fl)
            BTL_SERVER_FLOW_PushAbilityPopupOut((u8 *)p, a);
    }
    return r;
}
