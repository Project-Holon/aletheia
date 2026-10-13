/*
 * function: SCRCMD_PROC_CheckMonIsPlayerOwned
 * address:  0x0215BE24
 * packet:   pkt_ov010_0215BE24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: is the party member in the given slot the player's own
 * catch (trainer id, OT name, OT gender and game version all match)?
 * Writes the answer to a script variable.
 *
 * Levers (2026-09-28 tree_ov010_4): the allocation check as
 * `if (a && b) {...} else fail` (moves the failure block after the name
 * test), the name test as `== 0` (STRBUF_IsEqual answers "equal"), and the
 * version read into a local before the compare (`cmp r0, r1`).
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb  ov010
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_02008530  0x02008530  thumb
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   STRBUF_Create  0x020457B0  arm
 *   func_02008500  0x02008500  thumb
 *   STRBUF_IsEqual  0x0204589C  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_02008550  0x02008550  thumb
 *   g0209DF08      0x0209DF08  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *c, void *vm);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *vm);
struct Buf;
struct Sub0200852CObj;
struct U16Vec;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_02008500(void *player, void *str);
extern int STRBUF_IsEqual(struct Buf *a, struct Buf *b);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 g0209DF08;

int SCRCMD_PROC_CheckMonIsPlayerOwned(void *c, void *vm)
{
    void *player;
    void *mon;
    u16 *res;
    u32 slot;
    u32 heap;
    void *a;
    void *b;
    u32 ver;

    res = SCRIPT_WORK_ReadWorkPointer(c, vm);
    slot = SCRIPT_WORK_ReadWorkValue(c, vm);
    player = GAME_DATA_GetMyStatus(SCRCMD_WORK_GetGameData(vm));
    mon = 0;
    if (!SCRCMD_PROC_GetPartyMember(vm, slot, &mon)) {
        *res = 0;
        return 0;
    }
    if (POKE_TOOL_GetPartyValue(mon, 7, 0) != func_02008530(player)) {
        *res = 0;
        return 0;
    }
    heap = SCRCMD_WORK_GetHeapId(vm);
    a = STRBUF_Create(16, heap);
    b = STRBUF_Create(16, heap);
    if (a != 0 && b != 0) {
        POKE_TOOL_GetPartyValue(mon, 0x8D, (u32)a);
        func_02008500(player, b);
        if (STRBUF_IsEqual(a, b) == 0) {
            STRBUF_Delete(a);
            STRBUF_Delete(b);
            *res = 0;
            return 0;
        }
    } else {
        *res = 0;
        return 0;
    }
    STRBUF_Delete(a);
    STRBUF_Delete(b);
    if (POKE_TOOL_GetPartyValue(mon, 0x9A, 0) != func_02008550(player)) {
        *res = 0;
        return 0;
    }
    ver = POKE_TOOL_GetPartyValue(mon, 0x77, 0);
    if (ver != g0209DF08) {
        *res = 0;
        return 0;
    }
    *res = 1;
    return 0;
}
