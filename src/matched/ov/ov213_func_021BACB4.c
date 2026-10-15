/*
 * function: COMM_BTL_DEMO_GRAPHIC_InitBg
 * address: 0x021BACB4
 * packet: pkt_ov213_021BACB4
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BB17C 0x021BB17C data a4
 *   d_021BB1F8 0x021BB1F8 data a4
 */
struct DispConfig; struct BgTemplate;
extern const unsigned d_021BB1F8[][11];
extern struct DispConfig d_021BB17C;
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern void BG_SYS_Create(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void func_0203FC28(struct DispConfig *);
typedef unsigned int   u32;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
void COMM_BTL_DEMO_GRAPHIC_InitBg(void *p, unsigned heap)
{
    const unsigned *row;
    unsigned i, layer;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    func_0203FC28(&d_021BB17C);
    for (i = 0; i < 6; i++) {
        row = d_021BB1F8[i];
        layer = row[0];
        BG_SYS_InitBgLayer((unsigned char)layer, (const struct BgTemplate *)(row + 1), (unsigned char)row[9]);
        func_020414AC(layer);
        func_02040588(layer, row[10]);
    }
}
