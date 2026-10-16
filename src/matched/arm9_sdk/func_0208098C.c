/*
 * unit:     no
 * function: GX_ResetBankForClearImage
 * address:  0x0208098C
 * packet:   pkt_02080978
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   resetBankForX_  0x020808BC  arm
 */

typedef unsigned short u16;
extern int resetBankForX_(u16 *g3bit);
void GX_ResetBankForClearImage(int a0, int a1, int a2, int a3){ resetBankForX_((u16 *)((int)0x2150E58)); }
