/*
 * function: func_021BE2B4
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
 *   func_02020F34 0x02020F34 thumb
 *   func_02021014 0x02021014 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_02018584 0x02018584 thumb
 *   func_020185C4 0x020185C4 thumb
 *   func_0201B970 0x0201B970 thumb
 *   func_021BE874 0x021BE874 thumb ov091
 *   func_021BE914 0x021BE914 thumb ov091
 *   func_021BE948 0x021BE948 thumb ov091
 *   func_021BEA48 0x021BEA48 thumb ov091
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02020F34(u32, u32, u32);
struct Rec;
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_020307B0(void *p);
extern u32 func_02017E1C(void *, u32, u32);
extern void func_02017E40(void *, u32, u32);
extern u32 func_02018584(u16, u16, u16);
extern void func_020185C4(void *);
extern u32 func_0201B970(void *, u32, u32);
extern int func_021BE874(void *, int, int);
extern void func_021BE914(void *, u32, u32, u32);
extern int func_021BE948(int, int, int, int);
extern int func_021BEA48(int, int, int, int, u16, int);
int func_021BE2B4(void *mon, u16 item, u16 moveSlot, u16 arg, int heap)
{
    void *rec;
    int changed = 0;
    int applicable;
    int originalStatus, status, spa, spd, allowAbove100, amount;
    int hpStat, hp, atk, maxHp, def, speed, level, oldLevel, result, i;
    rec = func_02020F34(item, 0, (u16)heap);
    if (func_02021014(rec, 14) != 1) { func_020307B0(rec); return changed; }
    applicable = 0;
    originalStatus = func_02017E1C(mon, 157, 0);
    status = originalStatus;
    if (func_02021014(rec, 18)) { status = 0; applicable = 1; }
    if (func_02021014(rec, 19)) { status = 0; applicable = 1; }
    if (func_02021014(rec, 20)) { status = 0; applicable = 1; }
    if (func_02021014(rec, 21)) { status = 0; applicable = 1; }
    if (func_02021014(rec, 22)) { status = 0; applicable = 1; }
    if (originalStatus != status) { func_02017E40(mon, 157, status); changed = 1; }
    hp = func_02017E1C(mon, 160, 0);
    maxHp = func_02017E1C(mon, 161, 0);
    if ((func_02021014(rec, 26) || func_02021014(rec, 27)) && !func_02021014(rec, 28)) {
        if (hp == 0) {
            func_021BE914(mon, hp, maxHp, func_02021014(rec, 58));
            changed = 1;
        }
        applicable = 1;
    } else if (func_02021014(rec, 41)) {
        if (hp < maxHp) { func_021BE914(mon, hp, maxHp, func_02021014(rec, 58)); changed = 1; }
        applicable = 1;
    }
    level = func_02017E1C(mon, 158, 0);
    if (func_02021014(rec, 28)) {
        if (level < 100) {
            i = func_02017E1C(mon, 5, 0);
            result = func_02017E1C(mon, 111, 0);
            func_02017E40(mon, 8, func_02018584(i, result, level + 1));
            func_020185C4(mon);
            if (hp == 0) {
                result = func_02017E1C(mon, 161, 0);
                func_021BE914(mon, hp, result, result - maxHp);
            }
            changed = 1;
        }
        applicable = 1;
    }
    if (func_02021014(rec, 29)) applicable = 1;
    if (func_02021014(rec, 37)) {
        applicable = 1;
        if (func_021BE874(mon, moveSlot, 1) == 1) changed = 1;
        applicable = 1;
    } else if (func_02021014(rec, 38)) {
        if (func_021BE874(mon, moveSlot, 3) == 1) changed = 1;
        applicable = 1;
    }
    if (func_02021014(rec, 39)) {
        if (func_0201B970(mon, moveSlot, func_02021014(rec, 59)) == 1) changed = 1;
        applicable = 1;
    } else if (func_02021014(rec, 40)) {
        for (i = 0; i < 4; i++) if (func_0201B970(mon, i, func_02021014(rec, 59)) == 1) changed = 1;
        applicable = 1;
    }
    hpStat = func_02017E1C(mon, 13, 0);
    atk = func_02017E1C(mon, 14, 0);
    def = func_02017E1C(mon, 15, 0);
    speed = func_02017E1C(mon, 16, 0);
    spa = func_02017E1C(mon, 17, 0);
    spd = func_02017E1C(mon, 18, 0);
    allowAbove100 = func_02021014(rec, 48);
    if (func_02017E1C(mon, 5, 0) != 292 && func_02021014(rec, 42)) {
        amount = func_02021014(rec, 52);
        result = func_021BE948(hpStat, spd + (spa + (speed + (atk + def))), amount, allowAbove100);
        if (result != -1) { hpStat = result; func_02017E40(mon, 13, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(rec, 43)) {
        amount = func_02021014(rec, 53);
        result = func_021BE948(atk, spd + (spa + (speed + (hpStat + def))), amount, allowAbove100);
        if (result != -1) { atk = result; func_02017E40(mon, 14, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(rec, 44)) {
        amount = func_02021014(rec, 54);
        result = func_021BE948(def, spd + (spa + (speed + (hpStat + atk))), amount, allowAbove100);
        if (result != -1) { def = result; func_02017E40(mon, 15, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(rec, 45)) {
        amount = func_02021014(rec, 55);
        result = func_021BE948(speed, spd + (spa + (def + (hpStat + atk))), amount, allowAbove100);
        if (result != -1) { speed = result; func_02017E40(mon, 16, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(rec, 46)) {
        amount = func_02021014(rec, 56);
        result = func_021BE948(spa, spd + (speed + (def + (hpStat + atk))), amount, allowAbove100);
        if (result != -1) { spa = result; func_02017E40(mon, 17, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(rec, 47)) {
        amount = func_02021014(rec, 57);
        result = func_021BE948(spd, spa + (speed + (def + (hpStat + atk))), amount, allowAbove100);
        if (result != -1) { func_02017E40(mon, 18, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (changed == 0 && applicable == 1) { func_020307B0(rec); return 0; }
    oldLevel = func_02017E1C(mon, 9, 0);
    if (oldLevel < 100) {
        if (func_02021014(rec, 49)) {
            func_021BEA48((int)mon, oldLevel, func_02021014(rec, 60), item, arg, heap);
            func_020307B0(rec); return changed;
        }
    } else if (oldLevel >= 100 && oldLevel < 200) {
        if (func_02021014(rec, 50)) {
            func_021BEA48((int)mon, oldLevel, func_02021014(rec, 61), item, arg, heap);
            func_020307B0(rec); return changed;
        }
    } else if (oldLevel >= 200 && oldLevel <= 255) {
        if (func_02021014(rec, 51)) {
            func_021BEA48((int)mon, oldLevel, func_02021014(rec, 62), item, arg, heap);
            func_020307B0(rec); return changed;
        }
    }
    func_020307B0(rec);
    return changed;
}
