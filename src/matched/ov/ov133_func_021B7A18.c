/*
 * function: func_021B7A18
 * address: 0x021B7A18
 * packet: pkt_ov133_021B7A18
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   MUSICAL_MCSS_FreeElemImage 0x021F4D74 thumb ov112
 */
#include "../include/Obj00004.h"
#include "../include/Obj06496.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_021BA184(char *p);
typedef unsigned int   u32;
extern u32 func_021BA20C(u8 *p);
extern u32 func_021BA218(u8 *p);
extern u32 func_021BA208(u8 *p);
extern void MUSICAL_MCSS_FreeElemImage(u8 *, u8 *, int, u16);
void func_021B7A18(u8 *p)
{
    u8 *e = func_021BA184(((struct Obj00004 *)p)->f181C);
    u8 *q;
    u8 *s;
    while (e) {
        q = (u8 *)func_021BA20C(e);
        s = (u8 *)func_021BA218(e);
        if (((struct Obj06496 *)q)->fC == 1)
            MUSICAL_MCSS_FreeElemImage(*(u8 **)(p + 0x1884), s, ((struct Obj06496 *)q)->f0, ((struct Obj06496 *)q)->f8);
        else
            MUSICAL_MCSS_FreeElemImage(*(u8 * *)&((struct Obj00004 *)p)->f1884, s, ((struct Obj06496 *)q)->f0, ((struct Obj06496 *)q)->f4);
        e = (u8 *)func_021BA208(e);
    }
}
