/*
 * function: func_021CF7DC
 * address:  0x021CF7DC
 * packet:   pkt_ov021_021CF7DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: starts the func_021CF844 task over a 0xD8-byte work and
 * fills its header.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02008530  0x02008530  thumb
 *   func_021CF844  0x021CF844  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Work {
    u32 f00;
    u32 f04;
    u16 *f08;
    u32 f0c;
} Work;

extern void *func_0215A5DC(void *vm);
extern void *func_0215A5E4(void *vm);
extern void *func_0215A5F4(void *vm);
extern u16 *func_02159AE8(void *c, void *vm);
extern void  func_0215897C(void *vm, void *task);
struct Desc;
struct Obj;
struct Sub0200852CObj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern u8 *func_02012944(void *p);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_021CF844(void *a, int *task, struct Work *w);

int func_021CF7DC(void *c, void *vm)
{
    void *owner = func_0215A5F4(vm);
    void *sys = func_0215A5DC(vm);
    void *heap = func_0215A5E4(vm);
    u16 *var = func_02159AE8(c, vm);
    void *task;
    void *h2;
    Work *w;

    task = func_020122C0(sys, 0, func_021CF844, 0xd8);
    h2 = func_02012944(heap);
    w = func_020124E8(task);
    w->f00 = func_02008530(h2);
    w->f0c = 0;
    w->f04 = 0;
    w->f08 = var;
    func_0215897C(owner, task);
    return 1;
}
