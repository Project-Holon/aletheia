/*
 * function: OPTION_MENU_ExitGfx
 * address:  0x021B9B6C
 * packet:   pkt_ov068_021B9B6C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm
 *   func_020307B0  0x020307B0  arm
 *   BG_SYS_FreeTiles  0x02040DA8  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   gOptionMenuBgLayers     0x021BB614  data  ov068  a4
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern void BG_SYS_FreeTiles(u32 a, u32 b, u32 c);
extern void BG_SYS_FreeLayerBuf(u32 a);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *p, u32 a, u32 b);
extern u32 gOptionMenuBgLayers[][10];

void OPTION_MENU_ExitGfx(u32 *p)
{
    int i;

    for (i = 0; i < 19; i++) {
        if (p[i] != 0) {
            BMP_WIN_Delete((struct Descriptor *)p[i]);
        }
    }
    func_020307B0((void *)p[21]);
    BG_SYS_FreeTiles(4, 1, 0);
    i = 0;
    BG_SYS_FreeTiles(3, 1, 0);
    for (i = 0; i < 6; i++) {
        BG_SYS_FreeLayerBuf((u8)gOptionMenuBgLayers[i][0]);
    }
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p, 0, 0x7c);
}
