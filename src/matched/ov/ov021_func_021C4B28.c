/*
 * function: func_021C4B28
 * address:  0x021C4B28
 * packet:   pkt_ov021_021C4B28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the 8-byte record and initialises it.
 *
 * symbols:
 *   func_021C4B64  0x021C4B64  thumb  ov021
 *   d_021DE47C     0x021DE47C  data  ov021
 */

typedef unsigned int u32;

typedef struct {
    void *owner;
    u32 f4;
} R;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021C4B64(R *r);
extern char d_021DE47C[];

R *func_021C4B28(void *owner, u32 heap)
{
    R *r = func_02030734(heap, 8, 1, d_021DE47C, 0x163);

    r->owner = owner;
    func_021C4B64(r);
    return r;
}
