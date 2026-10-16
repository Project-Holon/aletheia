/*
 * function: GX_ResetBankForTex
 * address:  0x02080964
 * packet:   pkt_02080964
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
int GX_ResetBankForTex(void){ return resetBankForX_((void *)0x02150E54); }
