/*
 * function: func_021DC3EC
 * address: 0x021DC3EC
 * packet: pkt_ov119_021DC3EC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E55BC 0x021E55BC thumb ov119
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 */
#include "../include/Obj08058.h"
extern void func_021E55BC(char *p);
extern void *MCSS_Init(int, unsigned short);
extern void MCSS_SetTextureTransAdrs(void *, unsigned int);
extern void MCSS_SetOrthoMode(void *);
void func_021DC3EC(char *p)
{
    func_021E55BC(p);
    ((struct Obj08058 *)p)->f840 = MCSS_Init(4, (((struct Obj08058 *)p)->f5F4 & 0x7FFF) | 0x8000);
    MCSS_SetTextureTransAdrs(((struct Obj08058 *)p)->f840, 3 << 16);
    MCSS_SetOrthoMode(((struct Obj08058 *)p)->f840);
}
