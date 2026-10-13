/*
 * function: qr2_keybuffer_add
 * address:  0x0219B5EC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Appends a byte to the buffer at +0x100 of the block while the count is
 * under 0xfe and the value is 1..0xfe; 0 when either bound is hit.
 *
 * symbols:
 *

 */

int qr2_keybuffer_add(char *p, int v)
{
    int n = *(int *)(p + 0x100);

    if (n >= 0xfe) return 0;
    if (v < 1 || v > 0xfe) return 0;
    *(int *)(p + 0x100) = n + 1;
    *(unsigned char *)(p + n) = v;
    return 1;
}


