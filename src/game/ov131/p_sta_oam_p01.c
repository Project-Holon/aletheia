/*
 * file:     p_sta_oam_p01.c
 * unit:     yes
 * function: func_021D4240, func_021D4418, func_021D44C8, func_021D46E4, func_021D46EC
 * address:  0x021D4240
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_0201747C 0x0201747C thumb
 *   func_021D65D8 0x021D65D8 thumb ov131
 *   func_021D7B00 0x021D7B00 thumb ov131
 *   func_021D96B0 0x021D96B0 thumb ov131
 *   func_021D87E0 0x021D87E0 thumb ov131
 *   func_021D4964 0x021D4964 thumb ov131
 *   func_021D51DC 0x021D51DC thumb ov131
 *   func_021D4FBC 0x021D4FBC thumb ov131
 *   func_020056A0 0x020056A0 thumb
 *   func_02082A60 0x02082A60 arm
 *   func_021D5C4C 0x021D5C4C thumb ov131
 *   func_021D697C 0x021D697C thumb ov131
 *   func_021DA6A4 0x021DA6A4 thumb ov131
 *   func_021D911C 0x021D911C thumb ov131
 *   func_02012BF8 0x02012BF8 thumb
 *   func_021D9C3C 0x021D9C3C thumb ov131
 *   func_021D8F50 0x021D8F50 thumb ov131
 *   func_021D7C38 0x021D7C38 thumb ov131
 *   func_0203D34C 0x0203D34C arm
 *   func_02030EAC 0x02030EAC arm
 *   func_021D5180 0x021D5180 thumb ov131
 *   func_021D5258 0x021D5258 thumb ov131
 *   func_021D4F24 0x021D4F24 thumb ov131
 *   func_021D91EC 0x021D91EC thumb ov131
 *   func_021D881C 0x021D881C thumb ov131
 *   func_021D9734 0x021D9734 thumb ov131
 *   func_021D7B34 0x021D7B34 thumb ov131
 *   func_021D6608 0x021D6608 thumb ov131
 *   func_021D48E4 0x021D48E4 thumb ov131
 *   func_02012BE0 0x02012BE0 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_021D5DC4 0x021D5DC4 thumb ov131
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_021D5280 0x021D5280 thumb ov131
 *   func_021D6614 0x021D6614 thumb ov131
 *   func_021D52A8 0x021D52A8 thumb ov131
 *   func_021D7B48 0x021D7B48 thumb ov131
 *   func_021D9740 0x021D9740 thumb ov131
 *   func_021D8830 0x021D8830 thumb ov131
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0204A600 0x0204A600 arm
 *   func_02014C08 0x02014C08 thumb
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02014D2C 0x02014D2C thumb
 *   func_02047970 0x02047970 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021D5BAC 0x021D5BAC thumb ov131
 *   func_0204B878 0x0204B878 arm
 *   func_021D5650 0x021D5650 thumb ov131
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_021D4940 0x021D4940 thumb ov131
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_0204044C 0x0204044C arm
 *   func_02014B08 0x02014B08 thumb
 *   func_02016020 0x02016020 thumb
 *   func_020160C0 0x020160C0 thumb
 *   g_C0E4 0x021DC0E4 data ov131
 *   g_BFF4 0x021DBFF4 data ov131
 *   g_C004 0x021DC004 data ov131
 *   g_1448 0x020A1448 data
 *   g_BFC0 0x021DBFC0 data ov131
 *   g_BFE4 0x021DBFE4 data ov131
 */
#include "../../matched/include/Obj00238.h"
#include "../../matched/include/Obj23119.h"
#include "../../matched/include/Obj01255.h"
#include "../../matched/include/Obj23120.h"
#include "../../matched/include/Obj00035.h"
#include "../../matched/include/Obj23121.h"
#include "../../matched/include/Obj23122.h"
#include "../../matched/include/Obj01739.h"

struct Mon;
struct Context;
struct Node;
struct Actor;
struct McssSys;
struct Obj;
struct PrintSys;
struct W;
struct DispVram;
struct DispConfig;
struct Bank;
struct Light;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef signed short s16;

struct BgConfig {u32 w[8];};

struct Cfg {u32 w[4];u16 h[6];};

struct Vec3 {u32 x,y,z;};

typedef enum {GX_DISP_SELECT_SUB_MAIN=0, GX_DISP_SELECT_MAIN_SUB=1} GXDispSelect;

extern u8 func_020355C4(void);
extern void *func_021D6064(u8 *);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void *func_021D65D8(void *);
extern void **func_021D7B00(u16 *a);
extern u8 *func_021D96B0(u8 *);
extern void *func_021D87E0(u16 *a);
extern void func_021D4964(u8 *p);
extern void func_021D51DC(char *);
extern void func_021D4FBC(struct Context *ctx);
extern void *func_020056A0(u32,u32,u32);
extern void func_02082A60(const void *,void *,u32);
extern void func_021D5C4C(u8 *);
extern void func_021D697C(u8 *,int *);
extern void func_021DA6A4(u8 *a, u8 *p);
extern void func_021D911C(u8 *a, u8 *p);
extern int func_02012BF8(int a0, int a1);
extern void func_021D9C3C(void *,u8 *);
extern void func_021D8F50(void *,u8 *);
extern void func_021D7C38(void *,u8 *);
extern void func_0203D34C(u32,u32);
extern void func_02030EAC(struct Node *n);
extern void func_021D5180(char *);
extern void func_021D5258(char *);
extern void func_021D4F24(char *);
extern void func_021D91EC(void *,void *);
extern void func_021D881C(void *,u8 *);
extern void func_021D9734(u8 *a, u8 *p);
extern void func_021D7B34(int,char *);
extern void func_021D6608(void *,void *);
extern void func_021D48E4(char *);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void func_020355D8(u8);
extern u32 func_020307B0(void *p);
extern u32 func_02035CB8(u32 *,u32 *);
extern void func_021D5DC4(u8 *p);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021D5280(char *p);
extern void func_021D6614(u8 *a, u8 *p);
extern void func_021D52A8(char *p);
extern void func_021D7B48(void *,void *);
extern void func_021D9740(u8 *a, u8 *p);
extern void func_021D8830(u8 *,u8 *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void func_02014C08(char *);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02014D2C(struct McssSys *sys);
extern void func_02047970(void);
extern void func_02041EE4(u32,u32,u32);
extern int func_021D5BAC(u8 *,int,u16 *);
extern void func_0204B878(struct Obj *p, u16 value);
extern s32 func_021D5650(struct W *p);
extern void func_0204A648(void);
extern void func_020434CC(void),func_02043588(void);
extern void func_0202223C(u32,u32);
extern u32 func_02022224(void *);
extern void func_020433E0(const struct DispVram *);
extern void func_0203F8F4(u16),func_02045088(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_021D4940(struct BgConfig *,u32,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(u32 *,u32,u32,u32,u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
extern void func_02046440(u32,u32,u32,u32,u16,u16,void (*)(void));
extern u32 *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,struct Vec3 *,struct Vec3 *,struct Vec3 *,u16);
extern void func_02048AD0(struct Light *l);
extern void func_0207DCF8(const void *);
extern void func_02046BE0(u32,u32),func_0204044C(u32);
extern void *func_02014B08(u32,void *);
extern void func_02016020(void *,u32);
extern void func_020160C0(char *p, unsigned int v);
int func_021D4240(char *p);
int func_021D4418(char *p);
int func_021D44C8(char *p);
void func_021D46E4(void);
void func_021D46EC(char *p);
extern const struct DispVram g_C0E4;
extern struct DispConfig g_BFF4;
extern struct BgConfig g_C004[7];
extern struct Cfg g_1448;
extern struct Vec3 g_BFC0[3];
extern u16 g_BFE4[8];

int func_021D4240(char *p)
{
    u8 i;
    ((struct Obj00238 *)p)->f18=(*(u8 **)(p+8))[15];
    ((struct Obj00238 *)p)->f1A=255;
    ((struct Obj00238 *)p)->f1B=0;
    ((struct Obj00238 *)p)->f20=*(u32 *)0x02fffc3c;
    ((struct Obj00238 *)p)->f5C=4;
    ((struct Obj00238 *)p)->f44=1;
    ((struct Obj00238 *)p)->f48=0;
    ((struct Obj00238 *)p)->f4C=0;
    ((struct Obj00238 *)p)->f54=0;
    ((struct Obj00238 *)p)->fC=1;
    ((struct Obj00238 *)p)->f25C=0;
    ((struct Obj00238 *)p)->f260=0;
    ((struct Obj00238 *)p)->f50=0;
    ((struct Obj00238 *)p)->f1A0=0;
    ((struct Obj00238 *)p)->f10=0;
    ((struct Obj00238 *)p)->f14=0;
    ((struct Obj00238 *)p)->f1C=func_020355C4();
    if ((*(u8 **)(p+8))[13]==3) {
        (*(u8 **)(p+8))[13]=2;
        ((struct Obj00238 *)p)->f14=1;
    }
    if ((*(u8 **)(p+8))[12]==2) ((struct Obj00238 *)p)->f258=func_0201747C(func_021D6064((u8 *)p),((struct Obj00238 *)p)->f0);
    else ((struct Obj00238 *)p)->f258=0;
    func_021D46EC(p);
    ((struct Obj00238 *)p)->f88=func_021D65D8(p);
    ((struct Obj00238 *)p)->f8C=func_021D7B00((u16 *)p);
    ((struct Obj00238 *)p)->f90=func_021D96B0((u8 *)p);
    ((struct Obj00238 *)p)->f94=func_021D87E0((u16 *)p);
    func_021D4964((u8 *)p);
    func_021D51DC(p);
    func_021D4FBC((struct Context *)p);
    ((struct Obj00238 *)p)->f4=func_020056A0((u32)func_021D46E4,(u32)p,8);
    ((struct Obj00238 *)p)->f1A4=0;
    func_02082A60((void *)0x0500026c,p+0x1a6,12);
    func_02082A60((void *)0x05000360,p+0x1b6,64);
    func_02082A60((void *)0x050003a0,p+0x216,32);
    func_02082A60((void *)0x050003a0,p+0x236,32);
    func_021D5C4C((u8 *)p);
    if ((*(u8 **)(p+8))[13]==2) {
        ((struct Obj00238 *)p)->f58=3;
        func_021D697C((u8 *)p,*(int * *)&((struct Obj00238 *)p)->f88);
        func_021DA6A4((u8 *)p,((struct Obj00238 *)p)->f90);
        func_021D911C((u8 *)p,((struct Obj00238 *)p)->f94);
    } else {
        ((struct Obj00238 *)p)->f58=(*(u8 **)(p+8))[16];
        if (((struct Obj00238 *)p)->f58<3) {
            for(i=0;i<3;i++) *(int *)(p+0x60+i*4)=func_02012BF8((int)(((struct Obj23119 *)(*(char * *)&((struct Obj00238 *)p)->f8))->f8),i+7);
        }
        func_021D697C((u8 *)p,*(int * *)&((struct Obj00238 *)p)->f88);
        func_021D911C((u8 *)p,((struct Obj00238 *)p)->f94);
        switch (((struct Obj00238 *)p)->f58) {
        case 0: func_021D7C38(p,*(u8 * *)&((struct Obj00238 *)p)->f8C); break;
        case 1: func_021D9C3C(p,*(u8 * *)&((struct Obj00238 *)p)->f90); break;
        case 2: func_021D8F50(p,*(u8 * *)&((struct Obj00238 *)p)->f94); break;
        default: ((struct Obj00238 *)p)->f58=0;
            func_021D7C38(p,*(u8 * *)&((struct Obj00238 *)p)->f8C); break;
        }
    }
    func_0203D34C(1,((struct Obj00238 *)p)->f0);
    return 1;
}

/*
 * extent: Two zero alignment bytes at 0x021D44C6.
 */
int func_021D4418(char *p)
{
    u8 i;
    func_02030EAC(((struct Obj01255 *)p)->f4);
    (*(u8 **)(p+8))[15]=((struct Obj01255 *)p)->f18;
    func_021D5180(p);
    func_021D5258(p);
    func_021D4F24(p);
    func_021D91EC(p,((struct Obj01255 *)p)->f94);
    func_021D881C(p,*(u8 * *)&((struct Obj01255 *)p)->f94);
    func_021D9734((u8 *)p,((struct Obj01255 *)p)->f90);
    func_021D7B34((int)p,*(char * *)&((struct Obj01255 *)p)->f8C);
    func_021D6608(p,((struct Obj01255 *)p)->f88);
    func_021D48E4(p);
    if(((struct Obj01255 *)p)->f58<3){
        for(i=0;i<3;i++) func_02012BE0(((struct Obj23120 *)(*(char * *)&((struct Obj01255 *)p)->f8))->f8,i+7,*(int *)(p+i*4+0x60));
    }
    if(((struct Obj01255 *)p)->f14==1){
        (*(u8 **)(p+8))[13]=3;
        ((struct Obj01255 *)p)->f14=0;
    }
    func_020355D8(((struct Obj01255 *)p)->f1C);
    if(((struct Obj01255 *)p)->f258) func_020307B0(((struct Obj01255 *)p)->f258);
    return 1;
}

/*
 * interface: 02035CB8 writes fields only on success; their previous values
 *   remain initialized on failure. 021D5BAC guards a null output pointer.
 *   Tick difference is unsigned full-word arithmetic then byte truncation.
 *   Follower 021D46E4 is the complete eight-byte no-argument tail stub
 *   to owner 0204A648 (void(void)), with no return consumed.
 */
int func_021D44C8(char *p)
{
    u32 tick;
    ((struct Obj00035 *)p)->f30=((struct Obj00035 *)p)->f28;
    ((struct Obj00035 *)p)->f34=((struct Obj00035 *)p)->f2C;
    func_02035CB8((u32 *)(p+0x28),(u32 *)(p+0x2c));
    switch (*(u32 *)&((struct Obj00035 *)p)->f50) {
    case 0:
        if (((struct Obj00035 *)p)->fC==1) func_021D5DC4((u8 *)p);
        else {
            func_0202208C(0,1,1,0,6,1,((struct Obj00035 *)p)->f0);
            ((struct Obj00035 *)p)->f50=1;
        }
        break;
    case 1:
        if (func_020221A4()==1) ((struct Obj00035 *)p)->f50=4;
        break;
    case 2:
        if (((struct Obj00035 *)p)->f1A0==0 || func_0204B98C(((struct Obj00035 *)p)->f1A0)==0 || ((struct Obj23121 *)(*(char * *)&((struct Obj00035 *)p)->f8))->f24==1) {
            func_0202208C(0,0,0,0,6,1,((struct Obj00035 *)p)->f0);
            ((struct Obj00035 *)p)->f50=3;
        }
        break;
    case 3:
        if (func_020221A4()==1) return ((struct Obj00035 *)p)->f54;
        break;
    case 4:
        func_021D5280(p);
        if (((struct Obj00035 *)p)->fC==1) func_021D5DC4((u8 *)p);
        else {
            func_021D6614((u8 *)p,((struct Obj00035 *)p)->f88);
            if (((struct Obj23122 *)(*(char * *)&((struct Obj00035 *)p)->f8))->f24==1) {
                ((struct Obj00035 *)p)->f54=1;
                ((struct Obj00035 *)p)->f50=2;
            }
            func_021D52A8(p);
            if (((struct Obj00035 *)p)->fC==0) {
                switch (((struct Obj00035 *)p)->f5C) {
                case 0: func_021D7B48(p,((struct Obj00035 *)p)->f8C); break;
                case 1:
                case 3: func_021D9740((u8 *)p,((struct Obj00035 *)p)->f90); break;
                case 2: func_021D8830((u8 *)p,*(u8 * *)&((struct Obj00035 *)p)->f94); break;
                }
            }
        }
        break;
    }
    func_0201C4E4(((struct Obj00035 *)p)->f84);
    func_0204A600();
    func_02014C08(*(char * *)&((struct Obj00035 *)p)->f78);
    func_02047964();
    func_020479D8();
    func_02014D2C(((struct Obj00035 *)p)->f78);
    func_02047970();
    tick=*(u32 *)0x02fffc3c;
    ((struct Obj00035 *)p)->f1B+=(u8)(tick-((struct Obj00035 *)p)->f20);
    ((struct Obj00035 *)p)->f20=tick;
    while (((struct Obj00035 *)p)->f1B>=4) {
        func_02041EE4(3,1,1);
        func_02041EE4(3,4,1);
        func_02041EE4(7,1,1);
        func_02041EE4(7,4,1);
        ((struct Obj00035 *)p)->f1B-=4;
    }
    if (((struct Obj00035 *)p)->f48==1 && func_0204B98C(((struct Obj00035 *)p)->f188)==0) {
        if (func_021D5BAC((u8 *)p,0,0)==1) func_0204B878(((struct Obj00035 *)p)->f188,3);
        else func_0204B878(((struct Obj00035 *)p)->f188,17);
        ((struct Obj00035 *)p)->f48=0;
    }
    if (((struct Obj00035 *)p)->f4C==1 && func_0204B98C(((struct Obj00035 *)p)->f18C)==0) {
        if (func_021D5BAC((u8 *)p,1,0)==1) func_0204B878(((struct Obj00035 *)p)->f18C,2);
        else func_0204B878(((struct Obj00035 *)p)->f18C,16);
        ((struct Obj00035 *)p)->f4C=0;
    }
    func_021D5650((struct W *)p);
    return 0;
}

void func_021D46E4(void) { func_0204A648(); }

static inline void GX_SetVisiblePlane(int plane)
{ *(volatile u32 *)0x04000000=(u32)((*(volatile u32 *)0x04000000 & ~0x1f00) | (plane<<8)); }

static inline void GXS_SetVisiblePlane(int plane)
{ *(volatile u32 *)0x04001000=(u32)((*(volatile u32 *)0x04001000 & ~0x1f00) | (plane<<8)); }

static inline void GX_SetDispSelect(GXDispSelect sel)
{ *(volatile u16 *)0x04000304=(u16)((*(volatile u16 *)0x04000304 & ~0x8000) | (sel<<15)); }

/*
 * interface: complete original 020160C0 bytes 41 64 70 47 store r1 at
 *   r0+0x44 and return. Caller supplies object and full word 0x10000.
 *   02046440 owner's s16 heap is u16 here: original ldrh zero-extends its
 *   outgoing stack word. Lower 16-bit callee conversion remains unchanged.
 *   Config c initializes all 28 bytes before h[0] and consumer reads.
 * lever: game hardware writes use vendor visible-plane and enum display
 *   selection inlines; raw compound assignments change constant sharing.
 * witness: 020160C0 filed as src/matched/arm9/func_020160C0.c.
 * volatile: hardware DISPCNT/BLDCNT/POWCNT1/DISP3DCNT registers
 */
void func_021D46EC(char *p)
{
    struct Cfg c;
    func_020434CC();func_02043588();
    GX_SetVisiblePlane(0);GXS_SetVisiblePlane(0);
    func_0202223C(0,0);func_0202223C(1,0);
    func_02022224(0);func_02022224((void *)1);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    func_020433E0(&g_C0E4);
    func_0203F8F4(((struct Obj01739 *)p)->f0);func_02045088(((struct Obj01739 *)p)->f0);
    func_0203FC28(&g_BFF4);
    func_021D4940(&g_C004[6],1,0);func_021D4940(&g_C004[4],2,0);func_021D4940(&g_C004[0],3,0);
    func_02040588(0,1);
    func_021D4940(&g_C004[1],4,0);func_021D4940(&g_C004[2],5,0);func_021D4940(&g_C004[3],6,0);func_021D4940(&g_C004[5],7,0);
    func_0207D63C((u32 *)0x04000050,4,30,13,16);
    func_0207D63C((u32 *)0x04001050,4,8,13,16);
    c=g_1448;c.h[0]=110;
    func_0204A48C(&c,(u32)(&g_C0E4),((struct Obj01739 *)p)->f0);
    ((struct Obj01739 *)p)->f174=func_0204B100(96,0,((struct Obj01739 *)p)->f0);
    func_0204B270(((struct Obj01739 *)p)->f174);
    func_020434DC(16,1);func_02043598(16,1);
    func_02046440(0,2,0,1,0,((struct Obj01739 *)p)->f0,0);
    *(u32 * *)&((struct Obj01739 *)p)->f70=func_02048A24(2,0xc0000,0,0,0x100000,0x80000,0x200000,0,&g_BFC0[0],&g_BFC0[2],&g_BFC0[1],((struct Obj01739 *)p)->f0);
    func_02048AD0(((struct Obj01739 *)p)->f70);
    func_0207DCF8(g_BFE4);
    *(volatile u16 *)0x04000060 &= ~0x3020;
    func_02046BE0(0,0);func_0204044C(0);
    ((struct Obj01739 *)p)->f78=func_02014B08(2,(void *)((struct Obj01739 *)p)->f0);
    func_02016020(((struct Obj01739 *)p)->f78,0);
    func_020160C0(((struct Obj01739 *)p)->f78,0x10000);
}
