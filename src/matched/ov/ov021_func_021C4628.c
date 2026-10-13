/*
 * function: SCRCMD_PLAYER_GRID_EVENT_StartB
 * address:  0x021C4628
 * packet:   pkt_ov021_021C4628
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELD_PLAYER_GRID_EVENT_CreateJumpTask  0x021C1228  thumb  ov021
 *   SCRCMD_WORK_SetTargetObject  0x0215A644  thumb  ov010
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_PLAYER_GRID_EVENT_WaitB  0x021C4608  thumb  ov021
 */

typedef unsigned int u32;

extern unsigned short SCRCMD_WORK_GetHeapId(void *a0);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern u32 SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u32 FIELD_PLAYER_GRID_EVENT_CreateJumpTask(void *a, u32 b, u32 c, u32 d);
extern void SCRCMD_WORK_SetTargetObject(void *p, u32 v);
extern void VM_SetWait(char *p, int val);
extern int SCRCMD_PLAYER_GRID_EVENT_WaitB(void *a, void *b);

u32 SCRCMD_PLAYER_GRID_EVENT_StartB(u32 a, void *b)
{
    u32 w, y, t;
    void *x;

    w = SCRCMD_WORK_GetHeapId(b);
    x = FIELDMAP_GetFieldPlayer(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b)));
    y = FIELD_PLAYER_GetDirDisp(x);
    t = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    t = FIELD_PLAYER_GRID_EVENT_CreateJumpTask(x, y, t, w);
    SCRCMD_WORK_SetTargetObject((void *)b, t);
    VM_SetWait((char *)a, (int)SCRCMD_PLAYER_GRID_EVENT_WaitB);
    return 1;
}
