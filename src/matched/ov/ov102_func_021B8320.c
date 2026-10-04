/*
 * function: func_021B8320
 * address: 0x021B8320
 * packet: pkt_ov102_021B8320
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7DFC 0x021B7DFC thumb ov102
 *   func_021B63C4 0x021B63C4 thumb ov101
 *   func_021B63BC 0x021B63BC thumb ov101
 *   func_021B61E8 0x021B61E8 thumb ov101
 *   func_021B7F08 0x021B7F08 thumb ov102
 *   func_021B81B0 0x021B81B0 thumb ov102
 */
#include "../include/Obj10237.h"
#include "../include/Obj22152.h"
#include "../include/Obj22153.h"
#include "../include/Obj22154.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void func_021B7DFC(u8 *, void *, int, int, s16);
extern void func_021B63C4(int *);
extern void func_021B63BC(int *);
extern int func_021B61E8(int *);
extern void func_021B7F08(unsigned p, unsigned x);
extern void func_021B81B0(u8 *, u16 *);
void func_021B8320(u8 *p, u16 *state)
{
    switch (*state) {
    case 0:
        func_021B7DFC(p + 0xac, p + 0x9c, 5, 0, 0);
        func_021B63C4(*(int * *)&((struct Obj22152 *)(*(u8 * *)&((struct Obj10237 *)p)->f48C))->f4);
        func_021B63BC(*(int * *)&((struct Obj22153 *)(*(u8 * *)&((struct Obj10237 *)p)->f48C))->f4);
        *state = 1;
        break;
    case 1:
        if (func_021B61E8(*(int * *)&((struct Obj22154 *)(*(u8 * *)&((struct Obj10237 *)p)->f48C))->f4))
            *state = 2;
        break;
    case 2:
        func_021B7F08((unsigned int)p, (unsigned int)func_021B81B0);
        break;
    }
}
