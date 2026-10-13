/*
 * function: CPSi_TcpReadRaw
 * address:  0x0215AE18
 * packet:   pkt_ov009_0215AE18
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_TcpReadRaw (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   _tcp_send_ack  0x02159404  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_YieldThread  0x020858D8  arm
 */

extern void _tcp_send_ack(void *soc, int flush);
extern unsigned long OS_DisableInterrupts(void);
extern void OS_SleepThread(void *queue);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void OS_YieldThread(void);

unsigned char *CPSi_TcpReadRaw(unsigned long *len, char *soc)
{
    unsigned long enable;
    unsigned long n;

    if (*(unsigned char *)(soc + 8) == 4)
        _tcp_send_ack(soc, 1);
    if (*(unsigned long *)(soc + 0x50) == 0 && *(unsigned char *)(soc + 8) == 4) {
        enable = OS_DisableInterrupts();
        while (*(unsigned long *)(soc + 0x50) == 0 && *(unsigned char *)(soc + 8) == 4) {
            *(unsigned long *)(soc + 4) = 2;
            OS_SleepThread(0);
        }
        OS_RestoreInterrupts(enable);
    } else {
        OS_YieldThread();
    }
    n = *(unsigned long *)(soc + 0x50);
    *len = n;
    if (n != 0)
        return *(unsigned char **)(soc + 0x4c);
    return 0;
}
