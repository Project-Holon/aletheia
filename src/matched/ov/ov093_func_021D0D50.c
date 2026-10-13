/*
 * unit: yes
 * function: func_021D0D50, func_021D0E74
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
 * follower: 021D0E74 is an eight-byte tail-call stub to func_021CE1B0;
 * included in this complete 300-byte unit after parent ownership audit.
 * symbols:
 *   func_021CE1B0 0x021CE1B0 thumb ov093
 *   func_021D0C78 0x021D0C78 thumb ov093
 *   func_021D0980 0x021D0980 thumb ov093
 *   func_021CFD50 0x021CFD50 thumb ov093
 *   func_021D09E0 0x021D09E0 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   func_021D1058 0x021D1058 thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   BTL_ACTION_SetChange 0x021D8394 thumb ov093
 *   BTL_CLIENT_IsDoubleBattleLeadAlive 0x021D102C thumb ov093
 *   BTL_ACTION_SetChangeDepleted 0x021D83C4 thumb ov093
 *   BTL_CALC_ActionSetNone 0x021D8434 thumb ov093
 */
#include "../include/Obj01236.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021D0C78(void *,u8 *);
extern u8 func_021D0980(u8 *,u8 *);
struct G;
extern u8 *func_021CFD50(struct G *g, int k);
extern void func_021D09E0(u8 *p, u8 *order, u8 count, void *target);
extern u32 BTL_MAIN_GetRule(void **);
extern int func_021D1058(u8 *,void *);
extern void func_021B8E28(u8 *,u8,u8 *,u8 *);
extern void BTL_ACTION_SetChange(void *,u8,u8);
extern int BTL_CLIENT_IsDoubleBattleLeadAlive(char *p);
extern void BTL_ACTION_SetChangeDepleted(u32 *p);
extern void BTL_CALC_ActionSetNone(u32 *p);
int func_021D0D50(u8 *p)
{
    u8 order[6];
    u8 pair[2];
    u8 count;
    u8 n;
    u8 i;
    u8 *target;
    int result;
    p[0x1b3] = func_021D0C78(p,p+0x1b5);
    if (p[0x1b3]) {
        n = func_021D0980(p,order);
        if (n) {
            count = p[0x1b3];
            target = func_021CFD50((struct G *)p,p[0x1b5]);
            if (target) func_021D09E0(p,order,n,target);
            if (count > n) {
                if (BTL_MAIN_GetRule(*(void ** *)&((struct Obj01236 *)p)->f0) == 3) {
                    result = func_021D1058(p,p+0x124);
                    if (result) {
                        *(int *)&((struct Obj01236 *)p)->fDC = result;
                        ((struct Obj01236 *)p)->fD8 = p+0x124;
                        return 1;
                    }
                }
                count = n;
            }
            for (i=0;i<count;i++) {
                func_021B8E28(*(u8 * *)&((struct Obj01236 *)p)->f0,p[0x1b5+i],pair,pair+1);
                BTL_ACTION_SetChange(p+0x124+i*4,pair[1],order[i]);
            }
            ((struct Obj01236 *)p)->fD8 = p+0x124;
            ((struct Obj01236 *)p)->fDC = count*4;
        } else {
            if (BTL_CLIENT_IsDoubleBattleLeadAlive((char *)p)) {
                result = func_021D1058(p,p+0x124);
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

extern int func_021CE1B0(u8 *,int *);
int func_021D0E74(u8 *p,int *state)
{
    return func_021CE1B0(p,state);
}
