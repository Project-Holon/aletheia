/*
 * function: func_021D4544
 * address: 0x021D4544
 * packet: pkt_ov120_021D4544
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7A74 0x021D7A74 thumb ov120
 *   func_021D7F5C 0x021D7F5C thumb ov120
 *   func_021D80D4 0x021D80D4 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D44EC 0x021D44EC thumb ov120
 */
#include "../include/Obj05340.h"
typedef unsigned short u16;
typedef unsigned char  u8;
extern void func_021D7A74(u8 *p, int n);
extern void func_021D7F5C(char *p, u16 n);
extern void func_021D80D4(char *p);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D44EC(int);
void func_021D4544(int *a)
{
    --((struct Obj05340 *)a)->f14;
    if (((struct Obj05340 *)a)->f14 == 20)
        func_021D7A74((u8 *)(((struct Obj05340 *)a)->f40), 0x27);
    if (((struct Obj05340 *)a)->f14 == 0) {
        func_021D7F5C((char *)(((struct Obj05340 *)a)->f40), 0x23);
        func_021D80D4((char *)(((struct Obj05340 *)a)->f40));
        func_021D4244(a, (int)func_021D44EC, 0x241);
    }
}
