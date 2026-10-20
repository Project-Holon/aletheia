#ifndef GAME_ARM9_NNS_G2D_ANIM_BANK_H
#define GAME_ARM9_NNS_G2D_ANIM_BANK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g2d_anim_bank.c, prototypes copied from their definitions. */

struct NitroFileHeader;
struct AnimBank;

#include "../arm9/nns_g2d_anim_types.h"
#include "../types.h"

int NNS_G2dGetUnpackedAnimBank(struct NitroFileHeader *file, void **out);
int NNS_G2dGetUnpackedAnimBankEx(struct NitroFileHeader *file, void **out);
int NNSi_G2dGetUnpackedAnimBank(struct NitroFileHeader *file, void **out);
void NNSi_G2dUnpackAnimBank(volatile struct AnimBank *bank);
const AnimSequenceData *NNS_G2dGetAnimSequenceByIdx(const struct AnimBank *bank, u32 idx);
void *NNSi_G2dGetCellDataBankOamBase(CellDataBank *bank);
void NNSi_G2dFixupCellAnimBankTbl(void *p);
int NNS_G2dGetUnpackedCellBank(void *a, int *out);
void *NNS_G2dGetCellDataByIdx(CellDataBank *bank, u32 idx);
void NNSi_G2dUnpackCellBank(int *p);
int NNS_G2dGetUnpackedMultiCellBank(void *a, u32 *out);
void NNSi_G2dFixupMultiCellAnimBankTbl(void *animBank);
void NNSi_G2dUnpackMultiCellBank(volatile MultiCellBank *bank);
MultiCellData *NNS_G2dGetMultiCellDataByIdx(MultiCellBank *bank, u32 idx);
s32 NNS_G2dGetUnpackedCharacterData(struct NitroFileHeader *file, void **out);
void NNSi_G2dFixupCharacterData(u8 *block);
s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);
void NNSi_G2dFixupCharacterDataEx(u8 *block);
s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);
s32 NNS_G2dGetUnpackedPaletteCompressInfo(struct NitroFileHeader *file, void **out);
void NNSi_G2dFixupPaletteCompressInfo(u8 *block);
void NNSi_G2dFixupPaletteData(u8 *block);
/* END mkheaders: generated region */

#endif
