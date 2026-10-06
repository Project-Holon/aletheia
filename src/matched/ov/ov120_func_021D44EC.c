/*
 * function: func_021D44EC
 * address: 0x021D44EC
 * packet: pkt_ov120_021D44EC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D8904 0x021D8904 data a2
 *   func_0203CD98 0x0203CD98 arm
 *   func_021D8430 0x021D8430 thumb ov120
 *   func_021D8484 0x021D8484 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D44AC 0x021D44AC thumb ov120
 */
#include "../include/Obj08075.h"
typedef unsigned short u16;
typedef struct { u16 v[4]; } Halfwords;
extern const Halfwords d_021D8904;
extern int func_0203CD98(void);
typedef unsigned char  u8;
extern void func_021D8430(u8 *p, void *q);
extern void func_021D8484(char *p, int n);
extern void func_021D4244(int, void (*)(int), int);
extern void func_021D44AC(char *p);
void func_021D44EC(int a)
{
    Halfwords table = d_021D8904;
    const Halfwords *p = &table;
    if (func_0203CD98() != 0)
        p = (const Halfwords *)(a + 0x174);
    ((struct Obj08075 *)a)->f14 = 0xb4;
    func_021D8430((u8 *)(((struct Obj08075 *)a)->f40), (void *)(((struct Obj08075 *)a)->f3C));
    func_021D8484((char *)(((struct Obj08075 *)a)->f40), (int)p);
    func_021D4244(a, (void (*)(int))func_021D44AC, 0x232);
}
