/*
 * function: BTL_MSG_SetClientName
 * address:  0x021EED90
 * packet:   pkt_ov093_021EED90
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_IsTrainerSlotNpc  0x021B9F70  thumb  ov093
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 *   BTL_MAIN_GetTrainerId  0x021BA004  thumb  ov093
 *   BTL_MAIN_GetTrainerNameAndType  0x021B9FAC  thumb  ov093
 *   BTL_MAIN_GetTrainerHandle  0x021BA064  thumb  ov093
 *   BTL_MAIN_UpdateCommPlayerSupport  0x021BA080  thumb  ov093
 *   TPOKE_DATA_GetGenderValue  0x0202A3CC  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F134  0x0201F134  thumb
 *   gBtlMsgState     0x021F6398  data  ov093  a4
 */

#include "../include/G_ov093_021F6398.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct WordSet;
extern int BTL_MAIN_IsTrainerSlotNpc(u8 *p, int i);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern u16 BTL_MAIN_GetTrainerId(char *p, int i);
extern u32 BTL_MAIN_GetTrainerNameAndType(u8 *p, int i, u32 *out);
extern int BTL_MAIN_GetTrainerHandle(char *p, int i);
extern int BTL_MAIN_UpdateCommPlayerSupport(void *battle);
extern u8 TPOKE_DATA_GetGenderValue(u32 cls);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F134(struct WordSet *p, u32 i, u32 v);
extern struct G_ov093_021F6398 gBtlMsgState;

void BTL_MSG_SetClientName(void *win, u8 slot, u8 k)
{
    u32 t;
    int v;

    if (k != 4) {
        if (BTL_MAIN_IsTrainerSlotNpc((*(void * *)&gBtlMsgState), k) != 0) {
            if ((int)BTL_MAIN_GetCompetitor((*(void * *)&gBtlMsgState)) == 1) {
                v = BTL_MAIN_GetTrainerId((*(void * *)&gBtlMsgState), k);
                if (v != 0)
                    func_0201F134(win, slot, v);
            } else {
                v = BTL_MAIN_GetTrainerNameAndType((*(void * *)&gBtlMsgState), k, &t);
                func_0201EE0C(win, slot, (void *)v, TPOKE_DATA_GetGenderValue(t), 1, 2);
            }
        } else {
            func_0201F02C(win, slot, (void *)BTL_MAIN_GetTrainerHandle((*(void * *)&gBtlMsgState), k));
        }
    } else {
        func_0201F02C(win, slot, (void *)BTL_MAIN_UpdateCommPlayerSupport((*(void * *)&gBtlMsgState)));
    }
}
