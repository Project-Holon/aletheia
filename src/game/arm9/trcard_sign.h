#ifndef GAME_ARM9_TRCARD_SIGN_H
#define GAME_ARM9_TRCARD_SIGN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of trcard_sign.c, prototypes copied from their definitions. */

struct TrainerCardSignature;
struct SaveControl;

#include "../types.h"
#include "../arm9/trcard_sign_shared_types.h"

u32 TRCARD_SIGN_GetSize(void);
void TRCARD_SIGN_Init(struct TrainerCardSignature *card);
struct TrainerCardSignature *TRCARD_SIGN_GetFromSave(struct SaveControl *control);
u32 *TRCARD_SIGN_GetBitmap(struct TrainerCardSignature *card);
int TRCARD_SIGN_HasAnySignature(const struct TrainerCardSignature *card);
u8 TRCARD_SIGN_GetSeenBefore(const struct TrainerCardSignature *card);
struct TrainerCardSignature *TRCARD_SIGN_SetSeenBefore(struct TrainerCardSignature *card);
u16 TRCARD_SIGN_GetColor(const struct TrainerCardSignature *card);
void TRCARD_SIGN_SetColor(struct TrainerCardSignature *card, u16 color);
void TRCARD_SIGN_SetStyle(struct TrainerCardSignature *card, u8 style);
u8 TRCARD_SIGN_GetStyle(const struct TrainerCardSignature *card);
void TRCARD_SIGN_SetLastBadgeTime(struct TrainerCardSignature *card, u32 lo, u32 hi);
u64 TRCARD_SIGN_GetLastBadgeTime(const struct TrainerCardSignature *card);
struct BadgeDate TRCARD_SIGN_GetBadgeDate(struct TrainerCardSignature *card, int badge);
void TRCARD_SIGN_SetBadgeDate(struct TrainerCardSignature *card, u32 badge, u32 year, u32 month, u32 day);
u16 TRCARD_SIGN_GetBadgeTimer(const struct TrainerCardSignature *card, u32 badge);
void TRCARD_SIGN_SetBadgeTimer(struct TrainerCardSignature *card, int badge, int timer);
/* END mkheaders: generated region */

#endif
