/*
 * function: NAMEIN_SETUP_RunHistoryScreenEvent
 * address:  0x0216C7FC
 * packet:   pkt_ov010_0216C7FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 *
 * blockers: GAME_DATA_GetSaveBlock3B (unlabelled arm9 leaf, no witness), id_00000045 (pooled small
 * constant, a symbol; no witness), d_021BA650 (pointer into another overlay, no witness)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveBlock3B  0x02012EFC  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryTagA  0x0200DF40  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryTagB  0x0200DF4C  thumb
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   id_00000045    0x00000045  data  a1
 *   d_021BA650     0x021BA650  data  a4 ov069
 */

typedef unsigned char  u8;
struct Ctx;
struct Evt;
struct RecSlot;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveBlock3B(void **p);
struct RecSlot;
extern int BSUBWAY_SAVEDATA_GetHistoryTagA(struct RecSlot *p);
extern u8 BSUBWAY_SAVEDATA_GetHistoryTagB(struct RecSlot *p);
extern void *FIELD_STATUS_CreateSubProcEvent(char *a0, int a1, int a2, int a3, int a4);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern char d_021BA650[];
extern char id_00000045[];

int NAMEIN_SETUP_RunHistoryScreenEvent(int a, int *st, int *o)
{
    int t;
    switch (*st) {
    case 0:
        o[2] = (int)GAMESYSTEM_GetGameData((const struct Ctx *)o[1]);
        t = (int)GAME_DATA_GetSaveBlock3B((void **)o[2]);
        o[3] = BSUBWAY_SAVEDATA_GetHistoryTagA((struct RecSlot *)t);
        o[4] = BSUBWAY_SAVEDATA_GetHistoryTagB((struct RecSlot *)t);
        GAME_EVENT_CallEvent((struct Evt *)a, FIELD_STATUS_CreateSubProcEvent((char *)o[1], o[0], (int)id_00000045, (int)d_021BA650, (int)(&o[2])));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
