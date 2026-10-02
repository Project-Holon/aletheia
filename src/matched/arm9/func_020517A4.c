/*
 * function: func_020517A4
 * address:  0x020517A4
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a vector at offset 0x34. Filed as the witness for ov094 func_021FD1CC.
 */

typedef struct {
    int x, y, z;
} Vec;

void func_020517A4(char *p, const Vec *v)
{
    *(Vec *)(p + 0x34) = *v;
}
