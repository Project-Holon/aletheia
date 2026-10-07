/*
 * file:     subway_map_graphic_p02.c
 * unit:     yes
 * function: func_021B9898, func_021B989C, func_021B9940, func_021B99E8, func_021B9A44
 * address:  0x021B9898
 * region:   ov224
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   table 0x021B9C80 data ov224
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9A6C 0x021B9A6C thumb ov224
 *   func_021B9B10 0x021B9B10 thumb ov224
 *   func_021B9A58 0x021B9A58 thumb ov224
 *   func_021B9B7C 0x021B9B7C thumb ov224
 *   file 0x021B9D58 data ov224 a1
 *   vram 0x021B9CA0 data
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021B9BE8 0x021B9BE8 thumb ov224
 *   func_021B9B50 0x021B9B50 thumb ov224
 *   func_021B9ACC 0x021B9ACC thumb ov224
 *   func_021B9B6C  0x021B9B6C  thumb  ov224
 *   func_021B9B04  0x021B9B04  thumb  ov224
 */
#include "../../matched/include/Obj26109.h"
#include "../../matched/include/Obj26110.h"

#define DISP (*(volatile u16 *)0x04000060)
struct DispVram;
struct Node;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef enum { GX_SHADING_TOON = 0, GX_SHADING_HIGHLIGHT = 1 } GXShading;

extern void func_020434DC(u32,u32);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(u32,u32);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, u32, u32);
extern void func_0204335C(u32);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void *func_020056A0(void (*)(void *,char *),void *,u32);
extern void func_021B9A6C(void *,u32);
extern void func_021B9B10(unsigned char *,int,int);
extern void func_021B9A58(void *,char *);
extern void func_021B9B7C(void **p, u32 heap);
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);
extern void func_0201DD68(void);
extern void func_021B9BE8(u32 *p);
extern void func_021B9B50(char *p);
extern void func_021B9ACC(void *);
void func_021B9898(void);
void func_021B989C(void);
void *func_021B9940(u32 swap, u32 heap);
void func_021B99E8(char *p);
void func_021B9A44(void *p);
extern u16 table[][4];
extern char file[], vram[];

void func_021B9898(void) {}

static inline void G2_SetBG0Priority(int priority) {
    *(volatile u16 *)0x04000008 = (u16)((*(volatile u16 *)0x04000008 & ~3) | priority);
}

static inline void G3X_SetShading(GXShading shading) {
    DISP = (u16)((DISP & ~(2 | 0x1000 | 0x2000)) | (shading << 1));
}

static inline void G3X_AntiAlias(int enable) {
    if(enable) DISP = (u16)((DISP & ~(0x1000|0x2000)) | 16);
    else DISP &= (u16)~(16|0x1000|0x2000);
}

static inline void G3X_AlphaTest(int enable,int ref) {
    if(enable) { DISP = (u16)((DISP & ~(0x1000|0x2000)) | 4); *(volatile u16 *)0x04000340 = (u16)ref; }
    else DISP &= (u16)~(4|0x1000|0x2000);
}

static inline void G3X_AlphaBlend(int enable) {
    if(enable) DISP = (u16)((DISP & ~(0x1000|0x2000)) | 8);
    else DISP &= (u16)~(8|0x1000|0x2000);
}

static inline void G3X_EdgeMarking(int enable) {
    if(enable) DISP = (u16)((DISP & ~(0x1000|0x2000)) | 32);
    else DISP &= (u16)~(32|0x1000|0x2000);
}

void func_021B989C(void)
{
    u32 i;
    func_020434DC(1,1);
    i = 0;
    G2_SetBG0Priority(0);
    G3X_SetShading(GX_SHADING_HIGHLIGHT);
    G3X_AntiAlias(0);
    G3X_AlphaTest(0,0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(0);
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,0x7fff,0x3f,0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
    for (; i < 4; i++) func_02046A94((unsigned char)i,table[i]);
    func_02046BE0(0,0);
}

static inline void G2_BlendNone(void) { *(volatile u16 *)0x04000050 = 0; }

static inline void G2S_BlendNone(void) { *(volatile u16 *)0x04001050 = 0; }

static inline void GX_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04000000 = (u32)((*(volatile u32 *)0x04000000 & ~0xE000) | (window << 13));
}

static inline void GXS_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04001000 = (u32)((*(volatile u32 *)0x04001000 & ~0xE000) | (window << 13));
}

void *func_021B9940(u32 swap, u32 heap)
{
    char *p = func_02030734(heap, 16, 0, file, 460);
    func_02082BCC(p, 0, 16);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    func_0204335C(0);
    func_020433E0((const struct DispVram *)vram);
    func_0204363C(swap);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021B9A6C(p, heap);
    func_021B9B10((unsigned char *)p + 4, (int)vram, heap);
    func_021B9B7C((void **)(p + 8), heap);
    ((struct Obj26109 *)p)->fC = func_020056A0(func_021B9A58, p, 0);
    return p;
}

void func_021B99E8(char *p)
{
    func_02030EAC(((struct Obj26110 *)p)->fC);
    func_021B9BE8((u32 *)(p + 8));
    func_021B9B50(p + 4);
    func_021B9ACC(p);
    func_0201DD68();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    func_02082BCC(p, 0, 16);
    func_020307B0(p);
}

void func_021B9A44(void *p)
{
    void func_021B9B6C(void *);
    void func_021B9B04(void *);
    func_021B9B6C((char *)p + 4);
    func_021B9B04(p);
}
