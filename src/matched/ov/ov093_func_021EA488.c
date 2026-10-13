/*
 * function: func_021EA488
 * address:  0x021EA488
 * packet:   pkt_ov093_021EA488
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021EA504  0x021EA504  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad00[8];
    char *const *f08;
    u8 pad0c[0x1c - 0xc];
    u32 f1c;
    u32 f20;
    void *f24;
    int f28;
};

extern u8 *func_021E9100(u8 *p, int n);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021EA504(int *st, char *ctx);

void func_021EA488(struct S *s, u8 a, u8 b, u8 c)
{
    u8 *t;
    u8 *o;

    t = func_021E9100((u8 *)s, 4);
    o = func_021B98AC(s->f08, a);
    t[1] = b;
    t[2] = c;
    t[0] = a;
    t[3] = BTL_POKEPARAM_GetPokeId(o);
    s->f1c = 0;
    s->f20 = (u32)func_021EA504;
    s->f24 = s;
    s->f28 = 0;
}
