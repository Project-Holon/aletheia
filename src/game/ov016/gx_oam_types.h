#ifndef OV016_GX_OAM_TYPES_H
#define OV016_GX_OAM_TYPES_H

/*
 * One 8-byte OAM attribute entry (NitroSDK GXOamAttr). attr0 and attr1 form
 * the low word, attr2 and attr3 the high word; every OAM view in the ov016
 * files is this same record, only the member split differs. The two anonymous
 * structs expose the halfword split (attr0..attr3) and the word split
 * (attr01, attr23) so every caller reads the record through the same type.
 * Canonical owner of the record used by every file in src/game/ov016.
 */
#include "../sdk_gx.h"

#endif
