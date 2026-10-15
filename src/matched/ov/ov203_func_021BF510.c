/*
 * function: DEMO3D_DATA_CreateFade
 * address: 0x021BF510
 * packet: pkt_ov203_021BF510
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   DEMO3D_DATA_FadeMain 0x021BF550 thumb ov203
 *   DEMO3D_DATA_CreateFadeWork 0x021BF710 thumb ov203
 */
#include "../include/Obj03917.h"
struct Context;
struct S02030FB4;
struct TcblNode;
extern void * TCBL_AddTask(void *,void (*)(void *,void *),unsigned,unsigned);
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void DEMO3D_DATA_FadeMain(struct TcblNode *task, struct Context *ctx);
extern void DEMO3D_DATA_CreateFadeWork(char *,void *,int,int,int,int,int,int);
void DEMO3D_DATA_CreateFade(char *p,int a,int b,int c,int d,int e,int f)
{
    DEMO3D_DATA_CreateFadeWork(p,TCBL_GetWork(TCBL_AddTask(((struct Obj03917 *)p)->f20,(void (*)(void *, void *))DEMO3D_DATA_FadeMain,0x2C,1)),a,b,c,d,e,f);
}
