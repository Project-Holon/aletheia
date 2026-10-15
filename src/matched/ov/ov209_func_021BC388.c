/*
 * function: ZUKAN_LIST_InitBgSystem
 * address: 0x021BC388
 * packet: pkt_ov209_021BC388
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   gZukanListDisplayConfig 0x021BE804 data a4
 *   gZukanListBgTemplateLayer0 0x021BE894 data a4
 *   gZukanListBgTemplateLayer1 0x021BE874 data a4
 *   gZukanListBgTemplateLayer2 0x021BE814 data a4
 *   gZukanListBgTemplateLayer3 0x021BE8F4 data a4
 *   gZukanListBgTemplateLayer4 0x021BE8B4 data a4
 *   gZukanListBgTemplateLayer5 0x021BE854 data a4
 *   gZukanListBgTemplateLayer6 0x021BE8D4 data a4
 *   gZukanListBgTemplateLayer7 0x021BE834 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct Display {u32 w[4];};
struct BgTemplate {u32 w[8];};
extern const struct Display gZukanListDisplayConfig;
extern const struct BgTemplate gZukanListBgTemplateLayer0,gZukanListBgTemplateLayer1,gZukanListBgTemplateLayer2,gZukanListBgTemplateLayer3,gZukanListBgTemplateLayer4,gZukanListBgTemplateLayer5,gZukanListBgTemplateLayer6,gZukanListBgTemplateLayer7;
extern void BG_SYS_Create(u16);
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void BG_SYS_ClearSlot(u32);
typedef unsigned char  u8;
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041B6C(u32);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
void ZUKAN_LIST_InitBgSystem(void)
{
    struct Display display;
    struct BgTemplate b0,b1,b2,b3,b4,b5,b6,b7;
    BG_SYS_Create(107);
    display=gZukanListDisplayConfig;BG_SYS_SetGraphicsMode((struct DispConfig *)(&display));
    b0=gZukanListBgTemplateLayer0;BG_SYS_InitBgLayer(0,&b0,0);
    BG_SYS_ClearSlot(0);BG_SYS_InitRun(0,32,0,107);func_02041B6C(0);
    b1=gZukanListBgTemplateLayer1;BG_SYS_InitBgLayer(1,&b1,0);
    b2=gZukanListBgTemplateLayer2;BG_SYS_InitBgLayer(2,&b2,0);
    BG_SYS_ClearSlot(2);func_02041B6C(2);
    b3=gZukanListBgTemplateLayer3;BG_SYS_InitBgLayer(3,&b3,0);
    b4=gZukanListBgTemplateLayer4;BG_SYS_InitBgLayer(4,&b4,0);
    BG_SYS_ClearSlot(4);BG_SYS_InitRun(4,32,0,107);func_02041B6C(4);
    b5=gZukanListBgTemplateLayer5;BG_SYS_InitBgLayer(5,&b5,0);
    b6=gZukanListBgTemplateLayer6;BG_SYS_InitBgLayer(6,&b6,0);
    BG_SYS_ClearSlot(6);func_02041B6C(6);
    b7=gZukanListBgTemplateLayer7;BG_SYS_InitBgLayer(7,&b7,0);
    BG_SYS_SetMainPlaneVisible(15,1);BG_SYS_SetSubPlaneVisible(15,1);
}
