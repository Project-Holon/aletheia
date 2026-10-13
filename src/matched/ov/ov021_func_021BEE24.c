/*
 * function: EVENT_FIELDMAP_CONTROL_StartFadeInByFacing
 * address:  0x021BEE24
 * packet:   pkt_ov021_021BEE24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7  0x021BED44  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8  0x021BEDA4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5  0x021BEC84  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect6  0x021BECE4  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern void *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7(int a, int b);
extern int EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8(int a, int b);
extern void *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5(void *a, u32 b);
extern void *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect6(int a, int b);

void EVENT_FIELDMAP_CONTROL_StartFadeInByFacing(void *a, void *b)
{
    switch (FIELD_PLAYER_GetDirDisp(FIELDMAP_GetFieldPlayer(b))) {
    case 2:
    default:
        EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7((int)a, (int)b);
        break;
    case 3:
        EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8((int)a, (int)b);
        break;
    case 0:
        EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5(a, (u32)b);
        break;
    case 1:
        EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect6((int)a, (int)b);
        break;
    }
}
