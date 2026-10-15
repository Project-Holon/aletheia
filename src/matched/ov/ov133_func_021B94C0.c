/*
 * function: func_021B94C0
 * address: 0x021B94C0
 * packet: pkt_ov133_021B94C0
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA258 0x021BA258 thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   MUSICAL_MCSS_GetRenderElem 0x021F5450 thumb ov112
 *   MUSICAL_MCSS_SetElemField 0x021F4ED4 thumb ov112
 */
#include "../include/Obj00004.h"
#include "../include/Obj23319.h"
#include "../include/Obj23320.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_021BA184(char *p);
extern unsigned int func_021BA258(char *p);
typedef unsigned int   u32;
extern u32 func_021BA218(u8 *p);
extern u32 func_021BA208(u8 *p);
extern u8 *MUSICAL_MCSS_GetRenderElem(u8 *, int);
extern void MUSICAL_MCSS_SetElemField(u32 unused, u32 p, u16 v);
void func_021B94C0(u8 *p)
{
    u8 i;
    u8 *e, *q;
    u16 index;
    for (i = 0; i < 9; i++)
        *(u16 *)(*(u8 * *)&((struct Obj23319 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4 + 0x16 + i * 6) = 0;
    e = func_021BA184(((struct Obj00004 *)p)->f1824);
    while (e) {
        index = func_021BA258((char *)e);
        q = MUSICAL_MCSS_GetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f1880, index);
        MUSICAL_MCSS_SetElemField((u32)(((struct Obj00004 *)p)->f1884), func_021BA218(e), ((struct Obj23320 *)q)->f36);
        e = (u8 *)func_021BA208(e);
    }
}
