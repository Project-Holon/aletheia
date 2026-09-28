/*
 * function: func_0215B504
 * address:  0x0215B504
 * packet:   pkt_ov009_0215B504
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_SocGetLength (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_02159404  0x02159404  arm  ov009
 *   func_02162C28  0x02162C28  arm  ov009
 *   g_02150FEC  0x02150FEC  data
 */

extern char g_02150FEC[];
extern void func_02159404(void *soc, int flush);
extern long func_02162C28(void *soc);

long func_0215B504(void)
{
    long count;
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 8) == 4)
            func_02159404(soc, 1);
        if (*(unsigned char *)(soc + 9) != 0)
            return func_02162C28(soc);
        count = *(long *)(soc + 0x50);
        if (count != 0)
            return count;
        if (*(unsigned char *)(soc + 8) == 4)
            return count;
        if (*(unsigned char *)(soc + 8) == 10 || *(unsigned char *)(soc + 8) == 11)
            return count;
        return -1;
    }
    return 0;
}
