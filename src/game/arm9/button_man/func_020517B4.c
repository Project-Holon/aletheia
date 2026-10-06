/*
 * function: func_020517B4
 * address:  0x020517B4
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Copies the three halfwords at offset 0x50 out. Filed as the witness for ov094 func_021FD1CC.
 */

typedef struct {
    short x, y, z;
} Vec16;

void func_020517B4(char *p, Vec16 *out)
{
    *out = *(Vec16 *)(p + 0x50);
}
