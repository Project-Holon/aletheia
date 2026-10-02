/*
 * function: func_020517E8
 * address:  0x020517E8
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the word at offset 0x60. Filed as the witness for ov094 func_021FD1CC.
 */

void func_020517E8(char *p, int v)
{
    *(int *)(p + 0x60) = v;
}
