/*
 * function: BTL_SERVER_FLOW_StartAfterPokeChange
 * address: 0x021BBD8C
 * packet: pkt_ov093_021BBD8C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_ClearPokeChangeRequests 0x021BB920 thumb ov093
 *   BTL_EVENT_ResetVarStackIfUsed 0x021D74E4 thumb ov093
 *   func_021BBF88 0x021BBF88 thumb ov093
 *   func_021BBF98 0x021BBF98 thumb ov093
 *   BTL_SERVER_FLOW_BuildActionOrder 0x021BC610 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_SERVER_FLOW_ProcMemberChange 0x021BDC98 thumb ov093
 *   BTL_SERVER_FLOW_ProcMemberIn 0x021BD9D4 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_SERVER_FLOW_ProcAction 0x021BCCE0 thumb ov093
 *   BTL_SERVER_FLOW_ProcAfterMemberIn 0x021BDA00 thumb ov093
 *   BTL_SERVER_FLOW_ProcFaintRewards 0x021C5200 thumb ov093
 *   BTL_SERVER_FLOW_CollectChangeRequests 0x021BC4DC thumb ov093
 *   BTL_SERVER_FLOW_ProcTripleShift 0x021C4614 thumb ov093
 *   BTL_SERVER_FLOW_CheckShowdown 0x021BC2B0 thumb ov093
 *   BTL_SERVER_FLOW_ProcClientMemberChange 0x021C6158 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 a; u32 kind : 4; u32 x : 3; u32 y : 3; u32 z : 1; u32 pad : 21; u32 c; u8 d, f; unsigned short pad2; } E;
typedef struct {
    u8 *f0; void *f4; u8 pad8[4]; int *fC; u8 pad10[4]; u32 f14;
    u8 pad18[0x3e0 - 0x18]; u8 g3e0[0xee]; u8 g4ce[0x77c - 0x4ce];
    u8 init; u8 pad77d[5]; u8 n; u8 k; u8 pad784[0x5c]; E e[6];
} S;
extern void BTL_SERVER_ClearPokeChangeRequests(u8 *);
extern void BTL_EVENT_ResetVarStackIfUsed(void);
extern int func_021BBF88(u8 *, int);
extern int func_021BBF98(u8 *, int);
extern u8 BTL_SERVER_FLOW_BuildActionOrder(S *p, int a, E *q, int n);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void BTL_SERVER_FLOW_ProcMemberChange(u8 *p, u8 *a, u8 v);
extern void BTL_SERVER_FLOW_ProcMemberIn(u8 *p, u8 i, u8 a, u8 b, int c);
extern u32 BTL_MAIN_GetRule(void **p);
extern void BTL_SERVER_FLOW_ProcAction(S *p, E *e);
extern int BTL_SERVER_FLOW_ProcAfterMemberIn(u8 *p);
extern int BTL_SERVER_FLOW_ProcFaintRewards(u8 *p);
extern int BTL_SERVER_FLOW_CollectChangeRequests(u8 *p, u8 *out);
extern void BTL_SERVER_FLOW_ProcTripleShift(u8 *p);
extern int BTL_SERVER_FLOW_CheckShowdown(u8 *p);
extern void BTL_SERVER_FLOW_ProcClientMemberChange(u8 *p, u8 *a);

int BTL_SERVER_FLOW_StartAfterPokeChange(S *p, int a)
{
    int *q;
    u32 i;
    int saved;
    int ret;

    p->f14 = 0;
    q = p->fC;
    q[0] = 0;
    q[1] = 0;
    if (p->init == 0) {
        BTL_SERVER_ClearPokeChangeRequests(p->f0);
        BTL_EVENT_ResetVarStackIfUsed();
        saved = func_021BBF88(p->g3e0, 0);
        p->n = BTL_SERVER_FLOW_BuildActionOrder(p, a, p->e, 6);
        p->k = 0;
        for (i = 0; i < p->n; i++) {
            if (p->e[i].kind == 3 && p->e[i].z == 0) {
                if (BTL_POKEPARAM_IsFainted((void *)p->e[i].a) == 0) {
                    BTL_SERVER_FLOW_ProcMemberChange((u8 *)p, (u8 *)p->e[i].a, p->e[i].y);
                    p->e[i].f = 1;
                }
            }
        }
        for (i = 0; i < p->n; i++) {
            if (p->e[i].kind == 3 && p->e[i].z == 0) {
                if (BTL_POKEPARAM_IsFainted((void *)p->e[i].a) != 0) {
                    BTL_SERVER_FLOW_ProcMemberIn((u8 *)p, p->e[i].d, p->e[i].x, p->e[i].y, 1);
                    p->e[i].f = 1;
                }
            }
        }
        if (BTL_MAIN_GetRule(p->f4) == 3) {
            for (i = 0; i < p->n; i++) {
                if (p->e[i].kind == 6 && p->e[i].z == 0)
                    BTL_SERVER_FLOW_ProcAction(p, &p->e[i]);
            }
        }
        p->init = 1;
    }
    BTL_SERVER_FLOW_ProcAfterMemberIn((u8 *)p);
    BTL_SERVER_FLOW_ProcFaintRewards((u8 *)p);
    BTL_SERVER_FLOW_CollectChangeRequests((u8 *)p, p->g4ce);
    ret = 0;
    if (saved == func_021BBF98(p->g3e0, 0)) {
        BTL_SERVER_FLOW_ProcTripleShift((u8 *)p);
        return ret;
    }
    if (BTL_SERVER_FLOW_CheckShowdown((u8 *)p) == 0) {
        BTL_SERVER_FLOW_ProcClientMemberChange((u8 *)p, p->g4ce);
        return 2;
    }
    return 4;
}
