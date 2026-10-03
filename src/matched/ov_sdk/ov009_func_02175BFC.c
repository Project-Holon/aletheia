/*
 * function: func_02175BFC
 * address:  0x02175BFC
 * packet:   pkt_ov009_02175BFC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RequestSuspendMatchInit (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_020870D0  0x020870D0  arm
 */

extern int func_02175F3C(void);
extern unsigned long long func_020870D0(void);

void func_02175BFC(int suspend, void *callback, void *suspendResultParam)
{
    *(char *)(func_02175F3C() + 0x30) = 0;
    *(int *)(func_02175F3C() + 0x2c) = suspend;
    *(void **)(func_02175F3C() + 0x34) = callback;
    *(void **)(func_02175F3C() + 0x38) = suspendResultParam;
    *(unsigned long long *)(func_02175F3C() + 0x20) = 0;
    {
        unsigned long long tick = func_020870D0();
        *(unsigned long long *)(func_02175F3C() + 0x3c) = tick;
    }
    *(int *)(func_02175F3C() + 0x48) = 1;
}
