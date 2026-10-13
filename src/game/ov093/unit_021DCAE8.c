/*
 * file:     unit_021DCAE8.c
 * unit:     yes
 * function: func_021DCAE8, func_021DCB2C, func_021DCB38, func_021DCBD0, func_021DCBDC, func_021DCBE8, func_021DCC04, func_021DCC10, func_021DCC2C, func_021DCC5C, func_021DCC80, func_021DCCEC, func_021DCD20, func_021DCDB8, func_021DCDC4, func_021DCDD0, func_021DCDF8, func_021DCE18, func_021DCE48, func_021DCE90, func_021DCE9C, func_021DCEC4, func_021DCF24, func_021DCF5C, func_021DCF78, func_021DCF9C, func_021DCFA4, func_021DCFB4, func_021DCFD0, func_021DCFF8, func_021DD008, func_021DD044, func_021DD05C, func_021DD068, func_021DD080, func_021DD08C, func_021DD0A4, func_021DD0B0, func_021DD0C8, func_021DD0D4, func_021DD0EC, func_021DD0F8, func_021DD110, func_021DD11C, func_021DD134, func_021DD140, func_021DD158, func_021DD19C, func_021DD1D8, func_021DD234, func_021DD240, func_021DD26C, func_021DD2A4, func_021DD2D0, func_021DD2F8, func_021DD320, func_021DD338, func_021DD368, func_021DD39C, func_021DD480, func_021DD4B0, func_021DD4E0, func_021DD514, func_021DD570, func_021DD57C
 * address:  0x021DCAE8
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
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021E8804  0x021E8804  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D6740  0x021D6740  thumb  ov093
 *   PALANM_IsColorCodeKnown  0x020213C0  thumb
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F0AD0     0x021F0AD0  data   ov093  a4
 *   d_021F05E0 0x021F05E0 data a4
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F0708 0x021F0708 data a4
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021B9A5C  0x021B9A5C  thumb  ov093
 *   func_021D7320  0x021D7320  thumb  ov093
 *   func_021D70AC 0x021D70AC thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   d_021F0AE8 0x021F0AE8 data a4
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021B8C5C  0x021B8C5C  thumb  ov093
 *   func_021C8020  0x021C8020  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   d_021F0728     0x021F0728  data   ov093  a4
 *   d_021F0680     0x021F0680  data   ov093  a4
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   d_021F0750     0x021F0750  data   ov093  a4
 *   d_021F0B60     0x021F0B60  data   ov093  a4
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6F0C  0x021D6F0C  thumb  ov093
 *   d_021F1EA4     0x021F1EA4  data  ov093
 *   func_021D732C  0x021D732C  thumb  ov093
 *   func_021D7360  0x021D7360  thumb  ov093
 *   func_021D70B4  0x021D70B4  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 *   func_021D70BC 0x021D70BC thumb ov093
 *   func_021D70DC 0x021D70DC thumb ov093
 *   func_021D7404 0x021D7404 thumb ov093
 *   func_021D7438 0x021D7438 thumb ov093
 *   func_021D7AF0 0x021D7AF0 thumb ov093
 *   func_021C82B8 0x021C82B8 thumb ov093
 *   func_021D805C   0x021D805C  thumb
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021D70C8 0x021D70C8 thumb ov093
 *   d_021F1AC4 0x021F1AC4 data a4
 *   d_021F1AEC 0x021F1AEC data a4
 *   d_021F1DE4 0x021F1DE4 data a4
 *   d_021F1B14 0x021F1B14 data a4
 *   d_021F1B3C 0x021F1B3C data a4
 *   d_021F1B64 0x021F1B64 data a4
 *   d_021F1B8C 0x021F1B8C data a4
 *   func_021D778C  0x021D778C  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D7E10  0x021D7E10  thumb  ov093
 *   d_021F0760     0x021F0760  data   ov093  a4
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D554C 0x021D554C thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   d_021F1BB4 0x021F1BB4 data a4
 *   func_021DDE30 0x021DDE30 thumb ov093
 *   func_021DDEA4 0x021DDEA4 thumb ov093
 *   d_021F1E6C     0x021F1E6C  data   ov093  a4
 *   d_021F1AA4     0x021F1AA4  data   ov093  a4
 *   d_021F1BDC     0x021F1BDC  data   ov093  a4
 */
#include "unit_021DCAE8_types.h"

/* Handler tables defined in the overlay data, one per ability or item. */
extern const BtlEventHandlerEntry d_021F0AD0[];
extern const BtlEventHandlerEntry d_021F05E0[];
extern const BtlEventHandlerEntry d_021F0708[];
extern const BtlEventHandlerEntry d_021F0AE8[];
extern const BtlEventHandlerEntry d_021F0728[];
extern const BtlEventHandlerEntry d_021F0680[];
extern const BtlEventHandlerEntry d_021F0750[];
extern const BtlEventHandlerEntry d_021F0B60[];
extern const BtlEventHandlerEntry d_021F0760[];
extern const BtlEventHandlerEntry d_021F1AC4[];
extern const BtlEventHandlerEntry d_021F1AEC[];
extern const BtlEventHandlerEntry d_021F1DE4[];
extern const BtlEventHandlerEntry d_021F1B14[];
extern const BtlEventHandlerEntry d_021F1B3C[];
extern const BtlEventHandlerEntry d_021F1B64[];
extern const BtlEventHandlerEntry d_021F1B8C[];
extern const BtlEventHandlerEntry d_021F1E6C[];
extern const BtlEventHandlerEntry d_021F1BB4[];
extern const BtlEventHandlerEntry d_021F1AA4[];
extern const BtlEventHandlerEntry d_021F1BDC[];
extern ItemHandlerEntry d_021F1EA4[ITEM_HANDLER_COUNT];

/* Abilities */
void func_021DCAE8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work);
const BtlEventHandlerEntry *func_021DCB2C(int *count);
void func_021DCB38(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *func_021DCBD0(int *count);
const BtlEventHandlerEntry *func_021DCBDC(int *count);
void func_021DCBE8(int factor, int flow, int pokeId);
const BtlEventHandlerEntry *func_021DCC04(int *count);
void func_021DCC10(int factor, int flow, int pokeId);
void func_021DCC2C(int factor, int flow, int pokeId, int *work);
const BtlEventHandlerEntry *func_021DCC50(int *count);
void func_021DCC5C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, UnnerveWork *work);
void func_021DCC80(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, UnnerveWork *work);
int func_021DCCEC(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId);
const BtlEventHandlerEntry *func_021DCD14(int *count);
void func_021DCD20(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *func_021DCDB8(int *count);
const BtlEventHandlerEntry *func_021DCDC4(int *count);
void func_021DCDD0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DCDF8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DCE18(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DCE48(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *func_021DCE90(int *count);
void func_021DCE9C(int factor, int flow, unsigned int pokeId);

/* Held items */
struct BtlEventFactor *func_021DCEC4(struct BtlPokeParam *poke, u32 itemId);
void func_021DCF24(struct BtlPokeParam *poke);
struct BtlEventFactor *func_021DCF5C(struct BtlPokeParam *poke);
struct BtlEventFactor *func_021DCF78(struct BtlPokeParam *poke, unsigned int itemId);
void func_021DCF9C(struct BtlEventFactor *factor);
void func_021DCFA4(struct BtlPokeParam *poke);
void func_021DCFB4(struct BtlPokeParam *poke);
int func_021DCFD0(struct BtlSvFlow *flow, unsigned int percent);
int func_021DCFF8(struct BtlEventFactor *factor, int paramIndex);
int func_021DD008(struct BtlEventFactor *factor);
void func_021DD044(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD05C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD068(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *func_021DD074(int *count);
void func_021DD080(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD08C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *func_021DD098(int *count);
void func_021DD0A4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD0B0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *func_021DD0BC(int *count);
void func_021DD0C8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD0D4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *func_021DD0E0(int *count);
void func_021DD0EC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD0F8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *func_021DD104(int *count);
void func_021DD110(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD11C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *func_021DD128(int *count);
void func_021DD134(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD140(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *func_021DD14C(int *count);
void func_021DD158(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int sickKind);
void func_021DD19C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int sickKind);
int func_021DD1D8(struct BtlSvFlow *flow, int pokeId, int sickKind);
const BtlEventHandlerEntry *func_021DD234(int *count);
void func_021DD240(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD26C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD2A4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD2D0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD2F8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, int *work);
void func_021DD320(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, int *work);
u8 func_021DD338(struct BtlSvFlow *flow, int pokeId);
u8 func_021DD368(struct BtlSvFlow *flow, int pokeId);
int func_021DD39C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, int *work, int allowAnyLostSlot);
const BtlEventHandlerEntry *func_021DD474(int *count);
void func_021DD480(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD4B0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD4E0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DD514(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *func_021DD570(int *count);
const BtlEventHandlerEntry *func_021DD57C(int *count);

/* Magic Bounce: reflect the incoming move and show the ability window. */
void func_021DCAE8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && func_021D76BC(BTL_EVAR_HANDLED_FLAG, 1) != 0) {
        func_021C88B4(flow, HANDEX_KIND_ABILITY_WINDOW_IN, pokeId);
        func_021E8804(factor, flow, pokeId, work);
        func_021C88B4(flow, HANDEX_KIND_ABILITY_WINDOW_OUT, pokeId);
    }
}

const BtlEventHandlerEntry *func_021DCB2C(int *count)
{
    *count = 3;
    return d_021F0AD0;
}

/* Harvest: give back the consumed Berry when the Pokemon holds nothing (always in sun, else 50%). */
void func_021DCB38(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExSetItem *rec;
    struct BtlPokeParam *poke;
    u32 itemId;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        poke = func_021C7CF4(flow, pokeId);
        itemId = func_021D6740(poke);
        if (itemId != 0 && PALANM_IsColorCodeKnown(itemId) != 0 && func_021D5B40(poke) == 0
            && (func_021C8288(flow) == BTL_WEATHER_SUN || func_021D85C0(flow, 50) != 0)) {
            rec = func_021C88A4(flow, HANDEX_KIND_SET_ITEM, pokeId);
            rec->header |= HANDEX_FLAG_SHOW_ABILITY;
            rec->itemId = itemId;
            rec->pokeId = pokeId;
            rec->announce = 1;
            func_021C8838(&rec->str, HANDEX_STR_SET, 0x1db);
            func_021C8860(&rec->str, pokeId);
            func_021C8860(&rec->str, itemId);
            func_021C88C8(flow, rec);
        }
    }
}

const BtlEventHandlerEntry *func_021DCBD0(int *count)
{
    *count = 1;
    return d_021F0728;
}

const BtlEventHandlerEntry *func_021DCBDC(int *count)
{
    *count = 1;
    return d_021F0680;
}

/* Heavy Metal: double the weight. */
void func_021DCBE8(int factor, int flow, int pokeId) { if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_DOUBLE); }

const BtlEventHandlerEntry *func_021DCC04(int *count) { *count = 1; return d_021F05E0; }

/*
 * Light Metal: halve the weight.
 * extent: trailing two-byte zero alignment at 021DCC2A.
 */
void func_021DCC10(int factor, int flow, int pokeId) { if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_HALF); }

/* Contrary: invert the stat change. */
void func_021DCC2C(int factor, int flow, int pokeId, int *work) { if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) *work = func_021D76BC(BTL_EVAR_VOLUME,-func_021D775C(BTL_EVAR_VOLUME)); }

const BtlEventHandlerEntry *func_021DCC50(int *count) { *count = 1; return d_021F0708; }

/* Unnerve, when its owner enters. */
void func_021DCC5C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, UnnerveWork *work) { if(pokeId==func_021D775C(BTL_EVAR_POKE_ID)) func_021DCC80(factor,flow,pokeId,work); }

/* Unnerve: show the ability window once and install the Berry skip check. */
void func_021DCC80(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, UnnerveWork *work)
{
    HandExMessage *rec;
    u32 side;

    if (work->announced == 0) {
        side = func_021B9A5C(func_021B9A40(pokeId));
        func_021C88B4(flow, HANDEX_KIND_ABILITY_WINDOW_IN, pokeId);
        rec = func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
        func_021C8838(&rec->str, HANDEX_STR_STANDARD, 0xb0);
        func_021C8860(&rec->str, side);
        func_021C88C8(flow, rec);
        func_021C88B4(flow, HANDEX_KIND_ABILITY_WINDOW_OUT, pokeId);
        func_021D7320(factor, func_021DCCEC);
        work->announced = 1;
    }
}

/*
 * Unnerve skip check: a Berry held by a Pokemon of the other side is skipped.
 * extent: callback followed by store-and-return leaf at 021DCD14.
 * stack: the last two arguments sit in stack slots; the body reads the
 * halfword at +0 and the byte at +4 using a common stack base.
 */
int func_021DCCEC(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId)
{
    if(targetFactorType==BTL_EVENT_TYPE_ITEM) {
        if(!func_021B9A24(func_021D70AC(factor),targetOwnerId)) {
            if(PALANM_IsColorCodeKnown(targetKey)) return 1;
        }
    }
    return 0;
}

const BtlEventHandlerEntry *func_021DCD14(int *count) { *count=3; return d_021F0AE8; }

/* Imposter: transform into the Pokemon facing the owner, unless one of the two has fainted. */
void func_021DCD20(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExTransform *rec;
    struct BtlPokeParam *targetPoke;
    int targetId;
    int position;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        position = func_021C8010(flow, pokeId);
        targetId = func_021C8020(flow, func_021B8C5C(func_021C815C(flow), position));
        targetPoke = func_021C7CF4(flow, targetId);
        if (func_021D5B68(func_021C7CF4(flow, pokeId)) == 0 && func_021D5B68(targetPoke) == 0) {
            rec = func_021C88A4(flow, HANDEX_KIND_TRANSFORM, pokeId);
            rec->header |= HANDEX_FLAG_SHOW_ABILITY;
            rec->targetPokeId = targetId;
            func_021C8838(&rec->str, HANDEX_STR_SET, 0x284);
            func_021C8860(&rec->str, pokeId);
            func_021C8860(&rec->str, rec->targetPokeId);
            func_021C88C8(flow, rec);
        }
    }
}

const BtlEventHandlerEntry *func_021DCDB8(int *count)
{
    *count = 1;
    return d_021F0750;
}

const BtlEventHandlerEntry *func_021DCDC4(int *count)
{
    *count = 3;
    return d_021F0B60;
}

/* Illusion: the disguise ends when the owner is hit (not through a substitute). */
void func_021DCDD0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { if(pokeId==func_021D775C(BTL_EVAR_DEFENDER_ID) && func_021D775C(BTL_EVAR_HIT_SUBSTITUTE)==0) func_021DCE48(factor,flow,pokeId); }

/* Illusion: the disguise ends on another event about the owner. */
void func_021DCDF8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { if(pokeId==func_021D775C(BTL_EVAR_POKE_ID)) func_021DCE48(factor,flow,pokeId); }

/* Illusion: the disguise ends when the owner's ability changes to another ability. */
void func_021DCE18(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { int newAbilityId; newAbilityId=func_021D775C(BTL_EVAR_NEW_ABILITY_ID); if(newAbilityId!=func_021D70A8(factor) && pokeId==func_021D775C(BTL_EVAR_POKE_ID)) func_021DCE48(factor,flow,pokeId); }

/* Illusion: drop the disguise when it is active. */
void func_021DCE48(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExEndIllusion *rec;
    if (func_021D6C24(func_021C7CF4(flow, pokeId))) {
        rec = func_021C88A4(flow, HANDEX_KIND_END_ILLUSION, pokeId);
        rec->pokeId = pokeId;
        func_021C8838(&rec->str, HANDEX_STR_SET, 478);
        func_021C8860(&rec->str, pokeId);
        func_021C88C8(flow, rec);
    }
}

const BtlEventHandlerEntry *func_021DCE90(int *count)
{
    *count = 1;
    return d_021F0760;
}

/*
 * Victory Star: raise the accuracy of the owner's side by 10%.
 * lever: u8 result local reproduces 021DCEA6/021DCEA8 truncation in r0,
 * then shift-copy to r1; inline narrowing produced an extra register copy.
 */
void func_021DCE9C(int factor, int flow, unsigned int pokeId) { unsigned char attackerId; attackerId=func_021D775C(BTL_EVAR_ATTACKER_ID); if(func_021B9A24(pokeId,attackerId)) func_021D7704(BTL_EVAR_RATIO,BTL_RATIO_ACCURACY_BOOST); }

/* Add the event factor of an item to the factor list; 0 if the item has no handler. */
struct BtlEventFactor *func_021DCEC4(struct BtlPokeParam *poke, u32 itemId)
{
    u32 i;
    u16 speed;
    u8 ownerId;
    u32 handlerTable;
    u32 handlerCount;

    for (i = 0; i < ITEM_HANDLER_COUNT; i++) {
        if (itemId == d_021F1EA4[i].itemId) {
            speed = func_021D58A8(poke, 0xc);
            ownerId = func_021D5440(poke);
            handlerTable = d_021F1EA4[i].getHandlers(&handlerCount);
            return func_021D6F0C(BTL_EVENT_TYPE_ITEM, itemId, 6, speed, ownerId, handlerTable, handlerCount);
        }
    }
    return 0;
}

/* Remove the item factors of a Pokemon, except those that were added from outside. */
void func_021DCF24(struct BtlPokeParam *poke)
{
    struct BtlEventFactor *factor = func_021D732C(BTL_EVENT_TYPE_ITEM, func_021D5440(poke));
    while (factor != 0) {
        struct BtlEventFactor *next = func_021D7360(factor);
        if (func_021D70B4(factor, ITEM_WORK_FORCED_USE) == 0)
            func_021D7040(factor);
        factor = next;
    }
}

/*
 * Add the factor of the held item.
 * interface: 021D5B40's u16 field result is kept as a full register value
 * until the explicit halfword truncation at 021DCF68/021DCF6C; the caller
 * therefore uses a wide result and a u16 021DCEC4 argument, as the listing shows.
 */
struct BtlEventFactor *func_021DCF5C(struct BtlPokeParam *poke) { int heldItem; heldItem=func_021D5B40(poke); if(heldItem) return func_021DCEC4(poke,(unsigned short)heldItem); return 0; }

/* Add the factor of an item from outside (not held) and mark it as forced. */
struct BtlEventFactor *func_021DCF78(struct BtlPokeParam *poke, unsigned int itemId) { struct BtlEventFactor *factor; if(itemId) { factor=func_021DCEC4(poke,itemId); if(factor) { func_021D70BC(factor); func_021D70DC(factor,ITEM_WORK_FORCED_USE,1); return factor; } } return 0; }

/*
 * Remove one item factor.
 * tail-call thunk to func_021D7040
 */
void func_021DCF9C(struct BtlEventFactor *factor)
{
    func_021D7040(factor);
}

/* Switch off the item factors of a Pokemon. */
void func_021DCFA4(struct BtlPokeParam *poke) { func_021D7404(func_021D5440(poke),BTL_EVENT_TYPE_ITEM); }

/* Switch the item factors of a Pokemon on again; add the held item's factor when there is none. */
void func_021DCFB4(struct BtlPokeParam *poke) { if(!func_021D7438(func_021D5440(poke),BTL_EVENT_TYPE_ITEM)) func_021DCF5C(poke); }

/*
 * An item chance succeeds when the percent roll passes or the battle rule says so.
 * interface: 021C82B8 forwards r1=2 unchanged to 021B911C; r0 is consumed
 * after the call at 021DCFEA, requiring a result despite its legacy void extern.
 */
int func_021DCFD0(struct BtlSvFlow *flow, unsigned int percent) { if(func_021D7AF0(percent)) return 1; if(func_021C82B8(flow,2)) return 1; return 0; }

/*
 * Parameter of the item behind an event factor.
 * 021DCFF8  pass-through: second callee takes the first one's result
 * Leaf with no calls and no pool; 6 instructions, 16 bytes: push {r4, lr}; adds r4, r1, #0; bl func_021D70A8; adds r1, r4, #0; bl func_021D805C; pop {r4, pc}.
 */
int func_021DCFF8(struct BtlEventFactor *factor, int paramIndex)
{
    return func_021D805C(func_021D70A8(factor), paramIndex);
}

/* Boost ratio (4096 = 1.0) of an item whose parameter 2 is a percent bonus. */
int func_021DD008(struct BtlEventFactor *factor) { int percent; float ratio; percent=func_021DCFF8(factor,2)+100; if(percent>0) ratio=0.5f+(float)(percent<<12); else ratio=(float)(percent<<12)-0.5f; return (int)ratio/100; }

/* Mark the item as used and ask the flow to show it. */
void func_021DD044(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021D70C8(factor);
    func_021C88B4(flow, HANDEX_KIND_USE_ITEM, pokeId);
}

/* Cheri Berry (cures paralysis). */
void func_021DD05C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD158(factor, flow, pokeId, BTL_SICK_PARALYSIS);
}

void func_021DD068(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD19C(factor, flow, pokeId, BTL_SICK_PARALYSIS);
}

const BtlEventHandlerEntry *func_021DD074(int *count)
{
    *count = 5;
    return d_021F1AC4;
}

/* Chesto Berry (cures sleep). */
void func_021DD080(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD158(factor, flow, pokeId, BTL_SICK_SLEEP);
}

void func_021DD08C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD19C(factor, flow, pokeId, BTL_SICK_SLEEP);
}

const BtlEventHandlerEntry *func_021DD098(int *count)
{
    *count = 5;
    return d_021F1AEC;
}

/* Rawst Berry (cures burn). */
void func_021DD0A4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD158(factor, flow, pokeId, BTL_SICK_BURN);
}

void func_021DD0B0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD19C(factor, flow, pokeId, BTL_SICK_BURN);
}

const BtlEventHandlerEntry *func_021DD0BC(int *count)
{
    *count = 5;
    return d_021F1DE4;
}

/* Aspear Berry (cures freeze). */
void func_021DD0C8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD158(factor, flow, pokeId, BTL_SICK_FREEZE);
}

void func_021DD0D4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD19C(factor, flow, pokeId, BTL_SICK_FREEZE);
}

const BtlEventHandlerEntry *func_021DD0E0(int *count)
{
    *count = 5;
    return d_021F1B14;
}

/* Persim Berry (cures confusion). */
void func_021DD0EC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD158(factor, flow, pokeId, BTL_SICK_CONFUSION);
}

void func_021DD0F8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD19C(factor, flow, pokeId, BTL_SICK_CONFUSION);
}

const BtlEventHandlerEntry *func_021DD104(int *count)
{
    *count = 5;
    return d_021F1B3C;
}

/* Pecha Berry (cures poison). */
void func_021DD110(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD158(factor, flow, pokeId, BTL_SICK_POISON);
}

void func_021DD11C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD19C(factor, flow, pokeId, BTL_SICK_POISON);
}

const BtlEventHandlerEntry *func_021DD128(int *count)
{
    *count = 5;
    return d_021F1B64;
}

/* Lum Berry (cures any status). */
void func_021DD134(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD158(factor, flow, pokeId, BTL_SICK_ANY);
}

void func_021DD140(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DD19C(factor, flow, pokeId, BTL_SICK_ANY);
}

const BtlEventHandlerEntry *func_021DD14C(int *count)
{
    *count = 5;
    return d_021F1B8C;
}

/* Status berry used on its own: cure the status when the trigger kind allows it. */
void func_021DD158(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int sickKind)
{
    int triggerKind;
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (func_021D778C(BTL_EVAR_TRIGGER_KIND, &triggerKind) == 0 || triggerKind == 3 || triggerKind == 0) {
            if (func_021DD1D8(flow, pokeId, sickKind) != 0)
                func_021DD044(factor, flow, pokeId);
        }
    }
}

/* Status berry eaten through another move: cure the status. */
void func_021DD19C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int sickKind)
{
    HandExCureSick *rec;
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && func_021DD1D8(flow, pokeId, sickKind)) {
        rec = func_021C88A4(flow, HANDEX_KIND_CURE_SICK, pokeId);
        rec->sickKind = sickKind;
        rec->pokeCount = 1;
        rec->pokeIds[0] = pokeId;
        func_021C88C8(flow, rec);
    }
}

/* Does the Pokemon have the status condition that the berry cures? */
int func_021DD1D8(struct BtlSvFlow *flow, int pokeId, int sickKind)
{
    struct BtlPokeParam *poke = func_021C7CF4(flow, pokeId);
    switch (sickKind) {
    case BTL_SICK_ANY:
        if (func_021D62A8(poke) == 0 && func_021D62C4(poke, BTL_SICK_CONFUSION) == 0)
            break;
        return 1;
    case BTL_SICK_ANY_MAJOR:
        if (func_021D62A8(poke) != 0)
            return 1;
        return 0;
    case BTL_SICK_ANY_VOLATILE:
        if (func_021D7E10(poke) != 0)
            return 1;
        return 0;
    default:
        return func_021D62C4(poke, sickKind);
    }
    return 0;
}

const BtlEventHandlerEntry *func_021DD234(int *count)
{
    *count = 7;
    return d_021F1E6C;
}

/* Leppa Berry: use it when the last used move is out of PP. */
void func_021DD240(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (func_021DD338(flow, pokeId) != BTL_MOVE_SLOT_NONE)
            func_021DD044(factor, flow, pokeId);
    }
}

/* Leppa Berry: use it when any move is out of PP (checked for the trigger kinds 0 and 2). */
void func_021DD26C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int triggerKind;
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        triggerKind = func_021D775C(BTL_EVAR_TRIGGER_KIND);
        if (triggerKind != 2 && triggerKind != 0) return;
        if (func_021DD368(flow, pokeId) != BTL_MOVE_SLOT_NONE)
            func_021DD044(factor, flow, pokeId);
    }
}

/* Leppa Berry: use it when any move is out of PP. */
void func_021DD2A4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (func_021DD368(flow, pokeId) != BTL_MOVE_SLOT_NONE)
            func_021DD044(factor, flow, pokeId);
    }
}

/* Leppa Berry: claim the trigger when the last used move is out of PP. */
void func_021DD2D0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && func_021DD338(flow, pokeId) != BTL_MOVE_SLOT_NONE)
        func_021D76BC(BTL_EVAR_HANDLED_FLAG, 1);
}

/*
 * Leppa Berry eaten through another move: restore the PP of an empty move.
 * extent: trailing two-byte alignment padding.
 * prototype: third DD39C input widened to full register width; no truncation at call.
 */
void func_021DD2F8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, int *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) func_021DD39C(factor, flow, pokeId, work, 0);
}

/*
 * Leppa Berry used from outside: restore the PP of an empty move, or of a move that lost PP.
 * extent: trailing two-byte alignment padding.
 */
void func_021DD320(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) func_021DD39C(factor, flow, pokeId, work, 1);
}

/*
 * Slot of the last used move when it is out of PP, else the none value.
 * extent: trailing two-byte alignment padding.
 * prototype: C7CF4 result used and r1 supplied; 5584 index is the u8 return of 5778.
 */
u8 func_021DD338(struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *poke;
    u8 slot;
    poke = func_021C7CF4(flow, pokeId);
    slot = func_021D5778(poke, func_021D67B8(poke));
    if (slot != BTL_MOVE_SLOT_NONE && func_021D5584(poke, slot) == 0) return slot;
    return BTL_MOVE_SLOT_NONE;
}

/* First move slot that is out of PP, else the none value. */
u8 func_021DD368(struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *poke;
    u32 moveCount, i;
    poke = func_021C7CF4(flow, pokeId);
    moveCount = func_021D5448(poke);
    for (i = 0; i < moveCount; i++) {
        if (func_021D5584(poke, (u8)i) == 0) return (u8)i;
    }
    return BTL_MOVE_SLOT_NONE;
}

/* Restore 10 PP of an empty move slot (with allowAnyLostSlot, of any move that lost PP). */
int func_021DD39C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, int *work, int allowAnyLostSlot)
{
    struct BtlPokeParam *poke;
    u32 i;
    u32 moveCount;
    u8 slot;
    HandExRecoverPp *rec;
    poke = func_021C7CF4(flow, pokeId);
    slot = func_021DD338(flow, pokeId);
    if (slot == BTL_MOVE_SLOT_NONE) {
        slot = func_021DD368(flow, pokeId);
        if (slot == BTL_MOVE_SLOT_NONE && allowAnyLostSlot) {
            moveCount = func_021D5448(poke);
            for (i = 0; i < moveCount; i++) {
                if (func_021D554C(poke, i)) {
                    slot = i;
                    break;
                }
            }
        }
    }
    if (slot != BTL_MOVE_SLOT_NONE) {
        rec = func_021C88A4(flow, HANDEX_KIND_RECOVER_PP, pokeId);
        rec->volume = 10;
        rec->pokeId = pokeId;
        rec->moveSlot = slot;
        rec->showItem = 1;
        func_021C8838(&rec->str, HANDEX_STR_SET, 0x38f);
        func_021C8860(&rec->str, pokeId);
        func_021C8860(&rec->str, func_021D70A8(factor));
        func_021C8860(&rec->str, func_021D54C0(poke, slot));
        func_021C88C8(flow, rec);
        return 1;
    }
    return 0;
}

const BtlEventHandlerEntry *func_021DD474(int *count) { *count = 5; return d_021F1BB4; }

/* HP-restoring berries (Oran, Berry Juice, Sitrus): use the item when HP is low, unless Heal Block applies. */
void func_021DD480(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (func_021D62C4(func_021C7CF4(flow, pokeId), 15) == 0)
        func_021DDE30(factor, flow, pokeId, 2, 1);
}

void func_021DD4B0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (func_021D62C4(func_021C7CF4(flow, pokeId), 15) == 0)
        func_021DDE30(factor, flow, pokeId, 2, 0);
}

void func_021DD4E0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (func_021D62C4(func_021C7CF4(flow, pokeId), 15) == 0 && func_021DDEA4(flow, pokeId, 2) != 0)
        func_021DD044(factor, flow, pokeId);
}

/* Fixed-amount HP berry eaten through another move: restore the amount from the item parameter. */
void func_021DD514(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExRecoverHp *rec;
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        rec = func_021C88A4(flow, HANDEX_KIND_RECOVER_HP, pokeId);
        rec->pokeId = pokeId;
        rec->amount = func_021DCFF8(factor, 2);
        func_021C8838(&rec->str, HANDEX_STR_SET, 908);
        func_021C8860(&rec->str, pokeId);
        func_021C8860(&rec->str, func_021D70A8(factor));
        func_021C88C8(flow, rec);
    }
}

const BtlEventHandlerEntry *func_021DD570(int *count)
{
    *count = 4;
    return d_021F1AA4;
}

const BtlEventHandlerEntry *func_021DD57C(int *count)
{
    *count = 5;
    return d_021F1BDC;
}
