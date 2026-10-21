#ifndef GAME_ARM9_BMP_OAM_H
#define GAME_ARM9_BMP_OAM_H

#include "../types.h"

/* Init data of a bitmap OAM (BMP_OAM_Create). */
struct BmpOamParam {
    const struct Bmp *bmp;
    s16               x;
    s16               y;
    u32               animResId;
    u32               palette;
    u8                drawPriority;
    u8                bgPriority;
    u16               space;
    u32               engine;
};

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bmp_oam.c, prototypes copied from their definitions. */

struct BmpOamSys;
struct BmpOam;
struct BmpOamParam;

#include "../types.h"

struct BmpOamSys *BMP_OAM_CreateSys(u32 heapId, void *clact);
void BMP_OAM_DeleteSys(struct BmpOamSys *sys);
struct BmpOam *BMP_OAM_Create(struct BmpOamSys *sys, const struct BmpOamParam *param);
void BMP_OAM_Delete(struct BmpOam *bmpOam);
void BMP_OAM_SetEnabled(struct BmpOam *bmpOam, u32 enabled);
int BMP_OAM_GetEnabled(const struct BmpOam *bmpOam);
void BMP_OAM_UploadChars(struct BmpOam *bmpOam);
void BMP_OAM_GetPos(struct BmpOam *bmpOam, s16 *outX, s16 *outY);
void BMP_OAM_SetPos(struct BmpOam *bmpOam, s16 x, s16 y);
void BMP_OAM_SetObjMode(struct BmpOam *bmpOam, u32 objMode);
void BMP_OAM_SetDrawPriority(struct BmpOam *bmpOam, u32 drawPriority);
void BMP_OAM_SetBgPriority(struct BmpOam *bmpOam, u32 bgPriority);
void BMP_OAM_SetPalette(struct BmpOam *bmpOam, u32 palette);
u32 BMP_OAM_AcquireModeSlot(struct BmpOamSys *sys, u32 engine, void *arcTool);
void BMP_OAM_ReleaseModeSlots(struct BmpOamSys *sys);
int NATION_AREA_GetNationRecordCount(void);
u32 NATION_AREA_FindRecordIndex(u32 key);
u8 NATION_AREA_GetAreaCount(u32 key);
u32 NATION_AREA_GetAreaMsgBank(u32 key);
u32 NATION_AREA_GetAreaMsgBankByIndex(u32 recIdx);
u32 NATION_AREA_GetNationIdByIndex(u32 recIdx);
u32 NATION_AREA_GetAreaListArcMember(u32 recIdx);
int NATION_AREA_GetDefaultNation(void);
u32 NATION_AREA_IsValidNationArea(u32 id, u32 minValue, u32 flag);
u32 NATION_AREA_SanitizeNation(u32 id, u32 minValue, u32 flag);
u32 NATION_AREA_SanitizeArea(u32 id, u32 minValue, u32 flag);
int NATION_AREA_GetAreaTable(u32 key, u32 *outWord, u32 *outByte);
/* END mkheaders: generated region */

#endif
