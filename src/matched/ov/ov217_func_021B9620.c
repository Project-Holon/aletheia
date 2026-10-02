/*
 * function: func_021B9620
 * address: 0x021B9620
 * packet: pkt_ov217_021B9620
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: zero halfword alignment at 021B969E.
 * state domain: procsys 020315F0 resets subseq to 0 before this main callback;
 *   97B8 returns 1, 97BC returns 1..4, 97F8 returns 1/2/4, 9824 returns 1/3/4.
 *   96C8/9774 stores only those new states; state 4 exits immediately.
 *   Full lifecycle/body proof: scratchpad/overlay-goal-20260930-w32/S23/state-proof.md.
 * symbols:
 *   func_021B96A0 0x021B96A0 thumb ov217
 *   func_02012204 0x02012204 thumb
 *   func_021C09FC 0x021C09FC thumb ov217
 *   func_021B97B8 0x021B97B8 thumb ov217
 *   func_021B97BC 0x021B97BC thumb ov217
 *   func_021B97F8 0x021B97F8 thumb ov217
 *   func_021B9824 0x021B9824 thumb ov217
 *   func_021B99EC 0x021B99EC thumb ov217
 *   func_021B9854 0x021B9854 thumb ov217
 *   func_021B96C8 0x021B96C8 thumb ov217
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Ctx;
extern void func_021B96A0(u32);
extern u32 func_02012204(const struct Ctx *);
extern void func_021C09FC(void *);
extern u32 func_021B97B8(void *);
extern u32 func_021B97BC(u8 *);
extern u32 func_021B97F8(u32);
extern u32 func_021B9824(u32);
extern void func_021B99EC(const void *p);
extern void func_021B9854(void *);
extern void func_021B96C8(void *, int *, int);
int func_021B9620(void *unused, u32 *state, u32 unused2, u32 *p)
{
    u32 next;
    func_021B96A0((u32)p);
    if (func_02012204((const struct Ctx *)p[1]) != 0)
        func_021C09FC((void *)p[3]);
    switch (*state) {
    case 0: next = func_021B97B8(p); break;
    case 1: next = func_021B97BC((u8 *)p); break;
    case 2: next = func_021B97F8((u32)p); break;
    case 3: next = func_021B9824((u32)p); break;
    case 4: return 1;
    }
    func_021B99EC(p);
    func_021B9854(p);
    if (*state != next)
        func_021B96C8(p, (int *)state, next);
    return 0;
}
