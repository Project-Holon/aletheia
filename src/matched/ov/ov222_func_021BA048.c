/*
 * function: ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg
 * address: 0x021BA048
 * region: ov222
 * isa: thumb
 * packet: pkt_ov222_021BA048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
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
extern void MI_CpuFill8(void *,u32,u32);
extern void BG_SYS_Create(u32);
extern void BMP_WIN_Init(u32);
struct BgTemplate;
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void func_02040588(u8,u8);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg(void *p,u32 heap)
{
    u32 i;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)config);
    for(i=0;i<2;i++) {
        const struct Record *r=&records[i];
        u32 id=r->id;
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)r->template_data,(u8)r->type);
        BG_SYS_FreeSlot(id);
        func_02040588(id,r->enabled);
    }
}
