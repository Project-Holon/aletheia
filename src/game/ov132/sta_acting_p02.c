/*
 * file:     sta_acting_p02.c
 * unit:     yes
 * function: func_021F899C, func_021F8BD4
 * address:  0x021F899C
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02040588 0x02040588 arm
 *   func_02046440 0x02046440 arm
 *   func_0204044C 0x0204044C arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   func_0204EBD4 0x0204EBD4 arm
 *   func_0204ED70 0x0204ED70 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   func_021F8DA0 0x021F8DA0 thumb ov132
 *   d_021FDBA0 0x021FDBA0 data a4
 *   d_021FDAA0 0x021FDAA0 data a4
 *   d_021FDB40 0x021FDB40 data a4
 *   d_021FDB60 0x021FDB60 data a4
 *   d_021FDB80 0x021FDB80 data a4
 *   d_021FDAC0 0x021FDAC0 data a4
 *   d_021FDAE0 0x021FDAE0 data a4
 *   d_021FDB00 0x021FDB00 data a4
 *   d_021FDB20 0x021FDB20 data a4
 *   d_021FDAB0 0x021FDAB0 data a4
 *   d_020A1448 0x020A1448 data a4
 *   d_021FDA7C 0x021FDA7C data a4
 *   d_021FDBF8 0x021FDBF8 data a4
 *   d_021FDBD4 0x021FDBD4 data a4
 *   func_02049BDC 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02082A60 0x02082A60 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F6F24 0x021F6F24 thumb ov112
 */
#include "../../matched/include/Obj00503.h"

struct BgTemplate;
struct Blk3;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Light;
typedef unsigned u32_021F899C;

typedef unsigned short u16;

typedef unsigned char u8;

typedef int BOOL;

typedef struct { u32_021F899C w[3]; } Vec3;

typedef struct { Vec3 a,b,c; } Vectors;

typedef struct { u32_021F899C w[7]; } Blob28;

typedef enum { MAIN_SUB=0,SUB_MAIN=1 } GXDispSelect;

typedef unsigned int u32_021F8BD4;

extern void func_020434CC(void),func_02043588(void);
extern void func_0202223C(u32_021F899C,u32_021F899C);
extern u32_021F899C func_02022224(void *);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_021F8DA0(const struct BgTemplate *p, u32_021F899C id, u32_021F899C type);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02046440(u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u16,u16,void (*)(void));
extern void func_0204044C(u32_021F899C),func_02046BE0(u32_021F899C,u32_021F899C);
extern void *func_02048A24(u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,const Vec3 *,const Vec3 *,const Vec3 *,u16);
extern void func_02048AD0(struct Light *l);
extern void func_0207DCF8(const void *);
extern void *func_0204EBD4(u8 *src, void *heap);
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_0204A48C(const struct Cfg *cfg, u32_021F899C arg, u32_021F899C heapId);
extern void func_020434DC(u32_021F899C,u32_021F899C),func_02043598(u32_021F899C,u32_021F899C),func_0207D63C(void *,int,int,int,int);
extern void func_02049BDC(void *a0, u32_021F8BD4 a1, u32_021F8BD4 a2, u32_021F8BD4 a3, u32_021F8BD4 a4, u32_021F8BD4 a5, u16 a6);
extern u32_021F8BD4 func_02049658(void *a, u32_021F8BD4 b, u32_021F8BD4 c, u32_021F8BD4 d, u32_021F8BD4 e, u32_021F8BD4 f, u16 g);
extern void func_020498F4(void *a, u32_021F8BD4 b, u32_021F8BD4 c, u32_021F8BD4 d, u32_021F8BD4 e, u32_021F8BD4 f, u16 g);
extern void func_02049B68(void *a, u32_021F8BD4 b, u32_021F8BD4 c, u32_021F8BD4 d, u32_021F8BD4 e, u16 f);
extern void func_02082A60(const void *,void *,u32_021F8BD4);
extern void func_020409B4(u32_021F8BD4);
extern u8 *func_021F6F24(u32_021F8BD4 heap, u32_021F8BD4 v);
void func_021F899C(u8 *p);
void func_021F8BD4(u8 *p);
extern const Vectors d_021FDA7C;
extern const Blob28 d_021FDBF8;
extern const Vec3 d_021FDBD4;
extern const u32_021F899C d_021FDBA0[];
extern const u32_021F899C d_021FDAA0[];
extern const u32_021F899C d_021FDB40[];
extern const u32_021F899C d_021FDB60[];
extern const u32_021F899C d_021FDB80[];
extern const u32_021F899C d_021FDAC0[];
extern const u32_021F899C d_021FDAE0[];
extern const u32_021F899C d_021FDB00[];
extern const u32_021F899C d_021FDB20[];
extern const u32_021F899C d_021FDAB0[];
extern const u32_021F899C d_020A1448[];

static inline void GX_SetVisiblePlane(int plane) { *(volatile u32_021F899C *)0x04000000=(*(volatile u32_021F899C *)0x04000000&~0x1F00u)|((u32_021F899C)plane<<8); }

static inline void GXS_SetVisiblePlane(int plane) { *(volatile u32_021F899C *)0x04001000=(*(volatile u32_021F899C *)0x04001000&~0x1F00u)|((u32_021F899C)plane<<8); }

static inline void GX_SetDispSelect(GXDispSelect sel) { *(volatile u16 *)0x04000304=(u16)((*(volatile u16 *)0x04000304&~0x8000u)|(sel<<15)); }

static inline void G3X_EdgeMarking(BOOL enable) { if(enable) *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060&~0x3000u)|0x20); else *(volatile u16 *)0x04000060&=(u16)~0x3020; }

static inline void G3X_AntiAlias(BOOL enable) { if(enable) *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060&~0x3000u)|0x10); else *(volatile u16 *)0x04000060&=(u16)~0x3010; }

static inline void G3X_AlphaBlend(BOOL enable) { if(enable) *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060&~0x3000u)|8); else *(volatile u16 *)0x04000060&=(u16)~0x3008; }

static inline void GX_SetVisibleWnd(int window) { *(volatile u32_021F899C *)0x04000000=(*(volatile u32_021F899C *)0x04000000&~0xE000u)|((u32_021F899C)window<<13); }

static inline void G2_SetWndOBJInsidePlane(int wnd,BOOL effect) { u32_021F899C tmp; tmp=(*(volatile u16 *)0x0400004A&~0x3F00u)|((u32_021F899C)wnd<<8); if(effect) tmp|=0x2000; *(volatile u16 *)0x0400004A=(u16)tmp; }

static inline void G2_SetWndOutsidePlane(int wnd,BOOL effect) { u32_021F899C tmp; tmp=(*(volatile u16 *)0x0400004A&~0x3Fu)|(u32_021F899C)wnd; if(effect) tmp|=0x20; *(volatile u16 *)0x0400004A=(u16)tmp; }

void func_021F899C(u8 *p)
{
    Blob28 big;
    Vec3 small;
    void *light,*board;
    func_020434CC(); func_02043588();
    GX_SetVisiblePlane(0); GXS_SetVisiblePlane(0);
    func_0202223C(0,0); func_0202223C(1,0);
    func_02022224(0); func_02022224((void *)1);
    GX_SetDispSelect(SUB_MAIN);
    func_020433E0((const struct DispVram *)d_021FDBA0);
    func_0203F8F4(*(u16 *)p); func_02045088(*(u16 *)p);
    func_0203FC28((struct DispConfig *)d_021FDAA0);
    func_021F8DA0((const struct BgTemplate *)d_021FDB40,1,0);
    func_021F8DA0((const struct BgTemplate *)d_021FDB60,2,0);
    func_021F8DA0((const struct BgTemplate *)d_021FDB80,3,0);
    func_021F8DA0((const struct BgTemplate *)d_021FDAC0,5,0);
    func_021F8DA0((const struct BgTemplate *)d_021FDAE0,6,0);
    func_021F8DA0((const struct BgTemplate *)d_021FDB00,4,0);
    func_021F8DA0((const struct BgTemplate *)d_021FDB20,7,0);
    func_02040588(0,1);
    func_02046440(0,2,0,4,0,*(u16 *)p,0);
    func_0204044C(3);
    func_02046BE0(0,1);
    light=func_02048A24(2,0xC000,0,0,0x10000,0x1000,0x3E8000,0,&d_021FDA7C.c,&d_021FDA7C.a,&d_021FDA7C.b,*(u16 *)p);
    *(void **)(p+0xA8)=light;
    func_02048AD0(light);
    func_0207DCF8(d_021FDAB0);
    G3X_EdgeMarking(0); G3X_AntiAlias(1); G3X_AlphaBlend(1);
    func_02046BE0(0,0);
    big=d_021FDBF8;
    small=d_021FDBD4;
    board=func_0204EBD4((u8 *)(&big),(void *)(u32_021F899C)*(u16 *)p);
    *(void **)(p+0xAC)=board;
    func_0204ED70(board,(struct Blk3 *)(&small));
    func_0204A48C((const struct Cfg *)d_020A1448,(u32_021F899C)d_021FDBA0,*(u16 *)p);
    func_020434DC(16,1); func_02043598(16,1);
    func_0207D63C((void *)0x04000050,8,1,0,10);
    GX_SetVisibleWnd(4);
    G2_SetWndOBJInsidePlane(23,1);
    G2_SetWndOutsidePlane(31,1);
}

void func_021F8BD4(u8 *p)
{
    u16 palette[16];
    u8 i=0;
    u16 old,new;
    func_02049BDC((void *)(((struct Obj00503 *)p)->f18),2,0,32,32,32,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),8,3,0,0,0,((struct Obj00503 *)p)->f0);
    func_020498F4((void *)(((struct Obj00503 *)p)->f18),14,3,0,0,0,((struct Obj00503 *)p)->f0);
    func_02049BDC((void *)(((struct Obj00503 *)p)->f18),3,0,0,0,32,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),9,2,0,0,0,((struct Obj00503 *)p)->f0);
    func_020498F4((void *)(((struct Obj00503 *)p)->f18),15,2,0,0,0,((struct Obj00503 *)p)->f0);
    func_02049B68((void *)(((struct Obj00503 *)p)->f18),5,4,0,0,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),13,5,0,0,0,((struct Obj00503 *)p)->f0);
    func_020498F4((void *)(((struct Obj00503 *)p)->f18),17,5,0,0,0,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),12,6,0,0,0,((struct Obj00503 *)p)->f0);
    func_020498F4((void *)(((struct Obj00503 *)p)->f18),16,6,0,0,0,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),11,4,0,0,0,((struct Obj00503 *)p)->f0);
    func_02082A60((void *)0x05000400,p+0x16a,32);
    func_02082A60((void *)0x05000420,palette,32);
    for(i=0;i<16;i++){
        old=*(u16 *)(p+0x16a+i*2);
        new=palette[i];
        p[0x18a+i]=(u8)(new&31)-(u8)(old&31);
        p[0x19a+i]=(u8)((new&0x3e0)>>5)-(u8)((old&0x3e0)>>5);
        p[0x1aa+i]=(u8)((new&0x7c00)>>10)-(u8)((old&0x7c00)>>10);
    }
    func_020409B4(3);
    func_020409B4(5);
    ((struct Obj00503 *)p)->f3C=func_021F6F24(((struct Obj00503 *)p)->f0,(u32_021F8BD4)p);
}
