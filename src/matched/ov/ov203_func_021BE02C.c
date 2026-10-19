/*
 * function: DEMO3D_GRAPHIC_DeleteBg
 * address: 0x021BE02C
 * packet: pkt_ov203_021BE02C
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_021BFC24 0x021BFC24 data a4
 */
extern const unsigned d_021BFC24[][11];
extern void BG_SYS_FreeTiles(unsigned, unsigned, unsigned);
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *, int, unsigned);
void DEMO3D_GRAPHIC_DeleteBg(void *ctx)
{
    unsigned i = 0;
    unsigned layer;
    BG_SYS_FreeTiles(1, 1, 0);
    for (; i < 4; i++) {
        layer = d_021BFC24[i][0];
        func_02040588((unsigned char)layer, 0);
        BG_SYS_FreeLayerBuf((unsigned char)layer);
    }
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(ctx, 0, 4);
}
