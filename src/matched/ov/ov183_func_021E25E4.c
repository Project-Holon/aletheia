/*
 * function: func_021E25E4
 * address: 0x021E25E4
 * packet: pkt_ov183_021E25E4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: zero alignment halfword at 021E263E.
 * symbols:
 *   func_021E2E48 0x021E2E48 thumb ov183
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_021FD714 0x021FD714 thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj03333.h"
#include "../include/Obj24671.h"
#include "../include/Obj24672.h"
struct PrintSys;
extern void func_021E2E48(char *p, int a, int b);
extern void func_021FD820(char *);
extern void func_021FD15C(void *,int);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void func_021FD714(void *p);
extern void BMP_OAM_DeleteSys(void *p);
extern void func_021F9BA0(unsigned *ctx);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
int func_021E25E4(int obj,int b,int c,char *p)
{
    int i;
    func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj03333 *)p)->f3C));
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0x30));
    if (((struct Obj03333 *)p)->f8) {
        func_021FD15C(((struct Obj03333 *)p)->f8,((struct Obj24671 *)(*(char * *)&((struct Obj03333 *)p)->f3C))->f8);
        *(int *)&((struct Obj03333 *)p)->f8=0;
    }
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj03333 *)p)->f4));
    func_021FD714((void *)(((struct Obj03333 *)p)->fC));
    BMP_OAM_DeleteSys((void *)(((struct Obj03333 *)p)->f0));
    func_021F9BA0((unsigned int *)(((struct Obj24672 *)(*(char * *)&((struct Obj03333 *)p)->f3C))->f10));
    func_020315D4((struct S020315D4 *)obj);
    return 1;
}
