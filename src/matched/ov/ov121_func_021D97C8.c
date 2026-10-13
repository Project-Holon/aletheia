/*
 * function: func_021D97C8
 * address: 0x021D97C8
 * packet: pkt_ov121_021D97C8
 * region: ov121
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
 *   d_021DF598 0x021DF598 data a4
 *   d_021DF634 0x021DF634 data a4
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 id; u32 config[8]; u32 a; u32 b; } Entry;
extern const u32 d_021DF598[];
extern const Entry d_021DF634[];
extern void MI_CpuFill8(void *, int, u32);
extern void func_0203F8F4(u32);
extern void BMP_WIN_Init(u32);
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
struct BgTemplate;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_021D97C8(void *p, u32 a)
{
    u32 i;
    const Entry *e;
    u32 id;
    i = 0;
    MI_CpuFill8(p, 0, 4);
    func_0203F8F4(a);
    BMP_WIN_Init(a);
    func_0203FC28((struct DispConfig *)d_021DF598);
    do {
        e = &d_021DF634[i];
        id = e->id;
        func_0203FCA0((u8)id, (const struct BgTemplate *)e->config, (u8)e->a);
        func_020414AC((u8)id);
        func_02040588((u8)id, (u8)e->b);
        ++i;
    } while (i < 7);
}
