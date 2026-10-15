/*
 * function: DEMO3D_DATA_CreateMessage
 * address: 0x021BF2DC
 * packet: pkt_ov203_021BF2DC
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   DEMO3D_DATA_MessageMain 0x021BF320 thumb ov203
 *   DEMO3D_DATA_CreateMessageWindow 0x021BF404 thumb ov203
 */
#include "../include/Obj03917.h"
struct Context;
struct S02030FB4;
struct TcblNode;
extern void * TCBL_AddTask(void *,void (*)(void *,void *),unsigned,unsigned);
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void DEMO3D_DATA_MessageMain(struct TcblNode *task, struct Context *ctx);
extern void DEMO3D_DATA_CreateMessageWindow(char *,void *,int,int,int,unsigned char,unsigned char,unsigned char,unsigned char);
void DEMO3D_DATA_CreateMessage(char *p,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g)
{
    DEMO3D_DATA_CreateMessageWindow(p,TCBL_GetWork(TCBL_AddTask(((struct Obj03917 *)p)->f20,(void (*)(void *, void *))DEMO3D_DATA_MessageMain,0x28,1)),a,b,c,d,e,f,g);
}
