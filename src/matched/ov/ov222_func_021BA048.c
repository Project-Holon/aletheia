/*
 * function: func_021BA048
 * address: 0x021BA048
 * region: ov222
 * isa: thumb
 * packet: pkt_ov222_021BA048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   config 0x021BA280 data a4
 *   records 0x021BA2FC data a4
 * Caller narrows BG identifiers/fields to u8; heap forwarded full width.
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct Record { u32 id; u8 template_data[32]; u32 type; u32 enabled; };
extern u32 config[];
extern const struct Record records[];
extern void func_02082BCC(void *,u32,u32);
extern void func_0203F8F4(u32);
extern void BMP_WIN_Init(u32);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
void func_021BA048(void *p,u32 heap)
{
    u32 i;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)config);
    for(i=0;i<2;i++) {
        const struct Record *r=&records[i];
        u32 id=r->id;
        func_0203FCA0((u8)id,(const struct BgTemplate *)r->template_data,(u8)r->type);
        func_020414AC(id);
        func_02040588(id,r->enabled);
    }
}
