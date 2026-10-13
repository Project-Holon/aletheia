#ifndef ALETHEIA_OV010_COMM_PLAYER_TYPES_H
#define ALETHEIA_OV010_COMM_PLAYER_TYPES_H

/*
 * Position package of one player, exchanged between players (comm_player.c
 * and the union room and colosseum code). The including file must define
 * VecFx32 before this header.
 */

/* Position package exchanged between players. */
typedef struct CommPlayerPackage {
    unsigned int vanish;   /* 0x00 */
    VecFx32 pos;            /* 0x04 */
    unsigned short zoneId; /* 0x10 */
    unsigned char dir;     /* 0x12 */
    unsigned char pad13;
} CommPlayerPackage;

#endif
