/*
 * function: BR_CODEIN_SaveDestroy
 * address: 0x021E20A4
 * packet: pkt_ov183_021E20A4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: zero alignment halfword at 021E20F6.
 * symbols:
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BR_CODEIN_SaveDeleteTextWin 0x021E24AC thumb ov183
 *   BR_CODEIN_SaveTeardown 0x021E24C4 thumb ov183
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj10757.h"
#include "../include/Obj24648.h"
struct PrintSys;
extern void BR_UTIL_DeleteHandles(char *r5);
extern void BR_CODEIN_SaveDeleteTextWin(char *,char *);
extern void BR_CODEIN_SaveTeardown(char *,char *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void BR_UTIL_DeleteTask(void *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
int BR_CODEIN_SaveDestroy(int obj,int b,char *arg,char *p)
{
    int i;
    for (i=0;i<2;i++) BR_UTIL_DeleteHandles((char *)(*(int *)(p+i*4+0x14)));
    if (((struct Obj24648 *)(*(char * *)&((struct Obj10757 *)p)->f20))->f1C) BR_CODEIN_SaveDeleteTextWin(p,arg);
    else { BR_CODEIN_SaveDeleteTextWin(p,arg); BR_CODEIN_SaveTeardown(p,arg); }
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj10757 *)p)->f0));
    BR_UTIL_DeleteTask((void *)(((struct Obj10757 *)p)->f8));
    func_020315D4((struct S020315D4 *)obj);
    return 1;
}
