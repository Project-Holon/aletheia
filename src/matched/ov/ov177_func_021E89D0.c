/*
 * function: func_021E89D0
 * address:  0x021E89D0
 * packet:   pkt_ov177_021E89D0
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef struct {
    int f0;
    char pad0[0xc];
    int f10;
    int f14;
} S;

typedef unsigned short u16;
typedef unsigned int   u32;
struct Descriptor;
struct Obj;
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_0201F868(void *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);

void func_021E89D0(S *p)
{
    func_0202020C((struct Obj *)p->f10, 0, 0);
    func_0201F868((void *)p->f14);
    func_0201F7A8((void *)p->f0, 0);
    func_020456F8((struct Descriptor *)p->f0);
    func_020452E8((struct Descriptor *)p->f0);
    func_020307B0(p);
}
