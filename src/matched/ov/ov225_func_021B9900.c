/*
 * function: func_021B9900
 * address: 0x021B9900
 * packet: pkt_ov225_021B9900
 * region: ov225
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
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9A28 0x021B9A28 thumb ov225
 *   func_021B9ACC 0x021B9ACC thumb ov225
 *   func_021B9A14 0x021B9A14 thumb ov225
 *   file 0x021BBFE0 data ov225 a1
 *   vram 0x021BBE1C data ov225
 */
#include "../include/Obj26129.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern char file[], vram[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, u32, u32);
extern void BG_SYS_ClearGraphicsMemory(u32);
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void *func_020056A0(void (*)(void *,char *),void *,u32);
extern void func_021B9A28(void *,u32);
extern void func_021B9ACC(unsigned char *,int,int);
extern void func_021B9A14(void *,char *);

static inline void G2_BlendNone(void) { *(volatile u16 *)0x04000050 = 0; }
static inline void G2S_BlendNone(void) { *(volatile u16 *)0x04001050 = 0; }
static inline void GX_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04000000 = (u32)((*(volatile u32 *)0x04000000 & ~0xE000) | (window << 13));
}
static inline void GXS_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04001000 = (u32)((*(volatile u32 *)0x04001000 & ~0xE000) | (window << 13));
}
void *func_021B9900(u32 swap, u32 heap)
{
    char *p = func_02030734(heap, 16, 0, file, 454);
    func_02082BCC(p, 0, 16);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    BG_SYS_ClearGraphicsMemory(0);
    func_020433E0((const struct DispVram *)vram);
    func_0204363C(swap);
    func_0204361C();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    func_021B9A28(p, heap);
    func_021B9ACC((unsigned char *)p + 4, (int)vram, heap);
    ((struct Obj26129 *)p)->fC = func_020056A0(func_021B9A14, p, 0);
    return p;
}
