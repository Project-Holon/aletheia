/*
 * function: ISS_SYS_OnZoneChangeCity
 * address:  0x0202B7BC
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Parked: the only site, the ABS32 at +0008, names 0x0202AB5C, which is a
 * four-byte Thumb linker veneer (`ldr r3, [pc, #0]; bx r3` followed by the word
 * 0x0202AC61 - measured at 0x0202AB5C..0x0202AB60) sitting in the word run
 * before 0x0202AB64.  veneer_at() admits only the two ARM encodings, so the
 * `veneer` class refuses a Thumb stub; `label` has no label (disasm.py prints
 * it as data), `literal` has no pool word outside this range, and no C spelling
 * produces the stub, so it can never be a manifest entry.  Permanent.
 *
 * symbols:
 *   ISS_CITY_SYS_NotifyZoneChange  0x0202AB5C  thumb
 */
#include "../include/Obj15841.h"

typedef unsigned int u32;

struct Obj;

typedef unsigned char  u8;
extern void ISS_CITY_SYS_NotifyZoneChange(u8 *p, u32 a1);

void ISS_SYS_OnZoneChangeCity(struct Obj *o, u32 a1)
{
    ISS_CITY_SYS_NotifyZoneChange((u8 *)(((struct Obj15841 *)o)->f10), a1);
}
