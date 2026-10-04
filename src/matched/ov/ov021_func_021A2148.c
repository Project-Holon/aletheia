/*
 * function: func_021A2148
 * address:  0x021A2148
 * packet:   pkt_ov021_021A2148
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf (ldr r0,[r0,#0x14]; ldr r3,[pc]; bx r3), filed
 * for lane S30 (callee of ov028 functions).
 *
 * symbols:
 *   func_0218E188 0x0218E188 thumb ov021
 */

int func_0218E188(unsigned char *o);

int func_021A2148(unsigned char *o)
{
    return func_0218E188((unsigned char *)(*(int *)(o + 0x14)));
}
