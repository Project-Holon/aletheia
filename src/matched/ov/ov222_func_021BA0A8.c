/*
 * function: ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg
 * address: 0x021BA0A8
 * packet: pkt_ov222_021BA0A8
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   records 0x021BA2FC data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Record { u32 id;u8 template_data[32];u32 type;u32 enabled; };extern const struct Record records[];
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *,u32,u32);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg(void *p) { u32 i;for(i=0;i<2;i++)BG_SYS_FreeLayerBuf((u8)records[i].id);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4); }
