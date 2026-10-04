/*
 * function: func_02188910
 * address:  0x02188910
 * packet:   pkt_ov021_02188910
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012E40  0x02012E40  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020129F0  0x020129F0  thumb
 *   func_0218CC34  0x0218CC34  thumb
 *   func_021A0E58  0x021A0E58  thumb
 *   func_021903E0  0x021903E0  thumb
 *   func_021BC4F0  0x021BC4F0  thumb
 *   func_021890AC  0x021890AC  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04193.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u8 func_02012E40(const u8 *o);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
struct BigObj;
extern void func_020129F0(struct BigObj *p);
extern void func_0218CC34(u32 a);
extern void func_021A0E58(u32 *a);
struct Obj;
extern void func_021903E0(struct Obj *p);
extern void func_021BC4F0(int a);
extern void func_021890AC(unsigned char *p);

u32 func_02188910(void *a, u8 *b)
{
    if (func_02012E40((const u8 *)(((struct Obj04193 *)b)->f8)) != 0) {
        func_020129F0(func_020120F4(a));
        return 0;
    }
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_0218CC34(((struct Obj04193 *)b)->f48);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_021A0E58((u32 *)(((struct Obj04193 *)b)->f24));
    if (((struct Obj04193 *)b)->f28 != 0)
        func_021903E0((struct Obj *)((struct Obj04193 *)b)->f28);
    if (((struct Obj04193 *)b)->f30 != 0)
        func_021BC4F0((int)((struct Obj04193 *)b)->f30);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_021890AC(b);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_020129F0(func_020120F4(a));
    return 0;
}
