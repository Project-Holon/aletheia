/*
 * function: BR_CODEIN_ListDestroy
 * address: 0x021DD3F8
 * packet: pkt_ov183_021DD3F8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_CODEIN_ListDeleteButtons 0x021DDF5C thumb ov183
 *   BR_CODEIN_ListTeardown 0x021DDDE8 thumb ov183
 *   func_020409B4 0x020409B4 arm
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj06603.h"
#include "../include/Obj10732.h"
extern void BR_CODEIN_ListDeleteButtons(char *, char *);
extern void BR_CODEIN_ListTeardown(char *, char *);
extern void func_020409B4(unsigned int);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void BR_UTIL_DeleteHandles(char *);
struct PrintSys;
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void BMP_OAM_DeleteSys(void *);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
int BR_CODEIN_ListDestroy(struct S020315D4 *a, int unused, char *q, char *p)
{
    BR_CODEIN_ListDeleteButtons(p, q);
    BR_CODEIN_ListTeardown(p, q);
    func_020409B4(4);
    func_020409B4(1);
    BR_RES_ReleaseSprite((char *)(((struct Obj06603 *)q)->f8), 13);
    BR_UTIL_DeleteHandles(*(char * *)&((struct Obj10732 *)p)->f74);
    PRINTSYS_QUE_Delete(((struct Obj10732 *)p)->f4);
    BMP_OAM_DeleteSys(((struct Obj10732 *)p)->f0);
    func_020315D4(a);
    return 1;
}
