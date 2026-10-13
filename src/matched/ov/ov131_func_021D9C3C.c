/*
 * function: P_STA_SKILL_InitStatsPage
 * address: 0x021D9C3C
 * packet: pkt_ov131_021D9C3C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_SKILL_WindowTemplates 0x021DC2C2 data a1
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_SetPalette 0x02045798 arm
 *   P_STA_SKILL_PrintStatsPage 0x021D9E30 thumb ov131
 *   P_STA_SKILL_InitSlotText 0x021DB7D4 thumb ov131
 */
#include "../include/Obj04511.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 P_STA_SKILL_WindowTemplates[];
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void BMP_WIN_SetPalette(struct Descriptor *p, u8 v);
extern void P_STA_SKILL_PrintStatsPage(void *a, int b);
extern void P_STA_SKILL_InitSlotText(u8 *p, u8 *q, u8 *entry);
void P_STA_SKILL_InitStatsPage(void *a,u8 *p)
{
    u8 i;
    for(i=0;i<13;i++) {
        *(void **)(p+0x5c+i*4)=(void *)BMP_WIN_Create(4,P_STA_SKILL_WindowTemplates[i*4],P_STA_SKILL_WindowTemplates[i*4+1],P_STA_SKILL_WindowTemplates[i*4+2],P_STA_SKILL_WindowTemplates[i*4+3],14,1);
    }
    BMP_WIN_SetPalette(((struct Obj04511 *)p)->f60,13);
    P_STA_SKILL_PrintStatsPage(a,(int)p);
    for(i=0;i<p[43];i++) P_STA_SKILL_InitSlotText(a,p,p+0xb0+i*24);
    p[41]=255;
    ((struct Obj04511 *)p)->f0=1;
    ((struct Obj04511 *)p)->f20=0;
    p[40]=0;
}
