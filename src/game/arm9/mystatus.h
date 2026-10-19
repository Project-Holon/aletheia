#ifndef GAME_ARM9_MYSTATUS_H
#define GAME_ARM9_MYSTATUS_H

/* Public functions of mystatus.c, prototypes copied from their definitions. */

struct MyStatus;
struct Strbuf;

void *MYSTATUS_Create(int heap_id);
void MYSTATUS_Copy(const struct MyStatus *src, struct MyStatus *dest);
void MYSTATUS_Init(struct MyStatus *mystatus);
int MYSTATUS_IsNameEmpty(const struct MyStatus *mystatus);
void MYSTATUS_CopyName(u16 *dest, const u16 *src);
void MYSTATUS_NameFromStrbuf(u16 *out, struct Strbuf *buf);
const void *MYSTATUS_GetName(const void *mystatus);
void MYSTATUS_CopyNameChars(const u16 *src, u16 *dest, u32 n);
void MYSTATUS_NameToStrbuf(const u16 *name, struct Strbuf *buf);
struct Strbuf *MYSTATUS_CreateNameStrbuf(const u16 *name, int heap_id);
void MYSTATUS_SetId(struct MyStatus *mystatus, u32 id);
u32 MYSTATUS_GetId(const struct MyStatus *mystatus);
u16 MYSTATUS_GetIdLow16(const struct MyStatus *mystatus);
u32 MYSTATUS_GetProfileId(const struct MyStatus *mystatus);
void MYSTATUS_SetProfileIdOnce(struct MyStatus *mystatus, u32 profile_id);
void MYSTATUS_SetSex(struct MyStatus *mystatus, u8 sex);
u8 MYSTATUS_GetSex(const struct MyStatus *mystatus);
u8 MYSTATUS_GetTrainerView(const struct MyStatus *mystatus);
void MYSTATUS_SetTrainerView(struct MyStatus *mystatus, u8 trainer_view);
u8 MYSTATUS_GetRomCode(const struct MyStatus *mystatus);
void MYSTATUS_SetRomCode(struct MyStatus *mystatus, u8 rom_code);
u8 MYSTATUS_GetLanguage(const struct MyStatus *mystatus);
void MYSTATUS_SetLanguage(struct MyStatus *mystatus, u8 language);
u8 MYSTATUS_GetNation(const struct MyStatus *mystatus);
u8 MYSTATUS_GetArea(const struct MyStatus *mystatus);
void MYSTATUS_SetNationAndArea(struct MyStatus *mystatus, u8 nation, u8 area);

#endif
