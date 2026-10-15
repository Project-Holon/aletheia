/*
 * function: func_021E2F54
 * address: 0x021E2F54
 * packet: pkt_ov183_021E2F54
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 */
#include "../include/Obj10762.h"
#include "../include/Obj14445.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void BR_UTIL_Delete(u8 *p);
extern void func_020409B4(u32 index);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void BR_UTIL_DeleteTextWin(void *,int);
void func_021E2F54(char *p,char *q)
{
    int i;
    for (i=0;i<2;i++) {
        if (*(void **)(p+i*4+0x28)) {
            BR_UTIL_Delete(*(void **)(p+i*4+0x28));
            *(int *)(p+i*4+0x28)=0;
        }
    }
    func_020409B4(4);
    BR_RES_ApplyBgSet(((struct Obj14445 *)q)->f8,0x1e);
    if (((struct Obj10762 *)p)->f8) {
        BR_UTIL_DeleteTextWin(((struct Obj10762 *)p)->f8,((struct Obj14445 *)q)->f8);
        *(int *)&((struct Obj10762 *)p)->f8=0;
    }
}
