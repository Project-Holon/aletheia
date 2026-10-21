#ifndef GAME_ARM9_APP_KEYCURSOR_H
#define GAME_ARM9_APP_KEYCURSOR_H

#include "../types.h"

typedef struct PrintStreamCtrl PrintStreamCtrl;

struct KeyCursor *APP_KEYCURSOR_CreateDefault(u32 id, u32 isLive, u32 isFlip, u16 heapId);
struct KeyCursor *APP_KEYCURSOR_Create(u32 id, u32 live, u32 flip, u16 heap, void *pixels);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of app_keycursor.c, prototypes copied from their definitions. */

struct PrintStreamCtrl;
struct TextPrinter;
struct KeyCursor;
struct Bmp;
struct FieldSkillUseFlags;
typedef struct PrintStreamCtrl PrintStreamCtrl;

#include "../types.h"

void PRINTSYS_CTRL_Init(PrintStreamCtrl *ctrl, u32 inputType);
int PRINTSYS_CTRL_Update(PrintStreamCtrl *ctrl, struct TextPrinter *stream);
u32 PRINTSYS_CTRL_IsInputTrg(u32 inputType);
u32 PRINTSYS_CTRL_IsInputCont(u32 inputType);
u32 PRINTSYS_CTRL_IsInputIdle(u32 inputType);
struct KeyCursor *APP_KEYCURSOR_CreateDefault(u32 id, u32 isLive, u32 isFlip, u16 heapId);
struct KeyCursor *APP_KEYCURSOR_Create(u32 id, u32 live, u32 flip, u16 heap, void *pixels);
void APP_KEYCURSOR_Delete(struct KeyCursor *cursor);
void APP_KEYCURSOR_DrawMark(struct KeyCursor *cursor, const struct Bmp *bmp, u32 color);
void APP_KEYCURSOR_Animate(struct KeyCursor *cursor, const struct Bmp *bmp, u32 color);
void APP_KEYCURSOR_Update(struct KeyCursor *cursor, struct TextPrinter *printStream, void *win);
void FIELD_SKILL_USE_FLAGS_SetSkill(struct FieldSkillUseFlags *flags, int skillIndex, int usable);
u32 FIELD_SKILL_USE_FLAGS_IsSkillUsable(const struct FieldSkillUseFlags *flags, u32 skillIndex);
/* END mkheaders: generated region */

#endif
