/*
 * function: func_021EA1B8
 * address:  0x021EA1B8
 * packet:   pkt_ov093_021EA1B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021EA230  0x021EA230  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad00[4];
    u8 *f04;
    u8 pad08[0x1c - 8];
    u32 f1c;
    u32 f20;
    void *f24;
    int f28;
};

extern u8 *func_021E9100(u8 *p, int n);
extern u32 func_021CD9E0(u8 *p);
extern int func_021EA230(int *st, char *ctx);

void func_021EA1B8(struct S *s, u16 a, u8 b, int c)
{
    u8 *t;

    if (func_021CD9E0(s->f04) == 0) {
        t = func_021E9100((u8 *)s, 0xc);
        *(int *)(t + 4) = c;
        t[0xa] = b;
        *(u16 *)(t + 8) = 0;
        *(u16 *)t = a;
        s->f1c = 0;
        s->f20 = (u32)func_021EA230;
        s->f24 = s;
        s->f28 = 0;
    }
}
