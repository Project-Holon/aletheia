/*
 * function: func_021B712C
 * address: 0x021B712C
 * packet: pkt_ov172_021B712C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: Window register writes at 0x021B71A2, 0x021B71A6, 0x021B71AC, 0x021B71AE.
 * symbols:
 *   func_021B78B8 0x021B78B8 thumb ov172
 *   func_021BE100 0x021BE100 thumb ov172
 *   func_021B64AC 0x021B64AC thumb ov172
 */
#include "../include/Obj03852.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021B78B8(void *, char *);
extern int func_021BE100(void);
extern void func_021B64AC(char *p);
static inline void window0(int x1, int y1, int x2, int y2)
{
    *(volatile u16 *)0x04000040 = ((x1 << 8) & 0xff00) | (x2 & 255);
    *(volatile u16 *)0x04000044 = ((y1 << 8) & 0xff00) | (y2 & 255);
}
static inline void window1(int x1, int y1, int x2, int y2)
{
    *(volatile u16 *)0x04000042 = ((x1 << 8) & 0xff00) | (x2 & 255);
    *(volatile u16 *)0x04000046 = ((y1 << 8) & 0xff00) | (y2 & 255);
}
void func_021B712C(int unused, char *q)
{
    u8 i;
    if (((struct Obj03852 *)q)->f14 == 0) {
        for (i = 0; i < 4; i++) {
            if (func_021B78B8(q, q + 0x34 + i * 28) == 1) {
                ((struct Obj03852 *)q)->f10 |= (u8)(1 << i);
                break;
            }
        }
    }
    if (func_021BE100() == 1) func_021B64AC(((struct Obj03852 *)q)->fA4);
    if (((struct Obj03852 *)q)->f2D < 0xc0 && ((struct Obj03852 *)q)->f30 == 0) {
        ((struct Obj03852 *)q)->f2D += 8;
        window0(0, 0, 255, ((struct Obj03852 *)q)->f2D);
        window1(128, 0, 0, ((struct Obj03852 *)q)->f2D);
    }
}
