/*
 * function: func_021D4808
 * address: 0x021D4808
 * packet: pkt_ov120_021D4808
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4584 0x021D4584 thumb ov120
 *   func_021D47D4 0x021D47D4 thumb ov120
 */
#include "../include/Obj22827.h"
extern int func_0203CD98(void);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4584(u8 *p);
extern void func_021D47D4(u8 *p);
void func_021D4808(int *a)
{
    if (func_0203CD98() == 0) {
        func_021D4244(a, (int)((void (*)(int))func_021D4584), 0x2df);
        return;
    }
    if (func_02039CB4((struct Link *)func_020399A8(), 2, 0x22) != 0) {
        if (func_0203D3A8(func_020399A8(), 0x2200, 8, (u32)(*(char * *)&((struct Obj22827 *)a)->f48 + 4)) != 0)
            func_021D4244(a, (int)((void (*)(int))func_021D47D4), 0x2e7);
    }
}
