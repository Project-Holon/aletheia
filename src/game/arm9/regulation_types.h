#ifndef GAME_ARM9_REGULATION_TYPES_H
#define GAME_ARM9_REGULATION_TYPES_H

#include "../types.h"

/*
 * regulation.c: a 0xBC-byte battle rule set.  The get and set pair takes a
 * rule id 0..22; ids 9, 10 and 14 are the three bitmaps.
 */
typedef struct Regulation {
    u8  cupNo;
    u8  ruleNo;
    u8  numLo;
    u8  numHi;
    u8  level;
    u8  levelRange;
    u16 levelTotal;
    u8  bothPoke;
    u8  bothItem;
    u8  vetoPokeBit[0x52];
    u8  vetoItemBit[0x4C];
    u16 mustPoke;
    u8  mustPokeForm;
    u8  shooter;
    u8  vetoShooterBit[7];
    u8  timeVs;
    u8  timeCommand;
    u8  nickname;
    u8  cameraMode;
    u8  unused;
    u8  showPoke;
    u8  showPokeTime;
    u8  battleType;
    u8  battleCount;
} Regulation;

typedef struct RegulationCard {
    Regulation rule;
    s32 cupId;
    u8  cupName[0x92];
    s16 romVersion;
    s8  startYear;
    s8  startMonth;
    s8  startDay;
    s8  endYear;
    s8  endMonth;
    s8  endDay;
    s8  status;
    s8  bgm;
    u8  sameMatch;
    u8  cardType;
    u16 crc;
} RegulationCard;

#endif
