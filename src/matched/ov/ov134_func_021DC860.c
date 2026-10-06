/*
 * function: func_021DC860
 * address: 0x021DC860
 * packet: pkt_ov134_021DC860
 * region: ov134
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Unlabelled leaf at the start of ov134 (the listing prints it as .word
 * data); referenced as 0x021DC861 from the table word at 021DCCA0.
 */

typedef struct {
    char pad0[0xF0];
    int tbl[1];
} Tbl;

int func_021DC860(int i, Tbl *p)
{
    return p->tbl[i];
}
