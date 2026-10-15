/*
 * function: PSEL_UpdateTcbl
 * address:  0x021BAF30
 * packet:   pkt_021BAF30
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TCBL_Main  0x020310C4  arm
 *   PSEL_UpdateWindows  0x021BAF48  thumb  ov223
 *
 * Addresses are Black-image addresses.
 */

struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern int PSEL_UpdateWindows(char *p);

void PSEL_UpdateTcbl(int *p)
{
    TCBL_Main((struct Tcbl *)p[0x95]);
    PSEL_UpdateWindows((char *)p);
}
