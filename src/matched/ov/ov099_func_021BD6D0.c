/*
 * function: func_021BD6D0
 * address: 0x021BD6D0
 * packet: pkt_ov099_021BD6D0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0203D378 0x0203D378 arm
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
#include "../include/Obj22038.h"
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
typedef unsigned char  u8;
extern void func_0203D7B0(u8 a0);
extern int func_0203D7BC(int);
extern int func_0203D378(int);
extern void func_021BAAB8(char *, int, int);
int func_021BD6D0(char *p, int v)
{
    int zero;
    if (func_02039CB4((struct Link *)func_020399A8(), 0x19, 10) == 0) return v;
    zero = 0;
    func_0203D7B0(0);
    if (func_0203D378(func_0203D7BC(0)) != 0) {
        func_021BAAB8(p, 0x7c, zero);
    } else {
        func_021BAAB8(p, 0x7d, zero);
    }
    ((struct Obj22038 *)p)->f1CC = 0x8e;
    return v;
}
