/*
 * function: func_021B9A6C
 * address: 0x021B9A6C
 * packet: pkt_ov224_021B9A6C
 * region: ov224
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   config 0x021B9C54 data
 *   table 0x021B9CD0 data ov224
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Record { u32 id; u32 bg[8]; u32 kind; u32 visible; };
extern u32 config[];
extern struct Record table[];
extern void func_02082BCC(void *, u32, u32);
extern void func_0203F8F4(u32);
extern void BMP_WIN_Init(u32);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8, u8);
void func_021B9A6C(void *p, u32 heap)
{
    u32 i = 0;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)config);
    for (; i < 2; i++) {
        struct Record *r = &table[i];
        u32 id = r->id;
        func_0203FCA0((u8)id, (const struct BgTemplate *)r->bg, (u8)r->kind);
        func_020414AC(id);
        func_02040588(id, r->visible);
    }
}
