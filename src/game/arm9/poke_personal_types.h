#ifndef GAME_ARM9_POKE_PERSONAL_TYPES_H
#define GAME_ARM9_POKE_PERSONAL_TYPES_H

#include "../types.h"

/* The 0x3C byte personal record of one species or form (poke_personal.c). */
typedef struct PersonalData {
    u8  baseHp;
    u8  baseAttack;
    u8  baseDefense;
    u8  baseSpeed;
    u8  baseSpAttack;
    u8  baseSpDefense;
    u8  type1;
    u8  type2;
    u8  catchRate;
    u8  evoStage;
    u16 evHp : 2;
    u16 evAttack : 2;
    u16 evDefense : 2;
    u16 evSpeed : 2;
    u16 evSpAttack : 2;
    u16 evSpDefense : 2;
    u16 yieldFlag : 1;
    u16 reserved : 3;
    u16 heldItemCommon;
    u16 heldItemRare;
    u16 heldItemDream;
    u8  genderRatio;
    u8  eggCycles;
    u8  baseFriendship;
    u8  growthRate;
    u8  eggGroup1;
    u8  eggGroup2;
    u8  ability1;
    u8  ability2;
    u8  hiddenAbility;
    u8  escapeRate;
    u16 formStatsIndex;
    u16 formSpriteIndex;
    u8  formCount;
    u8  color : 6;
    u8  spriteFlip : 1;
    u8  formSpriteShared : 1;
    u16 baseExp;
    u16 height;
    u16 weight;
    u32 tmFlags1;
    u32 tmFlags2;
    u32 tmFlags3;
    u32 tmFlags4;
    u32 tutorFlags;
} PersonalData;

#endif
