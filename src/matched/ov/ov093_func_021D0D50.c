/*
 * unit: yes
 * function: BTL_CLIENT_ChooseReplacementsAuto, BTL_CLIENT_StepForwardToSubFn
 * address: 0x021D0D50
 * packet: pkt_ov093_021D0D50
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: separate order[6] then pair[2] stack arrays keep the order base
 * at sp+6 and the index in the ldrb register offset; one buffer or a
 * struct member array reassociates this into a base+index and immediate 2.
 * follower: 021D0E74 is an eight-byte tail-call stub to BTL_CLIENT_StepPlaybackRecordedAction;
 * included in this complete 300-byte unit after parent ownership audit.
 * symbols:
 *   BTL_CLIENT_StepPlaybackRecordedAction 0x021CE1B0 thumb ov093
 *   BTL_CLIENT_CollectOwnReceivedIds 0x021D0C78 thumb ov093
 *   BTL_CLIENT_ListAbleMons 0x021D0980 thumb ov093
 *   BTL_CLIENT_PickRandomFoe 0x021CFD50 thumb ov093
 *   BTL_CLIENT_SortMonsByMovePower 0x021D09E0 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_CLIENT_TrySetRotateAction 0x021D1058 thumb ov093
 *   BTL_MAIN_GetSlotClientAndNth 0x021B8E28 thumb ov093
 *   BTL_ACTION_SetChange 0x021D8394 thumb ov093
 *   BTL_CLIENT_IsDoubleBattleLeadAlive 0x021D102C thumb ov093
 *   BTL_ACTION_SetChangeDepleted 0x021D83C4 thumb ov093
 *   BTL_CALC_ActionSetNone 0x021D8434 thumb ov093
 */
#include "../include/Obj01236.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_CLIENT_CollectOwnReceivedIds(void *,u8 *);
extern u8 BTL_CLIENT_ListAbleMons(u8 *,u8 *);
struct G;
extern u8 *BTL_CLIENT_PickRandomFoe(struct G *g, int k);
extern void BTL_CLIENT_SortMonsByMovePower(u8 *p, u8 *order, u8 count, void *target);
extern u32 BTL_MAIN_GetRule(void **);
extern int BTL_CLIENT_TrySetRotateAction(u8 *,void *);
extern void BTL_MAIN_GetSlotClientAndNth(u8 *,u8,u8 *,u8 *);
extern void BTL_ACTION_SetChange(void *,u8,u8);
extern int BTL_CLIENT_IsDoubleBattleLeadAlive(char *p);
extern void BTL_ACTION_SetChangeDepleted(u32 *p);
extern void BTL_CALC_ActionSetNone(u32 *p);
int BTL_CLIENT_ChooseReplacementsAuto(u8 *p)
{
    u8 order[6];
    u8 pair[2];
    u8 count;
    u8 n;
    u8 i;
    u8 *target;
    int result;
    p[0x1b3] = BTL_CLIENT_CollectOwnReceivedIds(p,p+0x1b5);
    if (p[0x1b3]) {
        n = BTL_CLIENT_ListAbleMons(p,order);
        if (n) {
            count = p[0x1b3];
            target = BTL_CLIENT_PickRandomFoe((struct G *)p,p[0x1b5]);
            if (target) BTL_CLIENT_SortMonsByMovePower(p,order,n,target);
            if (count > n) {
                if (BTL_MAIN_GetRule(*(void ** *)&((struct Obj01236 *)p)->f0) == 3) {
                    result = BTL_CLIENT_TrySetRotateAction(p,p+0x124);
                    if (result) {
                        *(int *)&((struct Obj01236 *)p)->fDC = result;
                        ((struct Obj01236 *)p)->fD8 = p+0x124;
                        return 1;
                    }
                }
                count = n;
            }
            for (i=0;i<count;i++) {
                BTL_MAIN_GetSlotClientAndNth(*(u8 * *)&((struct Obj01236 *)p)->f0,p[0x1b5+i],pair,pair+1);
                BTL_ACTION_SetChange(p+0x124+i*4,pair[1],order[i]);
            }
            ((struct Obj01236 *)p)->fD8 = p+0x124;
            ((struct Obj01236 *)p)->fDC = count*4;
        } else {
            if (BTL_CLIENT_IsDoubleBattleLeadAlive((char *)p)) {
                result = BTL_CLIENT_TrySetRotateAction(p,p+0x124);
                if (result) {
                    *(int *)&((struct Obj01236 *)p)->fDC = result;
                    ((struct Obj01236 *)p)->fD8 = p+0x124;
                    return 1;
                }
            }
            BTL_ACTION_SetChangeDepleted((u32 *)(p+0x124));
            ((struct Obj01236 *)p)->fD8 = p+0x124;
            ((struct Obj01236 *)p)->fDC = 4;
        }
    } else {
        BTL_CALC_ActionSetNone((u32 *)(p+0x124));
        ((struct Obj01236 *)p)->fD8 = p+0x124;
        ((struct Obj01236 *)p)->fDC = 4;
    }
    return 1;
}

extern int BTL_CLIENT_StepPlaybackRecordedAction(u8 *,int *);
int BTL_CLIENT_StepForwardToSubFn(u8 *p,int *state)
{
    return BTL_CLIENT_StepPlaybackRecordedAction(p,state);
}
