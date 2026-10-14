/*
 * function: func_021FA0FC
 * address: 0x021FA0FC
 * packet: pkt_ov186_021FA0FC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FACE0 0x021FACE0 thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_BTN_DATA_GetSectionCount 0x021FB760 thumb ov186
 *   BR_BTN_DATA_GetRow 0x021FB704 thumb ov186
 *   BR_BTN_DATA_CreateLabel 0x021FB7D0 thumb ov186
 *   func_021FAC20 0x021FAC20 thumb ov186
 *   func_021FAFA0 0x021FAFA0 thumb ov186
 *   func_021FB514 0x021FB514 thumb ov186
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj01277.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct Fields;
struct U16Vec;
extern void func_021FACE0(char *p);
extern int BR_RES_GetMsgData(char *);
extern u16 BR_BTN_DATA_GetSectionCount(void *,int);
extern void *BR_BTN_DATA_GetRow(char *ctx, int section, unsigned item);
struct MsgBank;
extern void *BR_BTN_DATA_CreateLabel(unsigned * const *p, void *record, struct MsgBank *archive, unsigned short heap);
extern void func_021FAC20(struct Fields *,unsigned,unsigned,unsigned,void *,const void *,unsigned,u16);
extern int func_021FAFA0(void *,int);
extern void func_021FB514(char *p, short x, int y);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_021FA0FC(u8 *p,int section,const int *pos)
{
 int i,bank;
 void *rec,*text;
 for(i=0;i<p[0x38];i++)func_021FACE0((char *)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44));
 bank=BR_RES_GetMsgData(*(char * *)&((struct Obj01277 *)p)->f4);
 p[0x39]=BR_BTN_DATA_GetSectionCount(((struct Obj01277 *)p)->f44,section);
 for(i=0;i<p[0x39];i++){
  rec=BR_BTN_DATA_GetRow(*(char * *)&((struct Obj01277 *)p)->f44,section,(u16)i);
  text=BR_BTN_DATA_CreateLabel(*(unsigned *const * *)&((struct Obj01277 *)p)->f44,rec,(struct MsgBank *)bank,(((struct Obj01277 *)p)->f0&0x7fff)|0x8000);
  func_021FAC20((struct Fields *)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44),(u32)rec,((struct Obj01277 *)p)->f8,((struct Obj01277 *)p)->f48,((struct Obj01277 *)p)->f4,text,((struct Obj01277 *)p)->f10,((struct Obj01277 *)p)->f0);
  STRBUF_Delete(text);
  func_021FAFA0(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44,3);
  if(pos)func_021FB514(*(void **)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44+8),pos[0],(short)pos[1]);
 }
}
