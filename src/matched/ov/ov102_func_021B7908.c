/*
 * function: IRC_COMPATIBLE_MENU_InitBackgrounds
 * address: 0x021B7908
 * packet: pkt_ov102_021B7908
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_0203F8F4 0x0203F8F4 arm
 * BMP_WIN_Init 0x02045088 arm
 * func_0203FC28 0x0203FC28 arm
 * func_0203FCA0 0x0203FCA0 arm
 * func_020414AC 0x020414AC arm
 * func_02040588 0x02040588 arm
 * func_020490F4 0x020490F4 arm
 * func_02049B68 0x02049B68 arm
 * func_02049658 0x02049658 arm
 * func_020498F4 0x020498F4 arm
 * func_02040C14 0x02040C14 arm
 * func_02049740 0x02049740 arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * func_020056A0 0x020056A0 thumb
 * IRC_COMPATIBLE_MENU_BackgroundVBlank 0x021B7AAC thumb ov102
 * IRC_COMPATIBLE_MENU_BgDisplayConfig 0x021B8AC4 data a4
 * IRC_COMPATIBLE_MENU_BgLayerIds 0x021B8AEC data a4
 * IRC_COMPATIBLE_MENU_BgTemplates 0x021B8B5C data a4
 * IRC_COMPATIBLE_MENU_BgLayerTypes 0x021B8B0C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 IRC_COMPATIBLE_MENU_BgDisplayConfig[], IRC_COMPATIBLE_MENU_BgLayerIds[], IRC_COMPATIBLE_MENU_BgLayerTypes[];
extern const u32 IRC_COMPATIBLE_MENU_BgTemplates[][8];
extern void func_0203F8F4(u16);
extern void BMP_WIN_Init(u16);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02040C14(u32,u32,u32,u32);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void IRC_COMPATIBLE_MENU_BackgroundVBlank(void);
extern u32 func_020056A0(void (*)(void),void *,u32);
void IRC_COMPATIBLE_MENU_InitBackgrounds(u32 *p,u16 heap)
{
    int i;
    u32 layer;
    void *arc;
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)IRC_COMPATIBLE_MENU_BgDisplayConfig);
    for(i=0;i<8;i++) {
        layer=IRC_COMPATIBLE_MENU_BgLayerIds[i];
        func_0203FCA0((u8)layer,(const struct BgTemplate *)IRC_COMPATIBLE_MENU_BgTemplates[i],(u8)IRC_COMPATIBLE_MENU_BgLayerTypes[i]);
        func_020414AC(layer);
        func_02040588(layer,1);
    }
    arc=func_020490F4(94,heap);
    func_02049B68(arc,1,0,0,0,heap);
    func_02049B68(arc,1,4,0,0,heap);
    func_02049658(arc,0,3,0,0,0,heap);
    func_02049658(arc,0,6,0,0,0,heap);
    func_02049658(arc,48,4,0,0,0,heap);
    func_02049658(arc,42,2,0,0,0,heap);
    func_020498F4(arc,4,3,0,0,0,heap);
    func_020498F4(arc,4,6,0,0,0,heap);
    func_020498F4(arc,44,4,0,0,0,heap);
    func_020498F4(arc,43,2,0,0,0,heap);
    func_02040C14(5,0,1,0);
    p[0]=func_02049740(arc,49,5,0,0,heap);
    ARC_TOOL_DeleteHandle(arc);
    p[1]=func_020056A0(IRC_COMPATIBLE_MENU_BackgroundVBlank,p,0);
}
