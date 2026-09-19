/*
 * function: func_0202A3CC
 * address:  0x0202A3CC
 * packet:   pkt_0202A230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * Blocked: Data_0209FF1C is named by this function's one pool word
 * (0x0202A3D4) inside the compared range; `literal` has no outside site
 * and the target is neither a string nor a pointer table.  Every concrete
 * byte reproduces.
 *
 * symbols:
 *   Data_0209FF1C  0x0209FF1C  data
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern const u8 Data_0209FF1C[];

u8 func_0202A3CC(u32 idx)
{
    return Data_0209FF1C[idx];
}
