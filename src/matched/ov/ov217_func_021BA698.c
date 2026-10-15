/*
 * function: RESEARCH_TOP_InitOverlayBackgrounds
 * address: 0x021BA698
 * packet: pkt_ov217_021BA698
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021BA710 and 021BA71E write hardware words through the observed SDK helper.
 * symbols:
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   d_021C2EEC 0x021C2EEC data a4
 *   d_021C2F78 0x021C2F78 data a4
 *   d_021C2F18 0x021C2F18 data a4
 *   d_021C2F38 0x021C2F38 data a4
 *   d_021C2F58 0x021C2F58 data a4
 */
#include "../include/Obj25834.h"
typedef unsigned short u16;
struct DispConfig;struct BgTemplate;
extern struct DispConfig d_021C2EEC;
extern const struct BgTemplate d_021C2F78,d_021C2F18,d_021C2F38,d_021C2F58;
extern void func_0203FC28(struct DispConfig *);
extern void BG_SYS_InitBgLayer(unsigned,const struct BgTemplate *,unsigned);
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(volatile unsigned *,unsigned,unsigned,unsigned,unsigned);
extern void BMP_WIN_Init(u16);
void RESEARCH_TOP_InitOverlayBackgrounds(char *p)
{
    func_0203FC28(&d_021C2EEC);
    BG_SYS_InitBgLayer(6,&d_021C2F78,0);BG_SYS_InitBgLayer(7,&d_021C2F18,0);
    BG_SYS_InitBgLayer(2,&d_021C2F38,0);BG_SYS_InitBgLayer(3,&d_021C2F58,0);
    func_02040588(4,1);func_02040588(5,1);func_02040588(6,1);func_02040588(7,1);
    func_02040588(1,1);func_02040588(2,1);func_02040588(3,1);
    func_0207D63C((volatile unsigned *)0x04001050,2,1,7,15);
    func_0207D63C((volatile unsigned *)0x04000050,4,2,16,5);
    BMP_WIN_Init(((struct Obj25834 *)p)->f4);
}
