/*
 * function: func_021F1FB4
 * address: 0x021F1FB4
 * packet: pkt_ov194_021F1FB4
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: load window in each print arm; p+i*4+0x44 preserves per-element bases and constant registers.
 * symbols:
 *   func_0201F41C 0x0201F41C thumb
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_SetStringN 0x02045994 arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F22E8 0x021F22E8 thumb ov194
 */
#include "../include/Obj00418.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
extern void func_0201F41C(const u16 *,u16 *,u32);
struct CharBuf;
struct Descriptor;
struct StrObj;
struct Strbuf;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u16 STRBUF_GetEosChar(void);
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
struct Obj;
struct PrintSys;
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void func_0204B3DC(struct Obj *,unsigned int);
extern int func_021F22E8(u8 *);
int func_021F1FB4(u8 *p)
{
 u16 table[14];
 u16 pair[2];
 int i,x;
 void *window;
 if(((struct Obj00418 *)p)->f28){
  if(((struct Obj00418 *)p)->f1E)func_0201F41C((u16 *)p,table,((struct Obj00418 *)p)->f1E+1);
  if(((struct Obj00418 *)p)->f20)func_0201F41C((u16 *)(p+0x16),table+((struct Obj00418 *)p)->f1E,((struct Obj00418 *)p)->f20+1);
  if(((struct Obj00418 *)p)->f1E+((struct Obj00418 *)p)->f20>0){
   BMP_Clear(func_02045770(((struct Obj00418 *)p)->f40),0);
   for(i=0;i<((struct Obj00418 *)p)->f1E+((struct Obj00418 *)p)->f20;i++){
    pair[0]=table[i];pair[1]=STRBUF_GetEosChar();
    STRBUF_SetStringN(((struct Obj00418 *)p)->f3C,pair,2);
    x=64-(((struct Obj00418 *)p)->f22*14)/2;if(x<0)x=0;
    x+=i*14+7;
    x-=func_0201D304(((struct Obj00418 *)p)->f3C,((struct Obj00418 *)p)->f34,0)/2;
    if(i>=((struct Obj00418 *)p)->f1E){window=((struct Obj00418 *)p)->f38;PRINTSYS_PrintQueColor(window,(u32)func_02045770(((struct Obj00418 *)p)->f2C),(short)x,0,(u32)(((struct Obj00418 *)p)->f3C),((struct Obj00418 *)p)->f34,0xc80);}
    else {window=((struct Obj00418 *)p)->f38;func_0201C6FC(window,(u32)func_02045770(((struct Obj00418 *)p)->f2C),(short)x,0,((struct Obj00418 *)p)->f3C,((struct Obj00418 *)p)->f34);}
    p[0x30]=1;
   }
  }else{
   BMP_Clear(func_02045770(((struct Obj00418 *)p)->f40),0);
   BMP_WIN_TransferChars(((struct Obj00418 *)p)->f40);
  }
  for(i=0;i<((struct Obj00418 *)p)->f22;i++){
   CLACT_SetActorAnimFrame(*(void **)(p+i*4+0x44),0);
   CLACT_SetActorAnimSeq(*(void **)(p+i*4+0x44),1);
   func_0204B3DC(*(void **)(p+i*4+0x44),1);
  }
  for(;i<16;i++){
   CLACT_SetActorAnimFrame(*(void **)(p+i*4+0x44),0);
   CLACT_SetActorAnimSeq(*(void **)(p+i*4+0x44),1);
   func_0204B3DC(*(void **)(p+i*4+0x44),0);
  }
  for(i=0;i<=((struct Obj00418 *)p)->f1E && i<((struct Obj00418 *)p)->f22;i++)func_0204B3DC(*(void **)(p+i*4+0x44),1);
  CLACT_SetActorAnimSeq(*(void **)(p+0x44+((struct Obj00418 *)p)->f1E*4),0);
  ((struct Obj00418 *)p)->f28=0;
 }
 return func_021F22E8(p);
}
