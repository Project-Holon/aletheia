/*
 * function: func_0217FA10
 * address:  0x0217FA10
 * packet:   pkt_ov019_0217FA10
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02366.h"
#include "../include/Obj09421.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02082BCC(void *p, u32 v, u32 n);
struct G3dOwner;
struct G3dRec;
struct G3dSys;
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);

void func_0217FA10(char *self, u32 *out, u32 a2, u16 a3)
{
    func_02082BCC(out, 0, 0x14);
    out[0] = a2;
    ((struct Obj02366 *)out)->f10 = a3;
    out[1] = (u32)func_02047400((void *)(((struct Obj09421 *)self)->f14), 0, (void *)(((struct Obj09421 *)self)->f14));
    out[2] = (u32)func_02047564((struct G3dOwner *)out[1], (const struct G3dOwner *)(((struct Obj09421 *)self)->f18), 0);
    out[3] = (u32)func_0204767C(out[1], &out[2], 1);
    func_020477A4((struct G3dSys *)out[3], 0);
}
