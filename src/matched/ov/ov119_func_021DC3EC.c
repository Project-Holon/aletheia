/*
 * function: POKETRADE_PROC_InitMcssSystem
 * address: 0x021DC3EC
 * packet: pkt_ov119_021DC3EC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_InitG3DSystem 0x021E55BC thumb ov119
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 */
#include "../include/Obj08058.h"
extern void POKETRADE_2D_InitG3DSystem(char *p);
extern void *MCSS_Init(int, unsigned short);
extern void MCSS_SetTextureTransAdrs(void *, unsigned int);
extern void MCSS_SetOrthoMode(void *);
void POKETRADE_PROC_InitMcssSystem(char *p)
{
    POKETRADE_2D_InitG3DSystem(p);
    ((struct Obj08058 *)p)->f840 = MCSS_Init(4, (((struct Obj08058 *)p)->f5F4 & 0x7FFF) | 0x8000);
    MCSS_SetTextureTransAdrs(((struct Obj08058 *)p)->f840, 3 << 16);
    MCSS_SetOrthoMode(((struct Obj08058 *)p)->f840);
}
