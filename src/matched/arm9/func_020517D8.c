/*
 * function: func_020517D8
 * address:  0x020517D8
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the word at offset 0x5c. Filed as the witness for ov094 func_021FD1CC.
 */

void func_020517D8(char *p, int v)
{
    *(int *)(p + 0x5c) = v;
}
