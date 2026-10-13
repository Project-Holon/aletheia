#ifndef UNIT_021DE7E4_TYPES_H
#define UNIT_021DE7E4_TYPES_H
/*
 * ov093 held item handlers (battle items from Quick Powder to Smoke Ball):
 * event variable numbers and the effect records these handlers push to the
 * battle flow. Builds on the berry record types of unit_021DD588_types.h.
 */

#include "unit_021DD588_types.h"

#ifndef BTL_EVAR_ATTACKER_ID
#define BTL_EVAR_ATTACKER_ID 3
#endif
#define BTL_EVAR_MOVE_ID 0x12
#define BTL_EVAR_DAMAGE_TYPE 0x1a   /* 1 physical, 2 special */
#define BTL_EVAR_SICK_ID 0x1d       /* status being applied */
#define BTL_EVAR_SICK_CONT 0x1e     /* its packed duration and parameters */
#define BTL_EVAR_DAMAGE 0x32
#define BTL_EVAR_POWER_RATIO 0x35   /* fixed point multiplier, 0x1000 = 1.0 */
#define BTL_EVAR_AFFINITY_SCALED 0x38
#define BTL_EVAR_SURVIVE_RESULT 0x3a
#define BTL_EVAR_NO_EFFECT_FLAG 0x4d
#define BTL_EVAR_SCREEN_KIND 0x53
#define BTL_EVAR_SKIP_CHARGE_FLAG 0x51

#define BTL_ITEM_DITTO_SPECIES 0x84
#define BTL_SICK_MOVE_LOCK 0x1b     /* choice item lock */
#define BTL_SICK_INFATUATION 7
#define BTL_SICK_BIND 8

/* Kind 0: use the held item (flags bit 0 marks it as consumed by the handler). */
typedef struct {
    u32 header;
    u32 flags;
} HandExItemUse;

/* Kind 7: lose hit points (amount, message at +12). */
typedef struct {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 flags;       /* bit 1 set by the item damage handlers */
    u16 effectId;
    u8 effectParam;
    u8 effectKind;
    HandExStr str;
} HandExLoseHp;

/* Kind 0xb: cure a status slot of a Pokemon. */
typedef struct {
    u32 header;
    s32 sickIndex;
    u8 pokeId;
    u8 pad09[11];
    u8 flagA;
    u8 flagB;
} HandExCureSickSlot;

/* Kind 0xc: add a status condition with a packed duration and a message at +0x14. */
typedef struct {
    u32 header;
    u32 sickKind;
    u32 sickCont;
    u8 pad0C;
    u8 flagD;
    u8 pad0E;
    u8 pokeId;
    u8 mode;
    u8 pad11[3];
    HandExStr str;
} HandExAddSickFull;

/* Kind 0x23: consume the item and show a message at +8. */
typedef struct {
    u32 header;
    u8 pad04[4];
    HandExStr str;
} HandExConsumeItem;

/* Kind 0x24: move the held item of the attacker to the holder. */
typedef struct {
    u32 header;
    u8 pokeId;
} HandExStealItem;

#endif
