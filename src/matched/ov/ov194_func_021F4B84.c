/*
 * function: func_021F4B84
 * address: 0x021F4B84
 * packet: pkt_ov194_021F4B84
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 0x04000050, 0x04001050, 0x04000000, 0x04001000.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021F4CF0 0x021F4CF0 thumb ov194
 *   func_021F4C6C 0x021F4C6C thumb ov194
 *   func_0201DD68 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj24927.h"
struct Node;
extern void func_02030EAC(struct Node *);
extern void func_021F4CF0(unsigned char *);
extern void func_021F4C6C(void *p);
extern void func_0201DD68(void);
extern void MI_CpuFill8(void *, unsigned, unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
static inline void G2_BlendNone(void) { *(volatile unsigned short *)0x04000050 = 0; }
static inline void G2S_BlendNone(void) { *(volatile unsigned short *)0x04001050 = 0; }
static inline void GX_SetVisibleWnd(int window) { *(volatile unsigned *)0x04000000 = (*(volatile unsigned *)0x04000000 & ~0xE000) | (window << 13); }
static inline void GXS_SetVisibleWnd(int window) { *(volatile unsigned *)0x04001000 = (*(volatile unsigned *)0x04001000 & ~0xE000) | (window << 13); }
void func_021F4B84(unsigned char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj24927 *)p)->fC);
    func_021F4CF0(p + 4);
    func_021F4C6C(p);
    func_0201DD68();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    MI_CpuFill8(p, 0, 0x10);
    func_020307B0(p);
}
