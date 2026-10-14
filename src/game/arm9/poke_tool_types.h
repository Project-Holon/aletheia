#ifndef GAME_ARM9_POKE_TOOL_TYPES_H
#define GAME_ARM9_POKE_TOOL_TYPES_H

/*
 * Pokemon record types of poke_tool.c (the one definition: poke_tool.c,
 * poke_regulation.c and ov188 include it): the four 0x20-byte blocks of the
 * box part, the box part itself (0x88 bytes) and the party record (0xDC
 * bytes).  Uses only built-in types.
 */

/* Mail attached to a party Pokemon, 0x38 bytes (layout in mail.c). */
struct Mail {
    unsigned char data[0x38];
};

/* Block A of the box area (0x20 bytes). */
struct BoxPokemonBlockA {
    unsigned short species;
    unsigned short heldItem;
    unsigned int otId;
    unsigned int exp;
    unsigned char  friendship;
    unsigned char  ability;
    unsigned char  markings;
    unsigned char  language;
    unsigned char  evs[6];
    unsigned char  contestStats[6];
    unsigned int sinnohRibbons;
};

/* Block B of the box area (0x20 bytes). */
struct BoxPokemonBlockB {
    unsigned short moves[4];
    unsigned char  pp[4];
    unsigned char  ppUps[4];
    unsigned int ivHp : 5;
    unsigned int ivAttack : 5;
    unsigned int ivDefense : 5;
    unsigned int ivSpeed : 5;
    unsigned int ivSpAttack : 5;
    unsigned int ivSpDefense : 5;
    unsigned int isEgg : 1;
    unsigned int hasNickname : 1;
    unsigned int hoennRibbons;
    unsigned char  fatefulEncounter : 1;
    unsigned char  gender : 2;
    unsigned char  form : 5;
    unsigned char  nature;
    unsigned short hasHiddenAbility : 1;
    unsigned short spareBits : 15;
    unsigned int spareWord;
};

/* Block C of the box area (0x20 bytes). */
struct BoxPokemonBlockC {
    unsigned short nickname[11];
    unsigned char  spareByte;
    unsigned char  originGame;
    unsigned long long contestRibbons;
};

/* Block D of the box area (0x20 bytes). */
struct BoxPokemonBlockD {
    unsigned short otName[8];
    unsigned char  eggYear;
    unsigned char  eggMonth;
    unsigned char  eggDay;
    unsigned char  metYear;
    unsigned char  metMonth;
    unsigned char  metDay;
    unsigned short eggLocation;
    unsigned short metLocation;
    unsigned char  pokerus;
    unsigned char  ball;
    unsigned char  metLevel : 7;
    unsigned char  otGender : 1;
    unsigned char  encounterType;
    unsigned short ballExtra;
};

/* The part of a Pokemon record that is stored in a PC box, 0x88 bytes: the
 * personality value, the decode flags, the checksum, and the four blocks of
 * 0x20 bytes, shuffled by the personality value and masked with the checksum. */
struct BoxPokemon {
    unsigned int personality;
    unsigned short partyDecoded : 1;
    unsigned short boxDecoded : 1;
    unsigned short checksumFailed : 1;
    unsigned short spareFlags : 13;
    unsigned short checksum;
    unsigned char  blocks[0x80];
};

/* One Pokemon record, 0xDC bytes: the box part, then the party part (masked
 * with the personality value): status, level, stats and the attached mail. */
struct PokemonParam {
    struct BoxPokemon box;
    unsigned int statusCondition;
    unsigned char  level;
    unsigned char  capsuleIndex;
    unsigned short hp;
    unsigned short maxHp;
    unsigned short attack;
    unsigned short defense;
    unsigned short speed;
    unsigned short spAttack;
    unsigned short spDefense;
    struct Mail mail;
    unsigned char  pad[8];
};

#endif
