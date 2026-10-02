/*
 * function: func_021D0AC0
 * address:  0x021D0AC0
 * packet:   pkt_ov021_021D0AC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D0AE4  0x021D0AE4  thumb  ov021
 *   func_021D0B58  0x021D0B58  thumb  ov021
 *   func_021D0BCC  0x021D0BCC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021D0B58(void *a, u8 *p, u32 idx);
extern void func_021D0AE4(u8 *p, u32 c);
extern void func_021D0BCC(u8 *p);

void func_021D0AC0(void *a, u8 *p, u32 c)
{
    if (*(u32 *)(p + 0x130) != 0) {
        func_021D0B58(a, p, c);
    } else {
        func_021D0AE4(p, c);
    }
    func_021D0BCC(p);
}
