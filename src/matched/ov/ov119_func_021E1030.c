/*
 * function: func_021E1030
 * address: 0x021E1030
 * packet: pkt_ov119_021E1030
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 */
#include "../include/Obj00001.h"
typedef unsigned char  u8;
extern void func_0202F038(u8 *p);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);
void func_021E1030(char *p)
{
    if (((struct Obj00001 *)p)->f5F0) {
        func_0202F038(((struct Obj00001 *)p)->f5F0);
        ((struct Obj00001 *)p)->f5F0 = 0;
    }
    ((struct Obj00001 *)p)->f5F0 = func_0202EE8C((u32)(((struct Obj00001 *)p)->f744), ((struct Obj00001 *)p)->f71C, 0xF, 0x10, ((struct Obj00001 *)p)->f5F4);
}
