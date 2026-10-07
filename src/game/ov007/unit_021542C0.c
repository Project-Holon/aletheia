/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: func_021542C0, func_021542CC
 * address:  0x021542C0
 * region:   ov007
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02154310  0x02154310  thumb  ov007
 */
struct Ctx;
struct Desc;
struct Obj;
struct Comm;
typedef struct Pair {
    int a;
    int b;
} Pair;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

void *func_020120F4(const struct Ctx *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
u32 func_02012138(const struct Ctx *p);
u32 func_02026454(void *obj);
void func_02026400(struct Comm *p);
void *func_020124E8(struct Obj *p);
u32 func_02154310(void *obj, u32 *mode, u32 *args);
int func_021542C0(int x, Pair *p);
void *func_021542CC(void *p, int a, int b);


int func_021542C0(int x, Pair *p)
{
    return (int)func_021542CC((void *)x, p->a, p->b);
}


void *func_021542CC(void *p, int a, int b)
{
    void *r7;
    int *obj;

    func_020120F4(p);
    r7 = func_020122C0(p, 0, func_02154310, 0x10);
    obj = func_020124E8(r7);
    obj[0] = a;
    obj[1] = (int)p;
    obj[3] = b;
    if (func_02026454((void *)func_02012138(p)))
        func_02026400((struct Comm *)func_02012138(p));
    return r7;
}
