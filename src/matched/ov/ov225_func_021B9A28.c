/*
 * function: MANUAL_GRAPHIC_CreateBg
 * address: 0x021B9A28
 * packet: pkt_ov225_021B9A28
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
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
 *   config 0x021BBDF0 data ov225
 *   gManualGraphicMainBgLayerTable 0x021BBE4C data ov225
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Record { u32 id; u32 bg[8]; u32 kind; u32 visible; };
extern u32 config[];
extern struct Record gManualGraphicMainBgLayerTable[];
extern void MI_CpuFill8(void *, u32, u32);
extern void BG_SYS_Create(u32);
extern void BMP_WIN_Init(u32);
struct BgTemplate;
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void func_02040588(u8, u8);
void MANUAL_GRAPHIC_CreateBg(void *p, u32 heap)
{
    u32 i = 0;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)config);
    for (; i < 4; i++) {
        struct Record *r = &gManualGraphicMainBgLayerTable[i];
        u32 id = r->id;
        BG_SYS_InitBgLayer((u8)id, (const struct BgTemplate *)r->bg, (u8)r->kind);
        BG_SYS_FreeSlot(id);
        func_02040588(id, r->visible);
    }
}
