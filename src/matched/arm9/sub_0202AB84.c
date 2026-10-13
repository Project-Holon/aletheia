/*
 * function: ISS_CITY_SYS_ReleaseUnits
 * address:  0x0202AB84
 * packet:   pkt_0202AB7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   ISS_CITY_SYS_FreeUnits  0x0202ABD0  thumb
 */

typedef unsigned int u32;

struct Obj;
extern void ISS_CITY_SYS_FreeUnits(struct Obj *obj);

void ISS_CITY_SYS_ReleaseUnits(void *obj)
{
    ISS_CITY_SYS_FreeUnits(obj);
}
