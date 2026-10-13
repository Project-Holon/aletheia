/*
 * function: FLDEFF_RIPPLE_WarpToSpecialLocationTask
 * address:  0x021D2358
 * packet:   pkt_ov021_021D2358
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELDMAP_GetFog  0x02188C64  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinEaseIn  0x021C7260  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinLinear  0x021C71D4  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   FIELD_FOG_GetSlope  0x021A01D4  thumb  ov021
 *   FIELD_FOG_FADE_Init  0x021A01FC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_SetFormCode  0x021A30A4  thumb  ov021
 *   EVENT_MAPCHANGE_CreateSpecialLocationWarpEvent  0x02184F88  thumb  ov020
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 FIELDMAP_GetTaskManager(unsigned char *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u32 FIELDMAP_GetFog(unsigned char *p);
typedef unsigned short u16;
struct Evt;
extern void *FIELD_TASK_CreatePlayerSpinEaseIn(u32 a, u16 b, int c);
extern void *FIELD_TASK_CreatePlayerSpinLinear(u32 a, u32 b, u32 c);
extern void FIELD_TASK_MANAGER_AddTask(unsigned char *p, u32 *a, u32 b);
extern u32 FIELD_FOG_GetSlope(unsigned char *p);
extern void FIELD_FOG_FADE_Init(unsigned char *p, u32 a, u32 b, u32 c);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
typedef unsigned char  u8;
extern void FIELD_PLAYER_SetFormCode(u8 *p, u32 b);
extern void *EVENT_MAPCHANGE_CreateSpecialLocationWarpEvent(void *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int FLDEFF_RIPPLE_WarpToSpecialLocationTask(u32 a, int *seq, int *w)
{
    u32 s, r6, r7, r4;

    s = FIELDMAP_GetTaskManager((unsigned char *)w[1]);
    switch (*seq) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x63C);
        w[3] = 0x18;
        if (w[2]) {
            r6 = FIELDMAP_GetFog((unsigned char *)w[1]);
            r7 = (u32)FIELD_TASK_CreatePlayerSpinEaseIn(w[1], 0x14, 3);
            r4 = (u32)FIELD_TASK_CreatePlayerSpinLinear(w[1], 0xc, 3);
            FIELD_TASK_MANAGER_AddTask((unsigned char *)s, (u32 *)r7, 0);
            FIELD_TASK_MANAGER_AddTask((unsigned char *)s, (u32 *)r4, r7);
            FIELD_FOG_FADE_Init((unsigned char *)r6, 0x7F0F, FIELD_FOG_GetSlope((unsigned char *)r6), 0x1A);
        }
        (*seq)++;
        break;
    case 1:
        FIELD_PLAYER_SetFormCode(FIELDMAP_GetFieldPlayer((struct Obj00020 *)w[1]), 2);
        (*seq)++;
        break;
    case 2:
        w[3]--;
        if (w[3] > 0) {
            break;
        }
        GAME_EVENT_CallEvent((struct Evt *)a, EVENT_MAPCHANGE_CreateSpecialLocationWarpEvent((void *)w[0]));
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
