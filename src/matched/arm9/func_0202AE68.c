/*
 * function: ISS_CITY_SYS_RefreshVolume
 * address:  0x0202AE68
 * packet:   pkt_0202AE68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: 0202AE9C (thumb, from name) has no witness outside 0202AE68..0202AE9A. Every concrete byte reproduces.
 * status:   EXACT*
 *
 * symbols:
 *   ISS_CITY_SYS_HasCurrentUnit  0x0202AD8C  thumb
 *   ISS_CITY_SYS_GetVolume  0x0202AE64  thumb
 *   ISS_CITY_SYS_CalcUnitVolume  0x0202AE9C  thumb
 *   ISS_CITY_SYS_SetVolume  0x0202AEB8  thumb
 */

typedef unsigned int u32;

extern int ISS_CITY_SYS_HasCurrentUnit(int a0);
extern int ISS_CITY_SYS_CalcUnitVolume(void *obj);
typedef unsigned char  u8;
extern u32 ISS_CITY_SYS_GetVolume(u8 *p);
extern void ISS_CITY_SYS_SetVolume(void *obj, u32 value);

int ISS_CITY_SYS_RefreshVolume(void *obj)
{
    int v;

    if (ISS_CITY_SYS_HasCurrentUnit((int)obj) == 0) {
        return 0;
    }
    v = ISS_CITY_SYS_CalcUnitVolume(obj);
    if (v == ISS_CITY_SYS_GetVolume(obj)) {
        return 0;
    }
    ISS_CITY_SYS_SetVolume(obj, v);
    return 1;
}
