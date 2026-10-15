/*
 * function: RESEARCH_GRAPH_InitOverlayBackgrounds
 * address: 0x021BFFC8
 * packet: pkt_ov217_021BFFC8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * data: pool 021C0068 contains 6c 36 1c 02; contested ov217 hint removed per canonical rule, data a4 resolves sole-ref.
 * symbols:
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetLowBit 0x0204044C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   d_021C366C 0x021C366C data a4
 *   d_021C36D8 0x021C36D8 data ov217
 *   d_021C36F8 0x021C36F8 data ov217
 *   d_021C3718 0x021C3718 data ov217
 *   d_021C3738 0x021C3738 data ov217
 */
#include "../include/Obj25959.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct DispConfig { u32 a,b,c,d; };
struct BgTemplate { u32 a,b,c,d; unsigned char e,f,g,h; u32 i; unsigned char j,k,l,m; u32 n; };
extern struct DispConfig d_021C366C;
extern const struct BgTemplate d_021C36D8,d_021C36F8,d_021C3718,d_021C3738;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_SetLowBit(u32);
extern void BG_SYS_InitBgLayer(u32, const struct BgTemplate *, u32);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void func_0207D63C(u32 *, u32, u32, int, int);
extern void BMP_WIN_Init(u16);
void RESEARCH_GRAPH_InitOverlayBackgrounds(char *p)
{
    BG_SYS_SetGraphicsMode(&d_021C366C);
    BG_SYS_SetLowBit(2);
    BG_SYS_InitBgLayer(6, &d_021C36D8, 0);
    BG_SYS_InitBgLayer(7, &d_021C3738, 0);
    BG_SYS_InitBgLayer(2, &d_021C36F8, 0);
    BG_SYS_InitBgLayer(3, &d_021C3718, 0);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_SetPlaneVisible(5, 1);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_SetPlaneVisible(7, 1);
    BG_SYS_SetPlaneVisible(0, 1);
    BG_SYS_SetPlaneVisible(1, 1);
    BG_SYS_SetPlaneVisible(2, 1);
    BG_SYS_SetPlaneVisible(3, 1);
    func_0207D63C((u32 *)0x04001050, 2, 1, 7, 15);
    func_0207D63C((u32 *)0x04000050, 4, 2, 16, 5);
    BMP_WIN_Init(((struct Obj25959 *)p)->f4);
}
