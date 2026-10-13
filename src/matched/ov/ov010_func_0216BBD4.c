/*
 * function: FIELD_G3D_MAP_CmdStartSpPokeGimmickTask
 * address:  0x0216BBD4
 * packet:   pkt_ov010_0216BBD4
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
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   GIMMICK45_SecondarySwitchEventProc  0x021F39B8  thumb  ov045
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern int GIMMICK45_SecondarySwitchEventProc();
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int FIELD_G3D_MAP_CmdStartSpPokeGimmickTask(int c, int vm)
{
    void *ws;
    void *p8;
    void *p10;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int buf[3];
    int vec[3];
    int *x;
    int *y;
    int r;

    ws = SCRCMD_WORK_GetScriptWork((void *)vm);
    p8 = SCRCMD_WORK_GetGameSystem((void *)vm);
    p10 = GAMESYSTEM_GetFieldMap((void *)p8);
    a1 = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    a2 = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    a3 = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    a4 = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    a5 = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    a6 = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((void *)p10), (struct VecFx32 *)buf);
    vec[0] = (a2 << 16) + 0x8000;
    vec[1] = a3 << 15;
    vec[2] = (a4 << 16) + 0x8000;
    if (a1 == 0) {
        x = buf;
        y = vec;
    } else {
        x = vec;
        y = buf;
    }
    r = GIMMICK45_SecondarySwitchEventProc(p8, a1, x, y, a5 << 15, a6);
    if (r == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(ws, (void *)r);
    return 1;
}
