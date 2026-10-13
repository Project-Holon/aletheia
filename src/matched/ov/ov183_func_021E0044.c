/*
 * function: func_021E0044
 * address: 0x021E0044
 * packet: pkt_ov183_021E0044
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   func_021FFBD4 0x021FFBD4 thumb ov186
 *   func_021FFE5C 0x021FFE5C thumb ov186
 *   func_021FFE34 0x021FFE34 thumb ov186
 */
#include "../include/Obj04573.h"
#include "../include/Obj08315.h"
typedef unsigned short u16;
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern char *func_021FFBD4(void *, void *, int, int, int, int, int, u16);
extern void func_021FFE5C(char *);
extern unsigned func_021FFE34(char *p);
void func_021E0044(char *p, char *q)
{
    *(char * *)&((struct Obj04573 *)p)->f1C = func_021FFBD4(ZUKAN_SAVE_GetFromGameData(((struct Obj08315 *)q)->f10), ((struct Obj08315 *)q)->f8, ((struct Obj08315 *)q)->f4, ((struct Obj04573 *)p)->f44, ((struct Obj08315 *)q)->f0, ((struct Obj04573 *)p)->f3C, ((struct Obj04573 *)p)->f40, ((struct Obj04573 *)p)->f54);
    func_021FFE5C(*(char * *)&((struct Obj04573 *)p)->f1C);
    func_021FFE34(*(char * *)&((struct Obj04573 *)p)->f1C);
}
