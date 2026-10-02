/*
 * function: func_021BE2A8
 * address:  0x021BE2A8
 * packet:   pkt_ov021_021BE2A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE390  0x021DE390  data
 *   func_02030734  0x02030734  arm
 *   func_02047CFC  0x02047CFC  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 heap;
    void *obj;
    unsigned char rest[0x40];
} Obj;

extern int d_021DE390;
extern void *func_02030734(u16 heap, u32 size, u32 clear, const void *file, u32 line);
extern void *func_02047CFC(u16, u16, u16);

Obj *func_021BE2A8(u32 a, u32 b, u32 heap)
{
    Obj *o = func_02030734(heap, sizeof(Obj), 1, &d_021DE390, 0x4c);

    o->obj = func_02047CFC(a, b, heap);
    o->heap = heap;
    return o;
}
