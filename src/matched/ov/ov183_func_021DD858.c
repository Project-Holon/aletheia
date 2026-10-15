/*
 * function: func_021DD858
 * address: 0x021DD858
 * packet: pkt_ov183_021DD858
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: 2026-10-05 wave P10 lane Y1. Twin of func_021DD684 (same body: other table d_021E3400, getter func_021DE02C, selector 6/1, argument 11, strings 0x84/0x7f). 468 B; the 1140 B listing extent also holds func_021DDA2C, filed separately. The clamps are n = (n > 9999) ? 9999 : n; as in the twin.
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   func_021DE02C 0x021DE02C thumb ov183
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextLayout 0x021FC868 thumb ov186
 *   func_0200DB44 0x0200DB44 thumb
 *   func_0200DAC4 0x0200DAC4 thumb
 *   func_0200DAD8 0x0200DAD8 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BR_UTIL_SetTextFromBuffer 0x021FC7C4 thumb ov186
 *   func_0200DABC 0x0200DABC thumb
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   func_021DE084 0x021DE084 thumb ov183
 *   d_021E3400 0x021E3400 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Record{u8 a,b,c,d;int value;};
struct Triple{int a,b,c;};
extern const struct Record d_021E3400[];
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
extern int func_021DE02C(void *p, void *q);
extern void *BR_UTIL_Create(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern u32 func_0200DB44(struct Blk1AC *p, u32 i);
extern u16 func_0200DAC4(struct Blk1AC *p, u32 i);
extern u16 func_0200DAD8(struct Blk1AC *p, u32 i);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BR_UTIL_SetTextFromBuffer(char *,void *,void *,u16);
extern u16 func_0200DABC(struct Blk1AC *p);
extern int BR_RES_GetSprite(int,int,struct Triple *);
extern void func_021DE084(char *,void *,const char *,unsigned,short,short,u16);
void func_021DD858(char *p,char *q)
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
 BR_RES_LoadBgGraphics((void *)(*(int *)(q+8)),11,*(u16 *)(p+0x7c));
 select=func_021DE02C((void *)(*(int *)(q+0x10)),(void *)(*(int *)(q+0x14)))?6:1;
 for(index=0;index<8;index++){
  rec=&d_021E3400[index];slot=p+index*4;
  *(void **)(slot+0x34)=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x7c));
  BR_UTIL_SetTextLayout(*(void **)(slot+0x34),0,1,0);
  switch(index){
   case 1:
    obj=func_02045EC0((struct MsgBank *)second,func_021DE02C((void *)(*(int *)(q+0x10)),(void *)(*(int *)(q+0x14)))?0x84:0x7f);break;
   case 2:
    obj=func_02045EC0((struct MsgBank *)second,func_0200DB44(*(void **)(q+0x10),select)?0x91:0x87);break;
   case 3:{
    void *base;
    number1=func_0200DAC4(*(void **)(q+0x10),select);
    number1=(number1>9999)?9999:number1;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,*(u16 *)(p+0x7c));
    func_0201EFA4((void *)third,0,number1,4,1,1);
    func_0201F250((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   case 6:{
    void *base;
    number2=func_0200DAD8(*(void **)(q+0x10),select);
    number2=(number2>9999)?9999:number2;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,*(u16 *)(p+0x7c));
    func_0201EFA4((void *)third,0,number2,4,1,1);
    func_0201F250((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   default:obj=func_02045EC0((struct MsgBank *)second,rec->value);break;
  }
  BR_UTIL_SetTextFromBuffer(*(char **)(slot+0x34),obj,(void *)first,0x3da0);
  STRBUF_Delete(obj);
 }
 v=func_0200DABC(*(void **)(q+0x10));
 BR_RES_GetSprite(*(int *)(q+8),13,&triple);
 func_021DE084(p+8,*(void **)(q+4),(const char *)&triple,v,0xa0,0x20,*(u16 *)(p+0x7c));
}
