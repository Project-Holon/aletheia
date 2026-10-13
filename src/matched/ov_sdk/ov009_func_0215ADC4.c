/*
 * function: udp_read_raw
 * address:  0x0215ADC4
 * packet:   pkt_ov009_0215ADC4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      udp_read_raw (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

struct soc {
    char pad0[4];
    unsigned long state;
    char pad1[0x44];
    unsigned char *data;
    unsigned long len;
};

extern unsigned long OS_DisableInterrupts(void);
extern void OS_SleepThread(void *queue);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

unsigned char *udp_read_raw(unsigned long *len, struct soc *soc)
{
    unsigned long tmp;
    unsigned long enable = OS_DisableInterrupts();

    tmp = soc->len;

    while (tmp == 0) {
        soc->state = 3;
        OS_SleepThread(0);
        tmp = soc->len;
    }
    OS_RestoreInterrupts(enable);
    *len = tmp;
    return soc->data;
}
