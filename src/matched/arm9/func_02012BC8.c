/*
 * function: GAME_DATA_SetConfigFlag
 * address:  0x02012BC8
 * packet:   pkt_02012BC8
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CONFIG_SetBattleFlag  0x02008450  thumb
 *
 * Forward a boolean-normalised flag to CONFIG_SetBattleFlag on the object held at
 * +0x198 of the game-data object (func_0200873C(handle) in GAME_DATA_Create).
 *
 * The tail call's pool word names 0x02008450, an unlabelled Thumb leaf
 * (the bit-10 setter beside the labelled getter CONFIG_GetBattleFlag); this
 * pool word is its only reference in the image.  It is attested by the
 * compiled witness src/matched/CONFIG_SetBattleFlag.c (class `matched`).
 */
#include "../include/Obj15630.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Flags02008450;
extern void CONFIG_SetBattleFlag(struct Flags02008450 *flags, int on);

void GAME_DATA_SetConfigFlag(u8 *p, int on)
{
    CONFIG_SetBattleFlag((struct Flags02008450 *)((struct Obj15630 *)p)->f198, on ? 1 : 0);
}
