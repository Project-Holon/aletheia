/*
 * function: WIFI_BSUBWAY_GRAPHIC_TeardownBg
 * address:  0x021D8364
 * packet:   pkt_021D8364
 * region:   ov116
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021D83F0  0x021D83F0  data
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 g_021D83F0[];

void BG_SYS_FreeLayerBuf(u32 i);
void BMP_WIN_Exit(void);
void BG_SYS_Delete(void);
void MI_CpuFill8(void *dst, int c, int n);

void WIFI_BSUBWAY_GRAPHIC_TeardownBg(void *a0)
{
    unsigned int i;

    for (i = 0; i < 8; i++) {
        BG_SYS_FreeLayerBuf((u8)*(u32 *)(g_021D83F0 + i * 0x2c));
    }
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(a0, 0, 4);
}
