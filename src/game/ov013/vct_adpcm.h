#ifndef GAME_OV013_VCT_ADPCM_H
#define GAME_OV013_VCT_ADPCM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of vct_adpcm.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov013/vct_types.h"

void VCT_ADPCM_Decode4Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st);
void VCT_ADPCM_Encode4Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st);
void VCT_ADPCM_Decode3Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st);
void VCT_ADPCM_Encode3Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st);
void VCT_ADPCM_Decode2Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st);
void VCT_ADPCM_Encode2Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st);
void VCT_ADPCM_DecodePacket(AdpcmState *hdr, void *dst, int packetBytes, int bits);
void VCT_ADPCM_EncodePacket(AdpcmHeader *out, void *samples, int sampleCount, AdpcmState *st, int bits);
/* END mkheaders: generated region */

#endif
