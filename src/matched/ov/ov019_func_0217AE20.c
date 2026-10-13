/*
 * function: UNION_CHARA_ClearTable
 * address:  0x0217AE20
 * packet:   pkt_ov019_0217AE20
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     unlabelled leaf at the start of ov019 (prints as .word);
 *           called from UNION_ONESELF_ColosseumExitMain.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;

void func_02082BCC(void *p, int v, int n);

void UNION_CHARA_ClearTable(u8 *w)
{
    func_02082BCC(w + 0x2e88, 0, 0x258);
}
