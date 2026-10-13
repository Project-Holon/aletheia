/*
 * function: func_021B87B0
 * address: 0x021B87B0
 * packet: pkt_ov106_021B87B0
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the r3 and first-stack token parameters and the loop's token local
 *   are full words (u32); as u16 the prologue spill of r3 and the in-arm token
 *   reload scheduled differently (43 bytes).  CLACT_CreateActor takes the word in
 *   its u32 third slot, so no narrowing is visible anywhere.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_Create 0x02043678 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {void *text;u32 id:7,value:10,tag:8,seq:7;u16 number;u8 a,b,c,active,pad[2];} Item;
typedef struct {s16 x,y;u16 z;u8 a,b;} Param;
extern void MI_CpuFill8(void *,int,u32);
struct Bmp;
struct MsgBank;
struct Obj;
struct StrObj;
struct U16Vec;
struct WordSet;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 POKE_TOOL_CalcGraphicIndex(u32,u32,u32,u32);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern u32 POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void func_021B87B0(u8 *p,const Item *item,void *sys,u32 first,u32 second,void *msg,u32 font,void *set,void *bg,s16 y1,s16 y2,u16 heap) {
 Param cfg; u32 member,mode1,mode2; void *arc; void *a,*b,*c,*text; int i,width; u32 token;
 i=0;
 MI_CpuFill8(p,0,32);
 *(const Item **)p=item; *(void **)(p+28)=bg;
 *(void **)(p+4)=BMP_Create(32,3,32,heap);
 a=STRBUF_Create(32,heap); b=STRBUF_Create(32,heap);
 c=STRBUF_Create(32,heap); text=STRBUF_Create(32,heap);
 func_02045CAC(msg,5,a);func_02045CAC(msg,7,b);func_02045CAC(msg,8,c);
 func_0201EFA4(set,0,item->seq,2,0,1);
 func_0201EFA4(set,2,item->id,3,0,1);
 func_0201EFA4(set,3,item->value,3,0,1);
 func_0201F250(set,text,a);
 width=func_0201D304(text,font,0)>>1;
 PRINTSYS_Print(*(void **)(p+4),38-width,5,text,(void *)font);
 PRINTSYS_Print(*(void **)(p+4),52,5,item->text,(void *)font);
 func_0201F250(set,text,b);
 width=func_0201D304(text,font,0)>>1;
 PRINTSYS_Print(*(void **)(p+4),142-width,5,text,(void *)font);
 func_0201F250(set,text,c);
 width=func_0201D304(text,font,0)>>1;
 PRINTSYS_Print(*(void **)(p+4),194-width,5,text,(void *)font);
 STRBUF_Delete(text);STRBUF_Delete(c);STRBUF_Delete(b);STRBUF_Delete(a);
 member=POKE_TOOL_CalcGraphicIndex(item->number,item->a,item->b,item->c);
 mode1=func_0201BC40(); mode2=func_0201BCB4();
 arc=func_020490F4(7,heap);
 *(u32 *)(p+20)=CLACT_RegisterCharacter(arc,member,0,2,heap);
 *(u32 *)(p+24)=CLACT_RegisterCellAnim(arc,mode1,mode2,heap);
 ARC_TOOL_DeleteHandle(arc);
 MI_CpuFill8(&cfg,0,8);cfg.z=1;cfg.b=1;
 for(;i<2;i++) {
  u8 *q;
  cfg.x=232;
  if(i==0) {cfg.y=y1;token=first;} else {cfg.y=y2;token=second;}
  *(s16 *)(p+16+i*2)=cfg.y;
  q=p+i*4;
  *(void **)(q+8)=CLACT_CreateActor(sys,*(u32 *)(p+20),token,*(u32 *)(p+24),&cfg,i,heap);
  CLACT_SetActorPaletteOffset(*(void **)(q+8),POKE_TOOL_CalcIconPalette(item->number,item->a,item->b,item->c),0);
  if(cfg.y>-16 && cfg.y<208) CLACT_SetActorDrawEnable(*(void **)(q+8),1);
  else CLACT_SetActorDrawEnable(*(void **)(q+8),0);
 }
}
