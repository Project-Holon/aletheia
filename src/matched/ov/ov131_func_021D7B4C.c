/*
 * function: P_STA_INFO_LoadResources
 * address: 0x021D7B4C
 * packet: pkt_ov131_021D7B4C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   func_02045B38 0x02045B38 arm
 */
#include "../include/Obj00776.h"
#include "../include/Obj03285.h"

extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *, unsigned int, unsigned int, void **, unsigned short);
typedef unsigned int   u32;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
void P_STA_INFO_LoadResources(unsigned char *a, unsigned char *p, void *arc)
{
    ((struct Obj03285 *)p)->f50 = ARC_UTIL_LoadPaletteDataFromHandle(arc, 63, 0, (void **)(p+0x4c), ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f58 = ARC_UTIL_LoadPaletteDataFromHandle(arc, 72, 0, (void **)(p+0x54), ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f60 = ARC_UTIL_LoadPaletteDataFromHandle(arc, 64, 0, (void **)(p+0x5c), ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f68 = ARC_UTIL_LoadPaletteDataFromHandle(arc, 65, 0, (void **)(p+0x64), ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f38 = func_02045B38(0, 2, 188, ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f3C = func_02045B38(0, 2, 89, ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f40 = func_02045B38(0, 2, 92, ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f44 = func_02045B38(0, 2, 90, ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f48 = func_02045B38(0, 2, 91, ((struct Obj00776 *)a)->f0);
}
