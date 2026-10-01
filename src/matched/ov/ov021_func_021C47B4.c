/*
 * function: func_021C47B4
 * address:  0x021C47B4
 * packet:   pkt_ov021_021C47B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the 0xC-byte field-object record and initialises it.
 *
 * symbols:
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C90  0x02188C90  thumb  ov021
 *   func_021C47FC  0x021C47FC  thumb  ov021
 *   d_021DE468     0x021DE468  data  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    void *owner;
    u32 obj;
    u32 f8;
} R;

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C90(u8 *p);
extern void func_021C47FC(R *r);
extern char d_021DE468[];

R *func_021C47B4(u8 *owner, u32 heap)
{
    R *r = func_02030734(heap, 0xC, 1, d_021DE468, 0x56);

    r->owner = owner;
    r->obj = func_02188C90((u8 *)func_021ABE14(owner));
    func_021C47FC(r);
    return r;
}
