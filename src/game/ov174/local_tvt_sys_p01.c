/*
 * file:     local_tvt_sys_p01.c
 * unit:     yes
 * function: func_021B6100, func_021B61C4, func_021B622C, func_021B63B0, func_021B63DC, func_021B6508, func_021B6538, func_021B655C, func_021B6594, func_021B6704, func_021B6754, func_021B6760, func_021B6824, func_021B687C, func_021B68E8, func_021B68F8, func_021B6994, func_021B6A04
 * address:  0x021B6100
 * region:   ov174
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_021B6C70 0x021B6C70 thumb ov174
 *   func_020056A0 0x020056A0 thumb
 *   func_02012984 0x02012984 thumb
 *   func_02011400 0x02011400 thumb
 *   func_0203F4CC 0x0203F4CC arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02030EAC 0x02030EAC arm
 *   func_021B6D00 0x021B6D00 thumb ov174
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_021B6A90 0x021B6A90 thumb ov174
 *   func_021B6F2C 0x021B6F2C thumb ov174
 *   func_021B6F24 0x021B6F24 thumb ov174
 *   func_021B6D3C 0x021B6D3C thumb ov174
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02005728 0x02005728 thumb
 *   func_02040618 0x02040618 arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_0204A48C 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_0207D63C 0x0207D63C arm
 *   d_021B7450 0x021B7450 data a4
 *   d_021B7388 0x021B7388 data a4
 *   d_021B73D0 0x021B73D0 data a4
 *   d_021B73B0 0x021B73B0 data a4
 *   d_021B7410 0x021B7410 data a4
 *   d_021B7430 0x021B7430 data a4
 *   d_021B73F0 0x021B73F0 data a4
 *   d_020A1448 0x020A1448 data a4
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204A380 0x0204A380 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02012944 0x02012944 thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02008550 0x02008550 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020413B0 0x020413B0 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021B7360 0x021B7360 thumb ov174
 *   func_0204B404 0x0204B404 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   d_021B7380 0x021B7380 data a1
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_0201F548  0x0201F548  thumb
 *   func_02049B90  0x02049B90  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201DD68  0x0201DD68  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0201C440  0x0201C440  thumb
 *   func_02028590  0x02028590  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02028604 0x02028604 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_021B7364 0x021B7364 thumb ov174
 *   func_02028484 0x02028484 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02028470 0x02028470 thumb
 *   func_02045730 0x02045730 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_021B7350 0x021B7350 thumb ov174
 *   func_0201F250 0x0201F250 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 */
#include "../../matched/include/Obj01167.h"
#include "../../matched/include/Obj24197.h"
#include "../../matched/include/Obj00681.h"
#include "../../matched/include/Obj00152.h"
#include "../../matched/include/Obj03859.h"
#include "../../matched/include/Obj00545.h"
#include "../../matched/include/Obj24199.h"
#include "../../matched/include/Obj24200.h"
#include "../../matched/include/Obj00918.h"
#include "../../matched/include/Obj24201.h"
#include "../../matched/include/Obj02507.h"
#include "../../matched/include/Obj02218.h"
#include "../../matched/include/Obj00919.h"

struct BigObj;
struct Bank;
struct Node;
struct Obj;
struct Cfg;
struct DispConfig;
struct DispVram;
struct BgTemplate;
struct Sub0200852CObj;
struct Actor;
struct Vec2;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
struct WordSet;
struct Blk;
struct Ctx;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned short u16;

struct RtcTime{unsigned hour,minute,second;};

typedef unsigned int   u32_021B6100;

typedef unsigned int   u32_021B61C4;

typedef unsigned u32_021B622C;

typedef enum { SZ0=0,SZ1=1,SZ2=2,SZ3=3 } GXBGScrSize256x16Pltt;

typedef enum { OVER0=0,OVER1=1 } GXBGAreaOver;

typedef enum { SB0=0,SB31=31 } GXBGScrBase;

typedef enum { CB0=0,CB15=15 } GXBGCharBase;

typedef unsigned u32_021B63DC;

typedef struct { u32_021B63DC w[7]; } Config;

typedef unsigned int   u32_021B655C;

typedef unsigned u32_021B6594;

typedef struct { u16 x,y,z; u8 a,b; } Spec;

typedef signed int     s32;

typedef unsigned int   u32_021B6704;

typedef unsigned int u32_021B6760;

typedef unsigned int   u32_021B6824;

typedef unsigned int   u32_021B687C;

typedef signed char s8;

typedef signed short s16;

typedef unsigned int u32_021B68E8;

typedef unsigned int   u32_021B68F8;

typedef unsigned int   u32_021B6994;

typedef unsigned int   u32_021B6A04;

extern void *func_020490F4(u32_021B6100 id, u32_021B6100 heap);
extern char *func_021B6C70(char *p, int index);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern u8 func_02012984(const struct BigObj *p);
extern u8 func_02011400(int row, int col);
extern void func_0203F4CC(struct RtcTime *),func_0203D34C(unsigned,unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32_021B61C4 i);
extern void func_0204A8D4(u32_021B61C4 i);
extern void func_0204AFD8(u32_021B61C4 i);
extern u32_021B61C4 func_0204B1CC(struct Bank *bank);
extern void func_02049238(void *);
extern u32_021B61C4 func_020307B0(void *p);
extern void func_021B6D00(unsigned char *unused, char *p);
extern void func_0202208C(void *,u32_021B622C,u32_021B622C,u32_021B622C,u32_021B622C,u32_021B622C,u32_021B622C);
extern u32_021B622C func_020221A4(void);
extern void func_021B6A90(u8 *);
extern int func_021B6F2C(int,char *);
extern void func_021B6F24(u8 *,u8 *,int);
extern void func_021B6D3C(u8 *,u8 *);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern int func_02005728(int);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_020434CC(void),func_02043588(void);
extern void func_0202223C(u32_021B63DC a, u32_021B63DC color);
extern u32_021B63DC func_02022224(void *win);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16),func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02082A7C(int,int,u32_021B63DC);
extern void func_0204A48C(const struct Cfg *cfg, u32_021B63DC arg, u32_021B63DC heapId);
extern void func_020434DC(u32_021B63DC mask, u32_021B63DC enable);
extern void func_02043598(u32_021B63DC mask, u32_021B63DC enable);
extern struct Bank *func_0204B100(int count, u8 flag, u32_021B63DC heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_0204A5AC(void),func_020403F4(unsigned),func_020450C8(void),func_0203F9B4(void);
extern void func_0203FCA0(unsigned,const struct BgTemplate *,unsigned);
extern void func_02040588(unsigned,unsigned),func_020414AC(unsigned),func_020409B4(unsigned);
extern void *func_0204A380(void *a0, u32_021B655C a1, u32_021B655C a2, u32_021B655C a3);
extern void func_020498F4(void *,u32_021B6594,u32_021B6594,u32_021B6594,u32_021B6594,u32_021B6594,u16);
extern u8 *func_02012944(void *p);
extern int func_0204ACEC(void *,u32_021B6594,u32_021B6594,u32_021B6594,u16);
extern int func_0204A6C8(void *,u32_021B6594,u32_021B6594,u32_021B6594,u16);
extern s32 func_0204AF28(void *owner, u32_021B6594 first, u32_021B6594 second, u32_021B6594 mode);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *,u32_021B6594,u32_021B6594,u32_021B6594,u32_021B6594,u16);
extern u32_021B6594 func_02049658(void *a, u32_021B6594 b, u32_021B6594 c, u32_021B6594 d, u32_021B6594 e, u32_021B6594 f, u16 g);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32_021B6594 v);
extern void func_0204B92C(struct Obj *p, u32_021B6594 v);
extern unsigned func_021B7360(unsigned char *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021B6704 which);
extern void func_0204B9A0(struct Actor *a);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32_021B6760 heapId);
extern struct MsgBank *func_02045B38(u32_021B6760 resident, u32_021B6760 arcId, u32_021B6760 fileId, u32_021B6760 heapId);
extern void func_0201F5BC(u32_021B6760 a, u32_021B6760 b, u32_021B6760 c, u32_021B6760 d, u16 e);
extern u8 func_0201F548(int i);
extern void func_02049B90(u32_021B6760 a0, u32_021B6760 a1, u32_021B6760 a2, u32_021B6760 a3, u32_021B6760 a4, u32_021B6760 a5, u16 a6);
extern void func_02049B40(u32_021B6760 a, u32_021B6760 b, u32_021B6760 c, u32_021B6760 d, u32_021B6760 e, u16 f);
extern void func_0201DD68(void);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32_021B6760 count, u32_021B6760 workSize);
extern u32_021B6760 func_0201C440(void *p);
extern u32_021B6760 func_02028590(int a, int b, int c, u32_021B6760 d);
extern void func_0201DD78(u32_021B6760 r, u32_021B6760 g, u32_021B6760 b);
extern int func_02028604(int a0);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_020452E8(struct Descriptor *d);
extern u32_021B6824 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern unsigned func_0201CE30(void *);
extern void func_021B7364(char *p, int v);
extern s32 func_02028484(struct Blk *blk, void *h);
extern u32_021B687C func_0201C4E4(struct PrintSys *ps);
extern void func_0201F7A8(void *desc, u32_021B68F8 kind);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(unsigned);
extern void func_0201F73C(void *,int,int,int);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02028470(u8 *p, u32_021B68F8 v);
extern void func_02045334(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern u32_021B68F8 func_020450F0(u32_021B68F8 layer, u32_021B68F8 a, u32_021B68F8 b, u32_021B68F8 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *);
extern void func_021B7350(int,int *);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045EC0(struct MsgBank *bank, u32_021B6A04 index);
extern struct U16Vec *func_020457B0(u32_021B6A04 capacity, u32_021B6A04 heapId);
extern signed char func_02012FFC(void);
extern unsigned func_0201CCE4(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
void func_021B6100(u8 *p);
void func_021B61C4(u8 *p);
int func_021B622C(u8 *p);
void func_021B63B0(void);
void func_021B63DC(u8 *p);
void func_021B6508(unsigned char *p);
void func_021B6538(const struct BgTemplate *p, int i, int type);
void func_021B655C(char *p);
void func_021B6594(u8 *p);
void func_021B6704(u8 *p, int index);
void func_021B6754(char *p);
void func_021B6760(u8 *p);
void func_021B6824(u8 *p);
void func_021B687C(u8 *p);
int func_021B68E8(char *p);
void func_021B68F8(u8 *p,int mode);
void func_021B6994(u8 *p);
void func_021B6A04(u8 *p, int message);
extern const u32_021B63DC d_021B7450[],d_021B7388[],d_021B73D0[],d_021B73B0[],d_021B7410[],d_021B7430[],d_021B73F0[];
extern const Config d_020A1448;
extern const u8 d_021B7380[][2];

void func_021B6100(u8 *p)
{
 struct RtcTime time; unsigned config,lo,mid,hi; u8 i; void *task; unsigned one;
 func_021B63DC(p);
 ((struct Obj01167 *)p)->f18=func_020490F4(131,((struct Obj01167 *)p)->f0);
 func_021B655C((char *)p);func_021B6594(p);func_021B6760(p);
 config=func_02012984(((struct Obj24197 *)(*(u8 * *)&((struct Obj01167 *)p)->f30))->f4);
 lo=func_02011400(config,0);mid=func_02011400(config,2);hi=func_02011400(config,3);
 func_0203F4CC(&time);
 if(time.hour>=lo && time.hour<mid) ((struct Obj01167 *)p)->f10=0;
 else if(time.hour>=mid && time.hour<hi) ((struct Obj01167 *)p)->f10=1;
 else ((struct Obj01167 *)p)->f10=2;
 for(i=0;i<((struct Obj01167 *)p)->f8;i++) *(void **)(p+28+i*4)=func_021B6C70((char *)p,i);
 task=func_020056A0((unsigned)func_021B63B0,(unsigned)p,8);
 one=1;((struct Obj01167 *)p)->fD=one;((struct Obj01167 *)p)->f34=one;
 ((struct Obj01167 *)p)->f4=task;((struct Obj01167 *)p)->f89=0;
 ((struct Obj01167 *)p)->fE=0;((struct Obj01167 *)p)->f14=0;((struct Obj01167 *)p)->f2C=0;((struct Obj01167 *)p)->fC=0;
 func_0203D34C(0,((struct Obj01167 *)p)->f0);
}

void func_021B61C4(u8 *p)
{
    u8 i;
    func_02030EAC(((struct Obj00681 *)p)->f4);
    func_021B6824(p);
    for(i=0;i<((struct Obj00681 *)p)->f8;i++) if(*(void **)(p+28+i*4)) func_021B6D00(p,*(void **)(p+28+i*4));
    func_0204B3B4(((struct Obj00681 *)p)->f54);
    func_0204ADA4((u32_021B61C4)(((struct Obj00681 *)p)->f44));
    func_0204A8D4((u32_021B61C4)(((struct Obj00681 *)p)->f48));
    func_0204AFD8((u32_021B61C4)(((struct Obj00681 *)p)->f4C));
    func_0204B1CC(((struct Obj00681 *)p)->f50);
    func_02049238(((struct Obj00681 *)p)->f18);
    func_021B6508(p);
    func_020307B0(((struct Obj00681 *)p)->f38);
}

static inline void G2_SetBG2Control256x16Affine(GXBGScrSize256x16Pltt size,GXBGAreaOver over,GXBGScrBase scr,GXBGCharBase chr)
{
    *(volatile u16 *)0x0400000C=(u16)((*(volatile u16 *)0x0400000C &0x43)|(size<<14)|(chr<<2)|(scr<<8)|(over<<13));
}

static inline void G2_SetBG3Control256x16Affine(GXBGScrSize256x16Pltt size,GXBGAreaOver over,GXBGScrBase scr,GXBGCharBase chr)
{
    *(volatile u16 *)0x0400000E=(u16)((*(volatile u16 *)0x0400000E &0x43)|(size<<14)|(chr<<2)|(scr<<8)|(over<<13));
}

int func_021B622C(u8 *p)
{
    GXBGCharBase a,b;
    unsigned state;
    u8 i;
    switch(p[12]) {
    case 0:
        func_0202208C(0,1,1,0,6,1,((struct Obj00152 *)p)->f0);
        p[12]=1;
        break;
    case 1:
        if(func_020221A4()==1) p[12]=4;
        break;
    case 2:
        func_0202208C(0,0,0,0,6,1,((struct Obj00152 *)p)->f0);
        p[12]=3;
        break;
    case 3:
        if(func_020221A4()==1) return 1;
        break;
    case 4:
        func_021B6A90(p);
        break;
    }
    if(p[14]<20) p[14]++;
    if(*(int *)&((struct Obj00152 *)p)->f2C==0 && ((struct Obj00152 *)p)->f14==4) {
        if(p[13]==0) {a=4;b=10;} else {a=7;b=13;}
        G2_SetBG2Control256x16Affine(SZ1,OVER1,(GXBGScrBase)13,a);
        G2_SetBG3Control256x16Affine(SZ1,OVER1,(GXBGScrBase)14,b);
        p[13]=p[13]==0?1:0;
        ((struct Obj00152 *)p)->f14=0;
        p[14]=0;
    }
    if(*(char * *)&((struct Obj00152 *)p)->f2C!=0 && func_021B6F2C((int)p,*(char * *)&((struct Obj00152 *)p)->f2C)==1)
        *(char * *)&((struct Obj00152 *)p)->f2C=0;
    if(*(int *)&((struct Obj00152 *)p)->f2C==0) {
        state=*(unsigned *)&((struct Obj00152 *)p)->f14;
        switch(state) {
        case 0: case 1: case 2: case 3: {
            u32_021B622C index=(u8)state*4;
            u32_021B622C table=(u32_021B622C)p+28;
            if(*(u8 **)(table+index)!=0) {
                func_021B6F24(p,*(u8 **)(table+index),p[13]);
                *(u8 * *)&((struct Obj00152 *)p)->f2C=*(u8 **)(table+index);
                if(((struct Obj00152 *)p)->f8==2 && ((struct Obj00152 *)p)->f14==1) ((struct Obj00152 *)p)->f14=4;
                else (((struct Obj00152 *)p)->f14)++;
            } else ((struct Obj00152 *)p)->f14=state+1;
            break;
        }
        }
    }
    for(i=0;i<((struct Obj00152 *)p)->f8;i++) {
        if(*(u8 **)(p+28+i*4)!=0) func_021B6D3C(p,*(u8 **)(p+28+i*4));
    }
    func_021B687C(p);
    func_0204A600();
    return 0;
}

void func_021B63B0(void) {func_0204A648();func_02040618(1,0,func_02005728(256));func_02040618(1,3,func_02005728(256));}

/*
 *   one --arm, no region: MATCH, 16 bytes, blocker434CC.log; concrete bytes agree,
 *   unresolved 020434B4 is also omitted from that owner unit's function header.
 *   Scratch copy of owner unit also verifies TU EXACT: blocker434unit.log.
 *   extern void func_0204349C(void),func_020434B4(void);
 *   void func_020434CC(void) {func_0204349C();func_020434B4();}
 *   one --arm, no region: EXACT, 16 bytes, blocker43588.log.
 *   extern void func_02043558(void),func_02043570(void);
 *   void func_02043588(void) {func_02043558();func_02043570();}
 *   retained without an overlay token, ROM pool +0128 names 020A1448.
 * volatile: DISPCNT reads/writes 021B63EE..021B63FE; blend writes 021B6420/6424; POWCNT1 read/write 021B6426..642E.
 */
void func_021B63DC(u8 *p)
{
    Config c;
    func_020434CC();
    func_02043588();
    *(volatile u32_021B63DC *)0x04000000 &= ~0x1F00;
    *(volatile u32_021B63DC *)0x04001000 &= ~0x1F00;
    func_0202223C(0,0);
    func_0202223C(1,0);
    func_02022224(0);
    func_02022224((void *)1);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u16 *)0x04000304 |=0x8000;
    func_020433E0((const struct DispVram *)d_021B7450);
    func_0203F8F4(*(u16 *)p);
    func_02045088(*(u16 *)p);
    func_0203FC28((void *)d_021B7388);
    func_021B6538((const struct BgTemplate *)d_021B73D0,0,0);
    func_021B6538((const struct BgTemplate *)d_021B73B0,1,0);
    func_021B6538((const struct BgTemplate *)d_021B7410,2,2);
    func_021B6538((const struct BgTemplate *)d_021B7430,3,2);
    func_021B6538((const struct BgTemplate *)d_021B73F0,7,0);
    func_02082A7C(0,0x06000000,0x40000);
    c=d_020A1448;
    func_0204A48C((const struct Cfg *)(&c),(u32_021B63DC)d_021B7450,*(u16 *)p);
    func_020434DC(16,1);
    func_02043598(16,1);
    *(void **)(p+80)=func_0204B100(16,0,*(u16 *)p);
    func_0204B270(*(void **)(p+80));
    func_0207D63C((void *)0x04000050,1,30,16,4);
}

void func_021B6508(unsigned char *p) {func_0204A5AC();func_020403F4(7);func_020403F4(3);func_020403F4(2);func_020403F4(1);func_020403F4(0);func_020450C8();func_0203F9B4();}

void func_021B6538(const struct BgTemplate *p, int i, int type) {func_0203FCA0(i,p,type);func_02040588(i,1);func_020414AC(i);func_020409B4(i);}

void func_021B655C(char *p) {unsigned char *q=func_0204A380(((struct Obj03859 *)p)->f18,**(unsigned short * *)&((struct Obj03859 *)p)->f30+62,0,((struct Obj03859 *)p)->f0);((struct Obj03859 *)p)->f38=q;((struct Obj03859 *)p)->f3C=q;((struct Obj03859 *)p)->f40=q+8;if(q[2]==255 && q[3]==255) ((struct Obj03859 *)p)->f8=2;else ((struct Obj03859 *)p)->f8=4;}

void func_021B6594(u8 *p)
{
    int id=37;
    void *save;
    void *arc;
    Spec s;
    if(((struct Obj00545 *)p)->f8!=2) id=38;
    func_020498F4(((struct Obj00545 *)p)->f18,id,2,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(((struct Obj00545 *)p)->f18,id,3,0,0,0,((struct Obj00545 *)p)->f0);
    save=func_02012944(((struct Obj24199 *)(*(u8 * *)&((struct Obj00545 *)p)->f30))->f4);
    arc=func_020490F4(172,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f44=func_0204ACEC(arc,3,0,0,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f48=func_0204A6C8(arc,24,0,0,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f4C=func_0204AF28(arc,20,22,((struct Obj00545 *)p)->f0);
    if(func_02008550(save)==0) func_02049B68(arc,7,4,0,0x60,((struct Obj00545 *)p)->f0);
    else func_02049B68(arc,6,4,0,0x60,((struct Obj00545 *)p)->f0);
    func_02049658(arc,11,7,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(arc,14,7,0,0,0,((struct Obj00545 *)p)->f0);
    func_020409B4(7);
    func_02049B68(arc,0,0,0x160,0x20,((struct Obj00545 *)p)->f0);
    func_02049658(arc,8,1,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(arc,13,1,0,0,0,((struct Obj00545 *)p)->f0);
    func_020413B0(1,0,0,32,32,11);
    func_020409B4(1);
    func_02049238(arc);
    s.a=10; s.b=1; s.x=0;s.y=0;s.z=0;
    ((struct Obj00545 *)p)->f54=func_0204B294((void *)((struct Obj00545 *)p)->f50,((struct Obj00545 *)p)->f48,((struct Obj00545 *)p)->f44,((struct Obj00545 *)p)->f4C,&s,0,((struct Obj00545 *)p)->f0);
    func_0204B3DC(((struct Obj00545 *)p)->f54,0);
    func_0204B92C(((struct Obj00545 *)p)->f54,1);
}

void func_021B6704(u8 *p, int index)
{
    u16 point[2];
    unsigned width;
    unsigned x;
    unsigned y;
    width = func_021B7360(*((void **) ((p + 28) + (index * 4))));
    width = width / 2;
    x = ((d_021B7380[index][0] * 8) + 80) + width;
    point[0] = x;
    y = (d_021B7380[index][1] * 8) + 16;
    point[1] = y;
    func_0204B404(*((void **) (p + 84)), (const struct Vec2 *)point, 0);
    func_0204B3DC(*((void **) (p + 84)), 1);
    func_0204B9A0(*((void **) (p + 84)));
}

void func_021B6754(char *p) {func_0204B3DC(*(struct Obj * *)&((struct Obj24200 *)p)->f54,0);}


void func_021B6760(u8 *p)
{
    ((struct Obj00918 *)p)->f60 = (u32_021B6760)func_0201D7EC(0x17, 0, 0, 0, ((struct Obj00918 *)p)->f0);
    ((struct Obj00918 *)p)->f68 = (u32_021B6760)func_02045B38(0, 2, 0xc6, ((struct Obj00918 *)p)->f0);
    ((struct Obj00918 *)p)->f6C = (u32_021B6760)func_02045B38(0, 2, (u16)(*(u16 *)(((struct Obj00918 *)p)->f30) + 0xbf), ((struct Obj00918 *)p)->f0);
    func_0201F5BC(0, 1, 0xd, 0, ((struct Obj00918 *)p)->f0);
    func_02049B90(5, func_0201F548(0), 0, 0x20, 0x1a0, 0x20, ((struct Obj00918 *)p)->f0);
    func_02049B40(0x17, 7, 0, 0x180, 0x20, ((struct Obj00918 *)p)->f0);
    func_0201DD68();
    ((struct Obj00918 *)p)->f58 = (u32_021B6760)func_0203101C(((struct Obj00918 *)p)->f0, ((struct Obj00918 *)p)->f0, 3, 0x100);
    ((struct Obj00918 *)p)->f64 = 0;
    ((struct Obj00918 *)p)->f5C = 0;
    ((struct Obj00918 *)p)->f70 = 0;
    ((struct Obj00918 *)p)->f74 = 0;
    ((struct Obj00918 *)p)->f78 = func_0201C440((void *)(((struct Obj00918 *)p)->f0));
    ((struct Obj00918 *)p)->f7C = func_02028590(0xf, 1, 1, ((struct Obj00918 *)p)->f0);
    func_0201DD78(1, 2, 0xf);
}

/*
 * extent: Two zero alignment bytes 021B687A..021B687C.
 */
void func_021B6824(u8 *p)
{
    func_02028604((int)(((struct Obj00681 *)p)->f7C));
    func_0201C4C0(((struct Obj00681 *)p)->f78);
    if(((struct Obj00681 *)p)->f64) func_0201CE48(((struct Obj00681 *)p)->f64);
    if(((struct Obj00681 *)p)->f70) func_02045808(((struct Obj00681 *)p)->f70);
    if(((struct Obj00681 *)p)->f74) func_0201ED04(((struct Obj00681 *)p)->f74);
    func_02045C04(((struct Obj00681 *)p)->f6C);
    func_02045C04(((struct Obj00681 *)p)->f68);
    if(((struct Obj00681 *)p)->f5C) func_020452E8(((struct Obj00681 *)p)->f5C);
    func_0201D83C(((struct Obj00681 *)p)->f60);
    func_02031140(((struct Obj00681 *)p)->f58);
    func_0201DD68();
}

void func_021B687C(u8 *p)
{
    func_020310C4(((struct Obj00152 *)p)->f58);
    if(((struct Obj00152 *)p)->f64) {
        func_020286C4(((struct Obj00152 *)p)->f7C,((struct Obj00152 *)p)->f64,((struct Obj00152 *)p)->f5C);
        if(func_0201CE30(((struct Obj00152 *)p)->f64)!=0) func_021B7364(*(void **)(p+28+((struct Obj00152 *)p)->f88*4),0);
        else func_021B7364(*(void **)(p+28+((struct Obj00152 *)p)->f88*4),1);
        if(func_02028484((struct Blk *)(p+128),((struct Obj00152 *)p)->f64)==1) {
            func_0201CE48(((struct Obj00152 *)p)->f64);
            ((struct Obj00152 *)p)->f64=0;
            func_02045808(((struct Obj00152 *)p)->f70);
            ((struct Obj00152 *)p)->f70=0;
        }
    }
    func_0201C4E4(((struct Obj00152 *)p)->f78);
}


int func_021B68E8(char *p)
{
    return ((struct Obj24201 *)p)->f64 == 0;
}

/*
 * extent: 0x021B6992..0x021B6994 is two zero alignment bytes.
 */
void func_021B68F8(u8 *p,int mode)
{
 void *tmp;
 if(((struct Obj02507 *)p)->f5C){
 func_0201F7A8(((struct Obj02507 *)p)->f5C,1);
 tmp=((struct Obj02507 *)p)->f5C;func_020456F8(tmp);func_02041B6C(func_02045730(tmp));
 func_020452E8(((struct Obj02507 *)p)->f5C);((struct Obj02507 *)p)->f5C=0;
 }
 if(mode==0) ((struct Obj02507 *)p)->f5C=(void *)func_020450F0(0,1,1,30,4,12,1);
 else if(mode==1) ((struct Obj02507 *)p)->f5C=(void *)func_020450F0(0,1,19,30,4,12,1);
 func_0201F73C(((struct Obj02507 *)p)->f5C,1,1,13);
 func_02043B5C(func_02045770(((struct Obj02507 *)p)->f5C),15);
 func_02045334(((struct Obj02507 *)p)->f5C);func_02045374(((struct Obj02507 *)p)->f5C);
 func_02041B6C(0);func_02028470(p+128,6);
}

void func_021B6994(u8 *p)
{
 void *tmp; u8 i;
 if(((struct Obj02218 *)p)->f5C){
 func_0201F7A8(((struct Obj02218 *)p)->f5C,1);tmp=((struct Obj02218 *)p)->f5C;
 func_020456F8(tmp);func_02041B6C(func_02045730(tmp));
 func_020452E8(((struct Obj02218 *)p)->f5C);((struct Obj02218 *)p)->f5C=0;
 }
 if(((struct Obj02218 *)p)->f64){func_0201CE48(((struct Obj02218 *)p)->f64);((struct Obj02218 *)p)->f64=0;}
 if(((struct Obj02218 *)p)->f70){func_02045808(((struct Obj02218 *)p)->f70);((struct Obj02218 *)p)->f70=0;}
 for(i=0;i<((struct Obj02218 *)p)->f8;i++) if(*(int **)(p+28+i*4)) func_021B7350((int)p,*(int **)(p+28+i*4));
}

/*
 * extent: 0x021B6A8E..0x021B6A90 is two zero alignment bytes.
 */
void func_021B6A04(u8 *p, int message)
{
 void *tmp; unsigned speed;
 if(((struct Obj00919 *)p)->f64){func_0201CE48(((struct Obj00919 *)p)->f64);((struct Obj00919 *)p)->f64=0;}
 if(((struct Obj00919 *)p)->f70){func_02045808(((struct Obj00919 *)p)->f70);((struct Obj00919 *)p)->f70=0;}
 func_02043B5C(func_02045770(((struct Obj00919 *)p)->f5C),15);
 ((struct Obj00919 *)p)->f70=func_02045EC0(((struct Obj00919 *)p)->f6C,message);
 if(((struct Obj00919 *)p)->f74){
 tmp=func_020457B0(1024,((struct Obj00919 *)p)->f0);
 func_0201F250(((struct Obj00919 *)p)->f74,tmp,((struct Obj00919 *)p)->f70);
 func_02045808(((struct Obj00919 *)p)->f70);((struct Obj00919 *)p)->f70=tmp;
 }
 speed=func_02012FFC();
 *(unsigned *)&((struct Obj00919 *)p)->f64=func_0201CCE4(*(unsigned *)&((struct Obj00919 *)p)->f5C,0,0,*(unsigned *)&((struct Obj00919 *)p)->f70,((struct Obj00919 *)p)->f60,speed,((struct Obj00919 *)p)->f58,2,((struct Obj00919 *)p)->f0,15);
}
