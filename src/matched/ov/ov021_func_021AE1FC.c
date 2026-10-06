/*
 * function: func_021AE1FC
 * address:  0x021AE1FC
 * packet:   pkt_ov021_021AE1FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_021AE288  0x021AE288  thumb  ov021
 *   func_021AE890  0x021AE890  thumb  ov021
 *   func_021AE8B4  0x021AE8B4  thumb  ov021
 */

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02188CE8(u8 *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern void *func_02188C7C(unsigned char *p);
struct Ctx;
struct Rec;
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
struct S;
extern int func_021AE288(int a, int b, int c, u16 *d);
extern int func_021AE890(u32 a, u32 b);
extern void func_021AE8B4(struct S *s, u32 a, u32 b, u32 c);

int func_021AE1FC(int a, void *b, int c)
{
    int s0, s4, s8;
    u16 sc;
    void *s14;
    int s10;
    void *r4;
    void *r7;

    s0 = c;
    s4 = func_02188CE8((void *)a);
    r4 = func_021A3074(func_02188CB4((void *)a));
    r7 = func_02188C7C((void *)a);
    s14 = 0;
    s10 = 0;
    while (func_0216DD1C(r7, (struct Rec **)(&s14), (u32 *)(&s10)) == 1) {
        if (s14 != r4 && (b == 0 || b != s14)) {
            s8 = func_021AE288(s4, (int)s14, (int)r4, &sc);
            if (s8 != -1 && func_021AE890((u32)((void *)a), (u32)s14) == 0) {
                func_021AE8B4((struct S *)s0, (u32)s14, s8, sc);
                return 1;
            }
        }
    }
    return 0;
}
