/*
 * function: FLDEFF_RIPPLE_WarpToZoneStartTask
 * address:  0x021D2278
 * packet:   pkt_ov021_021D2278
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_TASK_CreatePlayerDrawOffsetTween  0x021C7858  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_PLAYER_SetFormCode  0x021A30A4  thumb  ov021
 *   FIELD_GetPlayerAreaZoneId  0x021CD440  thumb  ov021
 *   EVENT_MAPCHANGE_CreateZoneStartWarpEvent  0x02184FD4  thumb  ov020
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct { int x, y, z; } Vec;

extern u32 FIELDMAP_GetTaskManager(unsigned char *p);
extern int FIELD_TASK_CreatePlayerDrawOffsetTween(u32 a, u32 b, u32 c);
extern void FIELD_TASK_MANAGER_AddTask(unsigned char *p, u32 *a, u32 b);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GFL_USE_GetSeSlot(u32 a0);
extern int GFL_USE_IsSeSlotBusy(u32 a0);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
typedef unsigned char  u8;
extern void FIELD_PLAYER_SetFormCode(u8 *p, u32 b);
struct Evt;
extern int FIELD_GetPlayerAreaZoneId(void *a, u16 *out);
extern void *EVENT_MAPCHANGE_CreateZoneStartWarpEvent(void *p, u16 id);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);
extern int FLDMMDL_CheckEndAcmd(void *o);

int FLDEFF_RIPPLE_WarpToZoneStartTask(u32 a, int *seq, int *w)
{
    Vec v;
    u16 id;
    u32 s;
    void *o;

    switch (*seq) {
    case 0:
        s = FIELDMAP_GetTaskManager((unsigned char *)w[1]);
        v.x = 0;
        v.y = -0x40000;
        v.z = 0;
        FIELD_TASK_MANAGER_AddTask((unsigned char *)s, (u32 *)FIELD_TASK_CreatePlayerDrawOffsetTween(w[1], 0x28, (u32)(&v)), 0);
        w[3] = 8;
        (*seq)++;
        break;
    case 1:
        w[3]--;
        if (w[3] > 0) {
            break;
        }
        GFL_USE_PlaySeDefaultVolume(0x63C);
        (*seq)++;
        break;
    case 2:
        if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x63C)) != 0) {
            break;
        }
        o = FIELDMAP_GetFieldPlayer((struct Obj00020 *)w[1]);
        FIELD_PLAYER_GetMmdl((void *)o);
        FIELD_PLAYER_SetFormCode(o, 3);
        FIELD_GetPlayerAreaZoneId((void *)w[1], &id);
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_MAPCHANGE_CreateZoneStartWarpEvent((void *)w[0], id));
        (*seq)++;
        break;
    case 3:
        FLDMMDL_SetAcmd(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((struct Obj00020 *)w[1])), 8);
        (*seq)++;
        break;
    case 4:
        if (FLDMMDL_CheckEndAcmd(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((struct Obj00020 *)w[1])))) {
            return 1;
        }
        break;
    }
    return 0;
}
