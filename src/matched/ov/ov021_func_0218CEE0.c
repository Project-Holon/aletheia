/*
 * function: func_0218CEE0
 * address:  0x0218CEE0
 * packet:   pkt_ov021_0218CEE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 4-byte getter (ldr r0, [r0, #0x70]; bx lr), a leaf of
 * ov043 func_021F36C0.
 */

typedef unsigned char u8;

void *func_0218CEE0(void *p)
{
    return *(void **)((u8 *)p + 0x70);
}
