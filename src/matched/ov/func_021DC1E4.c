/*
 * function: func_021DC1E4
 * address:  0x021DC1E4
 * packet:   pkt_021DC1E4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Take-and-clear: returns the word at +0x13c; when it is set, clears it and hands back the address of the +0x218 block through out.
 */

typedef unsigned long u32;

u32 func_021DC1E4(char *obj, char **out)
{
    u32 v = *(u32 *)(obj + 0x13c);
    if (v != 0) {
        *(u32 *)(obj + 0x13c) = 0;
        *out = obj + 0x218;
    }
    return v;
}
