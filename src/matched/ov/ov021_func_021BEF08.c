/*
 * function: func_021BEF08
 * address:  0x021BEF08
 * packet:   pkt_ov021_021BEF08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 *   func_0208068C  0x0208068C  arm
 *   func_02087AE4  0x02087AE4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_02166B0C  0x02166B0C  thumb  ov010
 *   d_021D9F50     0x021D9F50  data  ov021  a4
 */
#include "../include/Obj20152.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[4]; } S16;

typedef signed int     s32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_0208068C(u32 a);
extern void func_02087AE4(void);
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0207FDCC(u32 a);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(u32 a, u32 b);
extern void func_02166B0C(void);
extern S16 d_021D9F50;

int func_021BEF08(u32 p0, int *st, u8 *q)
{
    S16 loc;

    if (*st == 0) {
        func_0204E720(((struct Obj20152 *)q)->fC, 0, 0x10, 0x10 - 0x11);
        func_0208068C(8);
        *(volatile u32 *)0x04000064 = 0x80330010;
        func_02087AE4();
        func_02087AE4();
        loc = d_021D9F50;
        func_0203FC28((struct DispConfig *)(&loc));
        *(volatile u16 *)0x0400000C = 0x4084 | (*(volatile u16 *)0x0400000C & 0x43);
        func_0207FDCC(8);
        func_0204047C(2, 0);
        func_02040588(2, 1);
        func_02166B0C();
        return 1;
    }
    return 0;
}
