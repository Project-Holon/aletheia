/*
 * function: IRCBATTLEMATCH_OpenQuitMenu
 * address: 0x021BA1D0
 * packet: pkt_ov100_021BA1D0
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_SetDisableKey 0x02027CD8 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   IRCBATTLEMATCH_SetPaletteFade 0x021B967C thumb ov100
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
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern int APP_TASKMENU_SetDisableKey(int a0, int a1);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void IRCBATTLEMATCH_SetPaletteFade(int,int);
void IRCBATTLEMATCH_OpenQuitMenu(int a) {
 struct Template t;
 int v;
 t.heap=((struct Obj00060 *)a)->f278;
 t.count=2;
 t.ptr=a+0xcc8;
 t.flag=1;
 t.x=32; t.y=13; t.z=13; t.w=3;
 v=(int)STRBUF_Create(100,t.heap);
 ((struct Obj00060 *)a)->fCC8=v;
 MSGDATA_ReadString((struct MsgBank *)(((struct Obj00060 *)a)->f288),26,(void *)v);
 ((struct Obj00060 *)a)->fCCC=0x39e3;
 v=(int)STRBUF_Create(100,((struct Obj00060 *)a)->f278);
 ((struct Obj00060 *)a)->fCD4=v;
 MSGDATA_ReadString((struct MsgBank *)(((struct Obj00060 *)a)->f288),27,(void *)v);
 ((struct Obj00060 *)a)->fCD8=0x39e3;
 ((struct Obj00060 *)a)->fCD0=0;
 ((struct Obj00060 *)a)->fCDC=0;
 v=(int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&t),(void *)(((struct Obj00060 *)a)->fCC4));
 ((struct Obj00060 *)a)->fCC0=v;
 switch(((struct Obj00060 *)a)->f24C) {case 9: case 10: case 11: break; default: APP_TASKMENU_SetDisableKey(v,1); break;}
 STRBUF_Delete((struct U16Vec *)(((struct Obj00060 *)a)->fCC8));
 STRBUF_Delete((struct U16Vec *)(((struct Obj00060 *)a)->fCD4));
 IRCBATTLEMATCH_SetPaletteFade(a,1);
}
