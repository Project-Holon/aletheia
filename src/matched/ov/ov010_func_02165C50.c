/*
 * function: func_02165C50
 * address:  0x02165C50
 * packet:   pkt_ov010_02165C50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (prints as .word data in ov010.s), the sole blocker
 * of ov011 func_02173368 +00CA: returns the top five bits of the second
 * word of its argument.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 lo : 27;
    u32 hi : 5;
} S;

u32 func_02165C50(S *a0)
{
    return a0->hi;
}
