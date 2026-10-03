/*
 * function: func_0217CEE8
 * address: 0x0217CEE8
 * packet: pkt_ov018_0217CEE8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0217CF0C 0x0217CF0C thumb ov018
 */
typedef struct { int f0, f4, f8; } Obj;
extern int func_0217CF0C(int, int *, Obj *);
typedef unsigned int   u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
void *func_0217CEE8(void *p, int a, int b)
{
    void *task;
    int *work;
    task = func_020122C0(p, 0, func_0217CF0C, 12);
    work = func_020124E8(task);
    work[0] = a;
    work[1] = b;
    return task;
}
