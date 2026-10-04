/*
 * function: func_0218A324
 * address:  0x0218A324
 * packet:   pkt_ov096_0218A324
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D67A8  0x021D67A8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u8 *func_0218A2FC(u8 *p, u8 i);
struct QL;
extern u16 func_021D67A8(struct QL *p);

void func_0218A324(u8 *p)
{
    u8 *s;
    int i;
    u16 h;
    s = func_0218A2FC(p, p[0x95]);
    for (i = 0; i < 4; i++) {
        h = *(u16 *)(p + p[0x95] * 8 + i * 2 + 0x4c);
        if (h == func_021D67A8((struct QL *)s))
            return;
        if (h == 0) {
            *(u16 *)(p + p[0x95] * 8 + 0x4c + i * 2) =func_021D67A8((struct QL *)s);
            return;
        }
    }
}
