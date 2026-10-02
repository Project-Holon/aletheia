/*
 * function: func_0217413C
 * address: 0x0217413C
 * packet: pkt_ov012_0217413C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0217416C 0x0217416C thumb ov012
 */
typedef unsigned char u8;
typedef struct { int f0; int f4; u8 *f8; } Work;
extern int func_020122C0(int, int, int, int);
extern Work *func_020124E8(int);
extern int func_0217416C(int, int *, int *);
int func_0217413C(int a, int b, u8 *p)
{
    int task;
    Work *w;
    task = func_020122C0(a, 0, (int)func_0217416C, 12);
    w = func_020124E8(task);
    w->f0 = a;
    w->f4 = b;
    w->f8 = p;
    *(int *)(p + 0x3548) = 1;
    return task;
}
