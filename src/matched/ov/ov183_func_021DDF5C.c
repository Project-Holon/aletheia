/*
 * function: func_021DDF5C
 * address: 0x021DDF5C
 * packet: pkt_ov183_021DDF5C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 */
#include "../include/Obj06603.h"
#include "../include/Obj10735.h"
#include "../include/Obj10736.h"
typedef unsigned char  u8;
extern void BR_UTIL_Delete(u8 *p);
extern void func_021FB494(char *p);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
void func_021DDF5C(char *p, char *q)
{
    int i;
    char *slot;
    for (i = 0; i < 4; i++) {
        slot = p + i * 4;
        if (((struct Obj10736 *)slot)->f24) {
            BR_UTIL_Delete(((struct Obj10736 *)slot)->f24);
            *(int *)&((struct Obj10736 *)slot)->f24 = 0;
        }
    }
    if (((struct Obj10735 *)p)->f20) {
        func_021FB494(((struct Obj10735 *)p)->f20);
        *(int *)&((struct Obj10735 *)p)->f20 = 0;
    }
    BR_RES_ReleaseSprite((char *)(((struct Obj06603 *)q)->f8), 6);
    BR_RES_ApplyBgSet(((struct Obj06603 *)q)->f8, 9);
}
