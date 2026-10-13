/*
 * function: SCRCMD_SYMBOL_StartEntryEvent
 * address:  0x0216AE10
 * packet:   pkt_ov010_0216AE10
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_DATA_GetSymbolMapFlag  0x02012FB0  thumb
 *   SYMBOL_MAP_IsBlankCell  0x0216662C  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   INTRUDE_COMM_GetMarkerPosForPartner  0x021767F0  thumb  ov011
 *   EVENT_MAPCHANGE_CreateWarpEvent  0x02184D38  thumb  ov020
 *   SYMBOL_MAP_GetSelectedNeighborCell  0x021665F0  thumb  ov010
 *   FIELD_G3D_MAP_StartSymbolEntry  0x0216B3A8  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
struct Ctx;
extern int GAME_DATA_GetSymbolMapFlag(unsigned char *base);
extern int SYMBOL_MAP_IsBlankCell(int a0);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void INTRUDE_COMM_GetMarkerPosForPartner();
struct Desc;
extern void *EVENT_MAPCHANGE_CreateWarpEvent(void *p, int unused, int a, const int *q, u16 s, int t);
extern int SYMBOL_MAP_GetSelectedNeighborCell(int a0, int a1, int a2);
struct Desc;
extern struct Desc *FIELD_G3D_MAP_StartSymbolEntry(int a0, int a1, int a2);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_SYMBOL_StartEntryEvent(int a0, int a1)
{
    int buf[3];
    int q[3];
    void *hd;
    void *b;
    void *c;
    int kind;
    int v;
    void *x;
    void *y;
    void *r;
    int s;

    hd = SCRCMD_WORK_GetScriptWork((void *)a1);
    b = SCRCMD_WORK_GetGameSystem((void *)a1);
    c = SCRCMD_WORK_GetGameData((void *)a1);
    kind = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    v = GAME_DATA_GetSymbolMapFlag(c);
    if (kind == 1 && SYMBOL_MAP_IsBlankCell(v) != 0) {
        x = GAMESYSTEM_GetFieldMap((void *)b);
        y = FIELDMAP_GetFieldPlayer((void *)x);
        s = GAMESYSTEM_GetGameComm(b);
        FIELD_PLAYER_GetPos(y, (struct VecFx32 *)q);
        INTRUDE_COMM_GetMarkerPosForPartner(s, c, buf);
        buf[0] = buf[0] + (q[0] - (0x3E << 14));
        r = EVENT_MAPCHANGE_CreateWarpEvent(b, (int)x, 0x117, buf, 1, 0);
    } else {
        if (kind != 9)
            v = SYMBOL_MAP_GetSelectedNeighborCell((int)b, GAME_DATA_GetSymbolMapFlag(c), kind);
        r = (void *)FIELD_G3D_MAP_StartSymbolEntry((int)b, kind, v);
    }
    SCRIPT_SYS_CallEvent(hd, r);
    return 1;
}
