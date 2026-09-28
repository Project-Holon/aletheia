/*
 * function: func_0215ADC4
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
 *   func_02087988  0x02087988  arm
 *   func_020857B0  0x020857B0  arm
 *   func_0208799C  0x0208799C  arm
 */

struct soc {
    char pad0[4];
    unsigned long state;
    char pad1[0x44];
    unsigned char *data;
    unsigned long len;
};

extern unsigned long func_02087988(void);
extern void func_020857B0(void *queue);
extern unsigned long func_0208799C(unsigned long state);

unsigned char *func_0215ADC4(unsigned long *len, struct soc *soc)
{
    unsigned long tmp;
    unsigned long enable = func_02087988();

    tmp = soc->len;

    while (tmp == 0) {
        soc->state = 3;
        func_020857B0(0);
        tmp = soc->len;
    }
    func_0208799C(enable);
    *len = tmp;
    return soc->data;
}
