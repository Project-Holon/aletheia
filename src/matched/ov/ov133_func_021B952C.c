/*
 * function: func_021B952C
 * address: 0x021B952C
 * packet: pkt_ov133_021B952C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C60 0x02035C60 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA324 0x021BA324 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021B95AC 0x021B95AC thumb ov133
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
extern int func_02035C60(void);
extern unsigned int TOUCHPANEL_GetPointCont(unsigned int *outA, unsigned int *outB);
extern void *func_021BA184(char *p);
extern unsigned int func_021BA324(u8 *, int, int);
typedef unsigned int   u32;
extern u32 func_021BA208(u8 *p);
extern void func_021B95AC(u8 *);
void func_021B952C(u8 *p)
{
    u8 *e, *best;
    unsigned int distance, n;
    *(int *)&((struct Obj00004 *)p)->f24 = ((struct Obj00004 *)p)->f1C;
    *(int *)&((struct Obj00004 *)p)->f28 = *(int *)&((struct Obj00004 *)p)->f20;
    ((struct Obj00004 *)p)->f14 = func_02035C60();
    ((struct Obj00004 *)p)->f18 = TOUCHPANEL_GetPointCont((unsigned int *)(p + 0x1c), (unsigned int *)(p + 0x20));
    if (((struct Obj00004 *)p)->f14 == 1) {
        best = 0;
        distance = 256;
        e = func_021BA184(((struct Obj00004 *)p)->f1824);
        while (e) {
            n = func_021BA324(e, ((struct Obj00004 *)p)->f1C, *(int *)&((struct Obj00004 *)p)->f20);
            if (distance > n) { best = e; distance = n; }
            e = (u8 *)func_021BA208(e);
        }
        if (best) *(u8 * *)&((struct Obj00004 *)p)->f38 = best;
    }
    if (((struct Obj00004 *)p)->f18 == 1 && *(u8 * *)&((struct Obj00004 *)p)->f38) func_021B95AC(p);
    if (((struct Obj00004 *)p)->f18 == 0) {
        ((struct Obj00004 *)p)->f30 = 0;
        *(u8 * *)&((struct Obj00004 *)p)->f38 = 0;
    }
}
