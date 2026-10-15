/*
 * function: DENDOU_VIEW_InitBgs
 * address: 0x021DC92C
 * packet: pkt_ov171_021DC92C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021DEA50 0x021DEA50 data a4
 *   d_021DEAC0 0x021DEAC0 data a4
 *   d_021DEAA0 0x021DEAA0 data a4
 *   sBgTemplateMain2 0x021DEB00 data a4
 *   sBgTemplateMain3 0x021DEA60 data a4
 *   d_021DEA80 0x021DEA80 data a4
 *   d_021DEAE0 0x021DEAE0 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct DispConfig {u32 w[4];};
struct BgTemplate {u32 w[8];};
extern const struct DispConfig d_021DEA50;
extern const struct BgTemplate d_021DEAC0,d_021DEAA0,sBgTemplateMain2,sBgTemplateMain3,d_021DEA80,d_021DEAE0;
extern void BG_SYS_Create(u16);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void BG_SYS_SetMainPlaneVisible(u32,u32),BG_SYS_SetSubPlaneVisible(u32,u32);
void DENDOU_VIEW_InitBgs(void)
{
    struct DispConfig d;
    struct BgTemplate a,b,c,e,f,g;
    BG_SYS_Create(140);
    d=d_021DEA50;BG_SYS_SetGraphicsMode(&d);
    a=d_021DEAC0;BG_SYS_InitBgLayer(0,&a,0);
    b=d_021DEAA0;BG_SYS_InitBgLayer(1,&b,0);
    c=sBgTemplateMain2;BG_SYS_InitBgLayer(2,&c,0);
    e=sBgTemplateMain3;BG_SYS_InitBgLayer(3,&e,0);
    f=d_021DEA80;BG_SYS_InitBgLayer(4,&f,0);
    g=d_021DEAE0;BG_SYS_InitBgLayer(5,&g,0);
    BG_SYS_SetMainPlaneVisible(13,1);BG_SYS_SetSubPlaneVisible(3,1);
}
