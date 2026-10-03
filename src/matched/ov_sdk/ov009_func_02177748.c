/*
 * function: func_02177748
 * address:  0x02177748
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_ResetLastSomeDataRecvTimeByAid: stamps the current tick into the aid's transport record.
 *
 * symbols:
 *   OS_GetTick  0x020870D0  arm
 *   func_02177770  0x02177770  arm  ov009
 */

extern unsigned long long OS_GetTick(void);
extern int func_02177770(int i);

void func_02177748(int aid)
{
    unsigned long long t = OS_GetTick();

    *(unsigned long long *)(func_02177770(aid) + 0x30) = t;
}
