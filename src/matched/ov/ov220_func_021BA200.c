/*
 * function: func_021BA200
 * address: 0x021BA200
 * packet: pkt_ov220_021BA200
 * region: ov220
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
 *   d_021BA3FC 0x021BA3FC data a4
 *   d_021BA458 0x021BA458 data a4
 */
struct DispConfig; struct BgTemplate;
extern const unsigned d_021BA458[][11];
extern struct DispConfig d_021BA3FC;
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern void func_0203F8F4(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void func_0203FC28(struct DispConfig *);
typedef unsigned int   u32;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
void func_021BA200(void *p, unsigned heap)
{
    const unsigned *row;
    unsigned i, layer;
    MI_CpuFill8(p, 0, 4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28(&d_021BA3FC);
    for (i = 0; i < 3; i++) {
        row = d_021BA458[i];
        layer = row[0];
        func_0203FCA0((unsigned char)layer, (const struct BgTemplate *)(row + 1), (unsigned char)row[9]);
        func_020414AC(layer);
        func_02040588(layer, row[10]);
    }
}
