/*
 * function: func_021E4000
 * address: 0x021E4000
 * packet: pkt_ov119_021E4000
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E43DC 0x021E43DC thumb ov119
 *   func_0203FB44 0x0203FB44 arm
 */
#include "../include/Obj00001.h"
extern void func_021E43DC(char *);
typedef unsigned int   u32;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
void func_021E4000(char *p)
{
    func_021E43DC(p);
    if (((struct Obj00001 *)p)->f870) {
        func_0203FB44((int)5, (unsigned short)(((struct Obj00001 *)p)->f870), (unsigned short)(((struct Obj00001 *)p)->f870 >> 16));
        *(int *)&((struct Obj00001 *)p)->f870 = 0;
    }
    if (((struct Obj00001 *)p)->f874) {
        func_0203FB44((int)7, (unsigned short)(((struct Obj00001 *)p)->f874), (unsigned short)(((struct Obj00001 *)p)->f874 >> 16));
        *(int *)&((struct Obj00001 *)p)->f874 = 0;
    }
    if (*(unsigned int *)&((struct Obj00001 *)p)->f644) {
        func_0203FB44((int)6, (unsigned short)(*(unsigned int *)&((struct Obj00001 *)p)->f644), (unsigned short)(*(unsigned int *)&((struct Obj00001 *)p)->f644 >> 16));
        *(int *)&((struct Obj00001 *)p)->f644 = 0;
    }
}
