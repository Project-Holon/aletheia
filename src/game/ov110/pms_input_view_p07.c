/*
 * file:     pms_input_view_p07.c
 * unit:     yes
 * function: func_021B9C74, func_021B9C90, func_021B9CBC, func_021B9CE4, func_021B9F34, func_021B9FB4, func_021BA070, func_021BA150, func_021BA1A0, func_021BA1D8, func_021BA1F0, func_021BA208, func_021BA220, func_021BA258, func_021BA290, func_021BA2D8, func_021BA398, func_021BA3F0, func_021BA4CC, func_021BA5C4, func_021BA6BC, func_021BA7CC, func_021BA8C4
 * address:  0x021B9C74
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EE8 0x02030EE8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204335C 0x0204335C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_021BBC5C 0x021BBC5C thumb ov110
 *   func_021BBD60 0x021BBD60 thumb ov110
 *   func_021BB290 0x021BB290 thumb ov110
 *   func_021BB328 0x021BB328 thumb ov110
 *   func_021BF844 0x021BF844 thumb ov110
 *   func_021BF8F4 0x021BF8F4 thumb ov110
 *   func_020498F4 0x020498F4 arm
 *   func_02049658 0x02049658 arm
 *   func_02040588 0x02040588 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021BF7C4 0x021BF7C4 thumb ov110
 *   func_021BF6D8 0x021BF6D8 thumb ov110
 *   func_021BAD68 0x021BAD68 thumb ov110
 *   func_021BAD2C 0x021BAD2C thumb ov110
 *   func_021BC990 0x021BC990 thumb ov110
 *   func_021BCB50 0x021BCB50 thumb ov110
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0207D46C 0x0207D46C arm
 *   func_02049238 0x02049238 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021BBCF0 0x021BBCF0 thumb ov110
 *   func_021BB2CC 0x021BB2CC thumb ov110
 *   func_021BF8BC 0x021BF8BC thumb ov110
 *   func_020403F4 0x020403F4 arm
 *   d_021C3714 0x021C3714 data a4
 *   d_021C3604 0x021C3604 data a4
 *   d_021C3694 0x021C3694 data a4
 *   d_021C36B4 0x021C36B4 data a4
 *   d_021C3674 0x021C3674 data a4
 *   d_021C3614 0x021C3614 data a4
 *   d_021C36F4 0x021C36F4 data a4
 *   d_021C36D4 0x021C36D4 data a4
 *   d_021C3654 0x021C3654 data a4
 *   d_021C3634 0x021C3634 data a4
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C450 0x0201C450 thumb
 *   func_021BC23C 0x021BC23C thumb ov110
 *   func_021BF714 0x021BF714 thumb ov110
 *   func_021BC72C 0x021BC72C thumb ov110
 *   func_021BCCA8 0x021BCCA8 thumb ov110
 *   func_021BCD44 0x021BCD44 thumb ov110
 *   func_021BAE24 0x021BAE24 thumb ov110
 *   func_021BAE94 0x021BAE94 thumb ov110
 *   func_021BAED0 0x021BAED0 thumb ov110
 *   func_021BC704 0x021BC704 thumb ov110
 *   func_021BC724 0x021BC724 thumb ov110
 *   func_021BF71C 0x021BF71C thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 *   func_021BC728 0x021BC728 thumb ov110
 *   func_021BF7E0 0x021BF7E0 thumb ov110
 *   func_021BCC58 0x021BCC58 thumb ov110
 *   func_021BC6EC 0x021BC6EC thumb ov110
 *   func_021BB76C 0x021BB76C thumb ov110
 *   func_021BBEF4 0x021BBEF4 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BB958 0x021BB958 thumb ov110
 *   func_021BB784 0x021BB784 thumb ov110
 *   func_021BBF54 0x021BBF54 thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_021BB6A0 0x021BB6A0 thumb ov110
 *   func_021BB658 0x021BB658 thumb ov110
 *   func_021BB8D8 0x021BB8D8 thumb ov110
 *   func_021BB8B8 0x021BB8B8 thumb ov110
 *   func_021BB954 0x021BB954 thumb ov110
 *   func_021BCEE4 0x021BCEE4 thumb ov110
 *   func_021BB9C0 0x021BB9C0 thumb ov110
 *   func_021BBB0C 0x021BBB0C thumb ov110
 *   func_021BCF38 0x021BCF38 thumb ov110
 *   func_021BCF70 0x021BCF70 thumb ov110
 *   func_021BD000 0x021BD000 thumb ov110
 *   func_021BD028 0x021BD028 thumb ov110
 *   func_021BB7A0 0x021BB7A0 thumb ov110
 *   func_021BB7B8 0x021BB7B8 thumb ov110
 *   func_021BC6F8 0x021BC6F8 thumb ov110
 *   func_021BBC10 0x021BBC10 thumb ov110
 *   func_021BB838 0x021BB838 thumb ov110
 *   func_021BB854 0x021BB854 thumb ov110
 *   func_021BCC88 0x021BCC88 thumb ov110
 *   func_021BF9F0 0x021BF9F0 thumb ov110
 *   func_021BFAA0 0x021BFAA0 thumb ov110
 *   func_021BFB58 0x021BFB58 thumb ov110
 *   func_021BF784 0x021BF784 thumb ov110
 *   func_021BFC64 0x021BFC64 thumb ov110
 *   func_021BF7AC 0x021BF7AC thumb ov110
 *   func_021BF7B8 0x021BF7B8 thumb ov110
 *   func_021BFDB0 0x021BFDB0 thumb ov110
 *   func_021BFC20 0x021BFC20 thumb ov110
 *   func_021BF7FC 0x021BF7FC thumb ov110
 *   func_021BFB7C 0x021BFB7C thumb ov110
 *   func_021BFBA0 0x021BFBA0 thumb ov110
 *   func_021BB870 0x021BB870 thumb ov110
 *   func_021BB8AC 0x021BB8AC thumb ov110
 *   func_021C00FC 0x021C00FC thumb ov110
 *   func_021BB804 0x021BB804 thumb ov110
 *   func_021BB814 0x021BB814 thumb ov110
 *   func_021BB82C 0x021BB82C thumb ov110
 */
#include "../../matched/include/Obj00135.h"
#include "../../matched/include/Obj22315.h"
#include "../../matched/include/Obj22316.h"
#include "../../matched/include/Obj22317.h"
#include "../../matched/include/Obj22318.h"
#include "../../matched/include/Obj22319.h"
#include "../../matched/include/Obj22320.h"
#include "../../matched/include/Obj22321.h"
#include "../../matched/include/Obj22322.h"
#include "../../matched/include/Obj22323.h"
#include "../../matched/include/Obj22324.h"
#include "../../matched/include/Obj22325.h"
#include "../../matched/include/Obj22326.h"
#include "../../matched/include/Obj22327.h"
#include "../../matched/include/Obj05286.h"
#include "../../matched/include/Obj22328.h"
#include "../../matched/include/Obj04441.h"
#include "../../matched/include/Obj07997.h"
#include "../../matched/include/Obj22329.h"
#include "../../matched/include/Obj22330.h"
#include "../../matched/include/Obj22331.h"
#include "../../matched/include/Obj22332.h"
#include "../../matched/include/Obj13769.h"
#include "../../matched/include/Obj22333.h"
#include "../../matched/include/Obj10265.h"
#include "../../matched/include/Obj06381.h"
#include "../../matched/include/Obj06382.h"
#include "../../matched/include/Obj06383.h"
#include "../../matched/include/Obj05287.h"
#include "../../matched/include/Obj01921.h"
#include "../../matched/include/Obj03748.h"
#include "../../matched/include/Obj06384.h"
#include "../../matched/include/Obj06385.h"
#include "../../matched/include/Obj01711.h"
#include "../../matched/include/Obj03749.h"
#include "../../matched/include/Obj01530.h"
#include "../../matched/include/Obj03237.h"
#include "../../matched/include/Obj01142.h"
#include "../../matched/include/Obj04442.h"
#include "../../matched/include/Obj01531.h"
#include "../../matched/include/Obj02164.h"
#include "../../matched/include/Obj01247.h"
#include "../../matched/include/Obj03238.h"
#include "../../matched/include/Obj02815.h"
#include "../../matched/include/Obj05288.h"

struct S02030EE8;
struct Node;
struct Object;
struct Descriptor;
struct CharBuf;
struct PrintSys;
struct BgTemplate;
struct DispConfig;
struct DispVram;
struct GfFont;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef enum { GX_DISP_SELECT_SUB_MAIN=0, GX_DISP_SELECT_MAIN_SUB=1 } GXDispSelect;

extern u32 func_02030EE8(struct S02030EE8 *p);
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);
extern void func_0204335C(unsigned);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u8 *func_021BBC5C(void *,u8 *,void *);
extern void func_021BBD60(u8 *p, u32 a);
extern u8 *func_021BB290(u32 a, u8 *b, u32 c);
extern void func_021BB328(u8 *p, u32 data);
extern u8 *func_021BF844(void *,void *,void *);
extern void func_021BF8F4(u8 *);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern int func_02061CA4(void *,u32,u32,int);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_021BF7C4(u8 *);
extern u32 func_021BF6D8(u8 *);
extern void func_021BAD68(u8 *,int);
extern void func_021BAD2C(u8 *,int);
extern u8 *func_021BC990(u8 *,u8 *,void *);
extern void func_021BCB50(struct Object *p);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
extern void func_0207D46C(void);
extern void func_02049238(void *);
extern signed int func_0204ABF0(void *a, unsigned int b, unsigned int c, unsigned int d, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021BBCF0(u8 *p);
extern void func_021BB2CC(u8 *p);
extern void func_021BF8BC(u8 *p);
extern u32 func_0201D83C(void *ptr);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020403F4(u32 i);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void *func_0201C450(u16,u32);
extern void func_021BC23C(void *);
extern u16 func_021BF714(u8 *);
extern void func_021BC72C(char *p, int i);
extern void func_021BCCA8(void *);
extern void func_021BCD44(u8 *p);
extern void func_021BAE24(u8 *p, u8 *a1, void *a2);
extern void func_021BAE94(u8 *p, u8 *q, void *a2);
extern void func_021BAED0(u8 *p, u8 *a1, void *a2);
extern void func_021BC704(u8 *p, u32 flag);
extern void func_021BC724(u8 *);
extern u16 func_021BF71C(u8 *);
extern void func_021BCF7C(u8 *p, int n, int v);
extern void func_021BC728(u8 *);
extern void func_021BF7E0(u8 *);
extern void func_021BCC58(u8 *);
extern void func_021BC6EC(void *p);
extern void func_021BB76C(u8 *);
extern void func_021BBEF4(u8 *p, u8 value);
extern u8 func_021BF6DC(u8 *);
extern void func_021BB958(char *p);
extern int func_021BB784(u8 *);
extern int func_021BBF54(u8 *);
extern u16 func_021BF724(u8 *);
extern void func_021BB6A0(u8 *, unsigned int);
extern void func_021BB658(u8 *, int);
extern void func_021BB8D8(u8 *);
extern void func_021BB8B8(u8 *);
extern int func_021BB954(u8 *);
extern void func_021BCEE4(char *p, u32 mode);
extern void func_021BB9C0(u8 *,int);
extern int func_021BBB0C(u8 *,int);
extern int func_021BCF38(char *p, u32 mode);
extern void func_021BCF70(u8 *,int);
extern int func_021BD000(char *p);
extern int func_021BD028(u8 *);
extern void func_021BB7A0(u8 *);
extern int func_021BB7B8(u8 *);
extern void func_021BC6F8(void *);
extern int func_021BBC10(u8 *);
extern void func_021BB838(u8 *);
extern int func_021BB854(u8 *);
extern void func_021BCC88(u8 *);
extern void func_021BF9F0(u8 *);
extern void func_021BFAA0(u8 *);
extern int func_021BFB58(u8 *);
extern unsigned func_021BF784(u8 *);
extern void func_021BFC64(u8 *,unsigned);
extern unsigned func_021BF7AC(u8 *);
extern unsigned func_021BF7B8(u8 *);
extern void func_021BFDB0(u8 *,unsigned,unsigned);
extern void func_021BFC20(u8 *,unsigned);
extern u8 func_021BF7FC(u8 *);
extern void func_021BFB7C(u8 *p);
extern int func_021BFBA0(u8 *);
extern void func_021BB870(u8 *);
extern int func_021BB8AC(u8 *);
extern int func_021C00FC(u8 *);
extern void func_021BB804(u8 *);
extern void func_021BB814(u8 *p);
extern int func_021BB82C(u8 *);
int func_021B9C74(unsigned int a);
int func_021B9C90(unsigned int a,int b);
void func_021B9CBC(u8 *p);
void func_021B9CE4(void *unused,u8 *p);
void func_021B9F34(u8 *p, void *archive);
void func_021B9FB4(int unused, u8 *p);
void func_021BA070(u8 *p);
void func_021BA150(int unused, u8 *p);
void func_021BA1A0(void *unused, u8 *p);
void func_021BA1D8(void *unused, u8 *p);
void func_021BA1F0(void *unused, u8 *p);
void func_021BA208(void *unused, u8 *p);
void func_021BA220(void *unused, u8 *p);
void func_021BA258(void *unused, u8 *p);
void func_021BA290(int unused, u8 *p);
void func_021BA2D8(int unused, u8 *p);
void func_021BA398(int unused, u8 *p);
void func_021BA3F0(void *unused,u8 *p);
void func_021BA4CC(void *unused,u8 *p);
void func_021BA5C4(void *unused,u8 *p);
void func_021BA6BC(void *unused, u8 *p);
void func_021BA7CC(void *unused, u8 *p);
void func_021BA8C4(void *unused,u8 *p);
extern const u8 d_021C3714[];
extern u8 d_021C3604[];
extern const u8 d_021C3694[],d_021C36B4[],d_021C3674[],d_021C3614[];
extern const u8 d_021C36F4[],d_021C36D4[],d_021C3654[],d_021C3634[];

int func_021B9C74(unsigned int a) { int i; for(i=0;i<4;i++) if(*(int *)(a+(unsigned)i*4+8)) return 0; return 1; }

int func_021B9C90(unsigned int a,int b) { int i; int value; for(i=0;i<4;i++) if(*(void **)(a+(unsigned)i*4+8)) { value=*(int *)(func_02030EE8(*(void **)(a+(unsigned)i*4+8))+12); if(value==b) return 0; } return 1; }

void func_021B9CBC(u8 *p)
{
    func_02030EAC(*(void **)(*(u32 *)&((struct Obj00135 *)p)->f0 + ((struct Obj00135 *)p)->f10 * 4 + 8));
    *(u32 *)(*(u32 *)&((struct Obj00135 *)p)->f0 + ((struct Obj00135 *)p)->f10 * 4 + 8) = 0;
    func_020307B0(p);
}

void func_021B9CE4(void *unused,u8 *p) {
    void *h;
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= ~0xe000;
    *(volatile u32 *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020434CC();
    func_02043588();
    *(volatile u32 *)0x04000000 &= ~0x1f00;
    *(volatile u32 *)0x04001000 &= ~0x1f00;
    h=func_020490F4(43,42);
    func_021BA070(p);
    func_021B9F34(p,(void *)h);
    *(u8 * *)&((struct Obj22315 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f54=func_021BBC5C(*(u8 * *)&((struct Obj00135 *)p)->f0,*(u8 * *)&((struct Obj00135 *)p)->f4,((struct Obj00135 *)p)->f8);
    func_021BBD60(*(u8 * *)&((struct Obj22316 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f54,(u32)h);
    *(u8 * *)&((struct Obj22317 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f58=func_021BB290((u32)(*(u8 * *)&((struct Obj00135 *)p)->f0),*(u8 * *)&((struct Obj00135 *)p)->f4,(u32)(((struct Obj00135 *)p)->f8));
    func_021BB328(*(u8 * *)&((struct Obj22318 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f58,(u32)h);
    *(u8 * *)&((struct Obj22319 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f5C=func_021BF844(*(u8 * *)&((struct Obj00135 *)p)->f0,*(u8 * *)&((struct Obj00135 *)p)->f4,((struct Obj00135 *)p)->f8);
    func_021BF8F4(*(u8 * *)&((struct Obj22320 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f5C);
    func_020498F4((void *)((u32)h),30,5,0,0,0,42);
    func_02049658((void *)((u32)h),18,5,0,0,0,42);
    func_020498F4((void *)((u32)h),31,6,0,0,0,42);
    func_02049658((void *)((u32)h),18,6,0,0,0,42);
    func_02040588(6,0);
    func_02049BDC((void *)((u32)h),4,4,128,160,32,42);
    ((struct Obj22321 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f68=0x294b;
    func_02061CA4((void *)31,188,(u32)(*(u8 * *)&((struct Obj00135 *)p)->f0+0x68),2);
    ((struct Obj22322 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f6A=0x5694;
    func_02061CA4((void *)31,190,(u32)(*(u8 * *)&((struct Obj00135 *)p)->f0+0x6a),2);
    func_02049658((void *)((u32)h),18,7,0,0,0,42);
    func_020498F4((void *)((u32)h),24,7,0,0,0,42);
    func_020413B0(7,0,0,32,32,5);
    ((struct Obj22323 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f6C=func_020450F0(7,3,5,26,7,5,1);
    func_02043B5C(func_02045770((struct Descriptor *)((struct Obj22324 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f6C),7);
    ((struct Obj22325 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f70=0;
    if(func_021BF7C4(*(u8 * *)&((struct Obj00135 *)p)->f4) || func_021BF6D8(*(u8 * *)&((struct Obj00135 *)p)->f4)!=2) func_021BAD68(p,1);
    else func_021BAD68(p,0);
    func_021BAD2C(*(u8 * *)&((struct Obj00135 *)p)->f0,0);
    *(u8 * *)&((struct Obj22326 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f64=func_021BC990(*(u8 * *)&((struct Obj00135 *)p)->f0,*(u8 * *)&((struct Obj00135 *)p)->f4,((struct Obj00135 *)p)->f8);
    func_021BCB50((struct Object *)(*(u8 * *)&((struct Obj22327 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f64));
    func_02040588(0,1);
    func_020434DC(16,1);
    func_02043598(16,1);
    func_0207D46C();
    func_02049658((void *)((u32)h),16,3,0,0,0,42);
    func_02049658((void *)((u32)h),17,3,96,0,0,42);
    func_02049238(h);
    func_021B9CBC(p);
}

void func_021B9F34(u8 *p, void *archive) {
    u8 *q = *(u8 * *)&((struct Obj22328 *)p)->f0;
    int i;
    for (i=0; i<2; ++i) {
        u8 *r = q+i*12;
        ((struct Obj05286 *)r)->f24 = func_0204ABF0(archive, 7, i, 0, 42);
        ((struct Obj05286 *)r)->f28 = func_0204A6C8((void *)archive, 19, 0, i, 42);
        ((struct Obj05286 *)r)->f2C = func_0204AF28((void *)archive, 36, 42, 42);
        ((struct Obj05286 *)r)->f3C = func_0204ABF0(archive, 1, i, 224, 42);
        ((struct Obj05286 *)r)->f40 = func_0204A6C8((void *)archive, 46, 0, i, 42);
        ((struct Obj05286 *)r)->f44 = func_0204AF28((void *)archive, 34, 40, 42);
    }
}

/*
 * volatile: 0x021BA058 reads hardware register 0x04000304 before updating it.
 */
void func_021B9FB4(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj04441 *)p)->f0;
    switch (((struct Obj04441 *)p)->f14) {
    case 0:
        func_0202208C(0,0,0,0,5,1,42);
        ++((struct Obj04441 *)p)->f14;
        break;
    case 1:
        if (func_020221A4()) {
            func_020452E8(((struct Obj22329 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f6C);
            func_021BBCF0(((struct Obj22330 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f54);
            func_021BB2CC(((struct Obj22331 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f58);
            func_021BF8BC(((struct Obj22332 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f5C);
            func_0201D83C(((struct Obj07997 *)q)->f80);
            func_0201C6EC(((struct Obj07997 *)q)->f7C);
            func_0201C4C0(((struct Obj07997 *)q)->f7C);
            ((struct Obj07997 *)q)->f7C = 0;
            func_020403F4(0);
            func_020403F4(1);
            func_020403F4(2);
            func_020403F4(3);
            func_020403F4(4);
            func_020403F4(5);
            func_020403F4(6);
            *(volatile u16 *)0x04000304 |= 0x8000;
            func_021B9CBC(p);
        }
        break;
    }
}

static inline void GX_SetDispSelect(GXDispSelect sel) {
    *(volatile u16 *)0x04000304=(u16)((*(volatile u16 *)0x04000304 & ~0x8000) | (sel<<15));
}

/*
 * lever: GX_SetDispSelect's enum inline keeps the 0xFFFF7FFF pool mask;
 *   a direct halfword &= expression emits 0x00007FFF (two bytes differ).
 * abi: original A0E0..A0EC truncates i separately before both calls;
 *   narrow first extern parameters retain those explicit u8 argument values.
 * volatile: hardware halfword at 04000304 is read/modified at A078..A07E.
 */
void func_021BA070(u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj22333 *)p)->f0;
    int i;
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    func_020433E0((const struct DispVram *)d_021C3714);
    func_0203FC28((struct DispConfig *)d_021C3604);
    func_0203FCA0(0,(const struct BgTemplate *)d_021C3694,0);
    func_0203FCA0(1,(const struct BgTemplate *)d_021C36B4,0);
    func_0203FCA0(2,(const struct BgTemplate *)d_021C3674,0);
    func_0203FCA0(3,(const struct BgTemplate *)d_021C3614,0);
    func_0203FCA0(4,(const struct BgTemplate *)d_021C36F4,0);
    func_0203FCA0(5,(const struct BgTemplate *)d_021C36D4,0);
    func_0203FCA0(6,(const struct BgTemplate *)d_021C3654,0);
    func_0203FCA0(7,(const struct BgTemplate *)d_021C3634,0);
    for(i=0;i<=7;++i) {
        func_020414EC((u8)i);
        func_02040588((u8)i,1);
    }
    ((struct Obj13769 *)q)->f80=func_0201D7EC(23,0,0,0,42);
    ((struct Obj13769 *)q)->f7C=func_0201C450(0x500,42);
}

void func_021BA150(int unused, u8 *p) {
    switch (((struct Obj10265 *)p)->f14) {
    case 0:
        func_0202208C(0, 1, 1, 0, 5, 1, 42);
        ++((struct Obj10265 *)p)->f14;
        break;
    case 1:
        if (func_020221A4()) ++((struct Obj10265 *)p)->f14;
        break;
    default:
        func_021B9CBC(p);
        break;
    }
}

void func_021BA1A0(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    q[0x74] = 0;
    func_021BC23C(((struct Obj06381 *)q)->f54);
    func_021BC72C((char *)(*(u8 * *)&((struct Obj06381 *)q)->f54), func_021BF714(*(u8 * *)&((struct Obj00135 *)p)->f4));
    func_021BCCA8(((struct Obj06381 *)q)->f64);
    func_021BCD44(((struct Obj06381 *)q)->f64);
    func_021B9CBC(p);
}

void func_021BA1D8(void *unused, u8 *p)
{
    func_021BAE24(((struct Obj00135 *)p)->f0, ((struct Obj00135 *)p)->f4, ((struct Obj00135 *)p)->f8);
    func_021B9CBC(p);
}

/*
 * extent: trailing two-byte zero alignment padding.
 */
void func_021BA1F0(void *unused, u8 *p)
{
    func_021BAE94(((struct Obj00135 *)p)->f0, ((struct Obj00135 *)p)->f4, ((struct Obj00135 *)p)->f8);
    func_021B9CBC(p);
}

void func_021BA208(void *unused, u8 *p)
{
    func_021BAED0(((struct Obj00135 *)p)->f0, ((struct Obj00135 *)p)->f4, ((struct Obj00135 *)p)->f8);
    func_021B9CBC(p);
}

void func_021BA220(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    q[0x74] = 1;
    func_021BC704(*(u8 * *)&((struct Obj06382 *)q)->f54, 0);
    func_021BC724(*(u8 * *)&((struct Obj06382 *)q)->f54);
    func_021BCF7C(*(u8 * *)&((struct Obj06382 *)q)->f64, (u8)func_021BF71C(*(u8 * *)&((struct Obj06382 *)q)->f18), 1);
    func_021B9CBC(p);
}

void func_021BA258(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    q[0x74] = 1;
    func_021BC704(*(u8 * *)&((struct Obj06383 *)q)->f54, 0);
    func_021BC724(*(u8 * *)&((struct Obj06383 *)q)->f54);
    func_021BCF7C(*(u8 * *)&((struct Obj06383 *)q)->f64, (u8)func_021BF71C(*(u8 * *)&((struct Obj06383 *)q)->f18), 0);
    func_021B9CBC(p);
}

void func_021BA290(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    q[0x74] = 0;
    func_021BCF7C(*(u8 * *)&((struct Obj05287 *)q)->f64, (u8)func_021BF71C(*(u8 * *)&((struct Obj05287 *)q)->f18), 0);
    func_021BC728(*(u8 * *)&((struct Obj05287 *)q)->f54);
    func_021BC704(*(u8 * *)&((struct Obj05287 *)q)->f54, 1);
    func_021BC72C((char *)(*(u8 * *)&((struct Obj05287 *)q)->f54), func_021BF714(*(u8 * *)&((struct Obj00135 *)p)->f4));
    func_021B9CBC(p);
}

void func_021BA2D8(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj03748 *)p)->f0;
    int a, b;
    switch (((struct Obj03748 *)p)->f14) {
    case 0:
        func_021BC704(*(u8 * *)&((struct Obj01921 *)q)->f54, 1);
        func_021BC72C((char *)(*(u8 * *)&((struct Obj01921 *)q)->f54), func_021BF714(*(u8 * *)&((struct Obj03748 *)p)->f4));
        ++((struct Obj03748 *)p)->f14;
        break;
    case 1:
        func_021BF7E0(*(u8 * *)&((struct Obj03748 *)p)->f4);
        func_021BCC58(*(u8 * *)&((struct Obj01921 *)q)->f64);
        func_021BC6EC(*(u8 * *)&((struct Obj01921 *)q)->f54);
        func_021BC724(*(u8 * *)&((struct Obj01921 *)q)->f54);
        func_021BB76C(*(u8 * *)&((struct Obj01921 *)q)->f58);
        func_021BBEF4(*(u8 * *)&((struct Obj01921 *)q)->f54, 0);
        if (func_021BF6DC(*(u8 * *)&((struct Obj03748 *)p)->f4) == 1) func_021BB958((char *)(*(u8 * *)&((struct Obj01921 *)q)->f58));
        if (func_021BF6DC(*(u8 * *)&((struct Obj03748 *)p)->f4) == 0) func_021BAD68(p, 2);
        else func_021BAD68(p, 4);
        ++((struct Obj03748 *)p)->f14;
        break;
    case 2:
        a = func_021BB784(*(u8 * *)&((struct Obj01921 *)q)->f58);
        b = func_021BBF54(*(u8 * *)&((struct Obj01921 *)q)->f54);
        if (a && b) {
            func_021BB6A0(*(u8 * *)&((struct Obj01921 *)q)->f58, func_021BF724(*(u8 * *)&((struct Obj01921 *)q)->f18));
            func_021BB658(*(u8 * *)&((struct Obj01921 *)q)->f58, 1);
            func_021B9CBC(p);
        }
        break;
    }
}

void func_021BA398(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj06384 *)p)->f0;
    switch (((struct Obj06384 *)p)->f14) {
    case 0:
        ++((struct Obj06384 *)p)->f14;
    case 1:
        func_021BCC58(*(u8 * *)&((struct Obj06385 *)q)->f64);
        func_021BB8D8(*(u8 * *)&((struct Obj06385 *)q)->f58);
        func_021BB8B8(*(u8 * *)&((struct Obj06385 *)q)->f58);
        if (func_021BF6DC(*(u8 * *)&((struct Obj06384 *)p)->f4) == 1) func_021BB958((char *)(*(u8 * *)&((struct Obj06385 *)q)->f58));
        ++((struct Obj06384 *)p)->f14;
        break;
    case 2:
        if (func_021BB954(*(u8 * *)&((struct Obj06385 *)q)->f58)) func_021B9CBC(p);
        break;
    }
}

/*
 * abi: CF70 forwards its legacy third argument only to CE48, whose full
 *   body ignores it and calls D0F8(p,7,0); original A448 sets only r0/r1.
 */
void func_021BA3F0(void *unused,u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj03749 *)p)->f0;
    int a,b;
    switch(((struct Obj03749 *)p)->f14) {
    case 0:
        func_021BCEE4((char *)(*(u8 * *)&((struct Obj01711 *)q)->f64),1);
        func_021BB9C0(*(u8 * *)&((struct Obj01711 *)q)->f58,0);
        ++((struct Obj03749 *)p)->f14;
        break;
    case 1:
        a=func_021BBB0C(*(u8 * *)&((struct Obj01711 *)q)->f58,0);
        b=func_021BCF38((char *)(*(u8 * *)&((struct Obj01711 *)q)->f64),1);
        if(a && b) {
            func_021BCF70(*(u8 * *)&((struct Obj01711 *)q)->f64,1);
            func_021BF7E0(*(u8 * *)&((struct Obj03749 *)p)->f4);
            func_021BCC58(*(u8 * *)&((struct Obj01711 *)q)->f64);
            func_021BB658(*(u8 * *)&((struct Obj01711 *)q)->f58,0);
            func_021BB8D8(*(u8 * *)&((struct Obj01711 *)q)->f58);
            func_021BB8B8(*(u8 * *)&((struct Obj01711 *)q)->f58);
            if(func_021BF6DC(*(u8 * *)&((struct Obj03749 *)p)->f4)==1) func_021BB958((char *)(*(u8 * *)&((struct Obj01711 *)q)->f58));
            if(func_021BF6DC(*(u8 * *)&((struct Obj03749 *)p)->f4)==0) func_021BAD68(p,2);
            else func_021BAD68(p,4);
            ++((struct Obj03749 *)p)->f14;
        }
        break;
    case 2:
        if(func_021BB954(*(u8 * *)&((struct Obj01711 *)q)->f58)) ++((struct Obj03749 *)p)->f14;
        break;
    case 3:
        func_021BB6A0(*(u8 * *)&((struct Obj01711 *)q)->f58,func_021BF724(*(u8 * *)&((struct Obj01711 *)q)->f18));
        func_021BB658(*(u8 * *)&((struct Obj01711 *)q)->f58,1);
        func_021B9CBC(p);
        break;
    }
}

void func_021BA4CC(void *unused,u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj03237 *)p)->f0;
    int a,b;
    switch(((struct Obj03237 *)p)->f14) {
    case 0:
        if(func_021BF6DC(*(u8 * *)&((struct Obj03237 *)p)->f4)==1) {
            func_021BCEE4((char *)(*(u8 * *)&((struct Obj01530 *)q)->f64),0);
            func_021BB9C0(*(u8 * *)&((struct Obj01530 *)q)->f58,0);
        } else func_021BD000((char *)(*(u8 * *)&((struct Obj01530 *)q)->f64));
        ++((struct Obj03237 *)p)->f14;
        break;
    case 1:
        if(func_021BF6DC(*(u8 * *)&((struct Obj03237 *)p)->f4)==1) {
            a=func_021BBB0C(*(u8 * *)&((struct Obj01530 *)q)->f58,0);
            b=func_021BCF38((char *)(*(u8 * *)&((struct Obj01530 *)q)->f64),0);
        } else {
            a=func_021BD028(*(u8 * *)&((struct Obj01530 *)q)->f64);
            b=1;
        }
        if(a && b) ++((struct Obj03237 *)p)->f14;
        break;
    case 2:
        func_021BCB50((struct Object *)(*(u8 * *)&((struct Obj01530 *)q)->f64));
        func_021BB658(*(u8 * *)&((struct Obj01530 *)q)->f58,0);
        func_021BB7A0(*(u8 * *)&((struct Obj01530 *)q)->f58);
        func_021BBEF4(*(u8 * *)&((struct Obj01530 *)q)->f54,1);
        if(func_021BF7C4(*(u8 * *)&((struct Obj03237 *)p)->f4) || func_021BF6D8(*(u8 * *)&((struct Obj03237 *)p)->f4)!=2) func_021BAD68(p,1);
        else func_021BAD68(p,0);
        ++((struct Obj03237 *)p)->f14;
        break;
    case 3:
        a=func_021BB7B8(*(u8 * *)&((struct Obj01530 *)q)->f58);
        b=func_021BBF54(*(u8 * *)&((struct Obj01530 *)q)->f54);
        if(a && b) {
            func_021BC728(*(u8 * *)&((struct Obj01530 *)q)->f54);
            func_021BC6F8(*(u8 * *)&((struct Obj01530 *)q)->f54);
            q[0x74]=0;
            func_021B9CBC(p);
        }
        break;
    }
}

void func_021BA5C4(void *unused,u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj04442 *)p)->f0;
    int a,b;
    switch(((struct Obj04442 *)p)->f14) {
    case 0:
        ++((struct Obj04442 *)p)->f14;
        break;
    case 1:
        if(func_021BBC10(*(u8 * *)&((struct Obj01142 *)q)->f58)) {
            func_021BB658(*(u8 * *)&((struct Obj01142 *)q)->f58,0);
            func_021BCEE4((char *)(*(u8 * *)&((struct Obj01142 *)q)->f64),3);
            ++((struct Obj04442 *)p)->f14;
        }
        break;
    case 2:
        if(func_021BCF38((char *)(*(u8 * *)&((struct Obj01142 *)q)->f64),3)) {
            func_021BB838(*(u8 * *)&((struct Obj01142 *)q)->f58);
            func_021BB9C0(*(u8 * *)&((struct Obj01142 *)q)->f58,0);
            ++((struct Obj04442 *)p)->f14;
        }
        break;
    case 3:
        a=func_021BBB0C(*(u8 * *)&((struct Obj01142 *)q)->f58,0);
        b=func_021BB854(*(u8 * *)&((struct Obj01142 *)q)->f58);
        if(a && b) {
            func_021BCC88(*(u8 * *)&((struct Obj01142 *)q)->f64);
            func_021BF9F0(*(u8 * *)&((struct Obj01142 *)q)->f5C);
            func_021BFAA0(*(u8 * *)&((struct Obj01142 *)q)->f5C);
            if(func_021BF6DC(*(u8 * *)&((struct Obj04442 *)p)->f4)==0) func_021BAD68(p,3);
            else func_021BAD68(p,5);
            ++((struct Obj04442 *)p)->f14;
        }
        break;
    case 4:
        if(func_021BFB58(*(u8 * *)&((struct Obj01142 *)q)->f5C)) {
            unsigned x;
            func_021BFC64(*(u8 * *)&((struct Obj01142 *)q)->f5C,func_021BF784(*(u8 * *)&((struct Obj01142 *)q)->f18));
            x=func_021BF7AC(*(u8 * *)&((struct Obj01142 *)q)->f18);
            func_021BFDB0(*(u8 * *)&((struct Obj01142 *)q)->f5C,x,func_021BF7B8(*(u8 * *)&((struct Obj01142 *)q)->f18));
            func_021BFC20(*(u8 * *)&((struct Obj01142 *)q)->f5C,1);
            func_021B9CBC(p);
        }
        break;
    }
}

void func_021BA6BC(void *unused, u8 *p)
{
    u8 *q;
    int a, b, flag;
    u32 enabled;
    q = *(u8 * *)&((struct Obj02164 *)p)->f0;
    enabled = func_021BF7FC(*(u8 * *)&((struct Obj02164 *)p)->f4);
    switch (((struct Obj02164 *)p)->f14) {
    case 0:
        func_021BD000((char *)(*(u8 * *)&((struct Obj01531 *)q)->f64));
        ++((struct Obj02164 *)p)->f14;
        break;
    case 1:
        if (func_021BD028(*(u8 * *)&((struct Obj01531 *)q)->f64)) ++((struct Obj02164 *)p)->f14;
        break;
    case 2:
        func_021BCC58(*(u8 * *)&((struct Obj01531 *)q)->f64);
        ++((struct Obj02164 *)p)->f14;
        break;
    case 3:
        func_021BFC20(*(u8 * *)&((struct Obj01531 *)q)->f5C, 0);
        func_021BFB7C(*(u8 * *)&((struct Obj01531 *)q)->f5C);
        ++((struct Obj02164 *)p)->f14;
        break;
    case 4:
        if (func_021BFBA0(*(u8 * *)&((struct Obj01531 *)q)->f5C)) {
            func_021BB8B8(*(u8 * *)&((struct Obj01531 *)q)->f58);
            ++((struct Obj02164 *)p)->f14;
        }
        break;
    case 5:
        func_021BAD2C(*(u8 * *)&((struct Obj02164 *)p)->f0, 0);
        flag = 0;
        func_021BB870(*(u8 * *)&((struct Obj01531 *)q)->f58);
        if (func_021BF6DC(*(u8 * *)&((struct Obj02164 *)p)->f4) == 0) {
            flag = 0;
            func_021BB9C0(*(u8 * *)&((struct Obj01531 *)q)->f58, flag);
        } else {
            if (enabled) flag = 1;
            func_021BB9C0(*(u8 * *)&((struct Obj01531 *)q)->f58, flag);
        }
        if (func_021BF6DC(*(u8 * *)&((struct Obj02164 *)p)->f4) == 0) func_021BAD68(p, 2);
        else func_021BAD68(p, 4);
        ++((struct Obj02164 *)p)->f14;
        break;
    case 6:
        a = func_021BB8AC(*(u8 * *)&((struct Obj01531 *)q)->f58);
        b = func_021BBB0C(*(u8 * *)&((struct Obj01531 *)q)->f58, enabled != 0);
        if (a && b) {
            func_021BB6A0(*(u8 * *)&((struct Obj01531 *)q)->f58, func_021BF724(*(u8 * *)&((struct Obj01531 *)q)->f18));
            func_021BB658(*(u8 * *)&((struct Obj01531 *)q)->f58, 1);
            func_021B9CBC(p);
        }
        break;
    }
}

void func_021BA7CC(void *unused, u8 *p)
{
    u8 *q;
    int a, b;
    q = *(u8 * *)&((struct Obj03238 *)p)->f0;
    switch (((struct Obj03238 *)p)->f14) {
    case 0:
        ++((struct Obj03238 *)p)->f14;
        break;
    case 1:
        if (func_021C00FC(*(u8 * *)&((struct Obj01247 *)q)->f5C)) {
            func_021BCB50((struct Object *)(*(u8 * *)&((struct Obj01247 *)q)->f64));
            func_021BFC20(*(u8 * *)&((struct Obj01247 *)q)->f5C, 0);
            func_021BFB7C(*(u8 * *)&((struct Obj01247 *)q)->f5C);
            func_021BBEF4(*(u8 * *)&((struct Obj01247 *)q)->f54, 1);
            ++((struct Obj03238 *)p)->f14;
        }
        break;
    case 2:
        a = func_021BFBA0(*(u8 * *)&((struct Obj01247 *)q)->f5C);
        b = func_021BBF54(*(u8 * *)&((struct Obj01247 *)q)->f54);
        if (a && b) {
            func_021BB804(*(u8 * *)&((struct Obj01247 *)q)->f58);
            func_021BAD2C(*(u8 * *)&((struct Obj03238 *)p)->f0, 0);
            func_021BB870(*(u8 * *)&((struct Obj01247 *)q)->f58);
            if (func_021BF7C4(*(u8 * *)&((struct Obj03238 *)p)->f4) || func_021BF6D8(*(u8 * *)&((struct Obj03238 *)p)->f4) != 2) func_021BAD68(p, 1);
            else func_021BAD68(p, 0);
            ++((struct Obj03238 *)p)->f14;
        }
        break;
    case 3:
        if (func_021BB8AC(*(u8 * *)&((struct Obj01247 *)q)->f58)) {
            func_021BB814(*(u8 * *)&((struct Obj01247 *)q)->f58);
            ++((struct Obj03238 *)p)->f14;
        }
        break;
    case 4:
        if (func_021BB82C(*(u8 * *)&((struct Obj01247 *)q)->f58)) {
            func_021BC23C(*(u8 * *)&((struct Obj01247 *)q)->f54);
            func_021BC704(*(u8 * *)&((struct Obj01247 *)q)->f54, 1);
            func_021BC728(*(u8 * *)&((struct Obj01247 *)q)->f54);
            func_021BC6F8(*(u8 * *)&((struct Obj01247 *)q)->f54);
            q[0x74] = 0;
            func_021B9CBC(p);
        }
        break;
    }
}

void func_021BA8C4(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 * *)&((struct Obj05288 *)p)->f0;
    switch(((struct Obj05288 *)p)->f14) {
    case 0:
        func_021BFC20((u8 *)(*(u32 *)&((struct Obj02815 *)q)->f5C),0);
        func_021BFB7C(((struct Obj02815 *)q)->f5C);
        ++((struct Obj05288 *)p)->f14; break;
    case 1:
        if(func_021BFBA0(((struct Obj02815 *)q)->f5C)) {
            func_021BB804(((struct Obj02815 *)q)->f58);
            func_021BAD2C(*(u8 * *)&((struct Obj05288 *)p)->f0,0);
            func_021BB870(((struct Obj02815 *)q)->f58);
            ++((struct Obj05288 *)p)->f14;
        } break;
    case 2:
        if(func_021BB8AC(((struct Obj02815 *)q)->f58)) {
            func_021BB814(((struct Obj02815 *)q)->f58);
            ++((struct Obj05288 *)p)->f14;
        } break;
    case 3:
        if(func_021BB82C(((struct Obj02815 *)q)->f58)) {
            func_021BC23C(((struct Obj02815 *)q)->f54);
            func_021BC704(*(u8 * *)&((struct Obj02815 *)q)->f54,0);
            func_021B9CBC(p);
        } break;
    }
}
