/*
 * function: func_021C4D7C
 * address:  0x021C4D7C
 * packet:   pkt_ov021_021C4D7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the 0x18-byte script-runner record.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   d_021DE48C     0x021DE48C  data  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 heap;
    u16 pad;
    void *owner;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
} R;

typedef unsigned char  u8;
extern u16 func_02188C84(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021DE48C[];

R *func_021C4D7C(void *owner, u32 v)
{
    u32 heap = func_02188C84(owner);
    R *r = func_02030734(heap, 0x18, 0, d_021DE48C, 0x61);

    r->heap = heap;
    r->owner = owner;
    r->f8 = 0;
    r->f10 = 0;
    r->f14 = v;
    return r;
}
