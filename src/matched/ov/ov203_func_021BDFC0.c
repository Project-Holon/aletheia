/*
 * function: DEMO3D_GRAPHIC_InitBg
 * address: 0x021BDFC0
 * packet: pkt_ov203_021BDFC0
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   d_021BFB50 0x021BFB50 data a4
 *   d_021BFC24 0x021BFC24 data a4
 */
typedef struct Descriptor { unsigned layer; unsigned config[8]; unsigned type, enable; } Descriptor;
extern const Descriptor d_021BFC24[];
extern const unsigned d_021BFB50[];
extern void MI_CpuFill8(void *, int, unsigned);
extern void BG_SYS_Create(unsigned);
extern void BMP_WIN_Init(unsigned);
typedef unsigned int   u32;
struct BgTemplate;
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
extern void BG_SYS_Init(unsigned, unsigned, unsigned, unsigned);
void DEMO3D_GRAPHIC_InitBg(void *ctx, unsigned heap)
{
    unsigned i = 0;
    const Descriptor *descriptor;
    unsigned layer;
    MI_CpuFill8(ctx, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BFB50);
    for (; i < 4; i++) {
        descriptor = &d_021BFC24[i];
        layer = descriptor->layer;
        BG_SYS_InitBgLayer((unsigned char)layer, (const struct BgTemplate *)descriptor->config, (unsigned char)descriptor->type);
        BG_SYS_FreeSlot(layer);
        func_02040588(layer, descriptor->enable);
    }
    BG_SYS_Init(1, 0, 1, 0);
}
