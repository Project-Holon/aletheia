/*
 * function: BOX2_MAIN_Main
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
 *   BOX2_SEQ_UpdatePrintQueue  0x021E1E34  thumb  ov170
 *   PROCSYS_Main  0x02031330  arm  arm9
 *
 * Re-derive d[2] from d[1] then test the entry; 0 means accepted.
 */


extern unsigned int PROCSYS_Main(void *);
extern int BOX2_SEQ_UpdatePrintQueue(char *p, int *state);
int BOX2_MAIN_Main(int a, int b, int c, int *d)
{
    d[2] = PROCSYS_Main((void *)d[1]);
    if (BOX2_SEQ_UpdatePrintQueue((char *)d, (int *)b) == 0)
        return 1;
    return 0;
}
