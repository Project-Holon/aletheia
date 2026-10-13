/*
 * function: SODATEYA_Create
 * address:  0x021C31D4
 * packet:   pkt_ov021_021C31D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates and initialises a 0x10-byte request record.
 *
 * symbols:
 *   d_021DE458     0x021DE458  data  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 heap;
    u16 pad;
    u32 a;
    u32 b;
    u16 n;
} R;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021DE458[];

R *SODATEYA_Create(u32 heap, u32 a, u32 b)
{
    R *r = func_02030734(heap, 0x10, 0, d_021DE458, 0x6A);

    r->heap = heap;
    r->a = a;
    r->b = b;
    r->n = 0;
    return r;
}
