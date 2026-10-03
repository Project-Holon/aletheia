/*
 * function: func_021D1164
 * address:  0x021D1164
 * packet:   pkt_ov021_021D1164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE684     0x021DE684  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_021D11F4  0x021D11F4  thumb  ov021
 *   func_021D1264  0x021D1264  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021D11F4(u32 *p, u32 b);
extern void func_021D1264(void *p);
extern char d_021DE684[];

void *func_021D1164(u32 heap, u32 v)
{
    u32 *p = func_02030734(heap, 0x1c, 1, d_021DE684, 0x8f);

    p[0] = v;
    func_021D11F4(p, heap);
    func_021D1264(p);
    return p;
}
