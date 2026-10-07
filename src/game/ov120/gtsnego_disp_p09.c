/*
 * file:     gtsnego_disp_p09.c
 * unit:     yes
 * function: func_021D4FF4, func_021D505C
 * address:  0x021D4FF4
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D8664 0x021D8664 thumb ov120
 *   func_020435F4 0x020435F4 arm
 *   func_021D7EC4 0x021D7EC4 thumb ov120
 *   func_021D68C4 0x021D68C4 thumb ov120
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 *   func_021D6D94 0x021D6D94 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4FD0 0x021D4FD0 thumb ov120
 *   func_021D4988 0x021D4988 thumb ov120
 *   func_021D8638 0x021D8638 thumb ov120
 *   func_0203C554 0x0203C554 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj04485.h"
#include "../../matched/include/Obj13931.h"

typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021D8664(u8 *p);
extern void func_020435F4(u32 planes);
extern void func_021D7EC4(u8 *p);
extern void func_021D68C4(u8 *p);
extern void func_021D63F4(u8 *p, int flag, int mode);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_02041B6C(u32 bit);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021D6D94(u8 *p);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4FD0(u8 *p);
extern void func_021D4988(int);
extern void func_021D8638(u8 *);
extern void func_0203C554(u32 a);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 a);
void func_021D4FF4(u8 *p);
void func_021D505C(int a, int b, int *p);

void func_021D4FF4(u8 *p)
{
    if (func_021D8664(((struct Obj04485 *)p)->f40)) {
        func_020435F4(8);
        func_021D7EC4(((struct Obj04485 *)p)->f40);
        func_021D68C4(((struct Obj04485 *)p)->f3C);
        func_021D63F4(((struct Obj04485 *)p)->f3C, 0, 0);
        func_021D69F4(((struct Obj04485 *)p)->f3C, 0, 9);
        func_02041B6C(5);
        if (((struct Obj04485 *)p)->f138 == 1) {
            func_02040588(4, 0);
            func_021D6D94(((struct Obj04485 *)p)->f3C);
        }
        func_021D4244((int *)p, (int)((void (*)(int))func_021D4FD0), 0x5dd);
    }
}

void func_021D505C(int a, int b, int *p)
{
    if (b == 0 && *(void (**)(int))p == func_021D4988) {
        func_021D8638(*(u8 * *)&((struct Obj13931 *)p)->f40);
        func_0203C554(1);
        func_020355D8(1);
        func_020061E4(0x551);
        func_021D4244(p, (int)((void (*)(int))func_021D4FF4), 0x5f5);
    }
}
