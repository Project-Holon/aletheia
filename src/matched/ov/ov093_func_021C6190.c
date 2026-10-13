/*
 * function: BTL_SERVER_FLOW_ProcPursuitBeforeSwitch
 * address: 0x021C6190
 * packet: pkt_ov093_021C6190
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   HAND_WAZA_AddMoveHandler 0x021E02DC thumb ov093
 *   HAND_WAZA_RemoveMoveHandlerOfPoke 0x021E03D8 thumb ov093
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_SetVarReadOnly 0x021D75EC thumb ov093
 *   BTL_EVENT_DispatchEventChecked 0x021D70F0 thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 *p; u32 type:4; u32 pad:3; u32 key:16; u32 rest:9; u8 bytes[5]; u8 skip; u8 flag; u8 unused; } Entry;
extern int func_021D59B4(u8 *p, int k);
extern int HAND_WAZA_AddMoveHandler(u8 *, u16, u32);
extern void HAND_WAZA_RemoveMoveHandlerOfPoke(u8 *a, int b);
extern void BTL_EVENT_PushVarFrame(int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int, u32);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern void BTL_EVENT_PopVarFrame(int);
static inline u16 entry_key(Entry *e)
{
    if (e->type == 1) return e->key;
    return 0;
}
#define OBJECT(i) (*(u8 **)((u32)p + (i) * 16 + 0x7e0))
#define SKIP(i) p[(i) * 16 + 0x7ed]
#define FLAG(i) p[(i) * 16 + 0x7ee]
int BTL_SERVER_FLOW_ProcPursuitBeforeSwitch(u8 *p, u8 *a)
{
    u32 i;
    for (i = 0; i < p[0x782]; i++) {
        u16 key;
        if (OBJECT(i) == a) continue;
        if (SKIP(i)) continue;
        key = entry_key((Entry *)(p + 0x7e0) + i);
        if (key == 228) {
            if (HAND_WAZA_AddMoveHandler(OBJECT(i), key, func_021D59B4(OBJECT(i), 12)))
                FLAG(i) = 1;
        }
    }
    p[0x788] = 0;
    BTL_EVENT_PushVarFrame(11288);
    BTL_EVENT_SetVarReadOnly(6, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_DispatchEventChecked(p, 0x53);
    BTL_EVENT_PopVarFrame(11291);
    for (i = 0; i < p[0x782]; i++) {
        u16 key;
        if (FLAG(i)) {
            key = entry_key((Entry *)(p + 0x7e0) + i);
            if (key == 228) HAND_WAZA_RemoveMoveHandlerOfPoke(*(u8 **)(p + i * 16 + 0x7e0), key);
            FLAG(i) = 0;
        }
    }
    return p[0x788];
}
