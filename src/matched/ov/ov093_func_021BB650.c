/*
 * function: func_021BB650
 * address:  0x021BB650
 * packet:   pkt_ov093_021BB650
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EE8B4  0x021EE8B4  thumb  ov093
 *   func_021EEB64  0x021EEB64  thumb  ov093
 *   func_021EE8F4  0x021EE8F4  thumb  ov093
 *   func_021EE96C  0x021EE96C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021EE8B4(u8 *p, int b);
struct QW;
extern u32 func_021EEB64(struct QW *p, u32 *out);
extern void func_021EE8F4(u8 *p, u8 idx, const void *src, u32 n);
extern u32 func_021EE96C(u8 *p, int a, int b);

int func_021BB650(u8 *p, int a, int b, int c)
{
    u32 i;
    u32 v;

    func_021EE8B4(p + 0x68, b);
    for (i = 0; i < 4; i++) {
        if (p[i * 12 + 0x1f] != 0xff) {
            u32 r = func_021EEB64((struct QW *)(*(u32 *)(p + i * 12 + 0x14)), &v);

            func_021EE8F4(p + 0x68, i, (const void *)r, (v << 22) >> 24);
        }
    }
    return func_021EE96C(p + 0x68, a, c);
}
