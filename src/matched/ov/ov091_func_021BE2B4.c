/*
 * function: PLIST_DEMO_UseItemOnMon
 * address: 0x021BE2B4
 * packet: pkt_ov091_021BE2B4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * levers: wave 82 R12. Real callee prototypes (02020F34 heap u32, 021BEA48 first int)
 *   with the caller-side (u16)heap narrowing the listing shows before 02020F34; item and
 *   moveSlot are u16 parameters (callers pass ldrh values / constant 0). u16 item
 *   fixed 31 of 35 bytes (spill reloads of item), u16 or u8 moveSlot the last 4 (r2 spill
 *   order); u16 chosen with item/arg, no byte evidence between u16 and u8.
 * symbols:
 *   FILE_UTIL_LoadItemRecord 0x02020F34 thumb
 *   FILE_UTIL_GetItemRecordParam 0x02021014 thumb
 *   func_020307B0 0x020307B0 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKE_TOOL_GetExpForLevel 0x02018584 thumb
 *   POKE_TOOL_RecalcParam 0x020185C4 thumb
 *   POKE_TOOL_RestorePP 0x0201B970 thumb
 *   PLIST_DEMO_RaiseMovePpUps 0x021BE874 thumb ov091
 *   PLIST_DEMO_RestoreHp 0x021BE914 thumb ov091
 *   PLIST_DEMO_AddEv 0x021BE948 thumb ov091
 *   PLIST_DEMO_ApplyFriendshipItem 0x021BEA48 thumb ov091
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *FILE_UTIL_LoadItemRecord(u32, u32, u32);
struct Rec;
extern u32 FILE_UTIL_GetItemRecordParam(struct Rec *p, u32 sel);
extern u32 func_020307B0(void *p);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern void POKE_TOOL_SetPartyValue(void *, u32, u32);
extern u32 POKE_TOOL_GetExpForLevel(u16, u16, u16);
extern void POKE_TOOL_RecalcParam(void *);
extern u32 POKE_TOOL_RestorePP(void *, u32, u32);
extern int PLIST_DEMO_RaiseMovePpUps(void *, int, int);
extern void PLIST_DEMO_RestoreHp(void *, u32, u32, u32);
extern int PLIST_DEMO_AddEv(int, int, int, int);
extern int PLIST_DEMO_ApplyFriendshipItem(int, int, int, int, u16, int);
int PLIST_DEMO_UseItemOnMon(void *mon, u16 item, u16 moveSlot, u16 arg, int heap)
{
    void *rec;
    int changed = 0;
    int applicable;
    int originalStatus, status, spa, spd, allowAbove100, amount;
    int hpStat, hp, atk, maxHp, def, speed, level, oldLevel, result, i;
    rec = FILE_UTIL_LoadItemRecord(item, 0, (u16)heap);
    if (FILE_UTIL_GetItemRecordParam(rec, 14) != 1) { func_020307B0(rec); return changed; }
    applicable = 0;
    originalStatus = POKE_TOOL_GetPartyValue(mon, 157, 0);
    status = originalStatus;
    if (FILE_UTIL_GetItemRecordParam(rec, 18)) { status = 0; applicable = 1; }
    if (FILE_UTIL_GetItemRecordParam(rec, 19)) { status = 0; applicable = 1; }
    if (FILE_UTIL_GetItemRecordParam(rec, 20)) { status = 0; applicable = 1; }
    if (FILE_UTIL_GetItemRecordParam(rec, 21)) { status = 0; applicable = 1; }
    if (FILE_UTIL_GetItemRecordParam(rec, 22)) { status = 0; applicable = 1; }
    if (originalStatus != status) { POKE_TOOL_SetPartyValue(mon, 157, status); changed = 1; }
    hp = POKE_TOOL_GetPartyValue(mon, 160, 0);
    maxHp = POKE_TOOL_GetPartyValue(mon, 161, 0);
    if ((FILE_UTIL_GetItemRecordParam(rec, 26) || FILE_UTIL_GetItemRecordParam(rec, 27)) && !FILE_UTIL_GetItemRecordParam(rec, 28)) {
        if (hp == 0) {
            PLIST_DEMO_RestoreHp(mon, hp, maxHp, FILE_UTIL_GetItemRecordParam(rec, 58));
            changed = 1;
        }
        applicable = 1;
    } else if (FILE_UTIL_GetItemRecordParam(rec, 41)) {
        if (hp < maxHp) { PLIST_DEMO_RestoreHp(mon, hp, maxHp, FILE_UTIL_GetItemRecordParam(rec, 58)); changed = 1; }
        applicable = 1;
    }
    level = POKE_TOOL_GetPartyValue(mon, 158, 0);
    if (FILE_UTIL_GetItemRecordParam(rec, 28)) {
        if (level < 100) {
            i = POKE_TOOL_GetPartyValue(mon, 5, 0);
            result = POKE_TOOL_GetPartyValue(mon, 111, 0);
            POKE_TOOL_SetPartyValue(mon, 8, POKE_TOOL_GetExpForLevel(i, result, level + 1));
            POKE_TOOL_RecalcParam(mon);
            if (hp == 0) {
                result = POKE_TOOL_GetPartyValue(mon, 161, 0);
                PLIST_DEMO_RestoreHp(mon, hp, result, result - maxHp);
            }
            changed = 1;
        }
        applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(rec, 29)) applicable = 1;
    if (FILE_UTIL_GetItemRecordParam(rec, 37)) {
        applicable = 1;
        if (PLIST_DEMO_RaiseMovePpUps(mon, moveSlot, 1) == 1) changed = 1;
        applicable = 1;
    } else if (FILE_UTIL_GetItemRecordParam(rec, 38)) {
        if (PLIST_DEMO_RaiseMovePpUps(mon, moveSlot, 3) == 1) changed = 1;
        applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(rec, 39)) {
        if (POKE_TOOL_RestorePP(mon, moveSlot, FILE_UTIL_GetItemRecordParam(rec, 59)) == 1) changed = 1;
        applicable = 1;
    } else if (FILE_UTIL_GetItemRecordParam(rec, 40)) {
        for (i = 0; i < 4; i++) if (POKE_TOOL_RestorePP(mon, i, FILE_UTIL_GetItemRecordParam(rec, 59)) == 1) changed = 1;
        applicable = 1;
    }
    hpStat = POKE_TOOL_GetPartyValue(mon, 13, 0);
    atk = POKE_TOOL_GetPartyValue(mon, 14, 0);
    def = POKE_TOOL_GetPartyValue(mon, 15, 0);
    speed = POKE_TOOL_GetPartyValue(mon, 16, 0);
    spa = POKE_TOOL_GetPartyValue(mon, 17, 0);
    spd = POKE_TOOL_GetPartyValue(mon, 18, 0);
    allowAbove100 = FILE_UTIL_GetItemRecordParam(rec, 48);
    if (POKE_TOOL_GetPartyValue(mon, 5, 0) != 292 && FILE_UTIL_GetItemRecordParam(rec, 42)) {
        amount = FILE_UTIL_GetItemRecordParam(rec, 52);
        result = PLIST_DEMO_AddEv(hpStat, spd + (spa + (speed + (atk + def))), amount, allowAbove100);
        if (result != -1) { hpStat = result; POKE_TOOL_SetPartyValue(mon, 13, result); POKE_TOOL_RecalcParam(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(rec, 43)) {
        amount = FILE_UTIL_GetItemRecordParam(rec, 53);
        result = PLIST_DEMO_AddEv(atk, spd + (spa + (speed + (hpStat + def))), amount, allowAbove100);
        if (result != -1) { atk = result; POKE_TOOL_SetPartyValue(mon, 14, result); POKE_TOOL_RecalcParam(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(rec, 44)) {
        amount = FILE_UTIL_GetItemRecordParam(rec, 54);
        result = PLIST_DEMO_AddEv(def, spd + (spa + (speed + (hpStat + atk))), amount, allowAbove100);
        if (result != -1) { def = result; POKE_TOOL_SetPartyValue(mon, 15, result); POKE_TOOL_RecalcParam(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(rec, 45)) {
        amount = FILE_UTIL_GetItemRecordParam(rec, 55);
        result = PLIST_DEMO_AddEv(speed, spd + (spa + (def + (hpStat + atk))), amount, allowAbove100);
        if (result != -1) { speed = result; POKE_TOOL_SetPartyValue(mon, 16, result); POKE_TOOL_RecalcParam(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(rec, 46)) {
        amount = FILE_UTIL_GetItemRecordParam(rec, 56);
        result = PLIST_DEMO_AddEv(spa, spd + (speed + (def + (hpStat + atk))), amount, allowAbove100);
        if (result != -1) { spa = result; POKE_TOOL_SetPartyValue(mon, 17, result); POKE_TOOL_RecalcParam(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(rec, 47)) {
        amount = FILE_UTIL_GetItemRecordParam(rec, 57);
        result = PLIST_DEMO_AddEv(spd, spa + (speed + (def + (hpStat + atk))), amount, allowAbove100);
        if (result != -1) { POKE_TOOL_SetPartyValue(mon, 18, result); POKE_TOOL_RecalcParam(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (changed == 0 && applicable == 1) { func_020307B0(rec); return 0; }
    oldLevel = POKE_TOOL_GetPartyValue(mon, 9, 0);
    if (oldLevel < 100) {
        if (FILE_UTIL_GetItemRecordParam(rec, 49)) {
            PLIST_DEMO_ApplyFriendshipItem((int)mon, oldLevel, FILE_UTIL_GetItemRecordParam(rec, 60), item, arg, heap);
            func_020307B0(rec); return changed;
        }
    } else if (oldLevel >= 100 && oldLevel < 200) {
        if (FILE_UTIL_GetItemRecordParam(rec, 50)) {
            PLIST_DEMO_ApplyFriendshipItem((int)mon, oldLevel, FILE_UTIL_GetItemRecordParam(rec, 61), item, arg, heap);
            func_020307B0(rec); return changed;
        }
    } else if (oldLevel >= 200 && oldLevel <= 255) {
        if (FILE_UTIL_GetItemRecordParam(rec, 51)) {
            PLIST_DEMO_ApplyFriendshipItem((int)mon, oldLevel, FILE_UTIL_GetItemRecordParam(rec, 62), item, arg, heap);
            func_020307B0(rec); return changed;
        }
    }
    func_020307B0(rec);
    return changed;
}
