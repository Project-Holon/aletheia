/*
 * function: func_0216EE7C
 * address:  0x0216EE7C
 * packet:   pkt_ov010_0216EE7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * After a battle: unless the outcome is 0 or 2, reports the lead party
 * member's state (fainted, at half HP or less, a move out of PP, a status
 * condition) by name, then reports the species depending on the mode and
 * outcome.
 *
 * symbols:
 *   func_02012934  0x02012934  thumb
 *   func_0201AB18  0x0201AB18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021654AC  0x021654AC  thumb  ov010
 *   func_02165424  0x02165424  thumb  ov010
 *   func_02165468  0x02165468  thumb  ov010
 *   func_021654F0  0x021654F0  thumb  ov010
 *   func_02045808  0x02045808  arm
 *   func_0216EE40  0x0216EE40  thumb  ov010
 *   func_0216EE20  0x0216EE20  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct BattleEnd {
    u32 mode;           /* 0x00 */
    u8 pad04[0x48];
    u32 *result;        /* 0x4C */
    u8 pad50[0x3C];
    u32 outcome;        /* 0x8C */
} BattleEnd;

typedef struct BattleEndCtx {
    u32 f00;
    void *sys;          /* 0x04 */
    BattleEnd *st;      /* 0x08 */
} BattleEndCtx;

struct BigObj;
struct U16Vec;
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AB18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_02017E1C(void *mon, u32 id, u32 arg);
extern void func_021654AC(void *name);
extern void func_02165424(void *name);
extern void func_02165468(void *name);
extern void func_021654F0(void *name);
extern void func_02045808(struct U16Vec *vec);
extern void func_0216EE40(void *p, int which);
extern void func_0216EE20(u16 id, int col);

void func_0216EE7C(BattleEndCtx *c)
{
    BattleEnd *st;
    void *party;
    void *mon;
    void *name;
    u16 hp;
    u16 maxHp;
    int i;

    st = c->st;
    party = func_02012934(c->sys);
    mon = func_0201AB28(party, func_0201AB18(party));
    if (st->outcome != 0 && st->outcome != 2) {
        name = func_020457B0(12, 0x8004);
        func_02017E1C(mon, 0x73, (u32)name);
        hp = func_02017E1C(mon, 0xA0, 0);
        maxHp = func_02017E1C(mon, 0xA1, 0);
        if (hp == 0)
            func_021654AC(name);
        else if (hp * 2 <= maxHp)
            func_02165424(name);
        for (i = 0; i < 4; i++) {
            if (func_02017E1C(mon, 0x36 + i, 0) != 0 && func_02017E1C(mon, 0x3A + i, 0) == 0) {
                func_02165468(name);
                break;
            }
        }
        if (func_02017E1C(mon, 0x9D, 0) != 0)
            func_021654F0(name);
        func_02045808(name);
    }
    switch (st->mode) {
    case 0:
        if (st->outcome == 3)
            func_0216EE40(st, 2);
        else if (st->outcome == 1)
            func_0216EE40(st, 1);
        break;
    case 1:
        if (st->outcome == 1)
            func_0216EE20(*st->result, 1);
        break;
    }
}
