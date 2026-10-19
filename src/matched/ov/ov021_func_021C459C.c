/*
 * function: SCRCMD_PLAYER_GRID_EVENT_StartHop
 * address:  0x021C459C
 * packet:   pkt_ov021_021C459C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   FIELD_PLAYER_GetPosInDir  0x021A3364  thumb  ov021
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_CreateHopTask  0x021C1024  thumb  ov021
 *   SCRCMD_WORK_SetTargetObject  0x0215A644  thumb  ov010
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_PLAYER_GRID_EVENT_WaitHop  0x021C457C  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned short u16;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
typedef unsigned char  u8;
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern void FIELD_PLAYER_GetPosInDir(u32 *a, int b, int *out);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern u32 FIELD_PLAYER_GRID_EVENT_CreateHopTask(void *a, u32 b, u32 c, u32 d);
extern void SCRCMD_WORK_SetTargetObject(void *p, u32 v);
extern void VM_SetWait(char *p, int val);
extern int SCRCMD_PLAYER_GRID_EVENT_WaitHop(void *a, void *b);

u32 SCRCMD_PLAYER_GRID_EVENT_StartHop(u32 a, u32 b)
{
    u32 buf[3];
    u32 z, w, t;
    void *x;
    void *y;

    x = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b));
    y = FIELDMAP_GetFieldPlayer((void *)x);
    z = FLDMMDL_GetDirDisp(FIELD_PLAYER_GetMmdl(y));
    x = (void *)FIELDMAP_GetG3dMapper(x);
    w = SCRCMD_WORK_GetHeapId((void *)b);
    FIELD_PLAYER_GetPosInDir(y, z, (int *)buf);
    t = MAP_ATTR_GetAt(x, buf);
    t = FIELD_PLAYER_GRID_EVENT_CreateHopTask(y, z, t, w);
    SCRCMD_WORK_SetTargetObject((void *)b, t);
    VM_SetWait((char *)a, (int)SCRCMD_PLAYER_GRID_EVENT_WaitHop);
    return 1;
}
