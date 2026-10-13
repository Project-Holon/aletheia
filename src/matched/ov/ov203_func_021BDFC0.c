/*
 * function: func_021BDFC0
 * address: 0x021BDFC0
 * packet: pkt_ov203_021BDFC0
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_02040C14 0x02040C14 arm
 *   d_021BFB50 0x021BFB50 data a4
 *   d_021BFC24 0x021BFC24 data a4
 */
typedef struct Descriptor { unsigned layer; unsigned config[8]; unsigned type, enable; } Descriptor;
extern const Descriptor d_021BFC24[];
extern const unsigned d_021BFB50[];
extern void MI_CpuFill8(void *, int, unsigned);
extern void func_0203F8F4(unsigned);
extern void BMP_WIN_Init(unsigned);
typedef unsigned int   u32;
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
extern void func_02040C14(unsigned, unsigned, unsigned, unsigned);
void func_021BDFC0(void *ctx, unsigned heap)
{
    unsigned i = 0;
    const Descriptor *descriptor;
    unsigned layer;
    MI_CpuFill8(ctx, 0, 4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)d_021BFB50);
    for (; i < 4; i++) {
        descriptor = &d_021BFC24[i];
        layer = descriptor->layer;
        func_0203FCA0((unsigned char)layer, (const struct BgTemplate *)descriptor->config, (unsigned char)descriptor->type);
        func_020414AC(layer);
        func_02040588(layer, descriptor->enable);
    }
    func_02040C14(1, 0, 1, 0);
}
