/*
 * function: func_021B9940
 * address: 0x021B9940
 * packet: pkt_ov224_021B9940
 * region: ov224
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 0x04000050 0x04001050 0x04000000 0x04001000
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9A6C 0x021B9A6C thumb ov224
 *   func_021B9B10 0x021B9B10 thumb ov224
 *   func_021B9A58 0x021B9A58 thumb ov224
 *   func_021B9B7C 0x021B9B7C thumb ov224
 *   file 0x021B9D58 data ov224 a1
 *   vram 0x021B9CA0 data
 */
#include "../include/Obj26109.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern char file[], vram[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, u32, u32);
extern void BG_SYS_ClearGraphicsMemory(u32);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void *func_020056A0(void (*)(void *,char *),void *,u32);
extern void func_021B9A6C(void *,u32);
extern void func_021B9B10(unsigned char *,int,int);
extern void func_021B9A58(void *,char *);
extern void func_021B9B7C(void **p, u32 heap);
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
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)vram);
    func_0204363C(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    func_021B9A6C(p, heap);
    func_021B9B10((unsigned char *)p + 4, (int)vram, heap);
    func_021B9B7C((void **)(p + 8), heap);
    ((struct Obj26109 *)p)->fC = func_020056A0(func_021B9A58, p, 0);
    return p;
}
