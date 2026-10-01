/*
 * function: func_020275C4
 * address:  0x020275C4
 * packet:   pkt_020275C4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf reading the word at +0xB08. Filed as the relocation
 * witness for ov021 func_021CD3A4 (wave A1).
 */

int func_020275C4(void *p)
{
    return *(int *)((char *)p + 0xB08);
}
