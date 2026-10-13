/*
 * function: garprequest
 * address:  0x0215B5C4
 * packet:   pkt_ov009_0215B5C4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      garprequest (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   send_arprequest  0x02157E54  arm  ov009
 *   OS_Sleep  0x02085A38  arm
 *   func_020870D0  0x020870D0  arm
 *   g_021A826C  0x021A826C  data
 */

extern char g_021A826C[];
extern void send_arprequest(unsigned long ip);
extern void OS_Sleep(unsigned long msec);
extern unsigned long long func_020870D0(void);

int garprequest(void)
{
    unsigned long start;

    send_arprequest(*(unsigned long *)(g_021A826C + 0x50));
    OS_Sleep(100);
    send_arprequest(*(unsigned long *)(g_021A826C + 0x50));
    start = (unsigned long)(func_020870D0() >> 16);
    while ((*(int (**)(void))(g_021A826C + 0x18))() != 0 && (int)((unsigned long)(func_020870D0() >> 16) - start) < 0x17) {
        if (*(unsigned char *)(g_021A826C + 1) != 0)
            return 0;
        OS_Sleep(100);
    }
    return 1;
}
