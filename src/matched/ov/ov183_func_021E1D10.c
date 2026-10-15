/*
 * function: BR_CODEIN_UploadDestroy
 * address: 0x021E1D10
 * packet: pkt_ov183_021E1D10
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj10753.h"
#include "../include/Obj24629.h"
extern void BR_UTIL_DeleteHandles(char *);
extern void BR_UTIL_DeleteTextWin(void *,int);
struct PrintSys;
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void BR_UTIL_DeleteTask(void *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
int BR_CODEIN_UploadDestroy(struct S020315D4 *a,int b,char *q,char *p){int i;for(i=0;i<2;i++)BR_UTIL_DeleteHandles(*(char **)(p+i*4+16));BR_UTIL_DeleteTextWin(((struct Obj10753 *)p)->fC,((struct Obj24629 *)q)->f8);PRINTSYS_QUE_Delete(((struct Obj10753 *)p)->f0);BR_UTIL_DeleteTask((void *)(((struct Obj10753 *)p)->f4));func_020315D4(a);return 1;}
