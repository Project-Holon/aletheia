/*
 * function: BTL_CLIENT_StepAutoSelectActions
 * address: 0x021CE3C8
 * packet: pkt_ov093_021CE3C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_CORE_StartAutoSelectNotice 0x021EAE44 thumb ov093
 *   BTLV_CORE_PollAutoSelectNotice 0x021EAE54 thumb ov093
 *   BTL_SIDE_GetClientPokeParam 0x021B990C thumb ov093
 *   BTL_CALC_ActionSetNone 0x021D8434 thumb ov093
 *   BTL_CLIENT_IsActionForced 0x021CF470 thumb ov093
 *   BTL_CLIENT_BuildUsableMoveMask 0x021CF81C thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_CALC_PeekMoveTarget 0x021D81F8 thumb ov093
 *   BTL_ACTION_SetFight 0x021D82D0 thumb ov093
 *   BTL_CLIENT_SetStruggleAction 0x021CF58C thumb ov093
 *   BTL_CLIENT_SetSubFn 0x021CE150 thumb ov093
 *   BTL_CLIENT_StepSendActions 0x021CF2F0 thumb ov093
 */
#include "../include/Obj00662.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTLV_CORE_StartAutoSelectNotice(void *);
extern int BTLV_CORE_PollAutoSelectNotice(void *);
typedef signed int     s32;
extern void *BTL_SIDE_GetClientPokeParam(char *p, unsigned int i, unsigned int j);
struct Unk021D82D0;
extern void BTL_CALC_ActionSetNone(u32 *p);
extern u32 BTL_CLIENT_IsActionForced(u8 *,void *,u8 *);
extern u32 BTL_CLIENT_BuildUsableMoveMask(u8 *,void *,u8 *);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u32 BTL_CALC_PeekMoveTarget(void *,void *,void *,u32,void *);
extern void BTL_ACTION_SetFight(struct Unk021D82D0 *out, u32 id, u32 sub);
extern void BTL_CLIENT_SetStruggleAction(struct Unk021D82D0 *out, u8 *p, void *q);
extern void BTL_CLIENT_SetSubFn(u8 *p, void *q);
extern u32 BTL_CLIENT_StepSendActions(u8 *p, s32 *st);
int BTL_CLIENT_StepAutoSelectActions(u8 *p,int *state)
{
    u8 out[4];
    u32 i;
    u32 id;
    switch (*state) {
    case 0:
        BTLV_CORE_StartAutoSelectNotice(((struct Obj00662 *)p)->f54);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_PollAutoSelectNotice(((struct Obj00662 *)p)->f54)) {
            for (; p[0x11d] < p[0x11c]; p[0x11d]++) {
                ((struct Obj00662 *)p)->f8 = BTL_SIDE_GetClientPokeParam(((struct Obj00662 *)p)->f4,p[0x1a6],p[0x11d]);
                *(u8 * *)&((struct Obj00662 *)p)->fC = p+0x124+p[0x11d]*4;
                BTL_CALC_ActionSetNone((u32 *)(*(u8 * *)&((struct Obj00662 *)p)->fC));
                if (!BTL_CLIENT_IsActionForced(p,((struct Obj00662 *)p)->f8,*(u8 * *)&((struct Obj00662 *)p)->fC)) {
                    i = BTL_CLIENT_BuildUsableMoveMask(p,((struct Obj00662 *)p)->f8,out);
                    if (i < 4) {
                        id = BTL_POKEPARAM_GetMoveId(((struct Obj00662 *)p)->f8,i);
                        BTL_ACTION_SetFight((struct Unk021D82D0 *)(*(u8 * *)&((struct Obj00662 *)p)->fC),id,BTL_CALC_PeekMoveTarget(((struct Obj00662 *)p)->f0,((struct Obj00662 *)p)->f4,((struct Obj00662 *)p)->f8,id,p+0x38));
                    } else BTL_CLIENT_SetStruggleAction((struct Unk021D82D0 *)(*(u8 * *)&((struct Obj00662 *)p)->fC),p,((struct Obj00662 *)p)->f8);
                }
            }
            (*state)++;
        }
        break;
    case 2:
        *(u8 * *)&((struct Obj00662 *)p)->fD8 = p+0x124;
        ((struct Obj00662 *)p)->fDC = p[0x11c]*4;
        BTL_CLIENT_SetSubFn(p,(void *)((u32)BTL_CLIENT_StepSendActions));
        break;
    }
    return 0;
}
