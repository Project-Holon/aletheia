/*
 * function: func_021B644C
 * address: 0x021B644C
 * packet: pkt_ov172_021B644C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6938 0x021B6938 thumb ov172
 *   func_021B6944 0x021B6944 thumb ov172
 *   func_02085D3C 0x02085D3C arm
 *   func_021B649C 0x021B649C arm ov172
 *   func_021B64A4 0x021B64A4 arm ov172
 *   func_021B66B0 0x021B66B0 thumb ov172
 */
#include "../../../matched/include/Obj01264.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021B6938(void *);
extern u16 func_021B6944(void *);
extern int func_02085D3C(void);
extern u32 func_021B649C(u32);
extern void func_021B64A4(int, u32, u32, u32, int, void (*)(void), int);
extern void func_021B66B0(void);
void func_021B644C(char *p)
{
    u32 width = func_021B6938(p);
    u32 height = func_021B6944(p);
    u32 offset = func_02085D3C() == 1 ? func_021B649C(width) : 0;
    width *= 2;
    func_021B64A4(1, (*(u32 **)(p + 4))[((struct Obj01264 *)p)->f18], offset >> 2,
                 width * height, 0, func_021B66B0, 0);
}
