/*
 * function: func_021D6F70
 * address:  0x021D6F70
 * packet:   pkt_ov123_021D6F70
 * region:   ov123
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02012E08  0x02012E08  thumb
 *   func_021D8F58  0x021D8F58  thumb  ov123
 *   func_021D5D58  0x021D5D58  thumb  ov123
 *   func_021D6EE0  0x021D6EE0  thumb  ov123
 *   func_021D6F44  0x021D6F44  thumb  ov123
 */
#include "../include/Obj05363.h"

typedef unsigned int u32;

extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_02012E08(char *p);
extern void func_021D8F58(char *p);
extern int func_021D5D58(char *p);
extern void func_021D6EE0(unsigned char *p, u32 v, int unused);
typedef unsigned char  u8;
extern void func_021D6F44(u8 *p);

void func_021D6F70(unsigned char *a)
{
    if (((struct Obj05363 *)a)->fAB != 0)
        return;
    if (func_020362DC() == 0 && func_02035C60() == 0)
        return;
    if (((struct Obj05363 *)a)->fAD != 0) {
        func_02012E08((char *)(((struct Obj05363 *)a)->f2C));
        ((struct Obj05363 *)a)->fAD = 0;
    }
    func_021D8F58((char *)a);
    if (((struct Obj05363 *)a)->f8 != 0) {
        if (func_021D5D58((char *)(((struct Obj05363 *)a)->f8)) != 0)
            func_021D6EE0(a, (int)func_021D6F44, 0x191);
        func_021D6EE0(a, 0x021D706D, 0x193);
    } else {
        func_021D6EE0(a, 0x021D706D, 0x196);
    }
}
