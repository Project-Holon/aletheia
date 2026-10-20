#ifndef GAME_ARM9_MAIL_H
#define GAME_ARM9_MAIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mail.c, prototypes copied from their definitions. */

struct Mail;
struct GameData;
struct PmsData;
struct MailBox;

#include "../types.h"

void MAIL_Init(struct Mail *mail);
int MAIL_IsDesignValid(const struct Mail *mail);
struct Mail *MAIL_Create(int heapId);
void MAIL_Copy(const struct Mail *src, struct Mail *dest);
void MAIL_InitForPlayer(struct Mail *mail, u8 design, u32 unused, struct GameData *gameData);
u32 MAIL_GetWriterId(const struct Mail *mail);
u16 *MAIL_GetWriterName(struct Mail *mail);
void MAIL_SetWriterName(struct Mail *mail, const void *name);
u8 MAIL_GetGender(const struct Mail *mail);
void MAIL_SetGender(struct Mail *mail, u8 gender);
u8 MAIL_GetDesign(const struct Mail *mail);
void MAIL_SetDesign(struct Mail *mail, u32 design);
u8 MAIL_GetLanguage(const struct Mail *mail);
void MAIL_SetLanguage(struct Mail *mail, u8 language);
u8 MAIL_GetVersion(const struct Mail *mail);
void MAIL_SetVersion(struct Mail *mail, u8 version);
u16 MAIL_GetMessageId(const struct Mail *mail);
void MAIL_SetMessageId(struct Mail *mail, u16 messageId);
struct PmsData *MAIL_GetMessage(struct Mail *mail, u32 index);
void MAIL_SetMessage(struct Mail *mail, struct PmsData *pms, u32 index);
struct MailBox *MAIL_GetBox(struct GameData *gameData);
u32 MAIL_GetBoxSize(void);
void MAIL_InitBox(struct Mail *box);
int MAIL_FindEmptySlot(struct Mail *box, int unused);
void MAIL_ClearSlot(struct Mail *box, u32 boxKind, int index);
void MAIL_SetSlot(struct Mail *box, u32 boxKind, int index, const struct Mail *src);
struct Mail *MAIL_CreateSlotCopy(struct Mail *box, u32 boxKind, int index, u32 heapId);
int MAIL_FindEmptySlotInRange(struct Mail *box, int count);
struct Mail *MAIL_GetSlot(struct Mail *box, u32 boxKind, int index);
/* END mkheaders: generated region */

#endif
