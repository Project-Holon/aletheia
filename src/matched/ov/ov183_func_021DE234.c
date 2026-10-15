/*
 * function: BR_CODEIN_ResultDestroy
 * address: 0x021DE234
 * packet: pkt_ov183_021DE234
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_CODEIN_ResultTeardown 0x021DE780 thumb ov183
 *   BR_CODEIN_ResultDeleteButtons 0x021DE8FC thumb ov183
 *   func_020409B4 0x020409B4 arm
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj10738.h"
extern void BR_CODEIN_ResultTeardown(char *, char *);
extern void BR_CODEIN_ResultDeleteButtons(char *, char *);
typedef unsigned int   u32;
struct PrintSys;
struct S020315D4;
extern void func_020409B4(u32 index);
extern void BR_UTIL_DeleteHandles(char *r5);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void BMP_OAM_DeleteSys(void *);
extern void func_020315D4(struct S020315D4 *p);
int BR_CODEIN_ResultDestroy(void *a, int b, char *q, char *p)
{
    BR_CODEIN_ResultTeardown(p, q);
    BR_CODEIN_ResultDeleteButtons(p, q);
    func_020409B4(4);
    func_020409B4(1);
    BR_UTIL_DeleteHandles(((struct Obj10738 *)p)->f64);
    PRINTSYS_QUE_Delete(((struct Obj10738 *)p)->f4);
    BMP_OAM_DeleteSys(((struct Obj10738 *)p)->f0);
    func_020315D4(a);
    return 1;
}
