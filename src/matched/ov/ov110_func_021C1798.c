/*
 * function: PMS_SELECT_GRAPHIC_ExitSceneBgs
 * address: 0x021C1798
 * packet: pkt_ov110_021C1798
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: observed 44-byte table rows use a typed Row pointer; integer address
 * arithmetic swaps base/index colours, Row member access is EXACT.
 * symbols:
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   gPmsSelectGraphicBgRows 0x021C3A74 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_FreeLayerBuf(u32);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *,int,u32);
typedef struct {u32 id; u32 rest[10];} Row;
extern Row gPmsSelectGraphicBgRows[];
void PMS_SELECT_GRAPHIC_ExitSceneBgs(void *p) { const Row *base; unsigned long i; base=gPmsSelectGraphicBgRows; for(i=0;i<6;i++) BG_SYS_FreeLayerBuf((u8)base[i].id); BMP_WIN_Exit(); BG_SYS_Delete(); MI_CpuFill8(p,0,4); }
