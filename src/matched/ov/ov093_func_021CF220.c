/*
 * function: BTL_CLIENT_StepAdvanceSlot
 * address: 0x021CF220
 * packet: pkt_ov093_021CF220
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_CORE_CloseMenuToReselect 0x021E9964 thumb ov093
 *   BTLV_CORE_IsMenuClosed 0x021E9974 thumb ov093
 *   BTL_SIDE_GetClientPokeParam 0x021B990C thumb ov093
 *   BTL_CLIENT_IsActionForced 0x021CF470 thumb ov093
 *   BTL_CALC_ActionSetNone 0x021D8434 thumb ov093
 *   BTL_CLIENT_SetSubFn 0x021CE150 thumb ov093
 *   BTL_CLIENT_StepSelectAction 0x021CE4D0 thumb ov093
 *   BTL_CLIENT_StepSendActions 0x021CF2F0 thumb ov093
 */
#include "../include/Obj00888.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTLV_CORE_CloseMenuToReselect(u32);
extern int BTLV_CORE_IsMenuClosed(u32);
extern void *BTL_SIDE_GetClientPokeParam(char *p, unsigned int i, unsigned int j);
extern u32 BTL_CLIENT_IsActionForced(u8 *, void *, u8 *);
extern void BTL_CALC_ActionSetNone(u32 *p);
extern void BTL_CLIENT_SetSubFn(u8 *p, void *q);
extern int BTL_CLIENT_StepSelectAction(u8 *p, u32 *st);
typedef signed int     s32;
extern u32 BTL_CLIENT_StepSendActions(u8 *p, s32 *st);
u32 BTL_CLIENT_StepAdvanceSlot(u8 *p, int *st)
{
    u8 n;
    void *q;
    switch (*st) {
    case 0:
        BTLV_CORE_CloseMenuToReselect(((struct Obj00888 *)p)->f54);
        ++*st;
        break;
    case 1:
        if (BTLV_CORE_IsMenuClosed(((struct Obj00888 *)p)->f54)) {
            ++p[0x11d];
            if (p[0x11d] < p[0x11c]) {
                if ((((u32)p[0x1b2] << 29) >> 31) == 0) {
                    BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepSelectAction));
                    break;
                }
                while (p[0x11d] < p[0x11c]) {
                    q = BTL_SIDE_GetClientPokeParam((char *)(((struct Obj00888 *)p)->f4), p[0x1a6], p[0x11d]);
                    if (!BTL_CLIENT_IsActionForced(p, q, p + 0x124 + p[0x11d] * 4))
                        BTL_CALC_ActionSetNone((u32 *)(p + 0x124 + p[0x11d] * 4));
                    ++p[0x11d];
                }
            }
            if (p[0x11d] >= p[0x11c]) {
                n = p[0x11c] + p[0x1af];
                p[0x1af] = 0;
                *(u8 * *)&((struct Obj00888 *)p)->fD8 = p + 0x124;
                ((struct Obj00888 *)p)->fDC = n * 4;
                BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepSendActions));
            }
        }
        break;
    }
    return 0;
}
