/*
 * function: func_02051818
 * address:  0x02051818
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the word at offset 0x68. Filed as the witness for ov094 func_021FD1CC.
 */

void func_02051818(char *p, int v)
{
    *(int *)(p + 0x68) = v;
}
