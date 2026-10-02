/*
 * function: func_020517E0
 * address:  0x020517E0
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the word at offset 0x60. Filed as the witness for ov094 func_021FD1CC.
 */

int func_020517E0(char *p)
{
    return *(int *)(p + 0x60);
}
