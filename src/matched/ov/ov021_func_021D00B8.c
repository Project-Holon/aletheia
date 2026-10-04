/*
 * function: func_021D00B8
 * address:  0x021D00B8
 * packet:   pkt_ov021_021D00B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_02011330  0x02011330  thumb
 *   func_021CFD08  0x021CFD08  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
struct Stream;
extern void *func_02158F74(void *p);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012F38(int base);
extern u16 func_02011330(struct Stream *s);
extern int func_021CFD08(u32 a, u32 b, u8 *c, int d, u32 e);

int func_021D00B8(u32 a, u32 b)
{
    u32 s, k, g;
    void *p;
    void *x;
    u8 *f;
    u16 *out;

    p = func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    f = (u8 *)func_02012F38((int)func_020120F4(x));
    s = (u32)func_02158F74(p);
    k = func_02159B10((void *)a, (void *)b);
    g = func_02011330((struct Stream *)a);
    out = func_02159AE8((void *)a, (void *)b);
    *out = func_021CFD08(s, (u32)x, f, k, g);
    return 0;
}
