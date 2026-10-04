/*
 * function: func_021DE70C
 * address:  0x021DE70C
 * packet:   pkt_ov119_021DE70C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_021D8F20  0x021D8F20  thumb  ov119
 *   func_020399A8  0x020399A8  arm
 *   func_020173EC  0x020173EC  thumb
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DE6AC  0x021DE6AC  thumb  ov119
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D8A24(void *p);
extern int func_021D8F20(void *p, int idx);
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_020173EC(void);
extern int func_0203D3A8(u32 h, u16 b, u16 c, void *q);
extern void func_021D8E84(void *p, int next);
extern void func_021DE6AC(char *p);

void func_021DE70C(void *p)
{
    u8 v;
    if (func_021D8A24(p) != 0) {
        v = func_021D8F20(p, 0);
        if (func_0203D3A8((u32)func_020399A8(), 0xC16, func_020173EC(), &v) == 0) {
            return;
        }
    }
    func_021D8E84(p, (int)func_021DE6AC);
}
