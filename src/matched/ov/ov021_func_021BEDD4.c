/*
 * function: EVENT_FIELDMAP_CONTROL_StartFadeOutByFacing
 * address:  0x021BEDD4
 * packet:   pkt_ov021_021BEDD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeOutByFacing  0x021BEDD4  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect7  0x021BED14  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect8  0x021BED74  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect5  0x021BEC54  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect6  0x021BECB4  thumb  ov021
 */

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
typedef unsigned int   u32;
extern u32 EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect7(u32 a, u32 b);
extern int EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect8(int a, int b);
extern int EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect5(int a, int b);
extern void *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect6(void *p, u32 b);

int EVENT_FIELDMAP_CONTROL_StartFadeOutByFacing(void *a, int b)
{
    switch (FIELD_PLAYER_GetDirDisp(FIELDMAP_GetFieldPlayer((struct Obj00020 *)b))) {
    case 2:
    default:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect7((u32)a, b);
    case 3:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect8((int)a, b);
    case 0:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect5((int)a, b);
    case 1:
        return (int)EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect6(a, b);
    }
}
