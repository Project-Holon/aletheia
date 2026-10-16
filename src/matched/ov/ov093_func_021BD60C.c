/*
 * function: BTL_SERVER_FLOW_TryEscape
 * address:  0x021BD60C
 * packet:   pkt_ov093_021BD60C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetCompetitorKind  0x021B86E4  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb  ov093
 *   BTL_SERVER_FLOW_CheckEscapeGuaranteed  0x021BD6B8  thumb  ov093
 *   BTL_SIDE_GetClientPoke  0x021B9920  thumb  ov093
 *   BTL_POKEPARAM_GetStatRaw  0x021D58A8  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_SERVER_FLOW_CommitEscape  0x021BD708  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_MAIN_GetCompetitorKind(unsigned int **p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern u8 BTL_MAIN_GetOwnClientId(u8 *p);
extern int BTL_SERVER_FLOW_CheckEscapeGuaranteed(u8 *p, u8 *a);
extern u8 *BTL_SIDE_GetClientPoke(void *p, u32 i, u8 j);
extern int BTL_POKEPARAM_GetStatRaw(u8 *p, int k);
extern u32 BTL_CALC_Random(u32 range);
extern int BTL_SERVER_FLOW_CommitEscape(u8 *p, u8 *a, int r, int z);

int BTL_SERVER_FLOW_TryEscape(u8 *p, u8 *a, u8 flag)
{
    int ret = 0;
    int k;
    u8 *q;
    u16 lo;
    u16 hi;
    int d;
    u32 t;
    if (BTL_MAIN_GetCompetitorKind((unsigned int **)(*(u8 * *)&((struct Obj00003 *)p)->f4)) == 0) {
        k = BTL_MAIN_PokeIdToClientIdThunk(BTL_POKEPARAM_GetPokeId(a));
        if (k == BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj00003 *)p)->f4)) {
            ret = BTL_SERVER_FLOW_CheckEscapeGuaranteed(p, a);
            if (ret) flag = 1;
        } else {
            flag = 1;
        }
    } else {
        flag = 1;
        ret = 1;
    }
    if (flag == 0) {
        q = BTL_SIDE_GetClientPoke(*(u8 * *)&((struct Obj00003 *)p)->f8, 1, 0);
        if (q) {
            lo = BTL_POKEPARAM_GetStatRaw(a, 0xc);
            hi = BTL_POKEPARAM_GetStatRaw(q, 0xc);
            if (lo <= hi) {
                d = (((int)lo << 12) / (int)hi << 7) >> 12;
                t = d + p[0x786] * 30;
                if (BTL_CALC_Random(0x100) >= t) return 0;
            }
        }
    }
    return BTL_SERVER_FLOW_CommitEscape(p, a, ret, 0);
}
