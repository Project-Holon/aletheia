/*
 * function: func_021DC900
 * address:  0x021DC900
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E1E34  0x021E1E34  thumb  ov170
 *   PROCSYS_Main  0x02031330  arm  arm9
 *
 * Re-derive d[2] from d[1] then test the entry; 0 means accepted.
 */


extern unsigned int PROCSYS_Main(void *);
extern int func_021E1E34(char *p, int *state);
int func_021DC900(int a, int b, int c, int *d)
{
    d[2] = PROCSYS_Main((void *)d[1]);
    if (func_021E1E34((char *)d, (int *)b) == 0)
        return 1;
    return 0;
}
