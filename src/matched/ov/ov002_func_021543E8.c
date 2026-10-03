/*
 * function: func_021543E8
 * address:  0x021543E8
 * packet:   pkt_021543E8
 * region:   ov002
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator + guard + link setup, stores five constructor arguments.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021542C0  0x021542C0  thumb  ov002
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
u32 func_02012138(const struct Ctx *p);
int func_02026454(int x);
void func_02026400(int x);
void *func_020124E8(struct Obj *p);
u32 func_021542C0(void *obj, u32 *mode, u32 *args);

void *func_021543E8(void *p, int a1, int a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_021542C0, 0x20);
    int *obj;

    if (func_02026454(func_02012138(p)))
        func_02026400(func_02012138(p));
    obj = func_020124E8(r0v);
    obj[1] = (int)p;
    obj[2] = a1;
    obj[4] = (u16)a2;
    obj[5] = a3;
    obj[6] = a4;
    obj[7] = 0;
    return r0v;
}
