/*
 * function: func_021B8FA8
 * address: 0x021B8FA8
 * packet: pkt_ov133_021B8FA8
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_021F4E2C 0x021F4E2C thumb ov112
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_021BA20C(u8 *p);
extern u32 func_021BA218(u8 *p);
extern void func_021F4E6C(u8 *p, u8 *e, u32 value);
extern void func_021F4E2C(void *unused, u8 *s, u8 *d);
void func_021B8FA8(u8 *p)
{
    if (*(u8 * *)&((struct Obj00004 *)p)->f38 == 0) {
        func_021F4E6C(((struct Obj00004 *)p)->f1884, ((struct Obj00004 *)p)->f4C, 0);
        return;
    }
    if (((struct Obj00004 *)p)->f50 == *(u16 *)func_021BA20C(*(u8 * *)&((struct Obj00004 *)p)->f38)) {
        func_021F4E6C(((struct Obj00004 *)p)->f1884, ((struct Obj00004 *)p)->f4C, 1);
        func_021F4E2C(((struct Obj00004 *)p)->f1884, (u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38), ((struct Obj00004 *)p)->f4C);
    }
}
