/*
 * function: INTRO_GRAPHIC_InitBg
 * address: 0x021BDD98
 * packet: pkt_ov204_021BDD98
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BFD80 0x021BFD80 data a4
 *   d_021BFF1C 0x021BFF1C data a4
 */

#include "../include/G_DispConfig.h"

struct DispConfig; struct BgTemplate;
extern const unsigned d_021BFF1C[][11];
extern struct DispConfig d_021BFD80;
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern void BG_SYS_Create(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
typedef unsigned int   u32;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
void INTRO_GRAPHIC_InitBg(void *p, unsigned heap)
{
    const unsigned *row;
    unsigned i, layer;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode(&(*(struct DispConfig *)&d_021BFD80));
    for (i = 0; i < 4; i++) {
        row = d_021BFF1C[i];
        layer = row[0];
        BG_SYS_InitBgLayer((unsigned char)layer, (const struct BgTemplate *)(row + 1), (unsigned char)row[9]);
        BG_SYS_FreeSlot(layer);
        func_02040588(layer, row[10]);
    }
}
