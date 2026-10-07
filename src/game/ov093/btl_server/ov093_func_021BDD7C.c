/*
 * function: func_021BDD7C
 * address:  0x021BDD7C
 * packet:   pkt_ov093_021BDD7C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021BD1D0  0x021BD1D0  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021BDE18  0x021BDE18  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C5108  0x021C5108  thumb  ov093
 *   func_021D64F0  0x021D64F0  thumb  ov093
 *   func_021BDE08  0x021BDE08  thumb  ov093
 */
#include "../../../matched/include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021BD1D0(u8 *p, u32 n);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021BDE18(u8 *p, u8 *a);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C5108(u8 *p, u8 *a, int z);
extern void func_021D64F0(u8 *a);
extern void func_021BDE08(u8 *p, u32 n);

void func_021BDD7C(u8 *p, u8 *a, u32 c)
{
    u32 n = func_021D5440(a);
    u32 s;
    int r = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, n);
    if (r != 6) func_021CD4B0(((struct Obj00003 *)p)->fC, 0x3C, r, c);
    func_021BD1D0(p, n);
    s = func_021CC8D8(p + 0x1D74, 3327);
    func_021BDE18(p, a);
    func_021CC95C((u32 *)(p + 0x1D74), s, 3329);
    func_021C5108(p, a, 0);
    func_021D64F0(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x20, func_021D5440(a));
    func_021BDE08(p + 0x1AB8, n);
}
