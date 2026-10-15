/*
 * function: BR_CODEIN_ListSetupRowA
 * address: 0x021DD684
 * packet: pkt_ov183_021DD684
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 the clamp is written n = (n > 9999) ? 9999 : n; the extra reads change the spill slot order of select, number1, number2 (was 10 bytes off with the if form).
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_CODEIN_ListIsEventA 0x021DE000 thumb ov183
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextLayout 0x021FC868 thumb ov186
 *   func_0200DB44 0x0200DB44 thumb
 *   func_0200DAC4 0x0200DAC4 thumb
 *   func_0200DAD8 0x0200DAD8 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BR_UTIL_SetTextFromBuffer 0x021FC7C4 thumb ov186
 *   func_0200DABC 0x0200DABC thumb
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_CODEIN_ListCreateActor 0x021DE084 thumb ov183
 *   d_021E33C0 0x021E33C0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Record{u8 a,b,c,d;int value;};
struct Triple{int a,b,c;};
extern const struct Record d_021E33C0[];
typedef unsigned int   u32;
struct Blk1AC;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern int BR_RES_GetWordSet(char *);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void BR_UTIL_SetTextLayout(u8 *p, u32 a, u32 b, u32 c);
extern int BR_CODEIN_ListIsEventA(void *p, char *q);
extern void *BR_UTIL_Create(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern u32 func_0200DB44(struct Blk1AC *p, u32 i);
extern u16 func_0200DAC4(struct Blk1AC *p, u32 i);
extern u16 func_0200DAD8(struct Blk1AC *p, u32 i);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BR_UTIL_SetTextFromBuffer(char *,void *,void *,u16);
extern u16 func_0200DABC(struct Blk1AC *p);
extern int BR_RES_GetSprite(int,int,struct Triple *);
extern void BR_CODEIN_ListCreateActor(char *,void *,const char *,unsigned,short,short,u16);
void BR_CODEIN_ListSetupRowA(char *p,char *q)
{
 int first,second,third,index,v;
 const struct Record *rec;
 char *slot;
 unsigned select;
 int number1,number2;
 void *obj;
 struct Triple triple;
 first=BR_RES_GetFont(*(char **)(q+8));
 second=BR_RES_GetMsgData(*(char **)(q+8));
 third=BR_RES_GetWordSet(*(char **)(q+8));
 BR_RES_LoadBgGraphics((void *)(*(int *)(q+8)),10,*(u16 *)(p+0x7c));
 select=BR_CODEIN_ListIsEventA((void *)(*(int *)(q+0x10)),(char *)(*(int *)(q+0x14)))?5:0;
 for(index=0;index<8;index++){
  rec=&d_021E33C0[index];slot=p+index*4;
  *(void **)(slot+0x34)=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x7c));
  BR_UTIL_SetTextLayout(*(void **)(slot+0x34),0,1,0);
  switch(index){
   case 1:
    obj=func_02045EC0((struct MsgBank *)second,BR_CODEIN_ListIsEventA((void *)(*(int *)(q+0x10)),(char *)(*(int *)(q+0x14)))?0x83:0x7e);break;
   case 2:
    obj=func_02045EC0((struct MsgBank *)second,func_0200DB44(*(void **)(q+0x10),select)?0x91:0x87);break;
   case 3:{
    void *base;
    number1=func_0200DAC4(*(void **)(q+0x10),select);
    number1=(number1>9999)?9999:number1;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,*(u16 *)(p+0x7c));
    WORDSET_SetSlotNumber((void *)third,0,number1,4,1,1);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   case 6:{
    void *base;
    number2=func_0200DAD8(*(void **)(q+0x10),select);
    number2=(number2>9999)?9999:number2;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,*(u16 *)(p+0x7c));
    WORDSET_SetSlotNumber((void *)third,0,number2,4,1,1);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   default:obj=func_02045EC0((struct MsgBank *)second,rec->value);break;
  }
  BR_UTIL_SetTextFromBuffer(*(char **)(slot+0x34),obj,(void *)first,0x3da0);
  STRBUF_Delete(obj);
 }
 v=func_0200DABC(*(void **)(q+0x10));
 BR_RES_GetSprite(*(int *)(q+8),13,&triple);
 BR_CODEIN_ListCreateActor(p+8,*(void **)(q+4),(const char *)&triple,v,0xa0,0x20,*(u16 *)(p+0x7c));
}
