/*
 * file:     union_oneself_p17.c
 * unit:     yes
 * function: func_0217FBD0, func_0217FC08, func_0217FC64, func_0217FCA4
 * address:  0x0217FBD0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020470D0 0x020470D0 arm
 *   func_02046EFC 0x02046EFC arm
 *   func_02034714  0x02034714  arm
 *   func_0217FD88  0x0217FD88  thumb  ov019
 *   d_02180814     0x02180814  data   ov019 a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_02047400  0x02047400  arm
 *   func_0204767C  0x0204767C  arm
 *   func_02047738 0x02047738 arm
 *   func_02047504 0x02047504 arm
 */
#include "../../matched/include/Obj04971.h"
#include "../../matched/include/Obj05959.h"
#include "../../matched/include/Obj04188.h"

struct Tagged;
struct Rec;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern void func_02034714(const char *a, u32 b, const char *c);
extern u8 *func_0217FD88(u8 *base);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
void func_0217FBD0(char *p);
void func_0217FC08(char *p, u32 a1, u32 a2);
void func_0217FC64(char *self, u32 *out, u32 a2, u16 a3, int flag);
void func_0217FCA4(u32 *p);
extern u32 d_02180814[];

void func_0217FBD0(char *p)
{
    func_020470D0(*(u32 * *)&((struct Obj04971 *)p)->fC8);
    func_020470D0(*(u32 * *)&((struct Obj04971 *)p)->fCC);
    func_02046EFC(*(struct Tagged * *)&((struct Obj04971 *)p)->fC8);
    func_02046EFC(*(struct Tagged * *)&((struct Obj04971 *)p)->fCC);
    *(u32 *)&((struct Obj04971 *)p)->fC8=0;
    *(u32 *)&((struct Obj04971 *)p)->fCC=0;
}


void func_0217FC08(char *p, u32 a1, u32 a2)
{
    if (((struct Obj05959 *)p)->fC8 == 0) {
        func_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    if (((struct Obj05959 *)p)->fCC == 0) {
        func_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    func_0217FC64(p, (u32 *)func_0217FD88((u8 *)p), a1, ((struct Obj05959 *)p)->fD0, a2);
    ((struct Obj05959 *)p)->fD0 = ((struct Obj05959 *)p)->fD0 + 1;
}


/*
 * The reload of out[1] before the last call is spelled with a volatile read.
 *
 * Addresses are Black-image addresses.
 */
void func_0217FC64(char *self, u32 *out, u32 a2, u16 a3, int flag)
{
    u32 *q;

    func_02082BCC(out, 0, 0x14);
    out[0] = a2;
    ((struct Obj04188 *)out)->f10 = a3;
    if (flag == 0) {
        q = (u32 *)(self + 0xc8);
    } else {
        q = (u32 *)(self + 0xcc);
    }
    out[1] = (u32)func_02047400((void *)(*q), 0, (void *)(*q));
    out[3] = (u32)func_0204767C(*(volatile u32 *)&out[1], 0, 0);
}

void func_0217FCA4(u32 *p) { func_02047738((struct Rec *)p[3]); func_02047504((struct Rec *)p[1]); func_02082BCC(p,0,0x14); }
