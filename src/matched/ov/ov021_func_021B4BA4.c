/*
 * function: SCRCMD_PROC_FLD_SetQuantityMask
 * address:  0x021B4BA4
 * packet:   pkt_ov021_021B4BA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   d_021D9654     0x021D9654  data  a4
 * d_021D9654 is a const table of 16-byte {x, y, w, h} records (two of them
 * in the listing: {0,12,32,12}, {0,12,32,6}). Without const the loads for
 * the register arguments cannot pass the first stack-argument store and
 * are issued after it; BG_SYS_SetTileEntry's u8 parameters follow the ldrb reads
 * of its stack arguments (as in src/matched/arm9/BMP_MENUWORK_DrawFrame.c).
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
} Rect;

extern const Rect d_021D9654[];
extern void BG_SYS_SetTileEntry(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);

void SCRCMD_PROC_FLD_SetQuantityMask(int i)
{
    BG_SYS_SetTileEntry(1, 0, d_021D9654[i].x, d_021D9654[i].y, d_021D9654[i].w, d_021D9654[i].h, 0);
}
