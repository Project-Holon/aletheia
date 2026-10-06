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
 *   reload scheduled differently (43 bytes).  func_0204B294 takes the word in
 *   its u32 third slot, so no narrowing is visible anywhere.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02043678 0x02043678 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201BABC 0x0201BABC thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_02045808 0x02045808 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {void *text;u32 id:7,value:10,tag:8,seq:7;u16 number;u8 a,b,c,active,pad[2];} Item;
typedef struct {s16 x,y;u16 z;u8 a,b;} Param;
extern void func_02082BCC(void *,int,u32);
struct Bmp;
struct MsgBank;
struct Obj;
struct StrObj;
struct U16Vec;
struct WordSet;
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201BABC(u32,u32,u32,u32);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern void *func_020490F4(u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern u32 func_0201BB5C(u32,u32,u32,u32);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021B87B0(u8 *p,const Item *item,void *sys,u32 first,u32 second,void *msg,u32 font,void *set,void *bg,s16 y1,s16 y2,u16 heap) {
 Param cfg; u32 member,mode1,mode2; void *arc; void *a,*b,*c,*text; int i,width; u32 token;
 i=0;
 func_02082BCC(p,0,32);
 *(const Item **)p=item; *(void **)(p+28)=bg;
 *(void **)(p+4)=func_02043678(32,3,32,heap);
 a=func_020457B0(32,heap); b=func_020457B0(32,heap);
 c=func_020457B0(32,heap); text=func_020457B0(32,heap);
 func_02045CAC(msg,5,a);func_02045CAC(msg,7,b);func_02045CAC(msg,8,c);
 func_0201EFA4(set,0,item->seq,2,0,1);
 func_0201EFA4(set,2,item->id,3,0,1);
 func_0201EFA4(set,3,item->value,3,0,1);
 func_0201F250(set,text,a);
 width=func_0201D304(text,font,0)>>1;
 func_0201C7A4(*(void **)(p+4),38-width,5,text,(void *)font);
 func_0201C7A4(*(void **)(p+4),52,5,item->text,(void *)font);
 func_0201F250(set,text,b);
 width=func_0201D304(text,font,0)>>1;
 func_0201C7A4(*(void **)(p+4),142-width,5,text,(void *)font);
 func_0201F250(set,text,c);
 width=func_0201D304(text,font,0)>>1;
 func_0201C7A4(*(void **)(p+4),194-width,5,text,(void *)font);
 func_02045808(text);func_02045808(c);func_02045808(b);func_02045808(a);
 member=func_0201BABC(item->number,item->a,item->b,item->c);
 mode1=func_0201BC40(); mode2=func_0201BCB4();
 arc=func_020490F4(7,heap);
 *(u32 *)(p+20)=func_0204A6C8(arc,member,0,2,heap);
 *(u32 *)(p+24)=func_0204AF28(arc,mode1,mode2,heap);
 func_02049238(arc);
 func_02082BCC(&cfg,0,8);cfg.z=1;cfg.b=1;
 for(;i<2;i++) {
  u8 *q;
  cfg.x=232;
  if(i==0) {cfg.y=y1;token=first;} else {cfg.y=y2;token=second;}
  *(s16 *)(p+16+i*2)=cfg.y;
  q=p+i*4;
  *(void **)(q+8)=func_0204B294(sys,*(u32 *)(p+20),token,*(u32 *)(p+24),&cfg,i,heap);
  func_0204B6F4(*(void **)(q+8),func_0201BB5C(item->number,item->a,item->b,item->c),0);
  if(cfg.y>-16 && cfg.y<208) func_0204B3DC(*(void **)(q+8),1);
  else func_0204B3DC(*(void **)(q+8),0);
 }
}
