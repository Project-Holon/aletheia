/*
 * function: func_0217B044
 * address:  0x0217B044
 * packet:   pkt_ov018_0217B044
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0217B084  0x0217B084  thumb  ov018
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int f00;
    int f04;
    int pad[2];
    int f10;
    u16 f14;
    u16 f16;
} Task;

extern void *func_020122C0(void *a, u32 b, void (*fn)(), u32 size);
extern Task *func_020124E8(void *task);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *func_021A3074(unsigned char *p);
extern void func_0217B084();

void *func_0217B044(void *a, int b, int c, u16 d, u16 e, int f)
{
    void *t;
    Task *p;

    t = func_020122C0(a, 0, func_0217B084, sizeof(Task));
    p = func_020124E8(t);
    MI_CpuFill8(p, 0, sizeof(Task));
    p->f00 = b;
    p->f04 = func_021A3074((void *)c);
    p->f16 = d;
    p->f14 = e;
    p->f10 = f;
    return t;
}
