/*
 * function: func_021D7180
 * address:  0x021D7180
 * packet:   pkt_ov123_021D7180
 * region:   ov123
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D580C  0x021D580C  thumb  ov123
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_021D6EE0  0x021D6EE0  thumb  ov123
 *   func_021D5A60  0x021D5A60  thumb  ov123
 *   func_021D57D0  0x021D57D0  thumb  ov123
 *   func_021D56FC  0x021D56FC  thumb  ov123
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005E64  0x02005E64  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_021D70BC  0x021D70BC  thumb  ov123
 *   func_021D7130  0x021D7130  thumb  ov123
 */
#include "../include/Obj03792.h"

typedef unsigned int u32;

typedef unsigned char  u8;
extern int func_021D580C(char *p);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D5A60(char *p);
extern void func_021D57D0(int, int, int, int);
extern void func_021D56FC(char *p, int mode);
extern void func_02005DE4(void *p);
extern void func_02005E64(void);
extern void func_02005D90(int, int);
extern void func_021D70BC(char *p);
extern void func_021D7130(void);

void func_021D7180(int a)
{
    if (func_021D580C((char *)(((struct Obj03792 *)a)->f18)) == 0)
        return;
    if (func_020362DC() == 0 && func_02035C60() == 0)
        return;
    if (((struct Obj03792 *)a)->f6C == 0) {
        func_021D6EE0((u8 *)a, (int)func_021D70BC, 0x217);
        return;
    }
    func_021D5A60((char *)(((struct Obj03792 *)a)->f18));
    func_021D57D0(((struct Obj03792 *)a)->f18, 0x16, ((struct Obj03792 *)a)->f6C,
                 ((struct Obj03792 *)a)->fC);
    func_021D56FC((char *)(((struct Obj03792 *)a)->f18), 0);
    func_02005DE4((void *)1);
    func_02005E64();
    func_02005D90(0x515, 0xffff);
    ((struct Obj03792 *)a)->f78 = 0xb4;
    func_021D6EE0((u8 *)a, (int)func_021D7130, 0x222);
}
