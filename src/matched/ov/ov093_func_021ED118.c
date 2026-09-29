/*
 * function: func_021ED118
 * address:  0x021ED118
 * packet:   pkt_ov093_021ED118
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED158  0x021ED158  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021ED158(int *, u8 *);

struct T {
    u16 h;
    int a;
    int b;
    u8 e;
    u8 f;
    u32 d;
};

void func_021ED118(u8 *p, int a, int b, u16 c, u32 d, int e, u8 f)
{
    struct T *q = (struct T *)(p + 0xf0);

    *(u16 *)(p + 0xf0) = c;
    q->a = a;
    q->b = b;
    q->e = e;
    q->f = f;
    q->d = d;
    *(int *)(p + 0xe0) = 0;
    *(int (**)(int *, u8 *))(p + 0xe4) = func_021ED158;
    *(u8 **)(p + 0xe8) = p;
    *(int *)(p + 0xec) = 0;
}
