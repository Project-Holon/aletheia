/*
 * file:     b_plist_anm.c
 * unit:     yes
 * function: B_PLIST_ANM_CopyMonSpriteTiles, B_PLIST_ANM_CopySubSpriteTiles, B_PLIST_ANM_BlitTileRect, B_PLIST_ANM_GetTileBuffer, B_PLIST_ANM_ApplyTilePalette, B_PLIST_ANM_UploadTileBuffer, B_PLIST_ANM_StartPaletteAnim, B_PLIST_ANM_StepPaletteAnim, B_PLIST_ANM_UpdateByMode, B_PLIST_ANM_CopyPaletteSlot, B_PLIST_ANM_CountActiveRecords, B_PLIST_ANM_UpdateSelectedTile, B_PLIST_ANM_CreateTileWindows
 * address:  0x0220B120
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02210F04 0x02210F04 thumb ov198
 *   d_02211A74 0x02211A74 data a4
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   d_02212540 0x02212540 data a4
 *   func_02210B00 0x02210B00 thumb ov198
 *   PALANM_CopyToSlot 0x020215BC thumb
 *   func_02211128 0x02211128 thumb ov198
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_0220BC70 0x0220BC70 thumb ov198
 *   d_02211B14 0x02211B14 data a1
 */
#include "../../matched/include/Obj14553.h"
#include "../../matched/include/Obj25125.h"
#include "../../matched/include/Obj25126.h"
#include "../../matched/include/Obj25127.h"
#include "../../matched/include/Obj25128.h"

struct PalAnmSlot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u8 x,y,w,h;} Rect_0220B5AC;

typedef struct {u8 low:7;u8 high:1;} Flags;

typedef struct Rect_0220B6D0 { u8 x,y,w,h; } Rect_0220B6D0;

typedef struct Bits_0220B760 { unsigned char low:4; unsigned char mode:3; unsigned char active:1; } Bits_0220B760;

typedef struct Bits_0220B7AC { unsigned char low:4; unsigned char mode:3; unsigned char active:1; } Bits_0220B7AC;

typedef struct {u8 low:7,high:1;} Bits_0220B848;

typedef struct {u8 low:7,high:1;} Bits_0220BBB4;

typedef struct Item { u8 a,b,c,d,e,f; } Item;

extern void MI_CpuCopy8(const void *,void *,u32);
extern int func_022110D4(u8 *,int);
extern u32 func_02210F04(u32,u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 func_020307B0(void *p);
extern void func_02041090(u32,u32,u32,u32,u8,u8);
extern void func_02041B6C(u32);
extern int func_02210B00(u8 *p, int i);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern int func_02211128(u8 *,u8 *,u8 *,int);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0220BC70(u8 *, unsigned int);
void B_PLIST_ANM_CopyMonSpriteTiles(char *p,u16 *src);
void B_PLIST_ANM_CopySubSpriteTiles(char *p,u16 *src);
void B_PLIST_ANM_BlitTileRect(u16 *dst, u16 *src, int x, int y, u8 width, u8 height);
void *B_PLIST_ANM_GetTileBuffer(void *p,u32 kind,u32 i,int which);
void B_PLIST_ANM_ApplyTilePalette(u8 *p,void *dst,u8 kind,u8 index,u8 which);
void B_PLIST_ANM_UploadTileBuffer(u8 *p,u8 state,u8 flag,u8 mode);
void B_PLIST_ANM_StartPaletteAnim(u8 *p,unsigned int state);
void B_PLIST_ANM_StepPaletteAnim(u8 *p);
void B_PLIST_ANM_UpdateByMode(u8 *p,u32 mode);
void B_PLIST_ANM_CopyPaletteSlot(unsigned char *p, u32 a1);
u8 B_PLIST_ANM_CountActiveRecords(u8 *p);
void B_PLIST_ANM_UpdateSelectedTile(u8 *p);
void B_PLIST_ANM_CreateTileWindows(u8 *p);
extern const Rect_0220B5AC d_02211A74[];
extern char d_02212540[];
extern Item d_02211B14[];

void B_PLIST_ANM_CopyMonSpriteTiles(char *p,u16 *src)
{
 int a=0x1dc,b=0x35c,c=0x4dc,d=0x65c;
 B_PLIST_ANM_BlitTileRect((u16 *)(p+a),src,0,0,16,6);
 a+=0xc0;B_PLIST_ANM_BlitTileRect((u16 *)(p+a),src,0,6,16,6);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+b),src,0,12,16,6);
 b+=0xc0;B_PLIST_ANM_BlitTileRect((u16 *)(p+b),src,0,18,16,6);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+c),src,16,0,16,6);
 c+=0xc0;B_PLIST_ANM_BlitTileRect((u16 *)(p+c),src,16,6,16,6);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+d),src,16,12,16,6);
 d+=0xc0;B_PLIST_ANM_BlitTileRect((u16 *)(p+d),src,16,18,16,6);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0x7dc),src,0,39,13,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0x85e),src,0,44,13,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0x8e0),src,13,39,13,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0x962),src,13,44,13,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0x9e4),src,0,49,5,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0xa16),src,5,49,5,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0xa48),src,10,49,5,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0xa7a),src,15,49,5,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0xaac),src,0,54,5,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0xade),src,5,54,5,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0xb10),src,10,54,5,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0xb42),src,15,54,5,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0xb74),src,26,24,5,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0xba6),src,26,29,5,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0xbd8),src,26,34,5,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0xc0a),src,26,39,5,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1b30),src,0,24,26,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1c34),src,0,29,26,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1d38),src,0,34,26,5);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1e3c),src,0,59,5,2);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1e50),src,5,59,5,2);
 B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1e64),src,10,59,5,2);
}

void B_PLIST_ANM_CopySubSpriteTiles(char *p,u16 *src)
{
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0xC3C),src,0,0,30,17);
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1038),src,0,17,30,17);
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1434),src,0,34,30,17);
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1830),src,0,51,16,6);
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0x18F0),src,16,51,16,6);
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0x19B0),src,0,57,16,6);
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1A70),src,16,57,16,6);
}

/*
 * trailing: 0220B4AE..0220B4AF is two-byte alignment padding.
 */
void B_PLIST_ANM_BlitTileRect(u16 *dst, u16 *src, int x, int y, u8 width, u8 height)
{
    u16 row;
    u16 col;
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++)
            dst[row * width + col] = src[(y + row) * 32 + x + col];
    }
}

void *B_PLIST_ANM_GetTileBuffer(void *p,u32 kind,u32 i,int which)
{
 switch(kind){
 case 0:case 1:case 2:case 3:case 4:case 5:
  if(which==0) return (void *)((u32)p+0x1dc+i*0xc0);
  else return (void *)((u32)p+0x4dc+i*0xc0);
 case 6:return (void *)((u32)p+0xb74+i*0x32);
 case 7:return (void *)((u32)p+0xc3c+i*0x3fc);
 case 8:case 9:case 10:case 11:return (void *)((u32)p+0x7dc+i*0x82);
 case 12:return (void *)((u32)p+0x9e4+i*0x32);
 case 13:return (void *)((u32)p+0xaac+i*0x32);
 case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:case 24:case 25:case 26:
  return (void *)((u32)p+0x1830+i*0xc0);
 case 27:return (void *)((u32)p+0x1b30+i*0x104);
 case 28:case 29:case 30:case 31:return (void *)((u32)p+0x1e3c+i*0x14);
 default:return 0;
 }
}

/*
 * lever: expand the inner-loop value use to pair[i]; the bounded permuter baseline was DIFF 7 and this mutation reached EXACT.
 */
void B_PLIST_ANM_ApplyTilePalette(u8 *p,void *dst,u8 kind,u8 index,u8 which)
{
 void *src;
 int count,n;
 u32 w;
 u8 i,j;
 u16 pair[2];
 u8 *rec;
 src=B_PLIST_ANM_GetTileBuffer(p,kind,index,which);
 w=((const u8 *)&d_02211A74[0].w)[kind*4];
 count=w*((const u8 *)&d_02211A74[0].h)[kind*4];
 MI_CpuCopy8(src,dst,count*2);
 switch(kind){
 case 0:case 1:case 2:case 3:case 4:case 5:
  n=func_022110D4(p,kind);
  rec=(u8 *)((u32)p+(u32)n*0x4c);
  if(((struct Obj14553 *)rec)->f8==0) break;
  if(((Flags *)(rec+0x1b))->high){
   pair[0]=*(u16 *)((u32)dst+(w*2+5)*2);
   pair[1]=*(u16 *)((u32)dst+(w*3+5)*2);
   for(i=0;i<2;i++){
    u16 value=pair[i];
    for(j=0;j<9;j++) (((u16 *)((u32)dst+(i+2)*w*2))+j)[6]=pair[i];
   }
   return;
  }else if(((struct Obj14553 *)rec)->f14==0){
   for(i=0;i<count;i++) *(u16 *)((u32)dst+i*2)=(*(u16 *)((u32)dst+i*2)&0xfff)|(((index&1)+7)<<12);
   return;
  }else if(func_02210F04((u32)p,n)==1){
   for(i=0;i<count;i++) *(u16 *)((u32)dst+i*2)=(*(u16 *)((u32)dst+i*2)&0xfff)|(((index&1)+5)<<12);
  }
  break;
 }
}

/*
 * lever: byte parameters, u32 dimensions and unsigned long byte-table offset.
 */
void B_PLIST_ANM_UploadTileBuffer(u8 *p,u8 state,u8 flag,u8 mode)
{
    unsigned long off=state*4;
    u32 h=((const u8 *)d_02211A74)[off+3];
    u32 w=((const u8 *)d_02211A74)[off+2];
    void *buf=func_02030734((u16)((((struct Obj25126 *)(*(char * *)&((struct Obj25125 *)p)->f0))->f10&0x7FFF)|0x8000),w*h*2,0,d_02212540,0x205);
    B_PLIST_ANM_ApplyTilePalette(p,buf,state,flag,mode);
    func_02041090(6,(u32)buf,((const u8 *)d_02211A74)[off],((const u8 *)d_02211A74)[off+1],w,h);
    func_02041B6C(6);
    func_020307B0(buf);
}

void B_PLIST_ANM_StartPaletteAnim(u8 *p,unsigned int state)
{
    ((Bits_0220B760 *)(p+0x1E9B))->mode=0;
    if (state<=5 && func_02210B00(p,state)==2) ((Bits_0220B760 *)(p+0x1E9B))->mode=1;
    p[0x1E98]=0;
    p[0x1E99]=0;
    p[0x1E9A]=state;
    ((Bits_0220B760 *)(p+0x1E9B))->active=1;
}

void B_PLIST_ANM_StepPaletteAnim(u8 *p)
{
    if (((Bits_0220B7AC *)(p+0x1E9B))->active != 0) {
        switch (p[0x1E98]) {
        case 0:
            B_PLIST_ANM_UploadTileBuffer(p,p[0x1E9A],1,((Bits_0220B7AC *)(p+0x1E9B))->mode);
            p[0x1E98]++;
            break;
        case 1:
            if (p[0x1E99]==4) {
                B_PLIST_ANM_UploadTileBuffer(p,p[0x1E9A],0,((Bits_0220B7AC *)(p+0x1E9B))->mode);
                p[0x1E99]=0;
                p[0x1E98]++;
            } else p[0x1E99]++;
            break;
        case 2:
            if (p[0x1E99]==1) {
                p[0x1E99]=0;
                p[0x1E98]=0;
                ((Bits_0220B7AC *)(p+0x1E9B))->active=0;
            } else p[0x1E99]++;
            break;
        }
    }
}

/*
 * trailing: 0220BB92..0220BB93 is two-byte alignment padding.
 * lever: the inline byte range guard adds 255 before its u8 narrowing.
 */
void B_PLIST_ANM_UpdateByMode(u8 *p,u32 mode)
{
 switch(mode){
 case 0:{
  u16 i;
  for(i=0;i<6;i++){
   int s=func_02210B00(p,i);
   if(s==0) B_PLIST_ANM_UploadTileBuffer(p,(u8)i,3,1);
   else if(s==1) B_PLIST_ANM_UploadTileBuffer(p,(u8)i,0,0);
   else if(s==2) B_PLIST_ANM_UploadTileBuffer(p,(u8)i,0,1);
  }
  if((u8)((*(u8 **)p)[0x1f]+255)<=1) B_PLIST_ANM_UpdateSelectedTile(p);
  else B_PLIST_ANM_UploadTileBuffer(p,6,0,0);
  break;
 }
 case 8:{
  u16 i;
  for(i=0;i<6;i++){
   int s=func_02210B00(p,i);
   if(s==0) B_PLIST_ANM_UploadTileBuffer(p,(u8)i,3,1);
   else if(s==1) B_PLIST_ANM_UploadTileBuffer(p,(u8)i,0,0);
   else if(s==2) B_PLIST_ANM_UploadTileBuffer(p,(u8)i,0,1);
  }
  B_PLIST_ANM_UploadTileBuffer(p,6,0,0);
  break;
 }
 case 1:{
  B_PLIST_ANM_UploadTileBuffer(p,6,0,0);B_PLIST_ANM_UploadTileBuffer(p,7,0,0);
  if(((Bits_0220B848 *)((u32)p+(u32)func_022110D4(p,(*(u8 **)p)[0x20])*0x4c+0x1b))->high){
   B_PLIST_ANM_UploadTileBuffer(p,8,3,0);B_PLIST_ANM_UploadTileBuffer(p,10,3,0);
  }else{
   B_PLIST_ANM_UploadTileBuffer(p,8,0,0);B_PLIST_ANM_UploadTileBuffer(p,10,0,0);
  }
  break;
 }
 case 2:
  if(B_PLIST_ANM_CountActiveRecords(p)==1){
   B_PLIST_ANM_UploadTileBuffer(p,12,0,0);B_PLIST_ANM_UploadTileBuffer(p,13,0,0);
  }else{
   B_PLIST_ANM_UploadTileBuffer(p,12,3,0);B_PLIST_ANM_UploadTileBuffer(p,13,3,0);
  }
  B_PLIST_ANM_UploadTileBuffer(p,11,0,0);B_PLIST_ANM_UploadTileBuffer(p,6,0,0);break;
 case 3:{
  u16 i;
  if(B_PLIST_ANM_CountActiveRecords(p)==1){
   B_PLIST_ANM_UploadTileBuffer(p,12,0,0);B_PLIST_ANM_UploadTileBuffer(p,13,0,0);
  }else{
   B_PLIST_ANM_UploadTileBuffer(p,12,3,0);B_PLIST_ANM_UploadTileBuffer(p,13,3,0);
  }
  for(i=0;i<4;i++){
   if(*(u16 *)((u32)p+(u32)func_022110D4(p,(*(u8 **)p)[0x20])*0x4c+i*8+0x30)!=0) B_PLIST_ANM_UploadTileBuffer(p,(u8)(i+14),0,0);
   else B_PLIST_ANM_UploadTileBuffer(p,(u8)(i+14),3,0);
  }
  B_PLIST_ANM_UploadTileBuffer(p,9,0,0);B_PLIST_ANM_UploadTileBuffer(p,6,0,0);break;
 }
 case 4:{
  u16 i;
  B_PLIST_ANM_UploadTileBuffer(p,6,0,0);
  for(i=0;i<4;i++){
   if((*(u8 **)p)[0x4b]==i) B_PLIST_ANM_UploadTileBuffer(p,(u8)(i+28),2,0);
   else B_PLIST_ANM_UploadTileBuffer(p,(u8)(i+28),0,0);
  }
  break;
 }
 case 5:{
  u16 i;
  for(i=0;i<4;i++){
   if(*(u16 *)((u32)p+(u32)func_022110D4(p,(*(u8 **)p)[0x20])*0x4c+i*8+0x30)!=0) B_PLIST_ANM_UploadTileBuffer(p,(u8)(i+18),0,0);
   else B_PLIST_ANM_UploadTileBuffer(p,(u8)(i+18),3,0);
  }
  B_PLIST_ANM_UploadTileBuffer(p,6,0,0);break;
 }
 case 6:
  B_PLIST_ANM_UploadTileBuffer(p,22,0,0);B_PLIST_ANM_UploadTileBuffer(p,23,0,0);B_PLIST_ANM_UploadTileBuffer(p,24,0,0);B_PLIST_ANM_UploadTileBuffer(p,25,0,0);B_PLIST_ANM_UploadTileBuffer(p,26,0,0);B_PLIST_ANM_UploadTileBuffer(p,6,0,0);break;
 case 7:
  B_PLIST_ANM_UploadTileBuffer(p,27,0,0);B_PLIST_ANM_UploadTileBuffer(p,6,0,0);break;
 }
}


void B_PLIST_ANM_CopyPaletteSlot(unsigned char *p, u32 a1)
{
    PALANM_CopyToSlot((struct PalAnmSlot *)(((struct Obj25127 *)p)->f1D8), p + 0x1e78, 1, 0xc0, 0x20);
}

/*
 * leaf: sole unresolved blocker of B_PLIST_ANM_UpdateByMode.
 */
u8 B_PLIST_ANM_CountActiveRecords(u8 *p)
{
 u16 i,count=0;
 for(i=0;i<6;i++){
  u8 *rec=(u8 *)((u32)p+i*0x4c);
  if(((struct Obj25128 *)rec)->f8!=0 && !((Bits_0220BBB4 *)(rec+0x1b))->high) count++;
 }
 return count>=2;
}

void B_PLIST_ANM_UpdateSelectedTile(u8 *p){u8 pair[2];if(func_02211128(p,pair+1,pair,0)==1)B_PLIST_ANM_UploadTileBuffer(p,6,0,0);else B_PLIST_ANM_UploadTileBuffer(p,6,3,0);}

/*
 * lever: a nonconst table pointer preserves the original load/store schedule.
 */
void B_PLIST_ANM_CreateTileWindows(u8 *p)
{
    Item *s = d_02211B14;
    u32 i;
    for (i=0;i<2;i++,s++)
        *(void **)(p+i*8+0x1F60)=(void *)BMP_WIN_Create(s->a,s->b,s->c,s->d,s->e,s->f,1);
    func_0220BC70(p,p[0x2180]);
}
