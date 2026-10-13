/*
 * file:     pdc.c
 * unit:     yes
 * function: func_021B6100, func_021B613C, func_021B6140, func_021B6144, func_021B6148, func_021B614C, func_021B6150, func_021B6154, func_021B6158, func_021B615C, func_021B61A4, func_021B61C4, func_021B61E8, func_021B6308, func_021B632C, func_021B6364, func_021B636C, func_021B6438, func_021B644C, func_021B6504, func_021B6578, func_021B6750, func_021B67A4, func_021B67D4, func_021B68DC, func_021B6910, func_021B694C, func_021B6988, IRC_COMPATIBLE_ProcExit, func_021B6A00, func_021B6A3C, func_021B6B5C, func_021B6B68, func_021B6B74, func_021B6B8C, func_021B6C34, func_021B6C60, func_021B6C90
 * address:  0x021B6100
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021B6E60 0x021B6E60 data a1
 *   ov094_id       0x0000005E  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_021F73F0 0x021F73F0 thumb ov094
 *   func_021F7544 0x021F7544 thumb ov094
 *   func_020307B0 0x020307B0 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_02202058 0x02202058 thumb ov094
 *   func_0203101C 0x0203101C arm
 *   func_02008254 0x02008254 thumb
 *   d_021B6E68 0x021B6E68 data a1
 *   d_021B6D80 0x021B6D80 data a2
 *   func_020310C4 0x020310C4 arm
 *   func_021F78E4 0x021F78E4 thumb ov094
 *   func_02202228 0x02202228 thumb ov094
 *   func_02031140 0x02031140 arm
 *   func_021F7808 0x021F7808 thumb ov094
 *   func_022021F4 0x022021F4 thumb ov094
 *   func_0201D83C 0x0201D83C thumb
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02046440 0x02046440 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204044C 0x0204044C arm
 *   func_020434DC 0x020434DC arm
 *   d_021B6DF4 0x021B6DF4 data a4
 *   d_021B6DB0 0x021B6DB0 data a4
 *   d_021B6DD8 0x021B6DD8 data a4
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02046788 0x02046788 arm
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_021F7998  0x021F7998  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021F8090  0x021F8090  thumb  ov094
 *   func_0220270C  0x0220270C  thumb  ov094
 *   func_02202DC4  0x02202DC4  thumb  ov094
 *   d_021B6D98     0x021B6D98  data   ov098  a4
 *   d_021B6DC0     0x021B6DC0  data   ov098  a4
 *   ov196_id 0x000000C4 data
 *   ov197_id 0x000000C5 data
 *   func_022025D8 0x022025D8 thumb ov094
 *   func_022026FC 0x022026FC thumb ov094
 *   func_0220266C 0x0220266C thumb ov094
 *   func_0220C834 0x0220C834 thumb ov197
 *   func_021F7CFC 0x021F7CFC thumb ov094
 *   func_021F7C0C 0x021F7C0C thumb ov094
 *   func_02007F1C 0x02007F1C thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   PALANM_GetPairedCodeForFirst 0x0202142C thumb
 *   func_02017E40 0x02017E40 thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   func_0207D55C 0x0207D55C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02045B38 0x02045B38 arm
 *   CONFIG_GetTextSpeed 0x02008374 thumb
 *   func_02013080 0x02013080 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02041300 0x02041300 arm
 *   func_02040C14 0x02040C14 arm
 *   func_020496E4 0x020496E4 arm
 *   PALANM_LoadArcPaletteToSlotAt 0x020215EC thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   BMP_WIN_DrawFrame 0x020454E0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   d_021B6E74 0x021B6E74 data a4
 *   d_021B6E24 0x021B6E24 data a4
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020403F4 0x020403F4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021B6CDC 0x021B6CDC thumb ov098
 *   PRINTSYS_PrintStreamRun 0x0201CE20 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   PRINTSYS_PrintStreamStop  0x0201CE0C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0207D63C  0x0207D63C  arm
 */
#include "../../matched/include/Obj21998.h"
#include "../../matched/include/Obj21999.h"
#include "../../matched/include/Obj22000.h"
#include "../../matched/include/Obj22001.h"
#include "../../matched/include/Obj22002.h"
#include "../../matched/include/Obj22003.h"
#include "../../matched/include/Obj22004.h"
#include "../../matched/include/Obj10195.h"
#include "../../matched/include/Obj10196.h"
#include "../../matched/include/Obj05258.h"
#include "../../matched/include/Obj00381.h"
#include "../../matched/include/Obj03730.h"
#include "../../matched/include/Obj01704.h"
#include "../../matched/include/Obj05259.h"
#include "../../matched/include/Obj07936.h"
#include "../../matched/include/Obj00466.h"
#include "../../matched/include/Obj07937.h"
#include "../../matched/include/Obj04409.h"
#include "../../matched/include/Obj03220.h"

#define P_021B61C4(k) (*(void **)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define BLDCNT (*(volatile u16 *)0x04000050)
#define SBLDCNT (*(volatile u16 *)0x04001050)
#define POWCNT (*(volatile u16 *)0x04000304)
#define DISP3DCNT (*(volatile u16 *)0x04000060)
#define BG0CNT (*(volatile u16 *)0x04000008)
struct Obj0203159C;
struct S020315D4;
struct GfFont;
struct Tcbl;
struct Obj;
struct S02031140;
struct DispVram;
struct DispConfig;
struct Cfg;
struct P_021B61C4;
struct W;
struct BgTemplate;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PalAnmSlot;
struct Rec3;
struct Descriptor;
struct CharBuf;
typedef unsigned int u32;

typedef unsigned short u16;

struct P_021B6100 { u32 a, b, c, d, e, f, g, h; };

typedef unsigned char u8;

typedef short s16;

typedef signed char s8;

typedef int s32;

struct W {
    u8 *f00;
    u32 f04;
    u16 f08;
};

struct Halves { u16 a,b,c,d; };

typedef int s32_021B61C4;

struct P_021B61C4 {
    void *parent; u32 pad04; void *w08; u32 pad0c; char *window; u8 *object; u32 pad18;
    u32 b1c; void *w20; u32 w24; u16 h28; u8 pad2a[6]; u8 b30, b31; u16 h32;
    u8 pad34, b35; u8 pad36[2]; void *w38; u32 w3c; u8 pad40[8]; u8 *w48;
    u8 pad4c[16]; u32 w5c, state; int timer; u32 pad68; u16 heap; u16 pad6e;
    void *w70; u8 workspace[1];
};

typedef signed int     s32_021B6504;

struct PdcWork {
    u8 pad_0[32];
    struct MsgBank *f20;
    u8 pad_24[8];
    void *f2C;
    struct WordSet *f30;
};

extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_02034AC4(int id);
extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082AC0(int v, void *p, u32 n);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int);
extern struct GfFont *func_0201D7EC(int,int,int,int,u32);
extern void *func_021F73F0(int,int,void *,int,u16 *,int,int,u16);
extern void func_021F7544(void *,int,u16);
extern u32 func_020307B0(void *p);
extern int func_021F86E0(void);
extern struct Obj *func_02202058(int a, int b, int c, int d, int e, u16 k);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02008254(u32);
extern void func_020310C4(struct Tcbl *p);
extern void func_021F78E4(void);
extern void func_02202228(void **);
extern void func_02031140(struct S02031140 *p);
extern void func_021F7808(void);
extern void func_022021F4(struct Obj *p);
extern unsigned int func_0201D83C(void *ptr);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *);
extern void func_0203FC28(struct DispConfig *);
extern void func_02046440(u32, u32, u32, u32, u16, u32, void (*)(void));
extern void func_02046BE0(u32, u32);
extern void func_0207DC44(int, int, int, int);
extern void func_0204A48C(const struct Cfg *, u32, u32);
extern void func_0204044C(u32);
extern void func_020434DC(u32, u32);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0204A5AC(void);
extern void func_02046788(void);
extern void func_021F7EE8(void *m, int key);
extern void func_021F7998(u32 a);
extern int func_021F7EB4(void);
extern void func_021F8090(u32 a, u32 b, u32 c);
extern void func_0220270C(char *s, int mode, void *arg);
extern int func_02202DC4(int a, char *b, char *c);
extern void func_022025D8(char *, int);
extern int func_022026FC(struct W *p);
extern void func_0220266C(struct Obj *p);
extern void func_0220C834(u8 *);
extern void func_021F7CFC(u32, u16, u8, int, int);
extern void func_021F7C0C(void);
extern u32 func_02007F1C(u8 *, u16, u16, u16);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u16);
extern int func_02005F38(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_0204E720(u32, int, int, int);
extern int func_0204E804(void);
extern unsigned short PALANM_GetPairedCodeForFirst(int a0);
extern void func_02017E40(void *, u32, u32);
extern void GFL_USE_FadeOutBgm(u32 a);
extern int func_0207D55C(volatile u16 *reg);
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern struct MsgBank *func_02045B38(u32, u32, u32, u32);
extern u32 CONFIG_GetTextSpeed(int);
extern signed char func_02013080(u32);
extern struct U16Vec *func_020457B0(u32, u32);
extern struct WordSet *func_0201EC64(u32);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02040C14(u32, u32, u32, u32);
extern u32 func_020496E4(u32, u32, u32, u32, u32, u16);
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *, u32, u32, u32, u32, u32, u16, u16);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void func_02045374(struct Cfg *);
extern void BMP_WIN_DrawFrame(struct Cfg *, u16, u32);
extern void func_020409B4(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(void *);
extern void func_0201CE48(void *);
extern void func_020403F4(int);
extern void func_02045C04(void *);
extern void func_020452E8(void *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_021B6CDC(u8 *);
extern void PRINTSYS_PrintStreamRun(void *);
extern u32 func_0201CE30(void *);
extern void func_0201CE38(void *);
extern void func_0201DD68(void);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_02045334(struct Descriptor *);
extern void func_0201DD78(u32, u32, u32);
extern void *func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void PRINTSYS_PrintStreamStop(void *);
extern void func_0201C7A4(void *, short, short, void *, void *);
extern void func_0207D63C(int, int, int, int, int);
struct P_021B6100 *func_021B6100(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 heap);
int func_021B613C(void *p);
int func_021B6140(void *p);
int func_021B6144(void *p);
u32 func_021B6148(u8 *p);
int func_021B614C(int *p);
u32 func_021B6150(u8 *p);
int func_021B6154(void *p);
int func_021B6158(void *p);
int func_021B615C(struct Obj0203159C *a, int b, int c);
int func_021B61A4(int a, int b, int c, unsigned p);
int func_021B61C4(void *a, int b, int c, void **p);
u8 *func_021B61E8(void *input,u16 heap);
int func_021B6308(unsigned p);
void func_021B632C(unsigned p);
void func_021B6364(u8 *p, u32 v);
void func_021B636C(u16 heap);
void func_021B6438(void);
int func_021B644C(char *p);
int func_021B6504(char *p);
int func_021B6578(struct P_021B61C4 *p);
int func_021B6750(char *p);
void func_021B67A4(int a);
u8 *func_021B67D4(void *a, void *b, void *c, u32 heap);
void func_021B68DC(u8 *p);
void func_021B6910(struct PdcWork *p, void *q);
void func_021B694C(struct PdcWork *p, u8 *q);
void func_021B6988(struct PdcWork *p, void *q);
void IRC_COMPATIBLE_ProcExit(struct PdcWork *p, void *q);
void func_021B6A00(u8 *p,u8 *q);
int func_021B6A3C(u8 *p);
void func_021B6B5C(char *p);
int func_021B6B68(char *p);
int func_021B6B74(unsigned char *p);
void func_021B6B8C(char *a, int b);
void func_021B6C34(char *p, int a);
void func_021B6C60(char *p);
void func_021B6C90(char *p, int flag);
extern const char d_021B6E60[];
extern char ov094_id[];
extern const char d_021B6E68[];
extern const struct Halves d_021B6D80;
extern const struct DispVram d_021B6DF4;
extern struct DispConfig d_021B6DB0;
extern const struct Cfg d_021B6DD8;
extern char d_021B6D98[];
extern char d_021B6DC0[];
extern char ov196_id[], ov197_id[];
extern const char d_021B6E74[];
extern const struct BgTemplate d_021B6E24;


struct P_021B6100 *func_021B6100(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 heap)
{
    struct P_021B6100 *p;
    p = func_02030734(heap, 0x20, 0, d_021B6E60, 0x50);
    p->a = a; p->b = b; p->c = c; p->d = d;
    p->e = e; p->f = f; p->g = g; p->h = 0;
    return p;
}



int func_021B613C(void *p)
{
    return ((struct Obj21998 *)p)->f0;
}



/*
 * three int getters at +0, +4, +8.
 */
int func_021B6140(void *p)
{
    return ((struct Obj21999 *)p)->f4;
}



int func_021B6144(void *p)
{
    return ((struct Obj22000 *)p)->f8;
}



u32 func_021B6148(u8 *p) { return ((struct Obj22001 *)p)->fC; }


int func_021B614C(int *p)
{
    return p[4];
}



u32 func_021B6150(u8 *p) { return ((struct Obj22002 *)p)->f14; }



int func_021B6154(void *p)
{
    return ((struct Obj22003 *)p)->f18;
}



int func_021B6158(void *p)
{
    return ((struct Obj22004 *)p)->f1C;
}



int func_021B615C(struct Obj0203159C *a, int b, int c)
{
    struct W *p;

    func_02034AC4((int)ov094_id);
    func_0203064C(1, 0x85, 0xc0000);
    p = func_0203159C(a, 0xc, 0x85);
    func_02082AC0(0, p, 0xc);
    p->f08 = 0x85;
    p->f00 = func_021B61E8((void *)c, p->f08);
    p->f04 = c;
    return 1;
}


int func_021B61A4(int a, int b, int c, unsigned p)
{
    *(int *)(((struct Obj10195 *)p)->f4 + 0x1c) = func_021B6308((unsigned int)(((struct Obj10195 *)p)->f0));
    if (*(int *)(((struct Obj10195 *)p)->f4 + 0x1c) != 0) return 1;
    return 0;
}






int func_021B61C4(void *a, int b, int c, void **p)
{
    func_021B632C((unsigned int)(*p));
    func_020315D4(a);
    func_020306F0(0x85);
    func_02034A5C((int)ov094_id);
    return 1;
}






u8 *func_021B61E8(void *input,u16 heap)
{
    u8 *p;
    struct Halves h;
    void *q;
    int ctx;
    p=func_02030734(heap,0x78,1,d_021B6E68,0x5e);
    H(0x6c)=heap;
    P_021B61C4(0)=input;
    func_021B636C(H(0x6c));
    P_021B61C4(8)=func_0201D7EC(23,0,0,0,H(0x6c));
    P_021B61C4(12)=func_0201D7EC(23,2,0,0,H(0x6c));
    *(u32 *)(p+0x60)=0;
    h=d_021B6D80;
    q=func_021F73F0(0,0,(void *)func_021B6144(input),0,(u16 *)&h,0,0,H(0x6c));
    func_021F7544(q,(int)P_021B61C4(12),H(0x6c));
    func_020307B0(q);
    ctx=func_021B613C(input);
    P_021B61C4(16)=(void *)func_02202058(ctx,0,func_021F86E0(),(int)P_021B61C4(8),(int)(p+0x74),H(0x6c));
    P_021B61C4(24)=func_0203101C(heap,heap,64,128);
    *(int *)(p+4)=func_021B6140(input);
    P_021B61C4(20)=func_021B67D4(P_021B61C4(8),(void *)func_021B6150(input),P_021B61C4(24),H(0x6c));
    P_021B61C4(0x70)=func_02008254(H(0x6c));
    func_021B6364(p,(u32)func_021B644C);
    return p;
}






int func_021B6308(unsigned p)
{
    int (*cb)(unsigned);
    func_020310C4(((struct Obj10196 *)p)->f18);
    func_021F78E4();
    func_02202228(*(void ** *)&((struct Obj10196 *)p)->f10);
    cb = *(int (**)(unsigned))(p + 0x68);
    if (cb != 0) return cb(p);
    return 0;
}






void func_021B632C(unsigned p)
{
    func_02031140(((struct Obj05258 *)p)->f18);
    func_021B68DC(((struct Obj05258 *)p)->f14);
    func_021F7808();
    func_022021F4(((struct Obj05258 *)p)->f10);
    func_0201D83C(((struct Obj05258 *)p)->f8);
    func_0201D83C(((struct Obj05258 *)p)->fC);
    func_021B6438();
    func_020307B0(((struct Obj05258 *)p)->f70);
    func_020307B0((void *)p);
}







void func_021B6364(u8 *p, u32 v) { *(u32 *)&((struct Obj00381 *)p)->f60 = 0; ((struct Obj00381 *)p)->f68 = v; }






void func_021B636C(u16 heap)
{
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0201DD60();
    func_020433E0(&d_021B6DF4);
    BLDCNT = 0;
    SBLDCNT = 0;
    POWCNT = (u16)(POWCNT | 0x8000);
    func_0203FC28(&d_021B6DB0);
    func_02046440(0, 1, 0, 1, 0, heap, 0);
    func_02046BE0(1, 0);
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 8);
    DISP3DCNT &= (u16)~0x3020;
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 16);
    func_0207DC44(0, 0, 0, 0);
    BG0CNT = (u16)((BG0CNT & ~3) | 1);
    func_0204A48C(&d_021B6DD8, (u32)&d_021B6DF4, heap);
    func_0204044C(1);
    func_020434DC(16, 1);
}






void func_021B6438(void)
{
    func_020450C8(); func_0203F9B4(); func_0204A5AC(); func_02046788();
}







int func_021B644C(char *p)
{
    int r;

    switch (((struct Obj00381 *)p)->f60) {
    case 0:
        func_021B6B5C((char *)(((struct Obj00381 *)p)->f14));
        ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        break;
    case 1:
        if (func_021B6B68((char *)(((struct Obj00381 *)p)->f14)) != 0) {
            func_021F7EE8(((struct Obj00381 *)p)->f4, 1);
            func_021F7998(0x231);
            func_021B67A4(2);
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            func_021B6910((struct PdcWork *)(((struct Obj00381 *)p)->f14), (void *)(*(int *)&((struct Obj00381 *)p)->f0));
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 3:
        if (func_021B6A3C((u8 *)(((struct Obj00381 *)p)->f14)) != 0) {
            r = func_021B6154(((struct Obj00381 *)p)->f0);
            func_021F8090(r, func_021B6140(((struct Obj00381 *)p)->f0), 1);
            func_021B6B5C((char *)(((struct Obj00381 *)p)->f14));
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 4:
        if (func_021B6B68((char *)(((struct Obj00381 *)p)->f14)) != 0) {
            func_021F7998(0x23e);
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 5:
        if (func_021F7EB4() == 0)
            func_021B6364((u8 *)p, (u32)func_021B6504);
        break;
    }
    return 0;
}







int func_021B6504(char *p)
{
    int r;

    switch (((struct Obj00381 *)p)->f60) {
    case 0:
        func_021B694C((struct PdcWork *)((u8 *)(((struct Obj00381 *)p)->f14)), (u8 *)(*(int *)&((struct Obj00381 *)p)->f0));
        ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        break;
    case 1:
        if (func_021B6A3C((u8 *)(((struct Obj00381 *)p)->f14)) != 0) {
            func_0220270C((char *)(((struct Obj00381 *)p)->f10), 7, 0);
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 2:
        r = func_02202DC4(((struct Obj00381 *)p)->f10, d_021B6D98, d_021B6DC0);
        if (r != -1) {
            if (r != 0)
                func_021B6364((u8 *)p, (u32)func_021B6750);
            else
                func_021B6364((u8 *)p, (u32)func_021B6578);
        }
        break;
    }
    return 0;
}






int func_021B6578(struct P_021B61C4 *p)
{
    u32 t;
    switch (p->state) {
    case 0:
        p->b1c = func_021B614C(p->parent);
        p->w38 = p->w70;
        p->w24 = 3;
        p->w20 = p->w08;
        p->h28 = p->heap;
        p->h32 = 0;
        p->w3c = 0;
        p->b30 = 0; p->b31 = 0; p->b35 = 0;
        p->w48 = p->workspace;
        p->w5c = 1;
        func_022025D8(p->window, 1);
        func_02034AC4((s32_021B6504)ov196_id);
        (p->state)++;
        break;
    case 1:
        if (!func_022026FC((struct W *)p->window)) {
            func_02034AC4((s32_021B6504)ov197_id);
            func_0220C834((u8 *)&p->b1c);
            (p->state)++;
        }
        break;
    case 2:
        if (p->b35) {
            func_02034A5C((s32_021B6504)ov196_id); func_02034A5C((s32_021B6504)ov197_id);
            func_0220266C((struct Obj *)p->window);
            if (p->h32 == 0) p->state = 3;
            else {
                func_02007F1C((u8 *)func_021B614C(p->parent), p->h32, 1, p->heap);
                p->state = 4;
            }
        }
        break;
    case 3:
        if (!func_022026FC((struct W *)p->window)) func_021B6364((u8 *)p, (u32)func_021B6504);
        break;
    case 4:
        if (!func_022026FC((struct W *)p->window)) {
            func_021B6988((struct PdcWork *)((int)p->object), (void *)((int)p->parent));
            (p->state)++;
        }
        break;
    case 5:
        if (func_021B6A3C(p->object)) {
            func_021F7CFC(1, p->h32, 4, 1, 0);
            (p->state)++;
        }
        break;
    case 6:
        if (!func_021F7EB4()) {
            IRC_COMPATIBLE_ProcExit((struct PdcWork *)((int)p->object), (void *)((int)p->parent));
            (p->state)++;
        }
        break;
    case 7:
        if (func_021B6B74(p->object)) GFL_USE_CancelChangeAndPlayBgm(0x518, 0xffff);
        if (func_021B6A3C(p->object)) (p->state)++;
        break;
    case 8:
        if (!func_02005F38()) {
            func_021F7C0C(); GFL_USE_CancelChangeAndPlayBgm(0x47c, 0xffff);
            (p->state)++;
        }
        break;
    case 9:
        if (!func_021F7EB4()) {
            p->timer = 80;
            (p->state)++;
        }
        break;
    case 10:
        if (((u32)func_020362DC() & 3) || func_02035C60() || --p->timer == 0) {
            func_0204E720(3, 0, 16, 2);
            (p->state)++;
        }
        break;
    case 11:
        if (!func_0204E804()) {
            t = PALANM_GetPairedCodeForFirst(p->h32);
            func_02017E40((void *)func_021B6140(p->parent), 152, t);
            return 1;
        }
        break;
    }
    return 0;
}







int func_021B6750(char *p)
{
    switch (((struct Obj03730 *)p)->f60) {
    case 0:
        func_021B6A00((u8 *)(((struct Obj03730 *)p)->f14), (u8 *)(((struct Obj03730 *)p)->f0));
        ((struct Obj03730 *)p)->f60 = ((struct Obj03730 *)p)->f60 + 1;
        break;
    case 1:
        if (func_021B6A3C((u8 *)(((struct Obj03730 *)p)->f14)) != 0) {
            func_0204E720(3, 0, 0x10, 2);
            GFL_USE_FadeOutBgm(8);
            ((struct Obj03730 *)p)->f60 = ((struct Obj03730 *)p)->f60 + 1;
        }
        break;
    case 2:
        if (func_0204E804() == 0)
            return 2;
        break;
    }
    return 0;
}






void func_021B67A4(int a) { if (func_0207D55C((unsigned short *)0x0400006c) <= 0) func_0204E720(3,16,0,a); else func_0204E720(12,16,0,a); }





/*
 * prototype: 02008374's three unused legacy trailing inputs omitted: full getter reads only r0, no forwarding; caller supplies no new values.
 */
u8 *func_021B67D4(void *a, void *b, void *c, u32 heap)
{
    u8 *p;
    u32 idx;
    p = func_02030734(heap, 0x48, 1, d_021B6E74, 0x82);
    func_0203FCA0(1, &d_021B6E24, 0);
    ((struct Obj01704 *)p)->f44 = heap;
    ((struct Obj01704 *)p)->f28 = c;
    *(struct MsgBank * *)&((struct Obj01704 *)p)->f20 = func_02045B38(0, 2, 0x56, ((struct Obj01704 *)p)->f44);
    ((struct Obj01704 *)p)->f24 = a;
    ((struct Obj01704 *)p)->f34 = func_02013080(CONFIG_GetTextSpeed((int)b));
    *(struct U16Vec * *)&((struct Obj01704 *)p)->f2C = func_020457B0(0x100, heap);
    *(struct WordSet * *)&((struct Obj01704 *)p)->f30 = func_0201EC64(heap);
    func_02041300(1, 0, 0, 0, 32, 32, 17);
    func_02040C14(1, 0, 1, 0);
    idx = func_020496E4(11, 89, 1, 0, 0, ((struct Obj01704 *)p)->f44);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)func_021F86E0(), 11, 90, ((struct Obj01704 *)p)->f44, 0, 32, 0, 0);
    *(u32 *)&((struct Obj01704 *)p)->f1C = func_020450F0(1, 1, 19, 30, 4, 0, 0);
    func_02045374(*(struct Cfg * *)&((struct Obj01704 *)p)->f1C);
    BMP_WIN_DrawFrame(*(struct Cfg * *)&((struct Obj01704 *)p)->f1C, idx, 0);
    func_020409B4(1);
    func_02040588(1, 0);
    func_021B6C34((char *)p + 4, *(int *)&((struct Obj01704 *)p)->f1C);
    return p;
}





void func_021B68DC(u8 *p) { func_02045808(((struct Obj05259 *)p)->f2C); func_0201ED04(((struct Obj05259 *)p)->f30); if (((struct Obj05259 *)p)->f0) func_0201CE48(((struct Obj05259 *)p)->f0); func_020403F4(1); func_02045C04(((struct Obj05259 *)p)->f20); func_020452E8(((struct Obj05259 *)p)->f1C); func_020307B0(p); }




void func_021B6910(struct PdcWork *p, void *q) {
    void *r;
    int t;
    r = func_02045EC0(p->f20, 0);
    t = func_021B6140(q);
    func_0201EEF4(p->f30, 0, (void *)t);
    func_0201F250(p->f30, p->f2C, r);
    func_021B6B8C((char *)p, 0x50);
    func_02045808((struct U16Vec *)r);
}




void func_021B694C(struct PdcWork *p, u8 *q) {
    void *r;
    u32 t;
    r = func_02045EC0(p->f20, 3);
    t = func_021B6148(q);
    func_0201F02C(p->f30, 0, (void *)t);
    func_0201F250(p->f30, p->f2C, r);
    func_021B6B8C((char *)p, 0);
    func_02045808((struct U16Vec *)r);
}




void func_021B6988(struct PdcWork *p, void *q) {
    void *r;
    int t;
    r = func_02045EC0(p->f20, 1);
    t = func_021B6140(q);
    func_0201EEF4(p->f30, 0, (void *)t);
    func_0201F250(p->f30, p->f2C, r);
    func_021B6B8C((char *)p, 0x50);
    func_02045808((struct U16Vec *)r);
}




void IRC_COMPATIBLE_ProcExit(struct PdcWork *p, void *q) {
    void *r;
    int t;
    r = func_02045EC0(p->f20, 2);
    t = func_021B6140(q);
    func_0201EEF4(p->f30, 0, (void *)t);
    func_0201F250(p->f30, p->f2C, r);
    func_021B6B8C((char *)p, 0x50);
    func_02045808((struct U16Vec *)r);
}




void func_021B6A00(u8 *p,u8 *q) { void *r; u32 t; r=func_02045EC0(((struct Obj07936 *)p)->f20,4); t=func_021B6148(q); func_0201F02C(((struct Obj07936 *)p)->f30,0,(void *)t); func_0201F250(((struct Obj07936 *)p)->f30,((struct Obj07936 *)p)->f2C,r); func_021B6B8C((char *)((int)p), 80); func_02045808(r); }




int func_021B6A3C(u8 *p)
{
    switch (p[0x39]) {
    case 0:
        func_021B6C90((char *)p + 4, p[0x38]);
        p[0x39]++;
    case 1:
        if (!func_021B6CDC(p + 4)) break;
        if (p[0x38]) {
            p[0x39] = 6;
            break;
        }
        if (((struct Obj00466 *)p)->f0) PRINTSYS_PrintStreamRun(((struct Obj00466 *)p)->f0);
        p[0x39]++;
    case 2:
        if (((struct Obj00466 *)p)->f0) {
            ((struct Obj00466 *)p)->f3C = func_0201CE30(((struct Obj00466 *)p)->f0);
            if (((struct Obj00466 *)p)->f3C) {
                p[0x39] = 3;
                if (((struct Obj00466 *)p)->f3C == 2) p[0x3a] = 1;
            }
        } else return 1;
        break;
    case 3:
        if ((func_020362DC() & 3) || func_02035C60()) ((struct Obj00466 *)p)->f40 = 0;
        if (((struct Obj00466 *)p)->f40) (((struct Obj00466 *)p)->f40)--;
        else p[0x39] = 5;
        break;
    case 4:
        if (((struct Obj00466 *)p)->f40) (((struct Obj00466 *)p)->f40)--;
        else p[0x39] = 5;
        break;
    case 5:
        if (((struct Obj00466 *)p)->f3C == 2) {
            func_0201DD68();
            func_0201CE48(*(struct Rec3 * *)&((struct Obj00466 *)p)->f0);
            ((struct Obj00466 *)p)->f0 = 0;
            p[0x39] = 6;
            return 1;
        } else {
            func_0201CE38(((struct Obj00466 *)p)->f0);
            p[0x39] = 2;
            ((struct Obj00466 *)p)->f40 = ((struct Obj00466 *)p)->f42;
        }
        break;
    case 6:
        return 1;
    }
    return 0;
}





void func_021B6B5C(char *p)
{
    func_021B6C60(p + 4);
}





int func_021B6B68(char *p)
{
    return func_021B6CDC((u8 *)(p + 4));
}




/*
 * notes:    test and clear flag byte at +0x3a, returns 1 if it was set. Witness for the call in ov098 func_021B6578 (2026-10-05, lane W-B).
 */
int func_021B6B74(unsigned char *p)
{
    if (p[0x3a]) {
        p[0x3a] = 0;
        return 1;
    }
    return 0;
}





void func_021B6B8C(char *a, int b)
{
    func_02043B5C(func_02045770(*(struct Descriptor **)(a + 0x1c)), 0xc);
    func_0201DD78(1, 9, 0xc);
    func_02040588(1, 1);
    if (b != 0) {
        PRINTSYS_PrintStreamStop(*(void **)a = func_0201CCE4(*(u32 *)(a + 0x1c), 0, 0,
                                  *(int *)(a + 0x2c), *(int *)(a + 0x24),
                                  *(int *)(a + 0x34), *(int *)(a + 0x28), 0,
                                  *(u16 *)(a + 0x44), 0xc));
        *(char *)(a + 0x38) = 0;
    } else {
        func_0201C7A4(func_02045770(*(struct Descriptor **)(a + 0x1c)), 0, 0,
                      *(void **)(a + 0x2c), *(void **)(a + 0x24));
        func_02045374(*(struct Cfg **)(a + 0x1c));
        func_020409B4(1);
        func_02045334(*(struct Descriptor **)(a + 0x1c));
        *(char *)(a + 0x38) = 1;
    }
    *(char *)(a + 0x39) = 0;
    *(u16 *)(a + 0x40) = b;
    *(u16 *)(a + 0x42) = b;
    *(char *)(a + 0x3a) = 0;
}





void func_021B6C34(char *p, int a)
{
    ((struct Obj07937 *)p)->f0 = a;
    ((struct Obj07937 *)p)->f14 = 0;
    ((struct Obj07937 *)p)->f4 = 0x1f000;
    ((struct Obj07937 *)p)->f8 = 0x7000;
    func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
}





/*
 * Unlabelled leaf inside the handed extent of func_021B6C34.
 */
void func_021B6C60(char *p)
{
    u8 s = ((struct Obj04409 *)p)->f14;

    if (s == 0 || s == 3) {
        ((struct Obj04409 *)p)->f4 = 0x1f000;
        ((struct Obj04409 *)p)->f8 = 0x7000;
        ((struct Obj04409 *)p)->fC = -0x52aa;
        ((struct Obj04409 *)p)->f10 = 0x1800;
        ((struct Obj04409 *)p)->f15 = 6;
        ((struct Obj04409 *)p)->f14 = 1;
    }
}





void func_021B6C90(char *p, int flag)
{
    if ((u8)(((struct Obj03220 *)p)->f14 + 0xff) <= 1) {
        if (flag == 0) {
            func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj03220 *)p)->f0)), 0xc);
            func_02045334((struct Descriptor *)((struct Obj03220 *)p)->f0);
        }
        ((struct Obj03220 *)p)->f4 = 0;
        ((struct Obj03220 *)p)->f8 = 0x10000;
        ((struct Obj03220 *)p)->fC = 0x52AA;
        ((struct Obj03220 *)p)->f10 = -0x1800;
        ((struct Obj03220 *)p)->f15 = 6;
        ((struct Obj03220 *)p)->f14 = 4;
    }
}
