/*
 * function: RESEARCH_COMMON_ClearFields
 * address:  0x021C0A04
 * packet:   pkt_ov217_021C0A04
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   RESEARCH_COMMON_ClearResourceIds  0x021C0AF8  thumb  ov217
 *   RESEARCH_COMMON_ClearClactUnit  0x021C0B8C  thumb  ov217
 *   RESEARCH_COMMON_ClearActor  0x021C0BB4  thumb  ov217
 *   RESEARCH_COMMON_ClearPalAnm  0x021C0C38  thumb  ov217
 *   RESEARCH_COMMON_ClearPaletteAnime  0x021C0CF0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00791.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void MI_CpuFill8(void *dst, int val, u32 n);
extern void RESEARCH_COMMON_ClearResourceIds(void *p);
extern void RESEARCH_COMMON_ClearClactUnit(void *p);
extern void RESEARCH_COMMON_ClearActor(void *p);
extern void RESEARCH_COMMON_ClearPalAnm(void *p);
extern void RESEARCH_COMMON_ClearPaletteAnime(void *p);

void RESEARCH_COMMON_ClearFields(u8 *p)
{
    MI_CpuFill8(p, 0, 0x40);
    ((struct Obj00791 *)p)->f30 = 0;
    ((struct Obj00791 *)p)->f34 = 0;
    RESEARCH_COMMON_ClearResourceIds(p);
    RESEARCH_COMMON_ClearClactUnit(p);
    RESEARCH_COMMON_ClearActor(p);
    RESEARCH_COMMON_ClearPalAnm(p);
    RESEARCH_COMMON_ClearPaletteAnime(p);
}
