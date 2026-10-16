/*
 * unit:     no
 * function: GX_ResetBankForSubOBJ
 * address:  0x020809B4
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
void GX_ResetBankForSubOBJ(void){ resetBankForX_((u16 *)((int)0x2150E60)); }
