/*
 * function: func_021A54B4
 * address:  0x021A54B4
 * packet:   pkt_ov021_021A54B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_021640B0  0x021640B0  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DCE8  0x0216DCE8  thumb  ov010
 *   func_021A3960  0x021A3960  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12739.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { s32 x, y, z; } VecFx32;

extern void *func_021A3960(u8 *p);
extern int func_0216DB4C(void *a0, int a1);
extern int func_0216DCE8(void *a0, int a1);
extern void func_0216D568(void *p, u32 v);
extern int func_02164010(int a);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *obj, struct VecFx32 *out);
extern void func_0216D85C(void *p, s16 v);
extern int func_021640B0(int a);
extern void func_02163F10(void *a0);

void func_021A54B4(u8 *p)
{
    VecFx32 v;
    void *o = func_021A3960(((struct Obj12739 *)p)->fC);

    func_0216DB4C(o, 0);
    func_0216DCE8(o, 0);
    func_0216D568(o, 0x140);
    func_02164010((int)o);
    func_0216D88C(o, (struct VecFx32 *)&v);
    func_0216D85C(o, (s16)((v.y >> 4) / 4096));
    func_021640B0((int)o);
    func_02163F10(o);
}
