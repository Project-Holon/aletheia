/*
 * function: func_0220B144
 * address:  0x0220B144
 * packet:   pkt_0220B144
 * region:   ov187
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220B0F8  0x0220B0F8  thumb  ov187
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned int u32;

extern void func_0220B0F8(u32 a, u32 b);
extern void func_020307B0(void *p);

void func_0220B144(u32 *p, u32 a)
{
    switch (p[0]) {
    case 0:
        break;
    case 1:
        func_0220B0F8(a, 1);
        break;
    }
    func_020307B0(p);
}
