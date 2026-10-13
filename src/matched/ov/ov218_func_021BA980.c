/*
 * function: func_021BA980
 * address: 0x021BA980
 * packet: pkt_ov218_021BA980
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: heap extern parameters widened where original forwards r5 without truncation; BG and flag callee parameters narrowed to u8 where A9AC-A9CE shows explicit shifts. 414AC visibly receives BG input despite its legacy asm void prototype.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BAEAC 0x021BAEAC data a4
 *   d_021BAF28 0x021BAF28 data a4
 */
typedef struct Record { unsigned bg; unsigned config[8]; unsigned type, enable; } Record;
extern const unsigned d_021BAEAC[];
extern const Record d_021BAF28[];
extern void MI_CpuFill8(void *, int, int);
extern void func_0203F8F4(unsigned);
extern void BMP_WIN_Init(unsigned);
typedef unsigned int   u32;
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
void func_021BA980(char *ctx, unsigned heap)
{
    unsigned i;
    const Record *record;
    unsigned bg;
    MI_CpuFill8(ctx, 0, 4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)d_021BAEAC);
    for (i = 0; i < 7; i++) {
        record = &d_021BAF28[i];
        bg = record->bg;
        func_0203FCA0((unsigned char)bg, (const struct BgTemplate *)record->config, (unsigned char)record->type);
        func_020414AC(bg);
        func_02040588(bg, record->enable);
    }
}
