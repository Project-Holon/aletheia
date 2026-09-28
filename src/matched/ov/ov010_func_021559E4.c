/*
 * function: func_021559E4
 * address:  0x021559E4
 * packet:   pkt_ov010_021559E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02155478  0x02155478  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0201A920  0x0201A920  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Task {
    void *f00;
    void *f04;
    u8 pad08[0x30];
    void *f38;
    void *f3c[4];
    u8 pad4c[4];
} Task;

extern void func_02155478(void);
extern void *func_020122C0(void *, int, void (*)(void), int);
extern void func_0201232C(void *, void (*)(void), int);
extern Task *func_020124E8(void *);
extern void *func_020120F4(void *);
extern void *func_02012EBC(void *);
extern void *func_0201A920(int);

void *func_021559E4(void *a, int b, void *c, int d)
{
    Task *t;
    int i;

    if (d != 0)
        c = func_020122C0(a, 0, func_02155478, 0xE8);
    else
        func_0201232C(c, func_02155478, 0xE8);
    t = func_020124E8(c);
    *(void **)((u8 *)t + 0x4C) = func_02012EBC(func_020120F4(a));
    t->f04 = func_020120F4(a);
    t->f00 = a;
    for (i = 0; i < 4; i++)
        t->f3c[i] = func_0201A920(4);
    t->f38 = func_0201A920(4);
    return c;
}
