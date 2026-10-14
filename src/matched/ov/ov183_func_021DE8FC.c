/*
 * function: func_021DE8FC
 * address: 0x021DE8FC
 * packet: pkt_ov183_021DE8FC
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
#include "../include/Obj08312.h"
#include "../include/Obj10744.h"
#include "../include/Obj10745.h"
typedef unsigned short u16;
typedef unsigned char  u8;
extern void BR_UTIL_Delete(u8 *p);
extern void func_021FB494(char *p);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
void func_021DE8FC(char *p, char *q)
{
    int i;
    for (i = 0; i < 3; i++) {
        char *slot = p + i * 4;
        if (((struct Obj10745 *)slot)->f10) {
            BR_UTIL_Delete(((struct Obj10745 *)slot)->f10);
            ((struct Obj10745 *)slot)->f10 = 0;
        }
    }
    if (((struct Obj10744 *)p)->fC) {
        func_021FB494(((struct Obj10744 *)p)->fC);
        ((struct Obj10744 *)p)->fC = 0;
    }
    BR_RES_ReleaseSprite((char *)(((struct Obj08312 *)q)->f8), 6);
    BR_RES_ApplyBgSet(((struct Obj08312 *)q)->f8, 15);
}
