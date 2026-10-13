/*
 * function: BTL_SERVER_FLOW_ProcMoveRankEffects
 * address: 0x021C2E64
 * packet: pkt_ov093_021C2E64
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum Kind keeps the output guard in r0 and reloads it into r3 at the call.
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_FLOW_NextSerialNumber 0x021C2E4C thumb ov093
 *   WAZA_TOOL_GetRankEffectCount 0x0201C020 thumb
 *   BTL_SERVER_FLOW_QueryMoveRankEffectEvent 0x021C2F70 thumb ov093
 *   BTL_SERVER_FLOW_TryChangeStatStage 0x021C3008 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C78A8 0x021C78A8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u32 x; } W;
enum Kind { K0, K1, K10 = 10 };
struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u32 BTL_SERVER_FLOW_NextSerialNumber(u8 *);
extern u8 WAZA_TOOL_GetRankEffectCount(u16);
extern void BTL_SERVER_FLOW_QueryMoveRankEffectEvent(u8 *, u16, u32, u8 *, u8 *, s32 *, s32 *);
extern int BTL_SERVER_FLOW_TryChangeStatStage(u8 *, u8, u8 *, enum Kind, s32, u8, u16, u32, int, u32);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C78A8(u8 *, u8 *, u32, u32, u32);
int BTL_SERVER_FLOW_ProcMoveRankEffects(u8 *p, const u16 *q, u8 *a, u8 *b, int k)
{
    u8 id;
    int result;
    u32 count, i;
    u32 serial;
    enum Kind kind;
    s32 value;
    int ok;
    u8 j;
    u32 lock;
    result = 0;
    id = BTL_POKEPARAM_GetPokeId(a);
    serial = BTL_SERVER_FLOW_NextSerialNumber(p);
    count = WAZA_TOOL_GetRankEffectCount(*q);
    for (i = 0; i < count; i++) {
        ok = 0;
        BTL_SERVER_FLOW_QueryMoveRankEffectEvent(p, *q, i, a, b, (s32 *)&kind, &value);
        if (kind != 0) {
            if (kind != 10) {
                ok = BTL_SERVER_FLOW_TryChangeStatStage(p, id, b, kind, value, id, ok, serial, k, 1);
            } else {
                for (j = 1; j < 6; j++) {
                    if (BTL_SERVER_FLOW_TryChangeStatStage(p, id, b, j, value, id, 0, serial, k, 1)) ok = 1;
                }
            }
            if (ok) {
                lock = func_021CC8D8((struct Lock *)(p + 0x1d74), 8247);
                func_021C78A8(p, b, *q, kind, value);
                func_021CC95C((u32 *)(p + 0x1d74), lock, 8249);
                result = 1;
            }
        }
    }
    return result;
}
