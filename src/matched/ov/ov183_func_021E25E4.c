/*
 * function: BR_CODEIN_SoclDestroy
 * address: 0x021E25E4
 * packet: pkt_ov183_021E25E4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: zero alignment halfword at 021E263E.
 * symbols:
 *   BR_CODEIN_CallStoredFnB 0x021E2E48 thumb ov183
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj03333.h"
#include "../include/Obj24671.h"
#include "../include/Obj24672.h"
struct PrintSys;
extern void BR_CODEIN_CallStoredFnB(char *p, int a, int b);
extern void BR_UTIL_DeleteHandles(char *);
extern void BR_UTIL_DeleteTextWin(void *,int);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void BR_UTIL_DeleteTask(void *p);
extern void BMP_OAM_DeleteSys(void *p);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
int BR_CODEIN_SoclDestroy(int obj,int b,int c,char *p)
{
    int i;
    BR_CODEIN_CallStoredFnB(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj03333 *)p)->f3C));
    for (i=0;i<2;i++) BR_UTIL_DeleteHandles(*(char **)(p+i*4+0x30));
    if (((struct Obj03333 *)p)->f8) {
        BR_UTIL_DeleteTextWin(((struct Obj03333 *)p)->f8,((struct Obj24671 *)(*(char * *)&((struct Obj03333 *)p)->f3C))->f8);
        *(int *)&((struct Obj03333 *)p)->f8=0;
    }
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj03333 *)p)->f4));
    BR_UTIL_DeleteTask((void *)(((struct Obj03333 *)p)->fC));
    BMP_OAM_DeleteSys((void *)(((struct Obj03333 *)p)->f0));
    BR_PROC_SYS_PopEntry((unsigned int *)(((struct Obj24672 *)(*(char * *)&((struct Obj03333 *)p)->f3C))->f10));
    func_020315D4((struct S020315D4 *)obj);
    return 1;
}
