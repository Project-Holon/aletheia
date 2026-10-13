/*
 * function: HAND_WAZA_MeFirstPickMove
 * address: 0x021E6E38
 * packet: pkt_ov093_021E6E38
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 202 bytes of code followed by 2-byte alignment nop at 021E6F02,
 * then the labelled Thumb veneer func_021E6F04.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke 0x021C7D00 thumb ov093
 *   BTL_SERVER_FLOW_GetRule 0x021C815C thumb ov093
 *   BTL_MAIN_GetEnemyLanePos 0x021B8C20 thumb ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds 0x021C7F68 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   BTL_SERVER_FLOW_GetActionWordByPokeId 0x021C804C thumb ov093
 *   BTL_SERVER_FLOW_IsPokeInPosTable 0x021C814C thumb ov093
 *   BTL_SERVER_FLOW_IsPokeAfflictedByStatus 0x021C8374 thumb ov093
 *   BTL_ACTION_GetFightMove 0x021D8340 thumb ov093
 *   WAZA_TOOL_IsDamaging 0x0201C314 thumb
 *   func_021E6F04 0x021E6F04 thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b);
extern int BTL_SERVER_FLOW_GetRule(int *p);
extern u8 BTL_MAIN_GetEnemyLanePos(int, u32, u32);
struct UtilWork;
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *p, int b, u8 *out);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern int BTL_SERVER_FLOW_GetActionWordByPokeId(void *, u8, u32 *);
extern int BTL_SERVER_FLOW_IsPokeInPosTable(u8 *p, int v);
extern int BTL_SERVER_FLOW_IsPokeAfflictedByStatus(u8 *p, int i);
extern u32 BTL_ACTION_GetFightMove(u32 *);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern int func_021E6F04(u32);
extern int BTL_EVENT_OverwriteVar(int, u32);
void HAND_WAZA_MeFirstPickMove(void *x, void *a, int c, u8 *d)
{
    u8 k;
    u8 v;
    u32 flags;
    u32 desc;
    u32 id;
    int ok;
    if (c == BTL_EVENT_GetVar(2)) {
        k = BTL_EVENT_GetVar(14);
        if (k == 6) {
            flags = BTL_SERVER_FLOW_GetFrontPosOfPoke(a, c);
            k = BTL_MAIN_GetEnemyLanePos(BTL_SERVER_FLOW_GetRule(a), flags, 0);
        }
        if (BTL_SERVER_FLOW_CollectAlivePokeIds(a, k, d) != 0) {
            void *m;
            m = BTL_SERVER_FLOW_GetPokeParam(a, *d);
            v = *d;
            ok = 0;
            if (BTL_POKEPARAM_TestTurnFlag(m, 3) == 0) {
                if (BTL_SERVER_FLOW_GetActionWordByPokeId(a, v, &desc) != 0) {
                    if (BTL_SERVER_FLOW_IsPokeInPosTable(a, v) != 0) {
                        if (BTL_SERVER_FLOW_IsPokeAfflictedByStatus(a, v) == 0) {
                            id = BTL_ACTION_GetFightMove(&desc);
                            if (id != 0 && WAZA_TOOL_IsDamaging((void *)id) != 0 && func_021E6F04(id) == 0)
                                ok = 1;
                        }
                    }
                }
            }
            if (ok != 0) {
                BTL_EVENT_OverwriteVar(18, id);
                BTL_EVENT_OverwriteVar(13, k);
                return;
            }
        }
        BTL_EVENT_OverwriteVar(65, 1);
    }
}
