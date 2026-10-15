/*
 * function: ZUKAN_DETAIL_GRAPHIC_CreateWindows
 * address: 0x021BCF98
 * packet: pkt_ov208_021BCF98
 * region: ov208
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
 *   d_021C8138 0x021C8138 data a4
 *   d_021C81B4 0x021C81B4 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct BgTemplate;
typedef struct {u32 bg,tmpl[8],type,on;} BgEntry;
extern const u32 d_021C8138[];
extern const BgEntry d_021C81B4[];
extern void MI_CpuFill8(void *,int,int);
extern void BG_SYS_Create(u32);
extern void BMP_WIN_Init(u32);
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
void ZUKAN_DETAIL_GRAPHIC_CreateWindows(void *p,u32 heap)
{
    u32 i=0;
    const BgEntry *row;
    u32 bg;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)d_021C8138);
    for(;i<8;i++) {
        row=&d_021C81B4[i];
        bg=row->bg;
        BG_SYS_InitBgLayer((u8)bg,(const struct BgTemplate *)row->tmpl,(u8)row->type);
        func_020414AC(bg);
        func_02040588(bg,row->on);
    }
}
