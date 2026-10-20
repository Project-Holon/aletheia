#ifndef GAME_OV136_MAILVIEW_H
#define GAME_OV136_MAILVIEW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mailview.c, prototypes copied from their definitions. */

struct MailEditProc;

void MAILVIEW_HideAllPlanes(void);
void MAILVIEW_VBlankTask(void *task, struct MailEditProc *proc);
void MAILVIEW_CursorBlendTask(void *unused, struct MailEditProc *proc);
int MAILVIEW_SetupStep(struct MailEditProc *proc);
void MAILVIEW_StartCursorBlendTask(struct MailEditProc *proc);
int MAILVIEW_Teardown(struct MailEditProc *proc);
void MAILVIEW_CreatePmsDraw(struct MailEditProc *proc);
void MAILVIEW_DeletePmsDraw(struct MailEditProc *proc);
void MAILVIEW_SetVramBanks(void);
void MAILVIEW_InitBgs(struct MailEditProc *proc);
void MAILVIEW_FreeBgs(struct MailEditProc *proc);
void MAILVIEW_LoadGraphics(struct MailEditProc *proc);
void MAILVIEW_FreeGraphics(struct MailEditProc *proc);
void MAILVIEW_CreateWindows(struct MailEditProc *proc);
void MAILVIEW_CreateButtons(struct MailEditProc *proc);
void MAILVIEW_DeleteWindows(struct MailEditProc *proc);
void MAILVIEW_PrintSentences(struct MailEditProc *proc);
void MAILVIEW_InitActorSystem(struct MailEditProc *proc);
void MAILVIEW_ExitActorSystem(struct MailEditProc *proc);
/* END mkheaders: generated region */

#endif
