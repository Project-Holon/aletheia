/*
 * function: func_02190860
 * address:  0x02190860
 * packet:   pkt_ov021_02190860
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x14-byte handle, builds a 0x34-byte template (func_02190B2C
 * plus the caller's words) and creates the object with func_0201FF30.
 * `const` on b is what interleaves its field loads with the r->c store.
 *
 * symbols:
 *   func_02192F74  0x02192F74  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 *   func_02190B2C  0x02190B2C  thumb  ov021
 *   func_021930C0  0x021930C0  thumb  ov021
 *   func_021904EC  0x021904EC  thumb  ov021
 *   func_0219067C  0x0219067C  thumb  ov021
 *   func_02190678  0x02190678  thumb  ov021
 *   func_0201FF30  0x0201FF30  thumb
 *   func_02020CF8  0x02020CF8  thumb
 *   func_02193144  0x02193144  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 *   func_02193170  0x02193170  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00126.h"
#include "../include/Obj07430.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 w00;
    u32 w04;
    u32 w08;
    u32 w0c;
    u8  pad10[0xc];
    u32 w1c;
    u8  pad20[4];
    u32 w24;
    u32 w28;
    u32 w2c;
    u32 w30;
} Tmpl;

typedef struct {
    u16 *owner;
    u32 slot;
    u32 id;
    u32 c;
    u32 obj;
} Handle;

extern char d_021DDA50[];

struct Dst;
struct Obj;
struct Src;
struct W;
extern void func_02192F74(struct W *w);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02190B2C(struct Dst *d, const struct Src *s);
extern int func_021930C0(int a, int unused, int b, int c, u16 d, u16 e, u16 f);
struct Obj;
struct Slot;
extern struct Slot *func_021904EC(u32 *p, u32 a, u32 b);
extern u8 *func_0219067C(u8 *p);
extern u32 func_02190678(u8 *p);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern void func_02020CF8(struct Obj *p, int heap);
extern void func_02193144(u32 heap);
extern void func_02193044(u32 v);
extern void func_02193170(u32 heap);

Handle *func_02190860(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u16 f, u32 g, u32 h, u32 i)
{
    Tmpl t;
    u8 k;
    Handle *r;

    k = a[1];
    func_02192F74((struct W *)a);
    if (f == 0xe) {
        k = a[2];
    }
    r = func_02030734(a[0], 0x14, 1, d_021DDA50, 0x606);
    func_02190B2C((struct Dst *)(&t), (const struct Src *)b);
    r->owner = a;
    r->c = c;
    r->id = func_021930C0(k, a[0], *(const u16 *)&((struct Obj07430 *)b)->f14, *(const u16 *)&((struct Obj07430 *)b)->f16,
                          *(const u16 *)&((struct Obj07430 *)b)->f18, *(const u16 *)&((struct Obj07430 *)b)->f1A, f);
    r->slot = (u32)func_021904EC((u32 *)a, 0, r->id);
    t.w24 = 0;
    t.w28 = (u32)func_0219067C((u8 *)r->slot);
    t.w2c = func_02190678((u8 *)r->slot);
    t.w30 = ((struct Obj00126 *)a)->f8;
    t.w0c = r->id;
    t.w00 = c;
    t.w08 = h;
    t.w04 = g;
    t.w1c = i;
    r->obj = (u32)func_0201FF30((struct Src *)(&t), d, e, a[0]);
    func_02020CF8((struct Obj *)r->obj, a[0]);
    if (f == 0xe) {
        func_02193144(a[0]);
        func_02193044(1);
    } else {
        func_02193170(a[0]);
    }
    return r;
}
