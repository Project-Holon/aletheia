/*
 * function: WCMi_ResetKeepAliveAlarm
 * address:  0x02165AF4
 * packet:   pkt_ov009_02165AF4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_ResetKeepAliveAlarm (system.o)
 *
 * symbols:
 *   OS_DisableInterrupts            0x02087988 arm
 *   OS_CancelAlarm                  0x020873f8 arm
 *   OS_SetAlarm                     0x0208738c arm
 *   OS_RestoreInterrupts            0x0208799c arm
 *   g_021AA7D4                      0x021AA7D4 data
 *   WcmKeepAliveAlarm               0x02165b5c arm
 */

extern unsigned long OS_DisableInterrupts(void);
extern void OS_CancelAlarm(void *alarm);
extern void OS_SetAlarm(void *alarm, unsigned long long tick, void (*handler)(void), void *arg);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern char g_021AA7D4[];
extern void WcmKeepAliveAlarm(void);

void WCMi_ResetKeepAliveAlarm(void)
{
    unsigned long e = OS_DisableInterrupts();
    char *w;

    w = *(char **)(g_021AA7D4 + 4);
    OS_CancelAlarm(w + 0x1000 + 0x294);
    w = *(char **)(g_021AA7D4 + 4);
    if (*(unsigned char *)(w + 0x1000 + 0x2de) == 9)
        OS_SetAlarm(w + 0x1000 + 0x294, 0x022f5341, WcmKeepAliveAlarm, 0);
    OS_RestoreInterrupts(e);
}
