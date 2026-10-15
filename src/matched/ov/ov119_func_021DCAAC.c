/*
 * function: POKETRADE_PROC_StartRequest0
 * address:  0x021DCAAC
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Send a one-descriptor request with the timer base 0xc6000.
 *
 * symbols:
 *   POKETRADE_PROC_AllocTradeWork  0x021DC854  thumb  ov119
 *   POKETRADE_PROC_InitTradeWork  0x021DC894  thumb  ov119
 */

extern void *POKETRADE_PROC_AllocTradeWork(void *a, int t);
extern int POKETRADE_PROC_InitTradeWork(int a, int b, char *q, char *p, int n);

void POKETRADE_PROC_StartRequest0(void *a, int b, int c)
{
    int r = (int)POKETRADE_PROC_AllocTradeWork(a, 0xc6000);

    POKETRADE_PROC_InitTradeWork((int)a, b, (char *)c, (char *)r, 0);
}

