/*
 * function: ISS_CITY_SYS_Delete
 * address:  0x0202AB28
 * packet:   pkt_0202A230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_CITY_SYS_ReleaseUnits  0x0202AB84  thumb
 *   sub_020307B0   0x020307B0  arm
 */

extern void ISS_CITY_SYS_ReleaseUnits(void *p);
typedef unsigned int   u32;
extern u32 sub_020307B0(void *p);

void ISS_CITY_SYS_Delete(void *p)
{
    ISS_CITY_SYS_ReleaseUnits(p);
    sub_020307B0(p);
}
