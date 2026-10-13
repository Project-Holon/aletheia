/*
 * function: ISS_CITY_SYS_UpdateFadeOut
 * address:  0x0202AD44
 * packet:   pkt_0202AD10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ISS_CITY_SYS_SetMode  0x0202ABFC  thumb
 *   ISS_CITY_SYS_GetFadeLevel  0x0202AE04  thumb
 *   ISS_CITY_SYS_StepFadeIn  0x0202AE08  thumb
 *   ISS_CITY_SYS_StepFadeOut  0x0202AE34  thumb
 *   ISS_CITY_SYS_RefreshVolume  0x0202AE68  thumb
 *   ISS_CITY_SYS_ApplyVolume  0x0202AEBC  thumb
 */

typedef unsigned int u32;

extern int  ISS_CITY_SYS_StepFadeIn(void *obj);
extern int  ISS_CITY_SYS_StepFadeOut(void *obj);
extern int  ISS_CITY_SYS_RefreshVolume(void *obj);
extern u32 ISS_CITY_SYS_GetFadeLevel(void *obj);
extern int ISS_CITY_SYS_ApplyVolume(int a0);
extern void ISS_CITY_SYS_SetMode(void *obj, u32 value);

void ISS_CITY_SYS_UpdateFadeOut(void *obj)
{
    int a = ISS_CITY_SYS_StepFadeOut(obj);
    int b = ISS_CITY_SYS_RefreshVolume(obj);

    if (a != 0 || b != 0) {
        ISS_CITY_SYS_ApplyVolume((int)obj);
    }
    if ((int)ISS_CITY_SYS_GetFadeLevel(obj) <= 0) {
        ISS_CITY_SYS_SetMode(obj, 0);
    }
}
