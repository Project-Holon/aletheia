/*
 * function: func_021B9D58
 * address: 0x021B9D58
 * packet: pkt_ov205_021B9D58
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02040EBC 0x02040EBC arm
 *   BMP_WIN_Init 0x02045088 arm
 *   d_021B9EFC 0x021B9EFC data a4
 *   d_021B9ECC 0x021B9ECC data a4
 *   d_021B9EDC 0x021B9EDC data a4
 */
typedef unsigned short u16;
extern void BG_SYS_Create(u16);
typedef unsigned int   u32;
struct BgTemplate;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02040EBC(unsigned,unsigned);
extern void BMP_WIN_Init(u16);
extern const unsigned d_021B9EFC[],d_021B9ECC[],d_021B9EDC[];
void func_021B9D58(u16 heap)
{
    BG_SYS_Create(heap);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B9EFC);
    func_0203FC28((void *)d_021B9ECC);
    BG_SYS_InitBgLayer(0,(const struct BgTemplate *)d_021B9EDC,0);
    func_02049B40(23,7,0,416,32,heap);
    func_02040EBC(0,0);
    BMP_WIN_Init(heap);
}
