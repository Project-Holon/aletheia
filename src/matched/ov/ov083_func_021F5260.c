/*
 * function: GPOWER_EVENT_CreateActivateEvent
 * address:  0x021F5260
 * packet:   pkt_ov083_021F5260
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct. Only blockers: four unlabelled arm9 leaves (the integrator's), each
 * with no witness outside the range.
 * blocker:
 *   0x02010F7C thumb (verified EXACT in ov083_func_021F5390.c's header):
 *     extern int ARC_TOOL_LoadMember(int a, int b, int c);
 *     int GPOWER_LoadPowerTable(int a) { return ARC_TOOL_LoadMember(0x26, 0, a); }
 *   0x02010F94 thumb (EXACT, `one --thumb`, no --region):
 *     typedef struct { u8 pad[10]; u8 fA; u8 fB; } Rec;
 *     u8 GPOWER_GetPowerType(Rec *rec, int slot) { return rec[slot].fA; }
 *   0x02010FA0 thumb (verified EXACT in ov032_func_021F1A28.c's header):
 *     u16 GPOWER_GetPowerCost(unsigned char *rec, int slot)
 *     { return *(u16 *)(rec + slot * 0xc + 2); }
 *   0x02010F8C thumb (verified in ov071_func_021B6458.c's header):
 *     void GPOWER_FreePowerTable(void *p) { void func_020307B0(void *); func_020307B0(p); }
 * The slot result is `int` (a `u8` local drops the per-use `lsls #16`), and
 * the declaration order h, s, obj puts them at sp+0x10, 0xc, 8.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GPOWER_LoadPowerTable  0x02010F7C  thumb
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   SCRIPT_SYS_GetEventScriptWork  0x021589D0  thumb  ov010
 *   GPOWER_GetPowerType  0x02010F94  thumb
 *   GPOWER_Activate   0x02010E14  thumb
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   GPOWER_EVENT_RestoreParty  0x021F5488  thumb  ov083
 *   GPOWER_GetPowerCost  0x02010FA0  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   MYITEM_SAVEDATA_RemoveItem   0x02007F1C  thumb
 *   GAME_BEACON_SEARCH_SetVersionAction  0x021652C4  thumb  ov010
 *   GAME_BEACON_SEARCH_SetHalfwordValue  0x021657B0  thumb  ov010
 *   GPOWER_FreePowerTable  0x02010F8C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Rec02010F94;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GPOWER_LoadPowerTable(u32 heap);
struct BigObj;
struct Desc;
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
extern int SCRIPT_SYS_GetEventScriptWork(int a0);
extern unsigned int GPOWER_GetPowerType(struct Rec02010F94 *p, int idx);
extern void GPOWER_Activate(int slot, u8 *rec, int select);
extern int SCRIPT_WORK_SetParams(int a, int b, int c, int d, u16 e);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern void  GPOWER_EVENT_RestoreParty(void *a0, void *a1, int a2);
extern u16   GPOWER_GetPowerCost(void *rec, int slot);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern u32 MYITEM_SAVEDATA_RemoveItem(u8 *base, u16 id, u16 qty, u16 d);
extern void GAME_BEACON_SEARCH_SetVersionAction(void *a0);
extern void  GAME_BEACON_SEARCH_SetHalfwordValue(int a0);
extern void  GPOWER_FreePowerTable(void *p);

void *GPOWER_EVENT_CreateActivateEvent(void *a0, int *a1)
{
    void *h;
    void *s;
    void *obj;
    void *rec;
    int id;
    int x;
    u16 q;

    obj = GAMESYSTEM_GetGameData(a0);
    rec = GPOWER_LoadPowerTable(0x8015);
    id = a1[0];
    h = SCRIPT_SYS_CreateScriptEventSimple((int)a0, 0x28B9, 0, 0x15);
    s = (void *)SCRIPT_SYS_GetEventScriptWork((int)h);
    if (id == 0x30 || id > 0x2D) {
        id = 0;
    }
    x = GPOWER_GetPowerType(rec, id);
    GPOWER_Activate(id, rec, a1[1]);
    if (id == 0x27) {
        SCRIPT_WORK_SetParams((int)s, (u16)id, (u16)0xB, (u16)a1[1], (u32)0);
    } else {
        SCRIPT_WORK_SetParams((int)s, (u16)id, (u16)x, (u16)a1[1], (u32)0);
    }
    GPOWER_EVENT_RestoreParty(a0, SCRIPT_WORK_GetWordSet(s), x);
    if (a1[1] != 0) {
        q = GPOWER_GetPowerCost(rec, id);
        MYITEM_SAVEDATA_RemoveItem(GAME_DATA_GetMyItem(obj), 0x23F, q, 0x8015);
        GAME_BEACON_SEARCH_SetVersionAction((void *)id);
    } else {
        GAME_BEACON_SEARCH_SetHalfwordValue(id);
    }
    GPOWER_FreePowerTable(rec);
    return h;
}
