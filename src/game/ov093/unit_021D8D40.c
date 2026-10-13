/*
 * file:     unit_021D8D40.c
 * unit:     yes
 * function: func_021D8D40, func_021D8D90, func_021D8D9C, func_021D8E00, func_021D8E1C, func_021D8E58, func_021D8E7C, func_021D8EDC, func_021D8F1C, func_021D8F54, func_021D8F84, func_021D8FCC, func_021D901C, func_021D9064, func_021D9070, func_021D90DC, func_021D90E8, func_021D910C
 * address:  0x021D8D40
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   d_021F06A0     0x021F06A0  data   ov093  a4
 *   d_021F0E1C     0x021F0E1C  data   ov093  a4
 *   d_021F0608 0x021F0608 data a4
 *   d_021F07E0     0x021F07E0  data   ov093  a4
 */
struct BtlPokeParam;
struct BtlMessage;
struct BtlEventFactor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* Header word of the server command made by func_021C88A4. */
struct BtlCmdHeader { u32 lowBits : 23; u32 announce : 1; u32 kind : 8; };

extern int func_021D775C(int key);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern void func_021D7704(int key, int multiplier);
extern int func_021C8010(void *server, unsigned int pokeId);
extern u8 func_021C7F68(void *server, int sideKey, u8 *out);
extern void *func_021C7CF4(void *server, int pokeId);
extern int func_021D59B4(u8 *pokeParam, int statKey);
extern u16 func_021D5444(struct BtlPokeParam *pokeParam);
extern int func_021C8288(void *server);
extern void *func_021C88A4(char *server, int cmdKind, int pokeId);
extern void func_021C8838(void *message, int kind, int stringId);
extern void func_021C8860(struct BtlMessage *message, u32 arg);
extern void func_021C88C8(void *server, void *cmd);
extern u16 func_021D70A8(struct BtlEventFactor *factor);
extern int func_021B9A24(unsigned int pokeIdA, unsigned int pokeIdB);
void func_021D8D40(struct BtlEventFactor *factor, void *server, int pokeId, u8 *work);
int *func_021D8D90(int *handlerCount);
int func_021D8D9C(void *server, int pokeId, u8 *idBuf, int abilityId);
int func_021D8E00(void *server, int pokeId);
void func_021D8E1C(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021D8E58(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021D8E7C(struct BtlEventFactor *factor, void *server, u32 pokeId, u32 form, u8 announce);
void func_021D8EDC(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021D8F1C(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021D8F54(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021D8F84(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021D8FCC(struct BtlEventFactor *factor, void *server, int pokeId);
void func_021D901C(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021D9064(int *handlerCount);
void func_021D9070(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021D90DC(int *handlerCount);
void func_021D90E8(struct BtlEventFactor *factor, void *server, int pokeId);
void *func_021D910C(int *handlerCount);
extern int d_021F06A0[];
extern int d_021F0E1C[];
extern unsigned int d_021F0608;
extern int d_021F07E0[];

/* Plus/Minus (ability 57/58): power event of the owner, special move, an ally has Plus or Minus. */
void func_021D8D40(struct BtlEventFactor *factor, void *server, int pokeId, u8 *work)
{
    if (pokeId == func_021D775C(3)) {
        if (func_021D8D9C(server, pokeId, work, 0x39) != 0 || func_021D8D9C(server, pokeId, work, 0x3a) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)func_021D775C(0x12)) == 2)
                func_021D7704(0x35, 6 << 10);
        }
    }
}

int *func_021D8D90(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F06A0;
}

/* Collects the pokemon on the side of pokeId into idBuf; true if another one has ability abilityId. */
int func_021D8D9C(void *server, int pokeId, u8 *idBuf, int abilityId)
{
    int side;
    u8 count;
    u8 i;

    side = func_021C8010(server, pokeId);
    if (side != 6) {
        count = func_021C7F68(server, (u16)((7 << 8) | side), idBuf);
        for (i = 0; i < count; i++) {
            if (pokeId != idBuf[i]) {
                if (abilityId == func_021D59B4(func_021C7CF4(server, idBuf[i]), 0x11))
                    return 1;
            }
        }
    }
    return 0;
}

/* True if the pokemon is Cherrim (species 421). */
int func_021D8E00(void *server, int pokeId)
{
    if (func_021D5444(func_021C7CF4(server, pokeId)) == 0x1a5) return 1;
    return 0;
}

/* Flower Gift: Cherrim takes the sunshine form when the weather is sun; marks the work flag. */
void func_021D8E1C(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (func_021D8E00(server, pokeId)) {
        func_021D8E7C(factor, server, pokeId, (unsigned char)(func_021C8288(server) == 1), 1);
        *work = 1;
    }
}

void func_021D8E58(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (pokeId == func_021D775C(2)) func_021D8E1C(factor, server, pokeId, work);
}

/* Queues a form change of pokeId to form, unless it already has that form. */
void func_021D8E7C(struct BtlEventFactor *factor, void *server, u32 pokeId, u32 form, u8 announce)
{
    u8 *cmd;

    if (form != func_021D59B4(func_021C7CF4(server, pokeId), 0x13)) {
        cmd = func_021C88A4(server, 0x39, pokeId);
        cmd[4] = pokeId;
        cmd[5] = form;
        ((struct BtlCmdHeader *)cmd)->announce = announce;
        func_021C8838(cmd + 8, 2, 0xde);
        func_021C8860((struct BtlMessage *)(cmd + 8), pokeId);
        func_021C88C8(server, cmd);
    }
}

void func_021D8EDC(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (*work != 0 && func_021D8E00(server, pokeId) != 0)
        func_021D8E7C(factor, server, pokeId, (u8)(func_021C8288(server) == 1), 1);
}

void func_021D8F1C(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (*work && pokeId == func_021D775C(2) && func_021D8E00(server, pokeId))
        func_021D8E7C(factor, server, pokeId, 0, 0);
}

void func_021D8F54(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (*work && func_021D8E00(server, pokeId)) func_021D8E7C(factor, server, pokeId, 0, 0);
}

void func_021D8F84(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    int factorKey;

    if (*work != 0 && func_021D8E00(server, pokeId) != 0) {
        if (pokeId == func_021D775C(2)) {
            factorKey = func_021D775C(0x10);
            if (factorKey != func_021D70A8(factor))
                func_021D8E7C(factor, server, pokeId, 0, 0);
        }
    }
}

/* Flower Gift: ally of the attacker, sun, physical move: attack x1.5. */
void func_021D8FCC(struct BtlEventFactor *factor, void *server, int pokeId)
{
    u8 attackerId;

    if (func_021D8E00(server, pokeId) != 0 && func_021C8288(server) == 1) {
        attackerId = func_021D775C(3);
        if (func_021B9A24(pokeId, attackerId) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)func_021D775C(0x12)) == 1)
                func_021D7704(0x35, 3 << 11);
        }
    }
}

/* Flower Gift: ally of the defender, sun, special move: special defense x1.5. */
void func_021D901C(struct BtlEventFactor *factor, void *server, int pokeId)
{
    u8 defenderId;

    if (func_021D8E00(server, pokeId) != 0 && func_021C8288(server) == 1) {
        defenderId = func_021D775C(4);
        if (func_021B9A24(pokeId, defenderId) != 0) {
            if (func_021D775C(0x1a) == 2)
                func_021D7704(0x35, 6 << 10);
        }
    }
}

int *func_021D9064(int *handlerCount)
{
    *handlerCount = 11;
    return d_021F0E1C;
}

/* Rivalry: same gender x1.25, opposite gender x0.75, genderless no change. */
void func_021D9070(struct BtlEventFactor *factor, void *server, int pokeId)
{
    void *attacker;
    void *defender;
    u8 attackerGender;
    u8 defenderGender;

    if (pokeId == func_021D775C(3)) {
        attacker = func_021C7CF4(server, pokeId);
        defender = func_021C7CF4(server, (u8)func_021D775C(4));
        attackerGender = func_021D59B4(attacker, 0x12);
        defenderGender = func_021D59B4(defender, 0x12);
        if (attackerGender != 2 && defenderGender != 2) {
            if (attackerGender == defenderGender) {
                func_021D7704(0x31, 5 << 10);
                return;
            }
            func_021D7704(0x31, 3 << 10);
        }
    }
}

int *func_021D90DC(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F07E0;
}

/* Technician: moves with base power 60 or less x1.5. */
void func_021D90E8(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == func_021D775C(3) && (unsigned int)func_021D775C(0x30) <= 0x3c) func_021D7704(0x31, 0x30 << 7);
}

void *func_021D910C(int *handlerCount) { *handlerCount = 1; return &d_021F0608; }
