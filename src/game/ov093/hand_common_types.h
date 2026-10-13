#ifndef HAND_COMMON_TYPES_H
#define HAND_COMMON_TYPES_H
/*
 * ov093 battle handlers (abilities and held items): types shared by all handler files.
 * One name per event variable key; the same key is a differently named result slot in
 * different events (0x41 and 0x51 are shared flag slots: the names are the Iron Ball and
 * Air Balloon uses that decide them).
 */
#include "btl_event_types.h"

/* Event variable keys read and written with BTL_EVENT_GetVar and BTL_EVENT_OverwriteVar. */
enum BtlEventVarKey {
    BTL_EVAR_POKE_ID = 0x02,
    BTL_EVAR_ATTACKER_ID = 0x03,
    BTL_EVAR_DEFENDER_ID = 0x04,
    BTL_EVAR_DEFENDER_COUNT = 0x05,
    BTL_EVAR_DEFENDER_FIRST = 0x06,
    BTL_EVAR_TURN_PHASE = 0x0C,
    BTL_EVAR_NEW_ABILITY_ID = 0x10,
    BTL_EVAR_ACTION_ORDER = 0x11,
    BTL_EVAR_MOVE_ID = 0x12,
    BTL_EVAR_MOVE_ID_USED = 0x14,
    BTL_EVAR_DEFENDER_TYPE = 0x15,
    BTL_EVAR_MOVE_TYPE = 0x16,
    BTL_EVAR_MOVE_PRIORITY = 0x18,
    BTL_EVAR_DAMAGE_TYPE = 0x1A,
    BTL_EVAR_SICK_ID = 0x1D,
    BTL_EVAR_SICK_CONT = 0x1E,
    BTL_EVAR_VOLUME = 0x20,
    BTL_EVAR_FAIL_REASON = 0x22,
    BTL_EVAR_WEATHER_TURNS = 0x24,
    BTL_EVAR_EFFECT_PERCENT_LOCKED = 0x25,
    BTL_EVAR_EFFECT_PERCENT = 0x26,
    BTL_EVAR_ATTACK_STAGE = 0x27,
    BTL_EVAR_DEFENSE_STAGE = 0x28,
    BTL_EVAR_ACCURACY = 0x2B,
    BTL_EVAR_CRITICAL_RANK = 0x2C,
    BTL_EVAR_SELF_CAUSED_FLAG = 0x2D,
    BTL_EVAR_TRIGGER_KIND = 0x2E,
    BTL_EVAR_POWER_RATIO = 0x31,
    BTL_EVAR_DAMAGE = 0x32,
    BTL_EVAR_POWER = 0x33,
    BTL_EVAR_RATIO = 0x35,
    BTL_EVAR_TYPE_AFFINITY = 0x38,
    BTL_EVAR_WEATHER = 0x39,
    BTL_EVAR_ENDURE_REASON = 0x3A,
    BTL_EVAR_NO_EFFECT_FLAG = 0x40,
    BTL_EVAR_FORCE_GROUNDED_FLAG = 0x41,
    BTL_EVAR_SAME_TYPE_FLAG = 0x44,
    BTL_EVAR_CRITICAL_FLAG = 0x45,
    BTL_EVAR_HIT_SUBSTITUTE_FLAG = 0x46,
    BTL_EVAR_EFFECT_BLOCKED_FLAG = 0x47,
    BTL_EVAR_ADDED_EFFECT_OFF_FLAG = 0x48,
    BTL_EVAR_IMMUNITY_OVERRIDE_FLAG = 0x4B,
    BTL_EVAR_SHEER_FORCE_FLAG = 0x4D,
    BTL_EVAR_FORCE_FLOATING_FLAG = 0x51,
    BTL_EVAR_SCREEN_KIND = 0x53
};

#endif
