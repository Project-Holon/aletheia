/*
 * file:     unit_021D9118.c
 * unit:     yes
 * function: func_021D9118, func_021D9148, func_021D9154, func_021D9190, func_021D919C, func_021D91D8, func_021D91E4, func_021D91FC, func_021D9208, func_021D9214, func_021D9224, func_021D9234, func_021D9240, func_021D9250, func_021D9260, func_021D926C, func_021D927C, func_021D928C, func_021D92CC, func_021D9340, func_021D936C, func_021D93A8
 * address:  0x021D9118
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetFlag 0x0201BEB8 thumb
 *   d_021F0758 0x021F0758 data a4
 *   func_0201BD28  0x0201BD28  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   d_021F06A8     0x021F06A8  data   ov093  a4
 *   func_021D76BC   0x021D76BC  thumb
 *   d_021F0720     0x021F0720  data   ov093  a4
 *   d_021F0618     0x021F0618  data   ov093  a4
 *   d_021F0880     0x021F0880  data   ov093  a4
 *   d_021F0890     0x021F0890  data   ov093  a4
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F06B8 0x021F06B8 data a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   d_021F0A40 0x021F0A40 data a4
 *   d_021F08A0     0x021F08A0  data   ov093  a4
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

extern int func_021D775C(int key);
extern void func_021D7704(int key, int multiplier);
extern unsigned int WAZA_TOOL_GetFlag(unsigned short moveId, unsigned int flagBit);
extern u32 func_0201BD28(u16 moveId, u32 field);
extern void *func_021C7CF4(void *server, int pokeId);
extern int func_021D62A8(struct BtlPokeParam *pokeParam);
extern int func_021D76BC(int key, u32 value);
extern void func_021C88B4(void *server, int phase, int pokeId);
extern void *func_021C88A4(char *server, int cmdKind, int pokeId);
extern void func_021C8838(void *message, int kind, int stringId);
extern void func_021C8860(struct BtlMessage *message, u32 arg);
extern void func_021C88C8(void *server, void *cmd);
extern int func_021C8288(void *server);
extern int func_021D7D6C(int condition);
void func_021D9118(struct BtlEventFactor *factor, void *server, int pokeId);
void *func_021D9148(int *handlerCount);
void func_021D9154(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021D9190(int *handlerCount);
void func_021D919C(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021D91D8(int *handlerCount);
void func_021D91E4(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021D91FC(int *handlerCount);
int *func_021D9208(int *handlerCount);
void func_021D9214(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021D9224(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *func_021D9234(int *handlerCount);
void func_021D9240(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021D9250(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *func_021D9260(int *handlerCount);
void func_021D926C(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021D927C(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021D928C(void *server, int pokeId, int *work, int blockedCause);
void func_021D92CC(void *server, int pokeId, int *work, int stringId);
void func_021D9340(struct BtlEventFactor *factor, void *server, int pokeId);
void *func_021D9360(int *handlerCount);
void func_021D936C(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021D93A8(struct BtlEventFactor *factor, void *server, int pokeId);
void *func_021D93CC(int *handlerCount);
extern unsigned int d_021F0758;
extern int d_021F06A8[];
extern int d_021F0720[];
extern int d_021F0618[];
extern int d_021F0880[];
extern int d_021F0890[];
extern unsigned int d_021F06B8;
extern unsigned int d_021F0A40;
extern int d_021F08A0[];

/* Iron Fist: punching moves (move flag 7) x1.2. */
void func_021D9118(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == func_021D775C(3) && WAZA_TOOL_GetFlag(func_021D775C(0x12), 7)) func_021D7704(0x31, 0x1333);
}

void *func_021D9148(int *handlerCount) { *handlerCount = 1; return &d_021F0758; }

/* Reckless: recoil moves, Jump Kick and Hi Jump Kick x1.2. */
void func_021D9154(struct BtlEventFactor *factor, void *server, int pokeId)
{
    u16 moveId;

    if (pokeId == func_021D775C(3)) {
        moveId = func_021D775C(0x12);
        if (func_0201BD28(moveId, 0x1e) != 0 || moveId == 0x1a || moveId == 0x88)
            func_021D7704(0x31, 0x1333);
    }
}

int *func_021D9190(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0720;
}

/* Marvel Scale: defender has a status condition, physical move: defense x1.5. */
void func_021D919C(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == func_021D775C(4)) {
        if (func_021D62A8(func_021C7CF4(server, pokeId))) {
            func_021D775C(0x12);
            if (func_021D775C(0x1a) == 1)
                func_021D7704(0x35, 0x1800);
        }
    }
}

int *func_021D91D8(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F06A8;
}

/* Mold Breaker: sets the ignore-ability flag while the owner attacks. */
void func_021D91E4(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == func_021D775C(3))
        func_021D76BC(0x51, 1);
}

int *func_021D91FC(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0618;
}

int *func_021D9208(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F0880;
}

void func_021D9214(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    func_021D928C(server, pokeId, work, 0x1);
}

void func_021D9224(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    func_021D92CC(server, pokeId, work, 0xc9);
}

int *func_021D9234(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F0890;
}

void func_021D9240(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    func_021D928C(server, pokeId, work, 0x6);
}

void func_021D9250(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    func_021D92CC(server, pokeId, work, 0xcf);
}

int *func_021D9260(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F08A0;
}

void func_021D926C(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    func_021D928C(server, pokeId, work, 0x8);
}

void func_021D927C(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    func_021D92CC(server, pokeId, work, 0xc6);
}

/* Indirect damage guard: when the owner takes damage of cause 8 or blockedCause, cancel it and arm the work flag. */
void func_021D928C(void *server, int pokeId, int *work, int blockedCause)
{
    if (pokeId == func_021D775C(2) && pokeId != func_021D775C(3)) {
        if (blockedCause == 8 || blockedCause == func_021D775C(0x1f)) {
            if (func_021D775C(0x20) < 0)
                work[0] = func_021D76BC(0x41, 1);
        }
    }
}

/* Shows the guard message once; work[0] is the armed flag, work[1] the weather of the last message. */
void func_021D92CC(void *server, int pokeId, int *work, int stringId)
{
    int weather;
    u8 *cmd;

    if (pokeId == func_021D775C(2) && work[0] != 0) {
        weather = func_021D775C(0x19);
        if (weather == 0 || work[1] != weather) {
            func_021C88B4(server, 2, pokeId);
            cmd = func_021C88A4(server, 4, pokeId);
            func_021C8838(cmd + 4, 2, stringId);
            func_021C8860((struct BtlMessage *)(cmd + 4), pokeId);
            func_021C88C8(server, cmd);
            func_021C88B4(server, 3, pokeId);
            work[1] = weather;
        }
        work[0] = 0;
    }
}

/* Halves residual damage: doubles the damage divisor of the owner. */
void func_021D9340(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == func_021D775C(2)) func_021D76BC(0x20, func_021D775C(0x20) << 1);
}

void *func_021D9360(int *handlerCount) { *handlerCount = 1; return &d_021F06B8; }

/* Leaf Guard: in sun, the defender cannot get a major status condition or the condition 0xe. */
void func_021D936C(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    int condition;
    if (pokeId == func_021D775C(4) && func_021C8288(server) == 1) {
        condition = func_021D775C(0x1d);
        if (func_021D7D6C(condition) || condition == 0xe) *work = func_021D76BC(0x41, 1);
    }
}

/* Leaf Guard: in sun, cancels the event for the owner. */
void func_021D93A8(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == func_021D775C(2) && func_021C8288(server) == 1) func_021D76BC(0x41, 1);
}

void *func_021D93CC(int *handlerCount) { *handlerCount = 3; return &d_021F0A40; }
