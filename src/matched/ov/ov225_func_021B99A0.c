/*
 * function: func_021B99A0
 * address: 0x021B99A0
 * packet: pkt_ov225_021B99A0
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 0x04000050 0x04001050 0x04000000 0x04001000
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021B9B0C 0x021B9B0C thumb ov225
 *   func_021B9A88 0x021B9A88 thumb ov225
 */
#include "../include/Obj26130.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_020307B0(void *);
extern void func_02082BCC(void *, u32, u32);
extern void func_0201DD68(void);
extern void func_021B9B0C(char *p);
extern void func_021B9A88(void *);
static inline void G2_BlendNone(void) { *(volatile u16 *)0x04000050 = 0; }
static inline void G2S_BlendNone(void) { *(volatile u16 *)0x04001050 = 0; }
static inline void GX_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04000000 = (u32)((*(volatile u32 *)0x04000000 & ~0xE000) | (window << 13));
}
static inline void GXS_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04001000 = (u32)((*(volatile u32 *)0x04001000 & ~0xE000) | (window << 13));
}
void func_021B99A0(char *p)
{
    func_02030EAC(((struct Obj26130 *)p)->fC);
    func_021B9B0C(p + 4);
    func_021B9A88(p);
    func_0201DD68();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    func_02082BCC(p, 0, 16);
    func_020307B0(p);
}
