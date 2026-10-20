#ifndef GAME_ARM9_MSGDATA_H
#define GAME_ARM9_MSGDATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msgdata.c, prototypes copied from their definitions. */

struct MsgBank;
struct Strbuf;
struct MsgFile;
struct MsgBankLoad;

#include "../types.h"

struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
u32 MSGDATA_Delete(struct MsgBank *bank);
struct MsgBank *MSGDATA_CreateFromMemory(const void *file, u32 heapId);
void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest);
void MSGDATA_DecryptStrbuf(struct Strbuf *str, u32 msgIndex);
u32 MSGDATA_DecryptUnits(u16 *str, u32 count, u32 msgIndex);
struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
u16 MSGDATA_GetMessageCount(const struct MsgBank *bank);
void MSGDATA_ReadUnits(struct MsgBank *bank, u32 msgIndex, u16 *str, u32 maxLen);
struct MsgFile *MSGDATA_LoadFileHeader(void *stream, u32 origin, u16 heapId);
void MSGDATA_LoadBank(struct MsgBankLoad *bank);
void MSGDATA_RefreshLanguage(struct MsgBank *bank);
s32 MSGDATA_GetLanguageIndex(const struct MsgFile *file);
void MSGDATA_SetLanguage(u8 languageId);
u8 MSGDATA_GetLanguage(void);
/* END mkheaders: generated region */

#endif
