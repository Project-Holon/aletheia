/*
 * function: func_0215AE18
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
 *   func_02159404  0x02159404  arm  ov009
 *   func_02087988  0x02087988  arm
 *   func_020857B0  0x020857B0  arm
 *   func_0208799C  0x0208799C  arm
 *   func_020858D8  0x020858D8  arm
 */

extern void func_02159404(void *soc, int flush);
extern unsigned long func_02087988(void);
extern void func_020857B0(void *queue);
extern unsigned long func_0208799C(unsigned long state);
extern void func_020858D8(void);

unsigned char *func_0215AE18(unsigned long *len, char *soc)
{
    unsigned long enable;
    unsigned long n;

    if (*(unsigned char *)(soc + 8) == 4)
        func_02159404(soc, 1);
    if (*(unsigned long *)(soc + 0x50) == 0 && *(unsigned char *)(soc + 8) == 4) {
        enable = func_02087988();
        while (*(unsigned long *)(soc + 0x50) == 0 && *(unsigned char *)(soc + 8) == 4) {
            *(unsigned long *)(soc + 4) = 2;
            func_020857B0(0);
        }
        func_0208799C(enable);
    } else {
        func_020858D8();
    }
    n = *(unsigned long *)(soc + 0x50);
    *len = n;
    if (n != 0)
        return *(unsigned char **)(soc + 0x4c);
    return 0;
}
