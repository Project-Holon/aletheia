/*
 * function: BTL_CLIENT_IsActionForced
 * address:  0x021CF470
 * packet:   pkt_ov093_021CF470
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_CALC_ActionSetNone  0x021D8434  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_CALC_ActionSetForcedSkip  0x021D8444  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   BTLV_CORE_GetSlotValue  0x021E8B80  thumb  ov093
 *   BTL_POKEPARAM_GetLastMoveSlot  0x021D67C4  thumb  ov093
 *   BTL_ACTION_SetFight  0x021D82D0  thumb  ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   BTL_POKEPARAM_FindMoveSlot  0x021D5778  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_POKEPARAM_IsFainted(void *q);
struct Unk021D82D0;
extern void BTL_CALC_ActionSetNone(u32 *p);
struct QL;
struct Unk021D62A8;
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTL_CALC_ActionSetForcedSkip(u32 *p);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
typedef struct { u32 v; } Word;
extern Word BTL_POKEPARAM_GetSickContRaw(void *q, int i);
extern u16 BTLV_CORE_GetSlotValue(Word v);
extern u8 BTL_POKEPARAM_GetLastMoveSlot(u8 *p);
extern void BTL_ACTION_SetFight(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
extern u8 BTL_POKEPARAM_FindMoveSlot(void *q, u32 id);

u32 BTL_CLIENT_IsActionForced(u8 *p, void *q, u8 *o)
{
    u32 id;
    u32 a;
    u32 b;
    Word t;
    if (BTL_POKEPARAM_IsFainted(q) != 0) {
        if (o != 0) {
            BTL_CALC_ActionSetNone((u32 *)o);
        }
        return 1;
    }
    if (BTL_POKEPARAM_TestContFlag(q, 0xc) != 0) {
        if (o != 0) {
            BTL_CALC_ActionSetForcedSkip((u32 *)o);
        }
        return 1;
    }
    id = 0x19;
    if (BTL_POKEPARAM_HasSick(q, id) != 0) {
        t = BTL_POKEPARAM_GetSickContRaw(q, id);
        id = BTLV_CORE_GetSlotValue(t);
        b = BTL_POKEPARAM_GetLastMoveSlot(q);
        if (o != 0) {
            BTL_ACTION_SetFight((struct Unk021D82D0 *)o, id, b);
        }
        return 1;
    }
    if (BTL_POKEPARAM_HasSick(q, 0x1a) != 0) {
        a = BTL_POKEPARAM_GetLastUsedMoveId(q);
        b = BTL_POKEPARAM_GetLastMoveSlot(q);
        BTL_POKEPARAM_FindMoveSlot(q, a);
        if (o != 0) {
            BTL_ACTION_SetFight((struct Unk021D82D0 *)o, a, b);
        }
        return 1;
    }
    return 0;
}
