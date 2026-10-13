/*
 * file:     zenkoku_zukan_award.c
 * unit:     yes
 * function: func_021B95A0, func_021B9748, func_021B97C4, func_021B9900, func_021B9960, func_021B9964, func_021B9B84, func_021B9BB0, func_021B9C1C, func_021B9CE4, func_021B9D64, func_021B9D84, func_021B9DD0, func_021B9E44, func_021B9E6C
 * address:  0x021B95A0
 * region:   ov222
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B9F10 0x021B9F10 thumb ov222
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0204047C 0x0204047C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02012944 0x02012944 thumb
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0207D518 0x0207D518 arm
 *   BG_SYS_ClearSubBgPlanes 0x02043558 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0203D34C 0x0203D34C arm
 *   tbl_021BA1F4 0x021BA1F4 data a4
 *   tbl_021BA360 0x021BA360 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021B9FB8 0x021B9FB8 thumb ov222
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   d_021BA1F4 0x021BA1F4 data a4
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BA014 0x021BA014 thumb ov222
 *   func_0204E804 0x0204E804 arm
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200873C 0x0200873C thumb
 *   CONFIG_GetAppliedFlag 0x020083E4 thumb
 *   func_02049B90 0x02049B90 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   BMP_WIN_SetPosX 0x02045780 arm
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_020437DC 0x020437DC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   d_021BA220 0x021BA220 data a1
 *   d_021BA1E0 0x021BA1E0 data a1
 *   func_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02040E78 0x02040E78 arm
 *   func_02045768 0x02045768 arm
 *   func_02041090 0x02041090 arm
 *   d_021BA378 0x021BA378 data a1
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021BA028 0x021BA028 thumb ov222
 *   d_021BA1D8 0x021BA1D8 data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02040618 0x02040618 arm
 *   func_0204B404 0x0204B404 arm
 *   func_02040804 0x02040804 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204B454 0x0204B454 arm
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BA2AC 0x021BA2AC data a4
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   GFL_USE_IsBgmFading  0x02005E50  thumb  arm9
 *   GFL_USE_PushBgm  0x02005E64  thumb  arm9
 *   GFL_USE_PopBgm  0x02005E9C  thumb  arm9
 */
#include "../../matched/include/Obj02559.h"
#include "../../matched/include/Obj02560.h"
#include "../../matched/include/Obj26077.h"
#include "../../matched/include/Obj26078.h"
#include "../../matched/include/Obj08456.h"
#include "../../matched/include/Obj08457.h"
#include "../../matched/include/Obj06725.h"
#include "../../matched/include/Obj01593.h"
#include "../../matched/include/Obj26080.h"
#include "../../matched/include/Obj26081.h"
#include "../../matched/include/Obj26082.h"

#define R (*(volatile u16*)0x04000060)
struct BgTemplate;
struct Obj;
struct Obj0203159C;
struct GfFont;
struct Node;
struct PrintSys;
struct S020315D4;
struct Big;
struct Bmp;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct Sub02008700Obj;
struct U16Vec;
struct WordSet;
struct Rec;
struct Vec2;
struct Actor;
struct PtS;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u32 id;u8 cfg[32];u32 type,enable;} Row_021B95A0;

typedef struct {u32 a,b,c;} Assets;

typedef enum { BG_MODE0=0, BG_MODE1=1 } BGMode;

typedef enum { COUNT=1 } LayerCount;

typedef struct {u32 layer;u8 data[40];} Row_021B9748;

typedef short s16_021B9964;

struct Obj {
    u16 heap; u16 pad2; void **info; u32 pad8;
    void *str; void *bmp; u8 pad14[4];
    void *bank; void *ptr[5]; u32 done[5];
};

struct Pos { u8 a, b, c, d; };

typedef signed int     s32;

typedef signed short s16_021B9D84;

typedef struct {s16_021B9D84 x,y;} Pt;

typedef signed short s16_021B9DD0;

extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void*,int,u32);
extern void *func_021B9F10(u32,u32);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void*);
extern void func_0204047C(int,u16);
extern void *func_020056A0(u32,void*,u32);
extern char *func_02012944(void*);
extern void BG_SYS_ClearSubPlanes(void),BG_SYS_ClearSubBgPlanes(void),func_0207D518(BGMode);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_02043598(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void*,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void*,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void*);
extern void func_0204E720(u32,int,int,int),func_020409B4(u32),func_0203D34C(u32,u32),GFL_USE_FadeOutBgm(u32);
extern void func_020403F4(u32 i);
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_021B9FB8(char*);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern void func_021BA014(char *p);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_SetBgmPlayerParam(void*);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32,unsigned short);
extern int func_02005F38(void);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32);
extern void func_0204E720(u32,int,int,int);
extern int func_0204E804(void);
extern u32 func_020362DC(void);
extern void func_020355D8(unsigned char);
extern u32 func_02035D20(u32*,u32*);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020409B4(unsigned);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int CONFIG_GetAppliedFlag(unsigned short *p);
extern void func_02049B90(u32,u32,u32,u32,u32,u32,u16);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void BMP_WIN_SetPosX(struct Descriptor *p, u8 v);
extern void BMP_WIN_SetPosY(struct Descriptor *p, u8 v);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void *func_02030734(u32,u32,int,const char*,u16);
extern u32 func_020307B0(void *p);
extern void func_02040E78(u32,void*,u32,u32);
extern u16 func_02045768(struct Descriptor *p);
extern void func_02041090(u32,u32,u32,u32,u8,u8);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_021BA028(char *p);
extern struct Obj *func_0204B294(void*,u32,u32,u32,const void*,u16,u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern unsigned func_02040804(unsigned);
extern void func_02041EE4(unsigned,unsigned,unsigned);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_020434DC(u32,u32);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16,int,int,int,int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void func_02046BE0(u32,u32);
int func_021B95A0(void *owner,void *unused,void *input);
int func_021B9748(void*scene,int unused1,int unused2,char*p);
int func_021B97C4(int unused, int *state, int unused2, unsigned char *p);
void func_021B98FC(void);
void func_021B9900(char*p);
void func_021B9960(char *p);
void func_021B9964(struct Obj *p);
void func_021B9B84(char *p);
void func_021B9BB0(char*p);
int func_021B9BFC(char*p);
void func_021B9C1C(char *p);
void func_021B9CE4(char*p);
void func_021B9D64(char *p);
void func_021B9D84(char*p);
void func_021B9DD0(char*p);
int func_021B9E44(char *p);
void func_021B9E6C(void);
extern const Row_021B95A0 tbl_021BA1F4[];
extern Assets tbl_021BA360[];
extern const Row_021B9748 d_021BA1F4[];
extern const u8 d_021BA220[];
extern struct Pos d_021BA1E0[];
extern char d_021BA378[];
extern const u32 d_021BA1D8[];
extern const u16 d_021BA2AC[][4];

int func_021B95A0(void *owner,void *unused,void *input)
{
 char *p,*settings;
 BGMode i;
 int selected,zero;
 const Row_021B95A0 *row;
 u32 id;
 u16 heap;
 void *h;
 func_0203064C((u32)((void*)1),131,0x30000);
 p=func_0203159C(owner,88,131);
 i=BG_MODE0;
 func_02082BCC(p,i,88);
 *(u16*)p=131;
 *(void**)(p+4)=input;
 *(void**)(p+8)=func_021B9F10(1,*(u16*)p);
 *(void**)(p+12)=func_0201D7EC(23,0,0,0,*(u16*)p);
 *(u32*)(p+16)=func_0201C440((void*)*(u16*)p);
 func_0204047C(1,1);func_0204047C(2,0);
 *(void**)(p+20)=func_020056A0((u32)func_021B98FC,p,1);
 func_021B9900(p);func_021B9964((struct Obj *)p);func_021B9C1C(p);func_021B9CE4(p);
 settings=func_02012944(*(void**)(*(char**)(p+4)));
 *(volatile u16*)0x04001050=i;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 *(volatile u32*)0x04001000 |= 0x10000;
 BG_SYS_ClearSubPlanes();func_0207D518(i);BG_SYS_ClearSubBgPlanes();
 do {
  row=&tbl_021BA1F4[i];id=row->id;
  func_0203FCA0((u8)id,(const struct BgTemplate *)row->cfg,(u8)row->type);func_020414AC(id);func_02040588(id,row->enable);
  i++;
 } while((u32)i<1u);
 func_02043598(16,1);
 heap=*(u16*)p;
 selected=1;if(*(u8*)(settings+29)!=1) selected=0;
 h=func_020490F4(30,heap);
 zero=0;
 func_02049B68(h,tbl_021BA360[selected].a,4,zero,zero,heap);
 func_02049658(h,tbl_021BA360[selected].b,4,zero,zero,zero,heap);
 func_020498F4(h,tbl_021BA360[selected].c,4,zero,zero,zero,heap);
 func_02049238(h);func_020409B4(4);func_021B9D84((char *)p);
 func_0204E720(3,16,16,0);func_0203D34C(0,*(u16*)p);
 if(*(int*)(*(char**)(p+4)+4)==0) GFL_USE_FadeOutBgm(6);
 return 1;
}

int func_021B9748(void*scene,int unused1,int unused2,char*p)
{
 LayerCount i;
 i=0;
 do {
  func_020403F4((u8)d_021BA1F4[i].layer);
  i++;
 } while((u32)i<COUNT);
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 func_021B9D64(p);
 func_021B9B84(p);
 func_021B9960(p);
 func_02030EAC(*(void* *)&((struct Obj02559 *)p)->f14);
 func_0201C6EC(*(void* *)&((struct Obj02559 *)p)->f10);
 func_0201C4C0(*(void* *)&((struct Obj02559 *)p)->f10);
 func_0201D83C(*(void* *)&((struct Obj02559 *)p)->fC);
 func_021B9FB8(*(char* *)&((struct Obj02559 *)p)->f8);
 func_020315D4(scene);
 func_020306F0(0x83);
 return 1;
}

int func_021B97C4(int unused, int *state, int unused2, unsigned char *p)
{
 int ready;
 u32 x,y;
 switch(*state) {
 case 0:
  ready=1;
  if(func_021B9BFC((char *)p)==0) ready=0;
  if(ready && ((struct Obj26077 *)(*(char* *)&((struct Obj02560 *)p)->f4))->f4==0) {
   if(GFL_USE_IsBgmFading()) ready=0;
   else {GFL_USE_SetBgmPlayerParam((void*)1);GFL_USE_PushBgm();GFL_USE_CancelChangeAndPlayBgm(0x524,0xffff);}
  }
  if(ready) {func_0204E720(3,16,0,0);*state=1;}
  break;
 case 1:
  if(!func_0204E804()) {if(((struct Obj26078 *)(*(char* *)&((struct Obj02560 *)p)->f4))->f4!=0) *state=4;else *state=2;}
  break;
 case 2: if(func_021B9E44((char *)p)) *state=3; break;
 case 3:
  if(!func_02005F38()) {GFL_USE_PopBgm();GFL_USE_SetBgmPlayerParam(0);GFL_USE_FadeInBgmFull(6);*state=4;}
  break;
 case 4:
  ready=0;
  if(func_020362DC()&3) {func_020355D8(0);ready=1;}
  else if(func_02035D20(&x,&y)) {func_020355D8(1);ready=1;}
  if(ready) {*state=5;func_0204E720(3,0,16,0);}
  break;
 case 5: if(!func_0204E804()) *state=6; break;
 case 6: return 1;
 }
 func_0201C4E4(*(void* *)&((struct Obj02560 *)p)->f10);
 func_021B9BB0((char *)p);
 if(*state>=1 && *state<=5) func_021B9DD0((char *)p);
 func_021BA014(*(void* *)&((struct Obj02560 *)p)->f8);
 return 0;
}

void func_021B98FC(void) {}

void func_021B9900(char*p)
{
    void *h;
    h=func_020490F4(0xca,((struct Obj08456 *)p)->f0);
    func_02049B68(h,2,0,0,0x1e0,((struct Obj08456 *)p)->f0);
    func_02049658(h,5,1,0,0,0,((struct Obj08456 *)p)->f0);
    func_020498F4(h,7,1,0,0,0,((struct Obj08456 *)p)->f0);
    func_02049238(h);
    func_020409B4(1);
}

void func_021B9960(char *p){}

void func_021B9964(struct Obj *p)
{
    u8 i, j;
    char *msg;
    int flag;
    u32 h;
    s16_021B9964 off;
    u32 ws, x, t;
    msg = func_02012944(*p->info);
    flag = CONFIG_GetAppliedFlag((short unsigned int *)func_0200873C(func_02012EBC(*p->info)));
    p->bank = 0;
    for (i = 0; i < 5; i++) {
        p->ptr[i] = 0;
        p->done[i] = 0;
    }
    p->done[0] = 1;
    p->done[1] = 1;
    func_02049B90(0x17, 5, 0, 0, 0x1e0, 0x20, p->heap);
    p->bank = func_02045B38(0, 3, 1, p->heap);
    for (i = 0; i < 5; i++) {
        p->ptr[i] = (void *)func_020450F0(d_021BA220[i*9], d_021BA220[i*9+1], d_021BA220[i*9+2], d_021BA220[i*9+3], d_021BA220[i*9+4], d_021BA220[i*9+5], d_021BA220[i*9+6]);
        func_02043B5C(func_02045770(p->ptr[i]), 0);
        func_02045334(p->ptr[i]);
    }
    if (flag == 1) {
        for (j = 0; j < 5; j++) {
            BMP_WIN_SetPosX(p->ptr[j], d_021BA1E0[j].a);
            BMP_WIN_SetPosY(p->ptr[j], d_021BA1E0[j].b);
        }
    }
    ws = (u32)func_0201EC64(p->heap);
    t = (u32)func_02045EC0(p->bank, 4);
    x = (u32)func_020457B0(0x20, p->heap);
    off = 0;
    func_0201F02C((struct WordSet *)ws, 0, msg);
    func_0201F250((struct WordSet *)ws, (void *)x, (void *)t);
    func_0201D304((struct StrObj *)x, (u32)p->str, 0);
    func_020437DC(func_02045770(p->ptr[2]));
    func_0201C724(p->bmp, (u32)func_02045770(p->ptr[2]), 0, 0, x, (u32)p->str, 0x440);
    func_02045808((struct U16Vec *)x);
    func_02045808((struct U16Vec *)t);
    func_0201ED04((struct WordSet *)ws);
    t = (u32)func_02045EC0(p->bank, 6);
    x = (u16)func_0201D304((struct StrObj *)t, (u32)p->str, 0);
    h = func_020437DC(func_02045770(p->ptr[3]));
    if (h >= x && flag == 1) off = ((int)(h - x)) / 2;
    func_0201C724(p->bmp, (u32)func_02045770(p->ptr[3]), off, 0, t, (u32)p->str, 0x440);
    func_02045808((struct U16Vec *)t);
    t = (u32)func_02045EC0(p->bank, 5);
    func_0201D304((struct StrObj *)t, (u32)p->str, 0);
    func_020437DC(func_02045770(p->ptr[4]));
    func_0201C724(p->bmp, (u32)func_02045770(p->ptr[4]), 0, 0, t, (u32)p->str, 0x440);
    func_02045808((struct U16Vec *)t);
    for (i = 1; i < 5; i++) {
        void *d = p->ptr[i];
        func_02045334(d);
        func_02045374(d);
        func_02041B6C(func_02045730(d));
    }
    func_021B9BB0((char *)p);
}

void func_021B9B84(char *p) { u8 i;for(i=0;i<5;i++){struct Descriptor *q=*(struct Descriptor **)((u32)p+(u32)i*4+28);if(q)func_020452E8(q);}if(*(struct Rec * *)&((struct Obj02559 *)p)->f18)func_02045C04(*(struct Rec * *)&((struct Obj02559 *)p)->f18); }

/*
 * function_starts: 021B9BFC
 * extent: lead 74B; 2 padding bytes; approved follower 30B; 2 terminal zero bytes at 021B9C1A outside TU.
 */
void func_021B9BB0(char*p)
{
    u8 i;
    for(i=0;i<5;i++){
        char*q=p+i*4;
        if(((struct Obj08457 *)q)->f30==0){
            if(func_0201C6C4(*(void* *)&((struct Obj02560 *)p)->f10,func_02045770(*(void* *)&((struct Obj08457 *)q)->f1C))==0){
                void*h=*(void* *)&((struct Obj08457 *)q)->f1C;
                func_02045334(h);func_02045374(h);func_02041B6C(func_02045730(h));
                ((struct Obj08457 *)q)->f30=1;
            }
        }
    }
}

int func_021B9BFC(char*p)
{
    u8 i;
    for(i=0;i<5;i++){
        if(*(int*)(p+i*4+0x30)==0)return 0;
    }
    return 1;
}

void func_021B9C1C(char *p)
{
 u16 *tiles;
 u16 *buf;
 u16 index;
 unsigned long tile;
 u8 x,y;
 buf=func_02030734(((struct Obj06725 *)p)->f0,32,1,d_021BA378,0x3db);
 index=0;
 buf[0]=0;
 buf[1]=0x1d29;
 buf[2]=0x3210;
 buf[3]=0;
 func_02040E78(2,buf,32,480);
 func_020307B0(buf);
 func_02043B5C(func_02045770(*(void* *)&((struct Obj06725 *)p)->f20),3);
 func_02045334(*(void* *)&((struct Obj06725 *)p)->f20);
 tiles=func_02030734(((struct Obj06725 *)p)->f0,1536,1,d_021BA378,0x3ec);
 tile=func_02045768(*(void* *)&((struct Obj06725 *)p)->f20)|0xf000;
 for(y=0;y<24;y++) for(x=0;x<32;x++) {tiles[index]=tile;index++;}
 func_02041090(2,(u32)tiles,0,24,32,24);
 func_020409B4(2);
 func_020307B0(tiles);
}

void func_021B9CE4(char*p)
{
 u32 t;
 void *h;
 h=func_020490F4(0xca,((struct Obj01593 *)p)->f0);
 *(int *)&((struct Obj01593 *)p)->f4C=func_0204AC18(h,0,0,0,0,2,((struct Obj01593 *)p)->f0);
 *(int *)&((struct Obj01593 *)p)->f48=func_0204A6C8(h,3,0,0,((struct Obj01593 *)p)->f0);
 *(int *)&((struct Obj01593 *)p)->f50=func_0204AF28(h,8,9,((struct Obj01593 *)p)->f0);
 func_02049238((void*)h);
 t=func_021BA028(*(void* *)&((struct Obj01593 *)p)->f8);
 *(void* *)&((struct Obj01593 *)p)->f54=func_0204B294((void*)t,((struct Obj01593 *)p)->f48,((struct Obj01593 *)p)->f4C,((struct Obj01593 *)p)->f50,d_021BA1D8,0,((struct Obj01593 *)p)->f0);
 func_0204B3DC(*(void* *)&((struct Obj01593 *)p)->f54,1);
 func_0204B92C(*(void* *)&((struct Obj01593 *)p)->f54,1);
}


void func_021B9D64(char *p)
{
    func_0204B3B4(((struct Obj02559 *)p)->f54);
    func_0204AFD8((u32)(((struct Obj02559 *)p)->f50));
    func_0204A8D4((u32)(((struct Obj02559 *)p)->f48));
    func_0204ADA4((u32)(((struct Obj02559 *)p)->f4C));
}

/*
 * note 2026-10-05 (final push G1L10): closed by a block-local table pointer `s16 *t` assigned after
 *   the two calls and read as t[0], t[1]. Earlier forms (pointer local at function top, late local
 *   with other types, byte-offset reads, int locals, pragmas) left the base and the first halfword
 *   in swapped registers (4 B).
 */
void func_021B9D84(char*p)
{
    Pt pos;
    if(*(int*)(*(char**)(p+4)+4)==0){
        s16_021B9D84 *t;
        func_02040618(1,3,0x40);
        func_02040618(2,3,0x40);
        t=(s16_021B9D84*)d_021BA1D8;
        pos.x=t[0];
        pos.y=t[1]-0x40;
        func_0204B404(*(void**)(p+0x54),(const struct Vec2 *)(&pos),0);
        *(u8*)(p+0x44)=0;
    }
}

void func_021B9DD0(char*p)
{
    int v;
    Pt pos;
    if(((struct Obj26080 *)(*(char* *)&((struct Obj02560 *)p)->f4))->f4==0){
        v=func_02040804(1);
        if(v!=0){
            if(((struct Obj02560 *)p)->f44==0){
                if(v>=2)v=2;
                func_02041EE4(1,5,v);func_02041EE4(2,5,v);
                func_0204B454(*(void* *)&((struct Obj02560 *)p)->f54,(struct PtS *)(&pos),0);
                pos.y=pos.y+(s16_021B9DD0)v;
                func_0204B404(*(void* *)&((struct Obj02560 *)p)->f54,(const struct Vec2 *)(&pos),0);
                ((struct Obj02560 *)p)->f44=0;
            }else --((struct Obj02560 *)p)->f44;
        }
    }
}

int func_021B9E44(char *p) { int flag;int result;if(((struct Obj26082 *)(*(char * *)&((struct Obj26081 *)p)->f4))->f4!=0)return 1;flag=1;if(func_02040804(1)!=0)flag=0;result=0;if(flag!=0)result=1;return result; }

/*
 * lever: SDK BG0 priority uses explicit (u16) assignment; compound &= pools 0xfffc.
 * volatile: 021B9E7A..021B9EB8 BG0CNT/DISP3DCNT re-reads; 021B9ED6 VIEWPORT
 */
void func_021B9E6C(void)
{
 u32 i;
 func_020434DC(1,1);
 *(volatile u16*)0x04000008 = (u16)(*(volatile u16*)0x04000008 & ~3);
 R=(R & ~0x3002)|2;
 R &= ~0x3010;
 R &= ~0x3004;
 R=(R & ~0x3000)|8;
 R &= ~0x3020;
 func_0207DC44(0,0,0,0);
 func_0207DD24(0,0,0x7fff,63,0);
 *(volatile u32*)0x04000580=0xbfff0000;
 for(i=0;i<4;i++)G3D_SYSTEM_SetLight((u8)i,d_021BA2AC[i]);
 func_02046BE0(0,0);
}
