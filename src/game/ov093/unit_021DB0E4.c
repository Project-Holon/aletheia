/*
 * file:     unit_021DB0E4.c
 * unit:     yes
 * function: func_021DB0E4, func_021DB128, func_021DB134, func_021DB1A8, func_021DB1D4, func_021DB200, func_021DB224, func_021DB254, func_021DB274, func_021DB298, func_021DB2B8, func_021DB2C8, func_021DB2F8, func_021DB318, func_021DB374, func_021DB404, func_021DB410, func_021DB41C, func_021DB430, func_021DB460, func_021DB474, func_021DB4C4, func_021DB4E8
 * address:  0x021DB0E4
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
 *   func_0689C8EC  0x0689C8EC  thumb
 *   func_0689C9B0  0x0689C9B0  thumb
 *   func_021E889C  0x021E889C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C888C  0x021C888C  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F08B0     0x021F08B0  data   ov093  a4
 *   func_021D7320 0x021D7320 thumb ov093
 *   func_021D7324 0x021D7324 thumb ov093
 *   d_021F0C24 0x021F0C24 data a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021DA8A8 0x021DA8A8 thumb ov093
 *   func_021DA96C 0x021DA96C thumb ov093
 *   d_021F0A70 0x021F0A70 data a4
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C8290  0x021C8290  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F0DD4     0x021F0DD4  data   ov093  a4
 *   d_021F0A58     0x021F0A58  data   ov093  a4
 */
#include "unit_021DB0E4_types.h"

/* Ability handlers: Run Away, Mold Breaker (and Turboblaze, Teravolt), Forecast, Storm Drain, Lightning Rod. */

extern int func_021E889C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern int func_0689C9B0(unsigned short abilityId);
extern int func_0689C8EC(int moveId);
extern int func_021D5444(struct BtlPokeParam *bpp);
extern int func_021DA8A8(struct BtlSvFlow *flow, int pokeId, int typeId);
extern void func_021DA96C(struct BtlSvFlow *flow, int pokeId, unsigned int statId, int amount);
extern int func_021C8290(struct BtlSvFlow *flow, int attackerId, int defenderId, int moveId);

void func_021DB0E4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DB128(int *handlerCount);
void func_021DB134(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int func_021DB1A8(struct BtlEventFactor *other, struct BtlSvFlow *flow, int factorType, int eventId, unsigned short key);
void func_021DB1D4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet);
void func_021DB200(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet);
void func_021DB224(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet);
const BtlEventHandler *func_021DB248(int *handlerCount);
void func_021DB254(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive);
void func_021DB274(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive);
void func_021DB298(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive);
void func_021DB2B8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive);
void func_021DB2C8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DB2F8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DB318(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DB374(struct BtlSvFlow *flow, int pokeId, u32 weather);
const BtlEventHandler *func_021DB404(int *handlerCount);
const BtlEventHandler *func_021DB410(int *handlerCount);
void func_021DB41C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected);
void func_021DB430(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DB454(int *handlerCount);
void func_021DB460(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected);
void func_021DB474(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected);
void func_021DB4C4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int func_021DB4E8(struct BtlSvFlow *flow, int pokeId, int *work, int typeId);

extern const BtlEventHandler d_021F08B0[];
extern const BtlEventHandler d_021F0C24[];
extern const BtlEventHandler d_021F0A70[];
extern const BtlEventHandler d_021F0DD4[];
extern const BtlEventHandler d_021F0A58[];


/* Run Away: after the escape check passes, show the escape message with its sound. */
void func_021DB0E4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExMessage *msg;

    if (func_021E889C(factor, flow, pokeId) != 0) {
        msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
        msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&msg->str, 1, 0x48);
        func_021C888C(&msg->str, 0x56a);
        func_021C88C8(flow, msg);
    }
}


const BtlEventHandler *func_021DB128(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F08B0;
}


/* Mold Breaker, Turboblaze, Teravolt: when the poke enters, show the message of its own ability. */
void func_021DB134(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExMessage *msg;
    int strId;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        switch (func_021D70A8(factor)) {
        case 0xa3:
            strId = 0x1f9;
            break;
        case 0xa4:
            strId = 0x1f6;
            break;
        default:
            strId = 0x1ba;
            break;
        }
        func_021C88B4(flow, HANDEX_TOKWIN_IN, pokeId);
        msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
        func_021C8838(&msg->str, 2, strId);
        func_021C8860(&msg->str, pokeId);
        func_021C88C8(flow, msg);
        func_021C88B4(flow, HANDEX_TOKWIN_OUT, pokeId);
    }
}


/* Skip check of the holder: ability factors listed as breakable are skipped. */
int func_021DB1A8(struct BtlEventFactor *other, struct BtlSvFlow *flow, int factorType, int eventId, unsigned short key)
{
    if (factorType == BTL_EVENT_TYPE_ABILITY && func_0689C9B0(key))
        return 1;
    return 0;
}


/* Mold Breaker: when the holder attacks, install the skip check on its factor (func_021D7320 stores the pointer unchanged). */
void func_021DB1D4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && *skipCheckSet == 0) {
        func_021D7320(factor, (u32)func_021DB1A8);
        *skipCheckSet = 1;
    }
}


void func_021DB200(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && *skipCheckSet == 1) {
        func_021D7324(factor);
        *skipCheckSet = 0;
    }
}


void func_021DB224(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && *skipCheckSet == 1) {
        func_021D7324(factor);
        *skipCheckSet = 0;
    }
}


const BtlEventHandler *func_021DB248(int *handlerCount)
{
    *handlerCount = 5;
    return d_021F0C24;
}


/* Forecast: set the form of the holder from the current weather. */
void func_021DB254(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive)
{
    func_021DB374(flow, pokeId, func_021C8288(flow));
    *formActive = 1;
}


void func_021DB274(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) func_021DB254(factor, flow, pokeId, formActive);
}


void func_021DB298(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive)
{
    if (*formActive != 0) func_021DB374(flow, pokeId, func_021C8288(flow));
}


void func_021DB2B8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive)
{
    if (*formActive != 0) func_021DB318(factor, flow, pokeId);
}


/* Go back to the base form when the holder gets another ability. */
void func_021DB2C8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int newAbilityId;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        newAbilityId = func_021D775C(BTL_EVAR_NEW_ABILITY_ID);
        if (newAbilityId != func_021D70A8(factor)) func_021DB318(factor, flow, pokeId);
    }
}


void func_021DB2F8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) func_021DB318(factor, flow, pokeId);
}


/* Put a Castform that is not in its base form back to the base form. */
void func_021DB318(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExChangeForm *cmd;
    struct BtlPokeParam *bpp;

    bpp = func_021C7CF4(flow, pokeId);
    if (func_021D5444(bpp) == SPECIES_CASTFORM && func_021D59B4(bpp, BPP_VALUE_FORM) != 0) {
        cmd = func_021C88A4(flow, HANDEX_CHANGE_FORM, pokeId);
        cmd->pokeId = pokeId;
        cmd->form = 0;
        func_021C8838(&cmd->str, 2, 0xde);
        func_021C8860(&cmd->str, pokeId);
        func_021C88C8(flow, cmd);
    }
}


/* Change a Castform to the form of the weather (none, sun, rain, hail); other weather gives the base form. */
void func_021DB374(struct BtlSvFlow *flow, int pokeId, u32 weather)
{
    HandExChangeForm *cmd;
    struct BtlPokeParam *bpp;
    u32 currentForm;
    u32 newForm;

    bpp = func_021C7CF4(flow, pokeId);
    if (func_021D5444(bpp) == SPECIES_CASTFORM) {
        currentForm = (u8)func_021D59B4(bpp, BPP_VALUE_FORM);
        switch (weather) {
        case 0:
            newForm = 0;
            break;
        case 1:
            newForm = 1;
            break;
        case 2:
            newForm = 2;
            break;
        case 3:
            newForm = 3;
            break;
        default:
            newForm = 0;
            break;
        }
        if (newForm != currentForm) {
            cmd = func_021C88A4(flow, HANDEX_CHANGE_FORM, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->pokeId = pokeId;
            cmd->form = newForm;
            func_021C8838(&cmd->str, 2, 0xde);
            func_021C8860(&cmd->str, pokeId);
            func_021C88C8(flow, cmd);
        }
    }
}


const BtlEventHandler *func_021DB404(int *handlerCount)
{
    *handlerCount = 9;
    return d_021F0DD4;
}


const BtlEventHandler *func_021DB410(int *handlerCount)
{
    *handlerCount = 3;
    return d_021F0A58;
}


/* Storm Drain: redirect single-target water moves to the holder. */
void func_021DB41C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected)
{
    *redirected = func_021DB4E8(flow, pokeId, redirected, POKETYPE_WATER);
}


/* Storm Drain: a water move that hit the holder is absorbed; the holder gains a Sp. Atk rank. */
void func_021DB430(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (func_021DA8A8(flow, pokeId, POKETYPE_WATER) != 0) func_021DA96C(flow, pokeId, BTL_STAT_SP_ATTACK, 1);
}


const BtlEventHandler *func_021DB454(int *handlerCount)
{
    *handlerCount = 3;
    return d_021F0A70;
}


/* Lightning Rod: redirect single-target electric moves to the holder. */
void func_021DB460(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected)
{
    *redirected = func_021DB4E8(flow, pokeId, redirected, POKETYPE_ELECTRIC);
}


/* Lightning Rod and Storm Drain: show the message when a move was redirected to the holder. */
void func_021DB474(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected)
{
    HandExMessage *msg;

    if (*redirected != 0) {
        if (func_021E85F8(pokeId) != 0) {
            msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
            msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
            func_021C8838(&msg->str, 2, 0x1c0);
            func_021C8860(&msg->str, pokeId);
            func_021C88C8(flow, msg);
        }
        *redirected = 0;
    }
}


/* Lightning Rod: an electric move that hit the holder is absorbed; the holder gains a Sp. Atk rank. */
void func_021DB4C4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (func_021DA8A8(flow, pokeId, POKETYPE_ELECTRIC) != 0) func_021DA96C(flow, pokeId, BTL_STAT_SP_ATTACK, 1);
}


/* True if a move of typeId from another poke can be redirected to the poke pokeId. */
int func_021DB4E8(struct BtlSvFlow *flow, int pokeId, int *work, int typeId)
{
    u8 attackerId;
    u16 moveId;
    u8 targetId;

    attackerId = func_021D775C(BTL_EVAR_ATTACKER_ID);
    if (attackerId != pokeId && typeId == func_021D775C(BTL_EVAR_MOVE_TYPE)) {
        moveId = func_021D775C(BTL_EVAR_MOVE_ID);
        if (func_021C8290(flow, attackerId, pokeId, moveId) == 0 && func_0689C8EC(moveId) == 0) {
            targetId = func_021D775C(BTL_EVAR_DEFENDER_ID);
            if (func_021D76BC(BTL_EVAR_DEFENDER_ID, pokeId) != 0 && targetId != pokeId)
                return 1;
        }
    }
    return 0;
}
