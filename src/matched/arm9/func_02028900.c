/*
 * function: func_02028900
 * address:  0x02028900
 * packet:   pkt_02028900
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */

typedef unsigned char u8;
typedef signed int    s32;

typedef struct {
    u8   pad00[8];
    void *f08;
    void *f0c;
    void *f10;
    u8   pad14[0x20 - 0x14];
    s32  f20;
    s32  f24[1];
    u8   pad28[0xa0 - 0x28];
    u8   fa0;
    volatile u8 fa1;
} Obj;

typedef struct {
    s32 op;
    s32 a;
    s32 b;
} Ins;

extern s32 _s32_div_f(s32 a, s32 b);

void *func_02028900(Obj *p)
{
    void *cur;
    s32 n;
    s32 i;
    s32 pc;
    Ins *ins;
    void *stack[1];

    cur = p->f08;
    if (p->f0c != 0) {
        cur = p->f0c;
    }
    if (p->f10 != 0) {
        cur = p->f10;
    }
    n = p->f20;
    pc = p->fa0;
    for (i = 0; i < n; i++) {
        stack[i] = (void *)p->f24[i];
    }
    while (pc != p->fa1) {
        ins = (Ins *)((char *)p + 0x28) + pc;
        if (ins->op == 3) {
            stack[n++] = cur;
        } else if (ins->op == 4) {
            n--;
            cur = stack[n];
        } else if ((unsigned)(ins->op - 5) <= 2) {
            cur = (void *)ins->a;
        }
        pc = (pc + 1) % 10;
    }
    return cur;
}
