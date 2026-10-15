/*
 * function: CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupBg
 * address: 0x021B9FB0
 * packet: pkt_ov221_021B9FB0
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: named row pointer fixes 8 register bytes; heap widened to preserve untruncated calls.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BA1D4 0x021BA1D4 data a4
 *   d_021BA250 0x021BA250 data a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 layer; u8 cfg[32];u32 type,enable;} Row;
extern const Row d_021BA250[];
extern u32 d_021BA1D4[];
extern void MI_CpuFill8(void*,int,u32);
extern void BG_SYS_Create(u32);
extern void BMP_WIN_Init(u32);
struct BgTemplate;
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void func_02040588(u8,u8);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupBg(void*p,u32 heap)
{
 u32 i;
 MI_CpuFill8(p,0,4);
 BG_SYS_Create(heap);
 BMP_WIN_Init(heap);
 BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BA1D4);
 for(i=0;i<2;i++){
  const Row *row=&d_021BA250[i];
  u32 layer=row->layer;
  BG_SYS_InitBgLayer((u8)layer,(const struct BgTemplate *)row->cfg,(u8)row->type);
  BG_SYS_FreeSlot(layer);
  func_02040588(layer,row->enable);
 }
}
