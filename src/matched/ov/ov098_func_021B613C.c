/*
 * unit:     yes
 * function: PDC_GetGameData, PDC_GetMon, PDC_GetScene
 * address:  0x021B613C
 * packet:   pkt_021B613C
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * three int getters at +0, +4, +8.
 */
#include "../include/Obj21998.h"
#include "../include/Obj21999.h"
#include "../include/Obj22000.h"

int PDC_GetGameData(void *p)
{
    return ((struct Obj21998 *)p)->f0;
}

int PDC_GetMon(void *p)
{
    return ((struct Obj21999 *)p)->f4;
}

int PDC_GetScene(void *p)
{
    return ((struct Obj22000 *)p)->f8;
}
