#ifndef GAME_ARM9_CRC_H
#define GAME_ARM9_CRC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of crc.c, prototypes copied from their definitions. */

#include "../sdk_math.h"
#include "../types.h"

void MATHi_CRC8InitTable(MATHCRC8Table *table, u8 poly);
void MATHi_CRC8Update(MATHCRC8Table *table, u8 *context, void *input, u32 length);
void MATHi_CRC16InitTable(MATHCRC16Table *table, u16 poly);
void MATHi_CRC16InitTableRev(MATHCRC16Table *table, u16 poly);
void MATHi_CRC16Update(MATHCRC16Table *table, u16 *context, void *input, u32 length);
void MATHi_CRC16UpdateRev(MATHCRC16Table *table, u16 *context, void *input, u32 length);
void MATHi_CRC32InitTableRev(MATHCRC32Table *table, u32 poly);
void MATHi_CRC32UpdateRev(MATHCRC32Table *table, u32 *context, void *input, u32 length);
u8 MATH_CalcCRC8(MATHCRC8Table *table, void *data, u32 dataLength);
u16 MATH_CalcCRC16(MATHCRC16Table *table, void *data, u32 dataLength);
u16 MATH_CalcCRC16CCITT(MATHCRC16Table *table, void *data, u32 dataLength);
u32 MATH_CalcCRC32(MATHCRC32Table *table, void *data, u32 dataLength);
/* END mkheaders: generated region */

#endif
