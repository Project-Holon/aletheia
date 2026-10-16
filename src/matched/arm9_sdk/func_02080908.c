/*
 * unit:     no
 * function: GX_ResetBankForOBJ
 * address:  0x02080908
 * packet:   pkt_020808F4
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
void GX_ResetBankForOBJ(void){ resetBankForX_((u16 *)((int)0x2150E50)); }
