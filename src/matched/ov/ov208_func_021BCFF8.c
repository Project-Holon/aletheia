/*
 * function: ZUKAN_DETAIL_GRAPHIC_DeleteWindows
 * address: 0x021BCFF8
 * packet: pkt_ov208_021BCFF8
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_021C81B4 0x021C81B4 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Ov208Bg { u32 bg; u8 pad[0x28]; };
extern const struct Ov208Bg d_021C81B4[8];
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *, int, int);
void ZUKAN_DETAIL_GRAPHIC_DeleteWindows(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        BG_SYS_FreeLayerBuf((u8)d_021C81B4[i].bg);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p, 0, 4);
}
