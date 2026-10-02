/*
 * function: func_02027A20
 * address:  0x02027A20
 * packet:   pkt_02027A20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter for the word at offset 0xC of a task menu object; witness for
 * the call at +0x16 of ov119 func_021DA318.
 */

unsigned func_02027A20(char *p)
{
    return *(unsigned *)(p + 0xC);
}
