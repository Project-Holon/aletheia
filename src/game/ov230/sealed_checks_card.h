#ifndef GAME_OV230_SEALED_CHECKS_CARD_H
#define GAME_OV230_SEALED_CHECKS_CARD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sealed_checks_card.c, prototypes copied from their definitions. */

#include "../types.h"

void OV230_ReadCardBytes(u8 *dst, u32 offset, s32 size);
u32 OV230_Crc32(const u8 *data, u32 size);
/* END mkheaders: generated region */

#endif
