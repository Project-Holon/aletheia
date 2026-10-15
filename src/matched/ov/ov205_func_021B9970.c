/*
 * function: SAVE_SCREEN_SetupBackground
 * address: 0x021B9970
 * packet: pkt_ov205_021B9970
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02049B40 0x02049B40 arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GPOWER_GetSpecialPowerId 0x020111E8 thumb
 *   d_021B9E90 0x021B9E90 data a4
 *   d_021B9E60 0x021B9E60 data a4
 *   d_021B9E70 0x021B9E70 data a4
 */
typedef unsigned short u16;
extern void BG_SYS_Create(u16);
typedef unsigned int   u32;
struct BgTemplate;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void BG_SYS_LoadPlttEntry(unsigned,unsigned);
extern void BMP_WIN_Init(u16);
extern unsigned GPOWER_GetSpecialPowerId(void);
extern const unsigned d_021B9E90[],d_021B9E60[],d_021B9E70[];
void SAVE_SCREEN_SetupBackground(u16 heap)
{
    unsigned zero;
    BG_SYS_Create(heap);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B9E90);
    BG_SYS_SetGraphicsMode((void *)d_021B9E60);
    zero=0;
    BG_SYS_InitBgLayer(0,(const struct BgTemplate *)d_021B9E70,0);
    func_02049B40(23,7,0,416,32,heap);
    if(GPOWER_GetSpecialPowerId()==20) BG_SYS_LoadPlttEntry(zero,65535);
    else BG_SYS_LoadPlttEntry(zero,zero);
    BMP_WIN_Init(heap);
}
