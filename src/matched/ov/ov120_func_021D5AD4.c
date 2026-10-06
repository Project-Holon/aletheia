/*
 * function: func_021D5AD4
 * address: 0x021D5AD4
 * packet: pkt_ov120_021D5AD4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021B6498 0x021B6498 thumb ov067
 *   func_020362DC 0x020362DC arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D593C 0x021D593C thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D5980 0x021D5980 thumb ov120
 *   func_021D5A84 0x021D5A84 thumb ov120
 *   func_021D7C10 0x021D7C10 thumb ov120
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 */
#include "../include/Obj01400.h"
typedef unsigned char u8;
extern u8 *func_021D6988(void *);
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_021D7AF4(char *p);
extern void func_021D79F4(u8 *p, u16 n);
extern int func_021B6498(u8 *);
extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8 v);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern int func_021D593C(u8 *, int);
extern void func_021D4244(int, int, int);
extern void func_021D5980(u8 *);
extern void func_021D5A84(u8 *);
extern void func_020061E4(u32 a);
extern int func_021D7C10(char *p);
struct S;
extern void func_021B63D0(struct S *p);
extern int func_021B6448(u8 *);
void func_021D5AD4(u8 *p)
{
    int changed = 0;
    u8 *q = func_021D6988(((struct Obj01400 *)p)->f3C);
    if (func_021D7AF4(((struct Obj01400 *)p)->f40)) {
        if (func_021B6498(q) == 0) {
            if (func_020362DC() != 0 && func_020355C4() == 1) {
                func_021D69F4(((struct Obj01400 *)p)->f3C, 0, ((struct Obj01400 *)p)->f15C);
                func_020355D8(changed);
                return;
            }
            if (func_020362DC() == 1) {
                if (((struct Obj01400 *)p)->f184 == 0) {
                    func_021D593C(p, ((struct Obj01400 *)p)->f15C);
                    func_021D4244((int)p, (int)func_021D5980, 0x8f4);
                    return;
                }
                func_020061E4(0x551);
            }
            if (func_020362DC() == 0x40) {
                changed = 1;
                func_020061E4(0x548);
                ((struct Obj01400 *)p)->f15C = 0;
            }
            if (func_020362DC() == 0x80) {
                changed = 1;
                func_020061E4(0x548);
                ((struct Obj01400 *)p)->f15C = 1;
            }
            if (changed)
                func_021D69F4(((struct Obj01400 *)p)->f3C, 0, ((struct Obj01400 *)p)->f15C);
            func_021D7C10((char *)(*(int *)&((struct Obj01400 *)p)->f40));
        }
        func_021B63D0((struct S *)func_021D6988(((struct Obj01400 *)p)->f3C));
        if (func_021B6448(func_021D6988(((struct Obj01400 *)p)->f3C)) == 1) {
            ((struct Obj01400 *)p)->f14 = 1;
            func_021D79F4(((struct Obj01400 *)p)->f40, 0x2a);
            if (func_020355C4() == 1)
                func_021D69F4(((struct Obj01400 *)p)->f3C, 0, 9);
            func_021D4244((int)p, (int)func_021D5A84, 0x916);
        }
    }
}
