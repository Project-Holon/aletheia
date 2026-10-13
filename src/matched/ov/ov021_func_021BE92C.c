/*
 * function: EVENT_FIELDMAP_CONTROL_StartFadeIn
 * address:  0x021BE92C
 * packet:   pkt_ov021_021BE92C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   EVENT_FIELDMAP_CONTROL_CreateFadeInEventDefault  0x021BEBA8  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeInEventForEffect  0x021BEB38  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEvent  0x021BEBD8  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5  0x021BEC84  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect6  0x021BECE4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7  0x021BED44  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8  0x021BEDA4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeInByFacing  0x021BEE24  thumb  ov021
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern void *EVENT_FIELDMAP_CONTROL_CreateFadeInEventDefault(int a, int b);
extern void *EVENT_FIELDMAP_CONTROL_CreateFadeInEventForEffect(void *p, int a1, int a2, int a3, int a4);
extern void *EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEvent(void *p, int a1, int a2, int a3);
extern void *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5(void *a, u32 b);
extern void *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect6(int a, int b);
extern void *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7(int a, int b);
extern int EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8(int a, int b);
extern int EVENT_FIELDMAP_CONTROL_StartFadeInByFacing(void *a, int b);

int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g)
{
    switch (sel) {
    default:
        return (int)EVENT_FIELDMAP_CONTROL_CreateFadeInEventDefault((int)a, b);
    case 0:
    case 1:
        return (int)EVENT_FIELDMAP_CONTROL_CreateFadeInEventForEffect(a, b, sel, d, e);
    case 3:
        return (int)EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEvent(a, b, f, g);
    case 5:
        return (int)EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5(a, b);
    case 6:
        return (int)EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect6((int)a, b);
    case 7:
        return (int)EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7((int)a, b);
    case 8:
        return EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8((int)a, b);
    case 9:
        return EVENT_FIELDMAP_CONTROL_StartFadeInByFacing(a, b);
    }
}
