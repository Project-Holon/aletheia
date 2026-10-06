/*
 * function: func_0219C554
 * address:  0x0219C554
 * packet:   pkt_ov021_0219C554
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Former blocker (now filed in src/matched/arm9): func_02050080 (0x02050080) is an unlabelled arm9 leaf with no witness
 * outside this range (Ilias's). Verified C, EXACT under --arm --region arm9:
 *     u32 func_02050080(u32 *p) { return p[1]; }
 * symbols:
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   sub_02030734   0x02030734  arm
 *   func_0216D51C  0x0216D51C  thumb  ov010
 *   func_0219CAD8  0x0219CAD8  thumb  ov021
 *   func_0219CBE0  0x0219CBE0  thumb  ov021
 *   func_0219D2CC  0x0219D2CC  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   d_021DDD70     0x021DDD70  data  a1
 *   d_021D8058     0x021D8058  data  a4
 */
#include "../include/Obj03116.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct { u32 a, b, c; } T12;
extern int d_021DDD70;
extern T12 d_021D8058;
extern u32 func_0216D4F8(u8 *p);
extern void *sub_02030734(u32, u32, int, const char *, u16);
extern void func_0216D51C(u8 *p, u32 v);
extern void func_0219CAD8(void *, u32);
extern void func_0219CBE0(u8 *o);
struct Blk3;
extern void func_0219D2CC(int *obj);
extern u32 func_02050080(u32 *p);
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_0204EDB0(u8 *dst, u8 *src);

void func_0219C554(u32 a, u32 b, u32 c)
{
    u8 *p = sub_02030734(func_0216D4F8((u8 *)a), 0x24, 1, (const char *)&d_021DDD70, 360);
    u32 h;
    T12 t;
    u8 z;
    ((struct Obj03116 *)p)->f10 = a;
    ((struct Obj03116 *)p)->f4 = b;
    ((struct Obj03116 *)p)->f2 = c;
    func_0216D51C((u8 *)a, (u32)p);
    func_0219CAD8(p, c);
    func_0219CBE0(p);
    func_0219D2CC((int *)p);
    h = func_02050080((u32 *)b);
    t = d_021D8058;
    func_0204ED70((u8 *)h, (struct Blk3 *)(&t));
    z = 0;
    func_0204EDB0((u8 *)h, &z);
}
