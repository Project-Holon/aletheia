/*
 * function: func_021DDE2C
 * address: 0x021DDE2C
 * packet: pkt_ov183_021DDE2C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   func_021DE000 0x021DE000 thumb ov183
 *   func_021DE02C 0x021DE02C thumb ov183
 *   func_021DE058 0x021DE058 thumb ov183
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   d_021E336C 0x021E336C data a4
 */
#include "../include/Obj00631.h"
#include "../include/Obj00632.h"
#include "../include/Obj14426.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Position { short x,y,z;u8 a,b; };
struct Triple { int a,b,c; };
struct Record { u8 a,b,c,d;int value; };
extern const struct Record d_021E336C[];
extern void BR_RES_LoadSprite(char *,unsigned,unsigned);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void *MI_CpuFill8(void *,int,unsigned);
extern int BR_RES_GetSprite(int,int,struct Triple *);
extern void *BR_BTN_CreateFromMessage(void *,int,int,int,int,int,int,int,void *,u16);
extern void *BR_UTIL_Create(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern int func_021DE000(void *p, char *q);
extern int func_021DE02C(void *p, void *q);
extern int func_021DE058(void *p, void *q);
extern void BR_UTIL_SetTextFromMessage(char *p, void *a, void *b, void *font, unsigned short value);
void func_021DDE2C(char *p,char *q)
{
 int first,second,i,id;
 struct Triple triple;
 struct Position pos;
 const struct Record *rec;
 char *slot;
 BR_RES_LoadSprite(*(char * *)&((struct Obj00632 *)q)->f8,6,((struct Obj00631 *)p)->f7C);
 BR_RES_LoadBgGraphics((void *)(*(int *)&((struct Obj00632 *)q)->f8),9,((struct Obj00631 *)p)->f7C);
 first=BR_RES_GetFont(*(char * *)&((struct Obj00632 *)q)->f8);
 second=BR_RES_GetMsgData(*(char * *)&((struct Obj00632 *)q)->f8);
 MI_CpuFill8(&pos,0,8);
 pos.x=0x50;pos.y=0xa8;pos.z=0;pos.a=1;
 BR_RES_GetSprite(*(int *)&((struct Obj00632 *)q)->f8,6,&triple);
 ((struct Obj00631 *)p)->f20=BR_BTN_CreateFromMessage(&pos,4,0x60,1,*(int *)&((struct Obj00632 *)q)->f4,*(int *)&((struct Obj00631 *)p)->f0,first,second,&triple,((struct Obj00631 *)p)->f7C);
 for(i=0;i<4;i++){
  rec=&d_021E336C[i];slot=p+i*4;
  ((struct Obj14426 *)slot)->f24=BR_UTIL_Create(4,rec->a,rec->b,rec->c,rec->d,14,((struct Obj00631 *)p)->f4,((struct Obj00631 *)p)->f7C);
  switch(i){
   case 0: if(func_021DE000((void *)(((struct Obj00632 *)q)->f10),(char *)(((struct Obj00632 *)q)->f14))) id=0x83;else id=0x7e;break;
   case 1: if(func_021DE02C((void *)(((struct Obj00632 *)q)->f10),(void *)(((struct Obj00632 *)q)->f14))) id=0x84;else id=0x7f;break;
   case 2: if(func_021DE058((void *)(((struct Obj00632 *)q)->f10),(void *)(((struct Obj00632 *)q)->f14))) id=0x85;else id=0x80;break;
   case 3: id=0x81;break;
  }
  BR_UTIL_SetTextFromMessage(((struct Obj14426 *)slot)->f24,(void *)second,(void *)id,(void *)first,0x3da0);
 }
}
