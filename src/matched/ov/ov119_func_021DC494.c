/*
 * function: func_021DC494
 * address: 0x021DC494
 * packet: pkt_ov119_021DC494
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_RegisterIconCharResources 0x021E4068 thumb ov119
 *   func_02049B40 0x02049B40 arm
 *   POKETRADE_NEGO_ExitMarkers 0x021DF904 thumb ov119
 *   POKETRADE_2D_RegisterIconSpriteResources 0x021E58A0 thumb ov119
 *   POKETRADE_2D_CreateBoxIconActors 0x021E467C thumb ov119
 *   POKETRADE_2D_LoadMainGfxAndMessageWindow 0x021E3F74 thumb ov119
 *   POKETRADE_2D_LoadBackgroundGfx 0x021E3E80 thumb ov119
 *   POKETRADE_2D_CreateBoxWindows 0x021E4420 thumb ov119
 *   POKETRADE_2D_UpdateVisibleColumns 0x021E4E64 thumb ov119
 */
#include "../include/Obj10356.h"
typedef unsigned short u16;
extern void POKETRADE_2D_RegisterIconCharResources(char *p);extern void func_02049B40(int,int,int,int,int,int);extern void POKETRADE_NEGO_ExitMarkers(void *);extern void POKETRADE_2D_RegisterIconSpriteResources(void *);extern void POKETRADE_2D_CreateBoxIconActors(void *);extern void POKETRADE_2D_LoadMainGfxAndMessageWindow(void *);extern void POKETRADE_2D_LoadBackgroundGfx(void *);extern void POKETRADE_2D_CreateBoxWindows(void *);extern void POKETRADE_2D_UpdateVisibleColumns(int,void *,int);
void func_021DC494(char *p) {POKETRADE_2D_RegisterIconCharResources(p);func_02049B40(23,5,4,448,32,((struct Obj10356 *)p)->f5F4);POKETRADE_NEGO_ExitMarkers(p);if(((struct Obj10356 *)p)->f118C<4)POKETRADE_2D_RegisterIconSpriteResources(p);POKETRADE_2D_CreateBoxIconActors(p);POKETRADE_2D_LoadMainGfxAndMessageWindow(p);POKETRADE_2D_LoadBackgroundGfx(p);POKETRADE_2D_CreateBoxWindows(p);POKETRADE_2D_UpdateVisibleColumns(((struct Obj10356 *)p)->f828,p,0);}
