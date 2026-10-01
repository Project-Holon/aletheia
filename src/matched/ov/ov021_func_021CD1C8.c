/*
 * function: func_021CD1C8
 * address:  0x021CD1C8
 * packet:   pkt_ov021_021CD1C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x28-byte zeroed holder on the given heap and opens archive 0xAF into its first word.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_021DE5D4  0x021DE5D4  data  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct {
    void *arc;
} Holder;

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void *func_020490F4(u32 id, u32 heap);
extern const char d_021DE5D4[];

Holder *func_021CD1C8(u32 heap)
{
    Holder *h = func_02030734(heap, 0x28, 1, d_021DE5D4, 0x5b);
    h->arc = func_020490F4(0xaf, heap);
    return h;
}
