/*
 * function: BR_CODEIN_ListSetupRowD
 * address: 0x021DDCCC
 * packet: pkt_ov183_021DDCCC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declaring the text object before the loop index fixes r4/r5.
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextFromBuffer 0x021FC7C4 thumb ov186
 *   BSUBWAY_SCOREDATA_GetLevel 0x0200DC08 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BSUBWAY_SCOREDATA_GetBattlePoints 0x0200DABC thumb
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_CODEIN_ListCreateActor 0x021DE084 thumb ov183
 *   d_021E338C 0x021E338C data a4
 */
#include "../include/Obj00363.h"
#include "../include/Obj00731.h"
#include "../include/Obj14425.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Record { u8 a,b,c,d; int value; };
struct Triple { int a,b,c; };
extern const struct Record d_021E338C[];
struct WordSet;
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern int BR_RES_GetWordSet(char *);
struct U16Vec;
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
typedef unsigned int   u32;
struct U16Vec;
struct WordSet;
extern void *BR_UTIL_Create(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern void BR_UTIL_SetTextFromBuffer(char *,void *,void *,u16);
struct Blk1AC;
struct MsgBank;
extern u8 BSUBWAY_SCOREDATA_GetLevel(struct Blk1AC *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u16 BSUBWAY_SCOREDATA_GetBattlePoints(struct Blk1AC *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int BR_RES_GetSprite(int,int,struct Triple *);
extern void BR_CODEIN_ListCreateActor(char *,void *,const char *,unsigned,short,short,u16);
void BR_CODEIN_ListSetupRowD(char *p,char *q)
{
 int first,second,third,v,text;
 void *obj;
 int i;
 char *slot;
 const struct Record *rec;
 struct Triple triple;
 first=BR_RES_GetFont(*(char * *)&((struct Obj00363 *)q)->f8);
 second=BR_RES_GetMsgData(*(char * *)&((struct Obj00363 *)q)->f8);
 third=BR_RES_GetWordSet(*(char * *)&((struct Obj00363 *)q)->f8);
 BR_RES_LoadBgGraphics((void *)(*(int *)&((struct Obj00363 *)q)->f8),13,((struct Obj00731 *)p)->f7C);
 for(i=0;i<5;i++){
  rec=&d_021E338C[i]; slot=p+i*4;
  ((struct Obj14425 *)slot)->f34=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,((struct Obj00731 *)p)->f4,((struct Obj00731 *)p)->f7C);
  if(i==4){
   v=BSUBWAY_SCOREDATA_GetLevel((struct Blk1AC *)(*(int *)&((struct Obj00363 *)q)->f10));
   text=(int)func_02045EC0((struct MsgBank *)second,rec->value);
   obj=STRBUF_Create(0x80,((struct Obj00731 *)p)->f7C);
   WORDSET_SetSlotNumber((void *)third,0,v,2,1,1);
   WORDSET_CopyTaggedText((void *)third,obj,(void *)text);
   STRBUF_Delete((struct U16Vec *)text);
  }else obj=(void *)func_02045EC0((struct MsgBank *)second,rec->value);
  BR_UTIL_SetTextFromBuffer(*(char * *)&((struct Obj14425 *)slot)->f34,obj,(void *)first,0x3da0);
  STRBUF_Delete((struct U16Vec *)((int)obj));
 }
 v=BSUBWAY_SCOREDATA_GetBattlePoints((struct Blk1AC *)(*(int *)&((struct Obj00363 *)q)->f10));
 BR_RES_GetSprite(*(int *)&((struct Obj00363 *)q)->f8,13,&triple);
 BR_CODEIN_ListCreateActor(p+8,((struct Obj00363 *)q)->f4,(const char *)&triple,v,0xa0,0x20,((struct Obj00731 *)p)->f7C);
}
