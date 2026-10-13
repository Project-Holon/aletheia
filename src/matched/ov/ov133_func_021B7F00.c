/*
 * function: func_021B7F00
 * address: 0x021B7F00
 * packet: pkt_ov133_021B7F00
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA25C 0x021BA25C thumb ov133
 *   func_021BA228 0x021BA228 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj04522.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_021BA184(char *p);
extern int func_021BA25C(u8 *, int, int);
extern u8 *func_021BA228(u8 *p);
extern u32 func_021BA208(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32);
int func_021B7F00(u8 *p, void *q, u32 a)
{
    u8 *e = func_021BA184(q);
    u32 *v;
    while (e) {
        if (func_021BA25C(e, ((struct Obj04522 *)p)->f1C, ((struct Obj04522 *)p)->f20) == 1) {
            v = (u32 *)func_021BA228(e);
            ((struct Obj04522 *)p)->f3C = 2;
            *(u8 * *)&((struct Obj04522 *)p)->f38 = e;
            GFL_USE_PlaySeDefaultVolume(0x623);
            ((struct Obj04522 *)p)->f40 = a;
            ((struct Obj04522 *)p)->f44 = v[0];
            ((struct Obj04522 *)p)->f48 = v[1];
            return 1;
        }
        e = (u8 *)func_021BA208(e);
    }
    return 0;
}
