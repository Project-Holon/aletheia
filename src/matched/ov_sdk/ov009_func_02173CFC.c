/*
 * function: func_02173CFC
 * address:  0x02173CFC
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_InitClWaitTimeout: clears the wait flag and stamps the current tick.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   OS_GetTick  0x020870D0  arm
 */

extern int func_02175F3C(void);
extern unsigned long long OS_GetTick(void);

void func_02173CFC(void)
{
    unsigned long long t;

    ((char *)func_02175F3C())[0x62e] = 0;
    t = OS_GetTick();
    *(unsigned long long *)(func_02175F3C() + 0x670) = t;
}
