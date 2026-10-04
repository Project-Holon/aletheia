/*
 * function: func_021B838C
 * address: 0x021B838C
 * packet: pkt_ov102_021B838C
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B63C4 0x021B63C4 thumb ov101
 *   func_021B63BC 0x021B63BC thumb ov101
 *   func_021B61E8 0x021B61E8 thumb ov101
 *   func_021B7F18 0x021B7F18 thumb ov102
 */
#include "../include/Obj07976.h"
#include "../include/Obj22155.h"
#include "../include/Obj22156.h"
#include "../include/Obj22157.h"
#include "../include/Obj22158.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B63C4(int *);
extern void func_021B63BC(int *);
extern int func_021B61E8(int *);
extern void func_021B7F18(u8 *);
void func_021B838C(u8 *p, u16 *state)
{
    switch (*state) {
    case 0:
        *state = 1;
        func_021B63C4(*(int * *)&((struct Obj22155 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->f4);
        func_021B63BC(*(int * *)&((struct Obj22156 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->f4);
        break;
    case 1:
        if (func_021B61E8(*(int * *)&((struct Obj22157 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->f4))
            *state = 2;
        break;
    case 2:
        ((struct Obj22158 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->fC = 2;
        func_021B7F18(p);
        break;
    }
}
