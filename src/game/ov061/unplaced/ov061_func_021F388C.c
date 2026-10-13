/*
 * function: func_021F388C
 * address:  0x021F388C
 * packet:   pkt_ov061_021F388C
 * region:   ov061
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_02162560, func_02162A64 (a thunk) and func_02162CE8 behind it are
 * unlabelled ov010 leaves filed alongside this function.
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02162560  0x02162560  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_02162A64  0x02162A64  thumb  ov010
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 */

#include "../unit_021F36C0_types.h"

struct GameSystem;
struct GameData;
struct EventData;
struct ConnectData;

extern struct GameSystem *func_02188C80(void *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct EventData *func_02012844(const struct GameData *gameData);
extern u16 func_02162560(struct EventData *eventData);
extern u16 func_02188C84(void *fieldMap);
extern void *func_02188D2C(void *fieldMap);
extern void func_021BE4B4(void *expObj, int unit, int model, int hidden);
extern struct ConnectData *func_021625CC(struct EventData *eventData, unsigned index);
extern u8 func_021626E8(struct ConnectData *connect);
extern void func_02162A64(struct ConnectData *connect, VecFx32 *out);
extern u16 func_02188C9C(void *fieldMap);
extern VecFx32 *func_021BE480(void *expObj, int unit, u16 model);
extern void *func_021BE674(void *expObj, int unit, unsigned int model, int animeIdx);
extern void func_021BE700(void *expObj, int unit, u16 model, u16 animeIdx, int enabled);

/* Shows a marker model (1..8) at the center of each map connection of exit type 6 and hides the others. */
void func_021F388C(Gimmick61Work *unusedWork, void *fieldMap)
{
    struct EventData *eventData;
    int connectCount;
    void *expObj;
    int i;
    struct ConnectData *connect;
    VecFx32 pos;

    eventData = func_02012844(func_020120F4(func_02188C80(fieldMap)));
    connectCount = func_02162560(eventData);
    func_02188C84(fieldMap);
    expObj = func_02188D2C(fieldMap);
    for (i = 0; i < GIMMICK61_MARKER_MAX; i++) {
        func_021BE4B4(expObj, 0, (u16)(i + 1), 1);
    }
    for (i = 0; i < connectCount; i++) {
        connect = func_021625CC(eventData, (u16)i);
        if (connect != 0 && func_021626E8(connect) == GIMMICK61_MARKER_EXIT_TYPE) {
            func_02162A64(connect, &pos);
            if (func_02188C9C(fieldMap) == GIMMICK61_LOWERED_ZONE_ID) {
                pos.y -= 0x2000;
            }
            func_021BE4B4(expObj, 0, (u16)(i + 1), 0);
            *func_021BE480(expObj, 0, i + 1) = pos;
            func_021BE674(expObj, 0, (u16)(i + 1), (u16)0);
            func_021BE700(expObj, 0, i + 1, 0, 1);
        }
    }
}
