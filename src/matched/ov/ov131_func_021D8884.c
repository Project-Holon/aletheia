/*
 * function: P_STA_RIBBON_LoadArcGraphics
 * address: 0x021D8884
 * packet: pkt_ov131_021D8884
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   P_STA_OAM_CreateManager 0x021DBA90 thumb ov131
 */
#include "../include/Obj00776.h"
#include "../include/Obj05392.h"

extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *, unsigned int, unsigned int, void **, unsigned short);
typedef unsigned short u16;
typedef unsigned int   u32;
struct S;
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct S *P_STA_OAM_CreateManager(u32 a, u32 b);
void P_STA_RIBBON_LoadArcGraphics(unsigned char *a, unsigned char *p, void *arc)
{
    ((struct Obj05392 *)p)->f2C = ARC_UTIL_LoadPaletteDataFromHandle(arc, 66, 0, (void **)(p+0x28), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f34 = ARC_UTIL_LoadPaletteDataFromHandle(arc, 67, 0, (void **)(p+0x30), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f3C = ARC_UTIL_LoadPaletteDataFromHandle(arc, 68, 0, (void **)(p+0x38), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f44 = ARC_UTIL_LoadPaletteDataFromHandle(arc, 69, 0, (void **)(p+0x40), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f4C = ARC_UTIL_LoadScreenDataFromHandle(arc, 12, 0, (u32)(p+0x48), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f6C = P_STA_OAM_CreateManager(((struct Obj00776 *)a)->f0, (u32)(((struct Obj00776 *)a)->f174));
}
