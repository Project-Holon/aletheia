/*
 * function: ISS_CITY_SYS_HandleZoneChange
 * address:  0x0202AC60
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ISS_CITY_SYS_SetMode 0x0202ABFC  thumb
 *   ISS_CITY_SYS_Disable 0x0202AC4C  thumb
 *   ISS_CITY_SYS_IsEnabled 0x0202ACC8  thumb
 *   ISS_CITY_SYS_HasCurrentUnit 0x0202AD8C  thumb
 *   ISS_CITY_SYS_HasUnitForZone 0x0202ADA0  thumb
 *   ISS_CITY_SYS_SelectUnitForZone 0x0202ADB4  thumb
 *   ISS_CITY_SYS_SetFadeLevel 0x0202AE60  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 ISS_CITY_SYS_IsEnabled(void *obj);
extern int ISS_CITY_SYS_HasCurrentUnit(int a0);
extern int ISS_CITY_SYS_HasUnitForZone(int a0, int a1);
extern int ISS_CITY_SYS_Disable(int a0);
extern int ISS_CITY_SYS_SelectUnitForZone(int a0, int a1);
extern void ISS_CITY_SYS_SetFadeLevel(void *obj, u32 value);
extern void ISS_CITY_SYS_SetMode(void *obj, u32 value);

void ISS_CITY_SYS_HandleZoneChange(u8 *p, u32 a1)
{
    if (ISS_CITY_SYS_IsEnabled(p) == 0) {
        return;
    }
    if (ISS_CITY_SYS_HasCurrentUnit((int)p) == 1) {
        if (ISS_CITY_SYS_HasUnitForZone((int)p, a1) == 1) {
            ISS_CITY_SYS_Disable((int)p);
            return;
        }
    }
    ISS_CITY_SYS_SelectUnitForZone((int)p, a1);
    if (ISS_CITY_SYS_HasCurrentUnit((int)p) == 1) {
        ISS_CITY_SYS_SetFadeLevel(p, 0);
        ISS_CITY_SYS_SetMode(p, 1);
        return;
    }
    ISS_CITY_SYS_SetMode(p, 2);
}
