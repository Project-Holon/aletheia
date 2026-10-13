/*
 * function: IRC_COMPATIBLE_ProcMain
 * address: 0x021B69F8
 * packet: pkt_ov101_021B69F8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * 2026-10-05: the callee IRC_COMPATIBLE_StepRunnerIsBusy is declared u32 here. Its matched definition
 * (ov101_func_021B6BFC.c) is void but tail-calls PROCSYS_Main, which returns u32, and
 * this caller tests r0 after the call. With the void declaration the old draft did not match.
 *
 * symbols:
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   IRC_COMPATIBLE_StepRunnerIsBusy 0x021B6BFC thumb ov101
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int GFL_USE_IsBgmFading(void);
extern u32 IRC_COMPATIBLE_StepRunnerIsBusy(u8 *);
int IRC_COMPATIBLE_ProcMain(void *task, u32 *state, void *unused, u8 *p) {
    switch (*state) {
    case 0:
        if (!GFL_USE_IsBgmFading()) *state += 1;
        break;
    case 1:
        if (IRC_COMPATIBLE_StepRunnerIsBusy(p + 4) == 0)
            (*(void (**)(u8 *, u8 *))(p + 20))(p, p + 24);
        if (*(u32 *)(p + 28)) return 1;
        break;
    }
    return 0;
}
