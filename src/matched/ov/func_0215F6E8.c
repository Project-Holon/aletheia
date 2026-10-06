/*
 * function: func_0215F6E8
 * address:  0x0215F6E8
 * packet:   pkt_0215F6E8
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, then two accessor stores and two teardown calls.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_0201213C  0x0201213C  thumb
 *   func_0215F630  0x0215F630  thumb  ov010
 *   func_0215F64C  0x0215F64C  thumb  ov010
 *   func_021666A4  0x021666A4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct Big;
void *func_020120F4(const struct Ctx *p);
u8 *func_02012944(void *p);
u8 *func_02012ED0(struct Big *p);
void func_0201213C(struct Ctx *p, u32 v);
int func_0215F630(void *p);
int func_0215F64C(int a0, int *st, int *a2);
void func_021666A4(int a0);

void *func_0215F6E8(void *p)
{
    int r4 = (int)func_020120F4(p);
    void *r7 = func_020122C0(p, 0, func_0215F64C, 0xc);
    int *r6 = func_020124E8(r7);

    r6[0] = (int)p;
    r6[1] = (int)func_0215F630((void *)r4);
    r6[2] = (int)func_02012944((void *)r4);
    func_021666A4((int)func_02012ED0((struct Big *)r4));
    func_0201213C(p, 0);
    return r7;
}
