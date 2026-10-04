/*
 * function: func_02187C20
 * address:  0x02187C20
 * packet:   pkt_ov020_02187C20
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02187860  0x02187860  thumb  ov020
 *   func_0202E8A4  0x0202E8A4  thumb
 *   func_0218794C  0x0218794C  thumb  ov020
 *   func_02040588  0x02040588  arm
 *   func_0207D534  0x0207D534  arm
 *   func_0207D658  0x0207D658  arm
 *   func_02187D40  0x02187D40  thumb  ov020
 *   func_02187D74  0x02187D74  thumb  ov020
 *   func_02187D54  0x02187D54  thumb  ov020
 *   func_02187D20  0x02187D20  thumb  ov020
 *   func_02188DB0  0x02188DB0  thumb  ov021
 *   func_02187D94  0x02187D94  thumb  ov020
 */
#include "../include/Obj01207.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
void func_02187860(char *p);
u8 func_0202E8A4(s32 x);
void func_0218794C(int a, int b);
void func_02040588(u32 which, u32 enable);
void func_0207D534(volatile u16 *reg, int brightness);
void func_0207D658(u32 addr, int plane, int brightness);
int func_02187D40(char *p);
int func_02187D74(char *p);
int func_02187D54(char *p);
u32 func_02187D20(char *p);
void func_02188DB0(u8 *a);
void func_02187D94(void *o);

void func_02187C20(char *o, int *p, int st)
{
    switch (st) {
    case 0:
        func_02187860(o);
        break;
    case 1:
        ((struct Obj01207 *)o)->f15 = func_0202E8A4(((struct Obj01207 *)o)->f15);
        func_0218794C(((struct Obj01207 *)o)->f15, ((struct Obj01207 *)o)->f8);
        break;
    case 2:
        func_02040588(3, 1);
        func_02040588(0, 0);
        func_0207D534((volatile u16 *)0x0400006C, 0);
        func_0207D658(0x04000050, 8, -16);
        ((struct Obj01207 *)o)->f1C = func_02187D40(o);
        break;
    case 3:
        ((struct Obj01207 *)o)->f1C = func_02187D74(o);
        break;
    case 4:
        ((struct Obj01207 *)o)->f1C = func_02187D54(o);
        if (func_02187D20(o) == 0 && ((struct Obj01207 *)o)->f15 == ((struct Obj01207 *)o)->f14) {
            func_02188DB0((u8 *)(((struct Obj01207 *)o)->f4));
            func_02040588(3, 1);
            func_02187D94(o);
        }
        break;
    case 5:
        break;
    }
    *p = st;
    *(int *)&((struct Obj01207 *)o)->f18 = 0;
}
