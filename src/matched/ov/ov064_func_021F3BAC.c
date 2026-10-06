/*
 * function: func_021F3BAC
 * address: 0x021F3BAC
 * packet: pkt_ov064_021F3BAC
 * region: ov064
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * checks: 1 own BE6E8 confirms four args/int return and matched accessor chain confirms pointer forwarding; 2 ov064/065 callers refreshed; 3 _Bool zero/flag retained, 4 two initialisation-order variants stayed DIFF4, 5 idioms/neighbours refreshed. W75 three fixed runs, baseline explain, first permuter300 reached EXACT* at candidate102; fixed one and shard verify confirmed it.
 * lever: initialise flag after the callee result has been captured; the
 * saved zero is then materialised before the saved one. The trailing
 * halfword at 021F3BD6 is zero alignment padding.
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021BE6E8 0x021BE6E8 thumb ov021
 */
struct Obj;
extern void *func_020124E4(struct Obj *p);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int func_021BE6E8(int a, int b, int c, int d);

int func_021F3BAC(void *p)
{
    unsigned char zero;
    unsigned char flag;
    int v;
    int s;
    int tmp;
    s = func_02188D2C(func_0201210C(func_020124E4(p)));
    zero = 0;
    tmp = func_021BE6E8(s, zero, 1, zero);
    v = tmp;
    flag = 1;
    if (v < 0x5000)
        flag = zero;
    return flag;
}
