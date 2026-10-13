/*
 * function: EVENT_FIELDMAP_CONTROL_StartFadeOut
 * address:  0x021BE8D4
 * packet:   pkt_ov021_021BE8D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEventDefault  0x021BEB78  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEventForEffect  0x021BEAFC  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect4  0x021BEC24  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect5  0x021BEC54  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect6  0x021BECB4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect7  0x021BED14  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect8  0x021BED74  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeOutByFacing  0x021BEDD4  thumb  ov021
 */

typedef unsigned int   u32;
extern u32 EVENT_FIELDMAP_CONTROL_CreateFadeOutEventDefault(u32 a, u32 b);
extern void *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventForEffect(int a, int b, int c, int d);
extern int EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect4(int a, int b);
extern int EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect5(int a, int b);
extern void *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect6(void *p, u32 b);
extern u32 EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect7(u32 a, u32 b);
extern int EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect8(int a, int b);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOutByFacing(void *a, int b);

int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d)
{
    switch (sel) {
    default:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventDefault((u32)a, b);
    case 0:
    case 1:
    case 3:
        return (int)EVENT_FIELDMAP_CONTROL_CreateFadeOutEventForEffect((int)a, b, sel, d);
    case 4:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect4((int)a, b);
    case 5:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect5((int)a, b);
    case 6:
        return (int)EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect6(a, b);
    case 7:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect7((u32)a, b);
    case 8:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect8((int)a, b);
    case 9:
        return EVENT_FIELDMAP_CONTROL_StartFadeOutByFacing(a, b);
    }
}
