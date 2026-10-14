/*
 * function: POKETRADE_2D_InitDisplayAndClact
 * address:  0x021E53F8
 * packet:   pkt_ov119_021E53F8
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   POKETRADE_2D_SetDisplayConfig 0x021E57E8 thumb
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   d_021E7D40 0x021E7D40 data a4
 *   d_021E7CC8 0x021E7CC8 data a4
 */
#include "../include/Obj22814.h"
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern void POKETRADE_2D_SetDisplayConfig(int);
typedef unsigned int   u32;
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern const char d_021E7D40[];
extern const char d_021E7CC8[];
void POKETRADE_2D_InitDisplayAndClact(char *p)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021E7D40);
    CLACT_InitSystem((const struct Cfg *)d_021E7CC8, (unsigned int)d_021E7D40, ((struct Obj22814 *)p)->f5F4);
    POKETRADE_2D_SetDisplayConfig(0);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
}
