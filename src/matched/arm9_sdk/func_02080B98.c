/*
 * function: GX_DisableBankForLCDC
 * address:  0x02080B98
 * packet:   pkt_02080B98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   disableBankForX_  0x02080A18  arm
 */

typedef unsigned short u16;
extern int disableBankForX_(u16 *g3bit);
void GX_DisableBankForLCDC(void){ disableBankForX_((void *)0x02150E4C); }
