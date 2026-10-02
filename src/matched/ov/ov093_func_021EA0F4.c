/*
 * function: func_021EA0F4
 * address:  0x021EA0F4
 * packet:   pkt_ov093_021EA0F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021EA160  0x021EA160  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad00[0x1c];
    u32 f1c;
    u32 f20;
    void *f24;
    int f28;
};

extern u8 *func_021E9100(u8 *p, int n);
extern int func_021EA160(int *st, char *ctx);

void func_021EA0F4(struct S *s, u16 a, u8 b, int c)
{
    u8 *t;

    t = func_021E9100((u8 *)s, 0xc);
    *(int *)(t + 4) = c;
    t[0xa] = b;
    *(u16 *)(t + 8) = 0;
    *(u16 *)t = a;
    s->f1c = 0;
    s->f20 = (u32)func_021EA160;
    s->f24 = s;
    s->f28 = 0;
}
