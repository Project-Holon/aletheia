/*
 * function: func_021618A0
 * address:  0x021618A0
 * packet:   pkt_021618A0
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, then a sub-init call and link fields.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02161850  0x02161850  thumb  ov010
 *   func_02161950  0x02161950  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct Ctx;
void *func_020120F4(const struct Ctx *p);
int func_02161850(void *a0, int *state, struct Obj *o);
void func_02161950(char *p);

void *func_021618A0(void *p, int a1, int a2, int a3)
{
    void *r0v = func_020122C0(p, 0, func_02161850, 0x34);
    char *r4 = func_020124E8(r0v);

    func_02161950(r4);
    *(void **)r4 = p;
    *(int *)(r4 + 4) = a1;
    *(int *)(r4 + 8) = (int)func_020120F4(p);
    *(u16 *)(r4 + 0xc) = a2;
    *(int *)(r4 + 0x10) = a3;
    return r0v;
}
