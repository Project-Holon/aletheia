/*
 * unit: yes
 * function: func_021FF024, func_021FF070
 * address: 0x021FF024
 * packet: pkt_ov135_021FF024
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FFBC8 0x021FFBC8 thumb ov135
 */
#include "../include/Obj00045.h"
#include "../include/Obj23427.h"
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021FFBC8(u8 *p);
int func_021FF024(char *p)
{
    unsigned r = func_021F4D14(p);
    if (r == 1) {
        func_021F4CE4(p);
        *(int *)&((struct Obj00045 *)p)->f28 = 2;
        func_021F4EC0((u8 *)p, 1, 0);
        if (((struct Obj00045 *)p)->fD0 > 0) func_021FFBC8((u8 *)p);
        ((struct Obj00045 *)p)->fD0 = 0;
    } else if (r == 2) {
        func_021F4CE4(p);
        *(int *)&((struct Obj00045 *)p)->f28 = 0;
    }
    return 2;
}
int func_021FF070(char *p)
{
    ((struct Obj23427 *)p)->f28 = 1;
    return 2;
}
