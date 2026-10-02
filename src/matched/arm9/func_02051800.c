/*
 * function: func_02051800
 * address:  0x02051800
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the word at offset 0x64. Filed as the witness for ov094 func_021FD1CC.
 */

void func_02051800(char *p, int v)
{
    *(int *)(p + 0x64) = v;
}
