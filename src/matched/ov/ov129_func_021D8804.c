/*
 * function: WF2DMAP_SCENE_InitBg
 * address: 0x021D8804
 * packet: pkt_ov129_021D8804
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_02082A7C 0x02082A7C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   d_021DA800 0x021DA800 data a4
 *   d_021DA638 0x021DA638 data a4
 *   d_021DA698 0x021DA698 data a4
 */
typedef unsigned u32;
typedef struct { u32 words[8]; } BgTemplate;
typedef struct { BgTemplate rows[3]; } MainTemplates;
typedef struct { BgTemplate rows[4]; } SubTemplates;
extern const u32 d_021DA800[];
extern const MainTemplates d_021DA638;
extern const SubTemplates d_021DA698;
extern void BG_SYS_ClearMainPlanes(void);
struct BgTemplate;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_02082A7C(u32,void *,u32);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u32);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void BG_SYS_SetLcdSwap(u32);
void WF2DMAP_SCENE_InitBg(void)
{
    MainTemplates main;
    SubTemplates sub;
    BG_SYS_ClearMainPlanes();
    BG_SYS_SetVramBanks((const struct DispVram *)d_021DA800);
    func_02082A7C(0,(void *)0x06000000,0x80000);
    func_02082A7C(0,(void *)0x06200000,0x20000);
    func_02082A7C(0,(void *)0x06400000,0x40000);
    func_02082A7C(0,(void *)0x06600000,0x20000);
    main=d_021DA638;
    BG_SYS_InitBgLayer(1,(const struct BgTemplate *)(&main.rows[0]),0);
    BG_SYS_InitBgLayer(2,(const struct BgTemplate *)(&main.rows[1]),0);
    BG_SYS_InitBgLayer(3,(const struct BgTemplate *)(&main.rows[2]),0);
    BG_SYS_ClearSlot(1); BG_SYS_ClearSlot(2); BG_SYS_ClearSlot(3);
    BG_SYS_SetMainPlaneVisible(1,0); BG_SYS_SetMainPlaneVisible(2,1); BG_SYS_SetMainPlaneVisible(4,0); BG_SYS_SetMainPlaneVisible(8,0);
    sub=d_021DA698;
    BG_SYS_InitBgLayer(4,(const struct BgTemplate *)(&sub.rows[0]),0);
    BG_SYS_InitBgLayer(5,(const struct BgTemplate *)(&sub.rows[1]),0);
    BG_SYS_InitBgLayer(6,(const struct BgTemplate *)(&sub.rows[2]),0);
    BG_SYS_InitBgLayer(7,(const struct BgTemplate *)(&sub.rows[3]),0);
    BG_SYS_ClearSlot(4); BG_SYS_ClearSlot(5); BG_SYS_ClearSlot(6); BG_SYS_ClearSlot(7);
    BG_SYS_SetSubPlaneVisible(1,1); BG_SYS_SetSubPlaneVisible(2,1); BG_SYS_SetSubPlaneVisible(4,0); BG_SYS_SetSubPlaneVisible(8,0);
    BG_SYS_SetLcdSwap(0);
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
}
