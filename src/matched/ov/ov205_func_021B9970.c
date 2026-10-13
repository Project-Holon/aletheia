/*
 * function: func_021B9970
 * address: 0x021B9970
 * packet: pkt_ov205_021B9970
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02040EBC 0x02040EBC arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GPOWER_GetSpecialPowerId 0x020111E8 thumb
 *   d_021B9E90 0x021B9E90 data a4
 *   d_021B9E60 0x021B9E60 data a4
 *   d_021B9E70 0x021B9E70 data a4
 */
typedef unsigned short u16;
extern void func_0203F8F4(u16);
typedef unsigned int   u32;
struct BgTemplate;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02040EBC(unsigned,unsigned);
extern void BMP_WIN_Init(u16);
extern unsigned GPOWER_GetSpecialPowerId(void);
extern const unsigned d_021B9E90[],d_021B9E60[],d_021B9E70[];
void func_021B9970(u16 heap)
{
    unsigned zero;
    func_0203F8F4(heap);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B9E90);
    func_0203FC28((void *)d_021B9E60);
    zero=0;
    func_0203FCA0(0,(const struct BgTemplate *)d_021B9E70,0);
    func_02049B40(23,7,0,416,32,heap);
    if(GPOWER_GetSpecialPowerId()==20) func_02040EBC(zero,65535);
    else func_02040EBC(zero,zero);
    BMP_WIN_Init(heap);
}
