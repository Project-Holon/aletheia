/*
 * function: TOWNMAP_GRH_ExitBgLayers
 * address:  0x021BB968
 * packet:   pkt_ov072_021BB968
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetTileUnit  0x02040DA8  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   sTownMapGrhBgTable     0x021BBC28  data  a4
 */

#include "../include/G_Ent.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Ent sTownMapGrhBgTable[];

extern void BG_SYS_SetTileUnit(u32 a, u32 b, u32 c);
extern void BG_SYS_FreeSlot(u8 a);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *p, int v, int n);

void TOWNMAP_GRH_ExitBgLayers(void *p)
{
    int i;
    u32 id;

    BG_SYS_SetTileUnit(1, 1, 0);
    for (i = 0; i < 7; i++) {
        id = sTownMapGrhBgTable[i].id;
        BG_SYS_FreeSlot(id);
        BG_SYS_FreeLayerBuf((u8)id);
    }
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p, 0, 4);
}
