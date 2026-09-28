/*
 * function: WCM_Finish
 * address:  0x02164EE0
 * packet:   pkt_ov009_02164EE0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_Finish (system.o)
 *
 * symbols:
 *   OS_DisableInterrupts            0x02087988 arm
 *   OS_RestoreInterrupts            0x0208799c arm
 *   g_021AA7D4                      0x021AA7D4 data
 */

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern char g_021AA7D4[];

long WCM_Finish(void)
{
    unsigned long e = OS_DisableInterrupts();
    char *w = *(char **)(g_021AA7D4 + 4);

    if (w == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (*(unsigned char *)(w + 0x1000 + 0x2de) != 1) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    *(void **)(g_021AA7D4 + 4) = 0;
    OS_RestoreInterrupts(e);
    return 0;
}
