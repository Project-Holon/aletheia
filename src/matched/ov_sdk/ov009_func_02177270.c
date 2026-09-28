/*
 * function: DWC_SetRecvTimeoutTime
 * address:  0x02177270
 * packet:   pkt_ov009_02177270
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_SetRecvTimeoutTime (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   OS_GetTick   0x020870D0 arm
 *   g_021AB180   0x021AB180 data
 */

extern unsigned long long OS_GetTick(void);
extern char g_021AB180[];

int DWC_SetRecvTimeoutTime(unsigned char aid, unsigned long time)
{
    unsigned long long tick;

    if (*(char **)g_021AB180 == 0)
        return 0;
    *(unsigned long *)(*(char **)g_021AB180 + aid * 0x38 + 0x2c) = time;
    tick = OS_GetTick();
    *(unsigned long long *)(*(char **)g_021AB180 + aid * 0x38 + 0x24) = tick;
    return 1;
}
