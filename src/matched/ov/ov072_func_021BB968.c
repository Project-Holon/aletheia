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
 *   func_02040DA8  0x02040DA8  arm
 *   func_020414AC  0x020414AC  arm
 *   func_020403F4  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   sTownMapGrhBgTable     0x021BBC28  data  a4
 */

#include "../include/G_Ent.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Ent sTownMapGrhBgTable[];

extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_020414AC(u8 a);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void MI_CpuFill8(void *p, int v, int n);

void TOWNMAP_GRH_ExitBgLayers(void *p)
{
    int i;
    u32 id;

    func_02040DA8(1, 1, 0);
    for (i = 0; i < 7; i++) {
        id = sTownMapGrhBgTable[i].id;
        func_020414AC(id);
        func_020403F4((u8)id);
    }
    BMP_WIN_Exit();
    func_0203F9B4();
    MI_CpuFill8(p, 0, 4);
}
