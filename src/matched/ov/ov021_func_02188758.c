/*
 * function: func_02188758
 * address:  0x02188758
 * packet:   pkt_ov021_02188758
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012104  0x02012104  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_021888C8  0x021888C8  thumb  ov021
 *   func_0204A600  0x0204A600  arm
 *   func_02035648  0x02035648  arm
 *   func_021892CC  0x021892CC  thumb  ov021
 *   func_020120D8  0x020120D8  thumb
 *   func_02168EEC  0x02168EEC  thumb  ov010
 *   func_021BC484  0x021BC484  thumb  ov021
 *   func_021C7FAC  0x021C7FAC  thumb  ov021
 *   func_021A2EB8  0x021A2EB8  thumb  ov021
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_021737A4  0x021737A4  thumb  ov012
 *   func_0217AE20  0x0217AE20  thumb  ov018
 *   func_021A0D68  0x021A0D68  thumb  ov021
 *   func_0216CD64  0x0216CD64  thumb  ov010
 *   func_021BE258  0x021BE258  thumb  ov021
 *   func_021ABE04  0x021ABE04  thumb  ov021
 *   func_0217F914  0x0217F914  thumb  ov018
 *   func_021BB948  0x021BB948  thumb  ov021
 *   func_021903E0  0x021903E0  thumb  ov021
 *   func_02030D28  0x02030D28  arm
 *   func_021C6D90  0x021C6D90  thumb  ov021
 *   func_0218D158  0x0218D158  thumb  ov021
 *   func_02189004  0x02189004  thumb  ov021
 *   func_02012ED0  0x02012ED0  thumb
 *   func_021C8660  0x021C8660  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00518.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 w[3];
} Rec12;

struct BigObj;
struct Ctx;
struct Obj;
struct Sub02014444Obj;
struct T;
struct V3;
extern u32 func_02012104(const struct Ctx *p);
extern void *func_02012B38(const struct BigObj *p);
extern u8 func_0201447C(struct Sub02014444Obj *o, u8 v);
extern u8 func_02012E40(const u8 *o);
extern void func_021888C8(char *o);
extern void func_0204A600(void);
extern void func_02035648(void);
extern u32 func_021892CC(u8 *a);
extern int func_020120D8(char *a);
extern void func_02168EEC(int a);
extern void func_021BC484(u32 a);
extern void func_021C7FAC(u32 a);
extern void func_021A2EB8(u32 *a);
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u32 id);
struct Ctx;
extern u32 func_02012138(const struct Ctx *a);
extern void func_021737A4(int a, int b);
extern void func_0217AE20(int a0, int a1, int a2);
extern void func_021A0D68(u32 *a);
extern int func_0216CD64(int a0);
extern void func_021BE258(void *p);
extern void func_021ABE04(u32 a);
extern void func_0217F914(u32 a);
extern void func_021BB948(u8 *p);
extern void func_021903E0(struct Obj *o);
extern void func_02030D28(struct Ctx *c);
extern void func_021C6D90(u8 *p);
extern void func_0218D158(struct T *dst, const struct V3 *src);
extern void func_02189004(u8 *p);
extern u32 *func_02012ED0(u32 a);
extern void func_021C8660(u32 a);

int func_02188758(void *a, u8 *p)
{
    if (func_02012104((const struct Ctx *)(((struct Obj00518 *)p)->f4)) == 0)
        func_0201447C(func_02012B38((const struct BigObj *)(((struct Obj00518 *)p)->f8)), 0);
    if (func_02012E40((const u8 *)(((struct Obj00518 *)p)->f8)) != 0)
        return 0;
    if (((struct Obj00518 *)p)->f140 != 0) {
        func_021888C8((char *)p);
        func_0204A600();
        return 0;
    }
    func_02035648();
    func_021892CC(p);
    if (func_020120D8(a) == 0) {
        (*(void (**)(u8 *, void *))(*(u8 **)(p + 0x108) + 8))(p, p + 0xF4);
        func_02168EEC(((struct Obj00518 *)p)->f8);
    }
    if (((struct Obj00518 *)p)->f30 != 0)
        func_021BC484(((struct Obj00518 *)p)->f30);
    func_021C7FAC(((struct Obj00518 *)p)->fA0);
    func_021A2EB8((u32 *)(((struct Obj00518 *)p)->f8C));
    if (func_02013CC8(((struct Obj00518 *)p)->fD0) == 1 || func_02013CE0(((struct Obj00518 *)p)->fD0) == 1)
        func_021737A4((int)((void *)func_02012138(a)), (int)p);
    else
        func_0217AE20((int)p, ((struct Obj00518 *)p)->f4, ((struct Obj00518 *)p)->f8C);
    func_021A0D68((u32 *)(((struct Obj00518 *)p)->f24));
    if (((struct Obj00518 *)p)->f38 != 0) {
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
        func_0216CD64(((struct Obj00518 *)p)->f38);
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    }
    func_021BE258(p);
    func_021ABE04(((struct Obj00518 *)p)->f94);
    if (((struct Obj00518 *)p)->f98 != 0)
        func_0217F914(((struct Obj00518 *)p)->f98);
    func_021BB948((u8 *)(((struct Obj00518 *)p)->fBC));
    if (((struct Obj00518 *)p)->f28 != 0)
        func_021903E0((struct Obj *)(((struct Obj00518 *)p)->f28));
    func_02030D28((struct Ctx *)(((struct Obj00518 *)p)->f110));
    func_021C6D90((u8 *)(((struct Obj00518 *)p)->f134));
    if (*(Rec12 * *)&((struct Obj00518 *)p)->fF0 != 0)
        *(Rec12 *)(p + 0xF4) = **(Rec12 * *)&((struct Obj00518 *)p)->fF0;
    func_0218D158((struct T *)(((struct Obj00518 *)p)->f48), (const struct V3 *)(p + 0xF4));
    func_02189004(p);
    func_021C8660(*func_02012ED0(((struct Obj00518 *)p)->f8));
    func_0204A600();
    func_021888C8((char *)p);
    return 0;
}
