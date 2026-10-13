/*
 * function: SCRCMD_PROC_CallWifiBattleMatch
 * address:  0x0215CC4C
 * packet:   pkt_ov010_0215CC4C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: reads a kind (0xF-0x13 mapped to 0-4) and a flag (0/1),
 * builds a four-word request on the stack and launches EVENT_WIFIBATTLEMATCH_Entry
 * (ov002) through GAME_EVENT_CreateOverlayEvent, parking the result in the script's slot.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   EVENT_WIFIBATTLEMATCH_Entry  0x02154438  thumb  ov002
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   ov002_id       0x00000002  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Req {
    void *sys;          /* 0x00 */
    u32 one;            /* 0x04 */
    u32 flag;           /* 0x08 */
    u32 kind;           /* 0x0C */
} Req;

extern void *SCRCMD_WORK_GetScriptWork(void *vm);
extern void *SCRCMD_WORK_GetGameSystem(void *vm);
extern u32 SCRIPT_WORK_ReadWorkValue(void *c, void *vm);
typedef signed int     s32;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Desc;
extern struct Desc *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void EVENT_WIFIBATTLEMATCH_Entry(s32 a, s32 *b);
extern u8 ov002_id[];
extern void SCRIPT_SYS_CallEvent(void *p, void *v);

int SCRCMD_PROC_CallWifiBattleMatch(void *c, void *vm)
{
    void *slot;
    void *sys;
    u32 kind;
    u32 flag;
    u32 k;
    u32 f;
    Req r;

    slot = SCRCMD_WORK_GetScriptWork(vm);
    sys = SCRCMD_WORK_GetGameSystem(vm);
    kind = SCRIPT_WORK_ReadWorkValue(c, vm);
    flag = SCRIPT_WORK_ReadWorkValue(c, vm);
    switch (kind) {
    case 0xF:
        k = 0;
        break;
    case 0x10:
        k = 1;
        break;
    case 0x11:
        k = 2;
        break;
    case 0x12:
        k = 3;
        break;
    case 0x13:
        k = 4;
        break;
    }
    switch (flag) {
    case 0:
        f = 0;
        break;
    case 1:
        f = 1;
        break;
    }
    r.sys = GAMESYSTEM_GetFieldMap(sys);
    r.one = 1;
    r.flag = f;
    r.kind = k;
    SCRIPT_SYS_CallEvent(slot, GAME_EVENT_CreateOverlayEvent(sys, (u32)ov002_id, (void *)EVENT_WIFIBATTLEMATCH_Entry, (u32)(&r)));
    return 1;
}
