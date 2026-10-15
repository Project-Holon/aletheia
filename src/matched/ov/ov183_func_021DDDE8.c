/*
 * function: BR_CODEIN_ListTeardown
 * address: 0x021DDDE8
 * packet: pkt_ov183_021DDDE8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_CODEIN_ListDeleteActor 0x021DE12C thumb ov183
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 */
#include "../include/Obj06603.h"
#include "../include/Obj10733.h"
#include "../include/Obj10734.h"
typedef unsigned char  u8;
extern void BR_CODEIN_ListDeleteActor(char *p);
extern void BR_UTIL_Delete(u8 *p);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void BR_UTIL_DeleteTextWin(void *, int);
void BR_CODEIN_ListTeardown(char *p, char *q)
{
    int i;
    char *slot;
    BR_CODEIN_ListDeleteActor(p + 8);
    for (i = 0; i < 16; i++) {
        slot = p + i * 4;
        if (((struct Obj10734 *)slot)->f34) {
            BR_UTIL_Delete(((struct Obj10734 *)slot)->f34);
            *(int *)&((struct Obj10734 *)slot)->f34 = 0;
        }
    }
    BR_RES_ApplyBgSet(((struct Obj06603 *)q)->f8, 10);
    if (((struct Obj10733 *)p)->f1C) {
        BR_UTIL_DeleteTextWin(((struct Obj10733 *)p)->f1C, ((struct Obj06603 *)q)->f8);
        *(int *)&((struct Obj10733 *)p)->f1C = 0;
    }
}
