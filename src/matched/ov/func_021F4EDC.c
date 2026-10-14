/*
 * function: WORLDTRADE_SetupGraphics
 * address:  0x021F4EDC
 * packet:   pkt_021F4EDC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_SetupVramBanks  0x021F4894  thumb  ov135
 *   WORLDTRADE_InitClactSystem  0x021F49F8  thumb  ov135
 *   WORLDTRADE_SetPlaneVisibleAll  0x021F4BCC  thumb  ov135
 *   g_02202BFC  0x02202BFC  data  ov135

 * Wire the shared table into the two initialisers and release the channel.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct DispVram;
extern void WORLDTRADE_SetupVramBanks(const struct DispVram *a0);
extern void WORLDTRADE_InitClactSystem(u8 *p, u32 v);
extern void WORLDTRADE_SetPlaneVisibleAll(u8 *p);
extern u8 g_02202BFC[];

void WORLDTRADE_SetupGraphics(u8 *p)
{
    WORLDTRADE_SetupVramBanks((const struct DispVram *)g_02202BFC);
    WORLDTRADE_InitClactSystem(p, (u32)g_02202BFC);
    WORLDTRADE_SetPlaneVisibleAll(p);
}
