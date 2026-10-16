/*
 * unit:     no
 * function: GX_DisableBankForSubOBJ
 * address:  0x02080BC0
 * packet:   pkt_02080BAC
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
void GX_DisableBankForSubOBJ(int a0, int a1, int a2, int a3){ disableBankForX_((u16 *)((int)0x2150E60)); }
