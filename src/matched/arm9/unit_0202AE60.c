/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202AE60
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ISS_CITY_SYS_SetFadeLevel, ISS_CITY_SYS_GetVolume
 *
 * A setter at offset 0x10 immediately followed by a getter at offset 0xc,
 * back to back with no gap. Neither has a relocation.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202AE60.c \
 *       --addr 0x0202AE60 --thumb
 */
#include "../include/Obj11306.h"
#include "../include/Obj17264.h"

typedef unsigned int u32;

void ISS_CITY_SYS_SetFadeLevel(void *obj, u32 value)
{
    ((struct Obj17264 *)obj)->f10 = value;
}

u32 ISS_CITY_SYS_GetVolume(void *obj)
{
    return ((struct Obj11306 *)obj)->fC;
}
