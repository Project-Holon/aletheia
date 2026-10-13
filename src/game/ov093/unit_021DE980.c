/*
 * file:     unit_021DE980.c
 * unit:     yes
 * function: func_021DE980, func_021DE9B8, func_021DE9D4, func_021DEA1C, func_021DEA58, func_021DEA8C, func_021DEAE8, func_021DEAF4, func_021DEB30, func_021DEB5C, func_021DEBA8
 * address:  0x021DE980
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
 *   d_021F150C     0x021F150C  data   ov093  a4
 *   d_021F1904 0x021F1904 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021E89D4  0x021E89D4  thumb  ov093
 *   d_021F16BC 0x021F16BC data a4
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   d_021F191C 0x021F191C data a4
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021DCFD0 0x021DCFD0 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 value);
extern void func_021D7704(int key, int multiplier);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern void *func_021C88A4(void *flow, int cmdKind, int pokeId);
extern void func_021C88C8(void *flow, void *cmd);
extern int func_021E89D4(u32 moveId);
extern void *func_021C7CF4(void *flow, int pokeId);
extern int func_021D5B48(void *pokeParam);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 func_021D70A8(struct BtlEventFactor *factor);
extern int func_021DCFF8(struct BtlEventFactor *factor, int index);
extern int func_021DCFD0(void *flow, u32 chance);
extern void func_021DD044(struct BtlEventFactor *factor, void *flow, int pokeId);
extern int d_021F1904;
extern int d_021F16BC;
extern int d_021F191C;
extern int d_021F150C[];

/* Choice Specs: 1.5 times power for special moves. */
void func_021DE980(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)func_021D775C(BTL_EVAR_MOVE_ID)) == 2)
            func_021D7704(BTL_EVAR_POWER_RATIO, 6144);
    }
}

int *func_021DE9AC(int *count)
{
    *count = 3;
    return &d_021F1904;
}

/* Choice Scarf: 1.5 times speed. */
void func_021DE9B8(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021D7704(BTL_EVAR_POWER_RATIO, 6144);
}

/* Choice items: lock the holder into the move it just used (anything but Struggle, 0xa5). */
void func_021DE9D4(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    u16 moveId;
    HandExAddSickFull *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        moveId = func_021D775C(BTL_EVAR_MOVE_ID);
        if (moveId != 0xa5) {
            cmd = (HandExAddSickFull *)func_021C88A4(flow, HANDEX_KIND_ADD_SICK, pokeId);
            cmd->pokeId = pokeId;
            cmd->sickKind = BTL_SICK_MOVE_LOCK;
            cmd->sickCont = func_021E89D4(moveId);
            cmd->mode = 2;
            func_021C88C8(flow, cmd);
        }
    }
}

/* Choice items: release the move lock when the holder leaves the field. */
void func_021DEA1C(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    HandExCureSickSlot *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        cmd = (HandExCureSickSlot *)func_021C88A4(flow, 11, pokeId);
        cmd->sickIndex = BTL_SICK_MOVE_LOCK;
        cmd->pokeId = pokeId;
        cmd->flagA = 1;
        cmd->flagB = 1;
        func_021C88C8(flow, cmd);
    }
}

int *func_021DEA4C(int *count)
{
    *count = 2;
    return &d_021F16BC;
}

/* Focus Sash: a hit at full HP leaves the holder at 1 HP. */
void func_021DEA58(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        if (func_021D5B48(func_021C7CF4(flow, pokeId)))
            *work = func_021D76BC(BTL_EVAR_SURVIVE_RESULT, 3);
        else
            *work = 0;
    }
}

/* Focus Sash: consume the item and show its message after it saved the holder. */
void func_021DEA8C(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    HandExConsumeItem *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && *work != 0) {
        cmd = (HandExConsumeItem *)func_021C88A4(flow, 0x23, pokeId);
        func_021C8838(&cmd->str, HANDEX_STR_SET, 0x3ef);
        func_021C8860(&cmd->str, pokeId);
        func_021C8860(&cmd->str, func_021D70A8(factor));
        func_021C88C8(flow, cmd);
        *work = 0;
    }
}

int *func_021DEAE8(int *count)
{
    *count = 3;
    return &d_021F191C;
}

/* Focus Band: a random chance (item parameter) to survive a hit with 1 HP. */
void func_021DEAF4(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    int chance;

    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        chance = (unsigned char)func_021DCFF8(factor, 2);
        if (func_021DCFD0(flow, chance))
            *work = func_021D76BC(BTL_EVAR_SURVIVE_RESULT, 3);
        else
            *work = 0;
    }
}

/* Focus Band: use the item when it saved the holder. */
void func_021DEB30(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (*work) {
            func_021DD044(factor, flow, pokeId);
            *work = 0;
        }
    }
}

/* Focus Band: show the message that the holder hung on. */
void func_021DEB5C(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    HandExMessage *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        cmd = (HandExMessage *)func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
        func_021C8838(&cmd->str, HANDEX_STR_SET, 0x3ef);
        func_021C8860(&cmd->str, pokeId);
        func_021C8860(&cmd->str, func_021D70A8(factor));
        func_021C88C8(flow, cmd);
    }
}

int *func_021DEBA8(int *count)
{
    *count = 1;
    return d_021F150C;
}
