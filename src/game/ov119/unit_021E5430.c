/*
 * file:     unit_021E5430.c
 * unit:     yes
 * function: func_021E5430, func_021E5520, func_021E55BC
 * address:  0x021E5430
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204044C 0x0204044C arm
 *   func_02040588 0x02040588 arm
 *   func_0204047C 0x0204047C arm
 *   d_021E7F24 0x021E7F24 data a4
 *   d_021E7E84 0x021E7E84 data a4
 *   d_021E7EA4 0x021E7EA4 data a4
 *   func_020434DC 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   d_021E7D00 0x021E7D00 data a4
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   d_021E7DE0 0x021E7DE0 data a4
 *   d_021E7CA0 0x021E7CA0 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 *   d_021E7C94 0x021E7C94 data a4
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 */
#include "pokemontrade_types.h"

struct Light;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct BgTemplate { u32 a,b,bufSize,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; } BgTemplate;

typedef enum { SHADING_TOON, SHADING_HIGHLIGHT } Shading;

typedef short s16;

typedef struct { int x,y,z; } Vec;

extern void func_0203FCA0(u32,const BgTemplate *,u32);
extern void func_02040C14(u32,u32,u32,u32);
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void func_020409B4(u32);
extern void func_0204044C(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204047C(int,u16);
extern void func_020434DC(u32 mask, u32 enable);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_Init(int,int,int,int,u16,u16,void (*)(void));
extern int G3D_CAMERA_Create(int,int,int,int,int,int,int,int,const Vec *,const Vec *,const Vec *,u16);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
void func_021E5430(void *a0);
void func_021E5520(void);
void func_021E55BC(char *p);
extern const BgTemplate d_021E7F24,d_021E7E84,d_021E7EA4;
extern char d_021E7D00[];
extern Vec d_021E7DE0, d_021E7CA0, d_021E7C94;
extern const s16 d_020A1EB8[];

void func_021E5430(void *a0)
{
 BgTemplate a,b,c;
 a=d_021E7F24;
 func_0203FCA0(3,&a,0);func_02040C14(3,0,1,0);
 func_02041300(3,0,0,0,32,24,17);func_020409B4(3);
 b=d_021E7E84;
 func_0203FCA0(2,&b,0);func_02040C14(2,0,1,0);
 func_02041300(2,0,0,0,32,24,17);func_020409B4(2);
 c=d_021E7EA4;
 func_0203FCA0(1,&c,0);
 func_02041300(1,0,0,0,32,24,17);func_020409B4(1);
 func_0204044C(0);func_02040588(0,1);func_0204047C(0,0);
}

static inline void shading(Shading s) { *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3002) | (s << 1)); }

static inline void antialias(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x10); else *(volatile u16 *)0x04000060 &= (u16)~0x3010; }

static inline void blend(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 8); else *(volatile u16 *)0x04000060 &= (u16)~0x3008; }

static inline void edge(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x20); else *(volatile u16 *)0x04000060 &= (u16)~0x3020; }

/*
 * volatile: 0x04000060 reread at 021E552E, 021E553E, 021E554A, 021E5556; 0x04000008 display register; 0x04000580 hardware store at 021E557A.
 */
void func_021E5520(void)
{
    unsigned i;
    func_020434DC(1,1);
    shading(SHADING_HIGHLIGHT); antialias(1); blend(1); edge(0);
    G3X_SetFog(1,0,0,0);
    G3X_SetClearColor(0,0,0x7fff,0x3f,0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((u8)i,(const u16 *)(d_021E7D00+i*8));
    *(volatile u16 *)0x04000008 = (u16)((*(volatile u16 *)0x04000008 & ~3) | 2);
}

/*
 * lever: const camera s16 table keeps loads interleaved with stack arguments.
 * volatile: 0x04000060 hardware read-modify-write at 021E5644 and 021E5648.
 */
void func_021E55BC(char *p)
{
    u16 heap;
    Vec v;
    G3D_SYSTEM_Init(0,2,0,1,0,(((TradeWork *)p)->f5F4&0x7fff)|0x8000,func_021E5520);
    heap = (((TradeWork *)p)->f5F4&0x7fff)|0x8000;
    v = d_021E7DE0;
    ((TradeWork *)p)->f810 = G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,&d_021E7CA0,&v,&d_021E7C94,heap);
    G3D_CAMERA_Reset((struct Light *)(((TradeWork *)p)->f810));
    *(volatile u16 *)0x04000060 &= 0xcfdf;
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
