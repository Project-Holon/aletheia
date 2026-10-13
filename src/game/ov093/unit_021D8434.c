/*
 * file:     unit_021D8434.c
 * unit:     yes
 * function: func_021D8434, func_021D8444, func_021D8454, func_021D845C, func_021D8470, func_021D8484, func_021D84F0, func_021D84F8, func_021D8510, func_021D8538, func_021D8548, func_021D8564, func_021D85B0, func_021D85C0, func_021D85F4, func_021D8678
 * address:  0x021D8434
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
 *   d_021F0710     0x021F0710  data   ov093  a4
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6F0C  0x021D6F0C  thumb  ov093
 *   d_021F0E74     0x021F0E74  data  ov093
 *   func_021D732C 0x021D732C thumb ov093
 *   func_021D7040 0x021D7040 thumb ov093
 *   func_021D7404 0x021D7404 thumb ov093
 *   func_021D7438 0x021D7438 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   d_021F08C0 0x021F08C0 data ov093 a4
 *   func_021D7AF0 0x021D7AF0 thumb ov093
 *   func_021C82B8 0x021C82B8 thumb ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C8120  0x021C8120  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "unit_021D8434_types.h"

typedef enum { MASK=15 } Mask;

struct BtlEventFactor *func_021D6F0C(int factorType, u32 key, int priority, u32 subPriority, u8 ownerId, u32 handlers, u16 handlerCount);
extern struct BtlEventFactor *func_021D732C(int factorType, int pokeId);
extern void func_021D7040(struct BtlEventFactor *factor);
extern void func_021D7404(u32 pokeId, int factorType);
extern int func_021D7438(int pokeId, int factorType);
int func_021C82B8(struct BtlSvFlow *flow, int flagId);
int func_021C7D00(struct BtlSvFlow *flow, int pokeId);
u8 *func_021C8120(struct BtlSvFlow *flow, int bufferId);
u8 func_021C7F68(struct BtlSvFlow *flow, int posKey, u8 *out);
void func_021C88B4(struct BtlSvFlow *flow, int kind, int pokeId);

void func_021D8434(u32 *action);
void func_021D8444(u32 *action);
unsigned int func_021D8454(BtlActionWord *action);
void func_021D845C(u32 *action);
void func_021D8470(u32 *action);
struct BtlEventFactor *func_021D8484(struct BtlPokeParam *bpp);
unsigned int func_021D84F0(unsigned int priority, unsigned int handlerCount);
int func_021D84F8(u32 *packedInfo);
void func_021D8510(struct BtlPokeParam *bpp);
void func_021D8538(struct BtlPokeParam *bpp);
void func_021D8548(struct BtlPokeParam *bpp);
void func_021D8564(struct BtlPokeParam *bppA, struct BtlPokeParam *bppB);
u16 func_021D85B0(struct BtlPokeParam *bpp);
int func_021D85C0(struct BtlSvFlow *flow, u32 percent);
u8 *func_021D85E8(u32 *packedInfo);
void func_021D85F4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021D8678(int *packedInfo);
extern AbilityHandlerEntry d_021F0E74[ABILITY_REGISTRY_COUNT];
extern u8 d_021F08C0[];
extern int d_021F0710[];

/*
 * The setters below write only the kind nibble of an action word.
 * stand-in: ActionSetNone clears the nibble and then masks with an enum
 * constant (a clear and a mask that contradict each other); the mask-first
 * order in the last AND selects the original register.
 */
void func_021D8434(u32 *action) { Mask mask=MASK; *action=mask & (*action & ~15); }

void func_021D8444(u32 *action) { *action = (*action & ~15) | BTL_ACTION_FORCED_SKIP; }


unsigned int func_021D8454(BtlActionWord *action)
{
    return action->kind;
}

void func_021D845C(u32 *action) { *action = ((*action & ~15) | BTL_ACTION_RECORD_RESET) & 15; }

void func_021D8470(u32 *action) { *action = ((*action & ~15) | BTL_ACTION_RECORD_ERROR) & 15; }


/* Adds the handler table of the ability that the poke holds to the event factor list. */
struct BtlEventFactor *func_021D8484(struct BtlPokeParam *bpp)
{
    u16 abilityId = func_021D59B4(bpp, 0x10);
    u32 i;
    u32 speed;
    u8 pokeId;
    int priority;
    u32 handlerCount;
    u32 handlers;

    for (i = 0; i < ABILITY_REGISTRY_COUNT; i++) {
        if (abilityId == d_021F0E74[i].abilityId) {
            speed = func_021D85B0(bpp);
            pokeId = func_021D5440(bpp);
            handlers = d_021F0E74[i].getHandlers(&handlerCount);
            priority = func_021D84F8(&handlerCount);
            return func_021D6F0C(BTL_EVENT_TYPE_ABILITY, abilityId, priority, speed, pokeId, handlers, handlerCount);
        }
    }
    return 0;
}

/* Packs the factor priority into the high half and the handler count into the low half. */
unsigned int func_021D84F0(unsigned int priority, unsigned int handlerCount)
{
    return (priority << 16) | handlerCount;
}

/* Splits the packed info: leaves the handler count in place and returns the priority (5 when none is packed). */
int func_021D84F8(u32 *packedInfo) { u16 priority = *packedInfo >> 16; if (priority == 0) priority = ABILITY_DEFAULT_PRIORITY; *packedInfo &= 65535; return priority; }

void func_021D8510(struct BtlPokeParam *bpp) { int pokeId = func_021D5440(bpp); struct BtlEventFactor *factor; while ((factor=func_021D732C(BTL_EVENT_TYPE_ABILITY,pokeId)) != 0) { func_021D7040(factor); } }

void func_021D8538(struct BtlPokeParam *bpp) { func_021D7404(func_021D5440(bpp),BTL_EVENT_TYPE_ABILITY); }

void func_021D8548(struct BtlPokeParam *bpp) { if (!func_021D7438(func_021D5440(bpp),BTL_EVENT_TYPE_ABILITY)) func_021D8484(bpp); }


/* Swaps the abilities of two pokes: removes both handler sets, then adds both again. */
void func_021D8564(struct BtlPokeParam *bppA, struct BtlPokeParam *bppB)
{
    int pokeIdA = func_021D5440(bppA);
    int pokeIdB = func_021D5440(bppB);
    struct BtlEventFactor *factorA = func_021D732C(BTL_EVENT_TYPE_ABILITY, pokeIdA);
    struct BtlEventFactor *factorB = func_021D732C(BTL_EVENT_TYPE_ABILITY, pokeIdB);

    if (factorA != 0)
        func_021D7040(factorA);
    if (factorB != 0)
        func_021D7040(factorB);
    func_021D8484(bppA);
    func_021D8484(bppB);
}

u16 func_021D85B0(struct BtlPokeParam *bpp) { return func_021D58A8(bpp,12); }

/* True after a percent roll succeeds, or when the flow flag 1 is set. */
int func_021D85C0(struct BtlSvFlow *flow, u32 percent) { int result; if (func_021D7AF0(percent)) return 1; result=func_021C82B8(flow,1)!=0; return result; }

u8 *func_021D85E8(u32 *packedInfo) { *packedInfo=2; return d_021F08C0; }


/* Intimidate: lowers the attack of every opposing poke when the owner enters. */
void func_021D85F4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int pos;
    u8 *targets;
    int targetCount;
    u32 i;
    BtlRankCmd *cmd;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    pos = func_021C7D00(flow, pokeId);
    targets = func_021C8120(flow, 6);
    targetCount = func_021C7F68(flow, (u16)(pos | 0x100), targets);
    if (targetCount == 0)
        return;
    func_021C88B4(flow, 2, pokeId);
    cmd = func_021C88A4(flow, 0xe, pokeId);
    cmd->statId = 1;
    cmd->amount = -1;
    cmd->showMessage = 1;
    cmd->targetCount = targetCount;
    for (i = 0; i < (u32)targetCount; i++)
        cmd->targets[i] = targets[i];
    func_021C88C8(flow, cmd);
    func_021C88B4(flow, 3, pokeId);
}

/* Inner Focus: handler table. */
int *func_021D8678(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F0710;
}
