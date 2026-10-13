/*
 * function: BTL_SERVER_FLOW_CommitEscape
 * address: 0x021BD708
 * packet: pkt_ov093_021BD708
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_PokeIdToClientIdThunk 0x021B8DDC thumb ov093
 *   BTL_MAIN_GetCompetitorKind 0x021B86E4 thumb ov093
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_MAIN_IsSameTeamClient 0x021B902C thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_CheckEscapePrevented 0x021BD850 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_CheckEscapeMessageSuppressed 0x021BD8AC thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_GetCommPos 0x021B86C0 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *   BTL_CLIENT_SET_Add 0x021D8244 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 b0:1, b1:1, b2:1, rest:5; } Bits;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
struct B;
extern int BTL_MAIN_GetCompetitorKind(unsigned int **p);
extern u8 BTL_MAIN_GetOwnClientId(u8 *p);
extern int BTL_MAIN_IsSameTeamClient(int, int);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern int BTL_SERVER_FLOW_CheckEscapePrevented(u8 *, u8 *);
extern int BTL_SERVER_FLOW_CheckEscapeMessageSuppressed(u8 *, u8 *);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern u8 BTL_MAIN_GetCommPos(u8 **p);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
extern void BTL_CLIENT_SET_Add(struct B *p, int n);

int BTL_SERVER_FLOW_CommitEscape(u8 *p, u8 *a, int r, int z)
{
    int k = BTL_MAIN_PokeIdToClientIdThunk(BTL_POKEPARAM_GetPokeId(a));
    u8 f;
    if (BTL_MAIN_GetCompetitorKind((unsigned int **)(*(u8 * *)&((struct Obj00003 *)p)->f4)) == 0) {
        f = (u8)(BTL_MAIN_IsSameTeamClient(k, BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj00003 *)p)->f4)) == 0 ? 1 : 0);
        if (r == 0 && BTL_POKEPARAM_IsFainted(a) == 0) {
            u32 l;
            l = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 2888);
            r = BTL_SERVER_FLOW_CheckEscapePrevented(p, a);
            BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), l, 2890);
            if (r) return 0;
        }
        if (((Bits *)(p + 0x78a))->b2 == 0) {
            if (z == 0) {
                u32 l;
                l = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 2904);
                r = BTL_SERVER_FLOW_CheckEscapeMessageSuppressed(p, a);
                BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), l, 2906);
            } else {
                r = 0;
            }
            if (r == 0) {
                if (f != 0) {
                    if (BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj00003 *)p)->f4) == 0)
                        BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5c, 0x4b, 0x56a, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
                } else {
                    BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5c, 0x48, 0x56a, 0xffff0000);
                }
            }
            p[0x78a] |= 4;
        }
    } else {
        if (BTL_MAIN_GetCommPos((u8 **)(*(u8 * *)&((struct Obj00003 *)p)->f4)) != 0 && ((Bits *)(p + 0x78a))->b2 == 0) {
            BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, 0xc6, 0xffff0000);
            p[0x78a] |= 4;
        }
    }
    BTL_CLIENT_SET_Add((struct B *)(p + 0x4b8), k);
    return 1;
}
