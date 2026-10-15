/*
 * function: GURU2_MAIN_SetupBg
 * address: 0x021DFB60
 * packet: pkt_ov137_021DFB60
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021DFB6E reads and 021DFB76 writes hardware register 04000304
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   gGuru2GameDispConfig 0x021E202C data a4
 *   gGuru2GameBg1Template 0x021E204C data a4
 *   gGuru2GameBg2Template 0x021E206C data a4
 *   gGuru2GameBg3Template 0x021E208C data a4
 *   gGuru2GameBg6Template 0x021E20AC data a4
 *   gGuru2GameBg7Template 0x021E20CC data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct DispConfig {u32 w[4];};
struct BgTemplate {u32 w[8];};
extern const struct DispConfig gGuru2GameDispConfig;
extern const struct BgTemplate gGuru2GameBg1Template,gGuru2GameBg2Template,gGuru2GameBg3Template,gGuru2GameBg6Template,gGuru2GameBg7Template;
extern void BG_SYS_Create(u16);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void BG_SYS_ClearSlot(u32);
typedef unsigned char  u8;
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
void GURU2_MAIN_SetupBg(char *a0)
{
    BG_SYS_Create(114);
    *(volatile u16 *)0x04000304 |= 0x8000;
    {struct DispConfig t=gGuru2GameDispConfig; BG_SYS_SetGraphicsMode(&t);}
    {struct BgTemplate t=gGuru2GameBg1Template; BG_SYS_InitBgLayer(1,&t,0); BG_SYS_ClearSlot(1); BG_SYS_InitRun(1,32,0,114);}
    {struct BgTemplate t=gGuru2GameBg2Template; BG_SYS_InitBgLayer(2,&t,0); BG_SYS_ClearSlot(2);}
    {struct BgTemplate t=gGuru2GameBg3Template; BG_SYS_InitBgLayer(3,&t,0); BG_SYS_ClearSlot(3);}
    {struct BgTemplate t=gGuru2GameBg6Template; BG_SYS_InitBgLayer(6,&t,0); BG_SYS_ClearSlot(6);}
    {struct BgTemplate t=gGuru2GameBg7Template; BG_SYS_InitBgLayer(7,&t,0); BG_SYS_ClearSlot(7);}
}
