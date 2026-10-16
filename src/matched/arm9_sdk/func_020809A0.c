/*
 * unit:     no
 * function: GX_ResetBankForSubBG
 * address:  0x020809A0
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
int GX_ResetBankForSubBG(void){ return resetBankForX_((u16 *)((int)0x2150E5E)); }
