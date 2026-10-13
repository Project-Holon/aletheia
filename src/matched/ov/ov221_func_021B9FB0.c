/*
 * function: func_021B9FB0
 * address: 0x021B9FB0
 * packet: pkt_ov221_021B9FB0
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: named row pointer fixes 8 register bytes; heap widened to preserve untruncated calls.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
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
extern void func_02082BCC(void*,int,u32);
extern void func_0203F8F4(u32);
extern void BMP_WIN_Init(u32);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
void func_021B9FB0(void*p,u32 heap)
{
 u32 i;
 func_02082BCC(p,0,4);
 func_0203F8F4(heap);
 BMP_WIN_Init(heap);
 func_0203FC28((struct DispConfig *)d_021BA1D4);
 for(i=0;i<2;i++){
  const Row *row=&d_021BA250[i];
  u32 layer=row->layer;
  func_0203FCA0((u8)layer,(const struct BgTemplate *)row->cfg,(u8)row->type);
  func_020414AC(layer);
  func_02040588(layer,row->enable);
 }
}
