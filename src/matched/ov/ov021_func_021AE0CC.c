/*
 * function: func_021AE0CC
 * address:  0x021AE0CC
 * packet:   pkt_ov021_021AE0CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AE1FC  0x021AE1FC  thumb  ov021
 *   func_0215A4C8  0x0215A4C8  thumb  ov010
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0218B6AC  0x0218B6AC  thumb  ov021
 *   func_021AE930  0x021AE930  thumb  ov021
 *   func_0215A438  0x0215A438  thumb  ov010
 *   func_021AE8D4  0x021AE8D4  thumb  ov021
 *   func_021AE8B4  0x021AE8B4  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rec {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
} Rec;

extern int func_021AE1FC(int a, void *b, int c);
extern u32 func_0215A4C8(u16 a);
extern void *func_02188C80(void *p);
extern int func_0218B6AC(void *ctx);
extern int func_021AE930(int a, u32 b);
extern void func_0215A438(int a, int b, Rec *src);
extern u32 func_021AE8D4(u32 a, u16 b);
struct S;
extern void func_021AE8B4(struct S *s, u32 a, u32 b, u32 c);

int func_021AE0CC(int a)
{
    Rec b;
    Rec c;
    u32 kind;
    u32 n;
    int z = 0;
    int ret = 0;

    if (func_021AE1FC(a, 0, (int)(&b)) == 1) {
        kind = func_0215A4C8(b.f10);
        n = func_0218B6AC(func_02188C80((void *)a));
        if (kind == 0) {
            if (n < 2 || func_021AE1FC(a, (void *)b.f0, (int)(&c)) == 0) {
                ret = func_021AE930(a, b.f0);
                b.f14 = 0;
                func_0215A438(ret, 0, &b);
            } else {
                ret = func_021AE930(a, b.f0);
                b.f14 = 2;
                func_0215A438(ret, z, &b);
                c.f14 = 2;
                func_0215A438(ret, 1, &c);
            }
        } else if (kind == 1) {
            if (n >= 2) {
                func_021AE8B4((struct S *)(&c), func_021AE8D4(b.f0, b.f10), b.f4, (u16)b.f8);
                ret = func_021AE930(a, b.f0);
                b.f14 = 1;
                func_0215A438(ret, z, &b);
                c.f14 = 1;
                func_0215A438(ret, 1, &c);
            }
        } else if (kind == 2 || kind == 3) {
            if (n >= 3) {
                ret = func_021AE930(a, b.f0);
                b.f14 = z;
                func_0215A438(ret, z, &b);
            }
        }
    }
    return ret;
}
