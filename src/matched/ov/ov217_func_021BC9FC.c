/*
 * function: RESEARCH_LIST_InitBackgrounds
 * address: 0x021BC9FC
 * packet: pkt_ov217_021BC9FC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   d_021C30C0 0x021C30C0 data a4 ov217
 *   d_021C3110 0x021C3110 data a4 ov217
 *   d_021C3130 0x021C3130 data a4 ov217
 *   d_021C30F0 0x021C30F0 data a4 ov217
 *   d_021C3150 0x021C3150 data a4
 *   d_021C3170 0x021C3170 data a4 ov217
 * Pool +B4 names 021C3150; no cross-overlay loading proof. Alignment-only
 * hint permits sole-ref/data validation of the original template address.
 */
#include "../include/Obj25880.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct DispConfig;
struct BgTemplate;
extern struct DispConfig d_021C30C0;
extern const struct BgTemplate d_021C3110, d_021C3130, d_021C30F0, d_021C3150, d_021C3170;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32, const struct BgTemplate *, u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void BMP_WIN_Init(u16);
void RESEARCH_LIST_InitBackgrounds(char *p)
{
    BG_SYS_SetGraphicsMode(&d_021C30C0);
    BG_SYS_InitBgLayer(6, &d_021C3110, 0);
    BG_SYS_InitBgLayer(7, &d_021C3130, 0);
    BG_SYS_InitBgLayer(0, &d_021C30F0, 0);
    BG_SYS_InitBgLayer(2, &d_021C3150, 0);
    BG_SYS_InitBgLayer(3, &d_021C3170, 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
    func_02040588(1, 1);
    func_02040588(0, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_0207D63C(0x04001050, 2, 1, 16, 5);
    func_0207D63C(0x04000050, 4, 2, 16, 5);
    BMP_WIN_Init(((struct Obj25880 *)p)->f8);
}
