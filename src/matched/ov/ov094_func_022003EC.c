/*
 * function: func_022003EC
 * address:  0x022003EC
 * packet:   pkt_ov094_022003EC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MCSS_TOOL_MakeAddWorkFromPP  0x02017100  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   MCSS_TOOL_SetSpindaSpotHook  0x020172AC  thumb
 */
typedef unsigned int u32;

typedef struct {
    int pad00;              /* 0x00 */
    void *obj;              /* 0x04 */
} Work;

struct Stats;
extern void MCSS_TOOL_MakeAddWorkFromPP(void *p, struct Stats *out, u32 lvl);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void MCSS_TOOL_SetSpindaSpotHook(int a0, int a1);

void func_022003EC(Work *w, void *p, int *a, int flags)
{
    int v = 1;

    if (flags & 1)
        v = 0;
    MCSS_TOOL_MakeAddWorkFromPP(p, (struct Stats *)a, v);
    MCSS_TOOL_SetSpindaSpotHook((int)w->obj, func_02017E1C(p, 0, 0));
}
