/*
 * function: func_021BA290
 * address: 0x021BA290
 * packet: pkt_ov100_021BA290
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_SetDisableKey 0x02027CD8 thumb
 */
#include "../include/Obj00060.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Template { int heap; u8 count,pad[3]; int ptr,flag; u8 x,y,z,w; };
typedef unsigned int   u32;
struct MsgBank;
struct TaskMenu;
struct TaskMenuTmpl;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int APP_TASKMENU_SetDisableKey(int a0, int a1);
void func_021BA290(int a,int flag) {
 struct Template t;
 int v;
 t.heap=((struct Obj00060 *)a)->f278;
 t.flag=1;
 t.x=32;t.y=24;t.z=13;t.w=3;
 if(flag!=0) {
  t.count=2;t.ptr=a+0xcc8;
  v=(int)STRBUF_Create(100,t.heap);((struct Obj00060 *)a)->fCC8=v;
  MSGDATA_ReadString((struct MsgBank *)(((struct Obj00060 *)a)->f288),0x23,(void *)v);
  ((struct Obj00060 *)a)->fCCC=0x39e3;((struct Obj00060 *)a)->fCD0=0;
  v=(int)STRBUF_Create(100,((struct Obj00060 *)a)->f278);((struct Obj00060 *)a)->fCD4=v;
  MSGDATA_ReadString((struct MsgBank *)(((struct Obj00060 *)a)->f288),2,(void *)v);
  ((struct Obj00060 *)a)->fCD8=0x39e3;((struct Obj00060 *)a)->fCDC=1;
  ((struct Obj00060 *)a)->fCC0=(int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&t),(void *)(((struct Obj00060 *)a)->fCC4));
  STRBUF_Delete((struct U16Vec *)(((struct Obj00060 *)a)->fCC8));STRBUF_Delete((struct U16Vec *)(((struct Obj00060 *)a)->fCD4));
  ((struct Obj00060 *)a)->fCBC=0;
 } else {
  t.count=1;t.ptr=a+0xcc8;
  v=(int)STRBUF_Create(100,t.heap);((struct Obj00060 *)a)->fCC8=v;
  MSGDATA_ReadString((struct MsgBank *)(((struct Obj00060 *)a)->f288),2,(void *)v);
  ((struct Obj00060 *)a)->fCCC=0x39e3;((struct Obj00060 *)a)->fCD0=1;
  ((struct Obj00060 *)a)->fCC0=(int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&t),(void *)(((struct Obj00060 *)a)->fCC4));
  STRBUF_Delete((struct U16Vec *)(((struct Obj00060 *)a)->fCC8));((struct Obj00060 *)a)->fCBC=1;
 }
 switch(((struct Obj00060 *)a)->f24C) {case 9:case 10:case 11:break;default:APP_TASKMENU_SetDisableKey(((struct Obj00060 *)a)->fCC0,1);break;}
}
