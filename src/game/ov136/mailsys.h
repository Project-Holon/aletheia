#ifndef GAME_OV136_MAILSYS_H
#define GAME_OV136_MAILSYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mailsys.c, prototypes copied from their definitions. */

struct MailDraft;
struct Mail;
struct MailEditProc;

struct MailDraft *MAILSYS_CreateMessage(struct Mail *mail, unsigned heap);
void MAILSYS_DeleteMessage(struct MailDraft *draft);
void MAILSYS_WriteMessageToMail(struct Mail *mail, struct MailDraft *draft);
void MAILSYS_FillDefaultSentences(struct MailEditProc *proc, struct MailDraft *draft);
int MAILSYS_ProcInit(void *a, void *b, struct MailDraft *draft);
int MAILSYS_ProcMain(void *a, void *b, void *c, struct MailEditProc *proc);
int MAILSYS_ProcExit(void *a, void *b, void *c, struct MailEditProc *proc);
int MAILSYS_RunSequence(struct MailEditProc *proc);
int MAILSYS_IsMessageIncomplete(struct MailEditProc *proc);
void MAILSYS_ResetCursorBlend(struct MailEditProc *proc);
int MAILSYS_OnTouchMode(struct MailEditProc *proc);
int MAILSYS_OnKeyModeNoOp(struct MailEditProc *proc);
int MAILSYS_UpdateInputMode(struct MailEditProc *proc);
int MAILSYS_SwitchInputModeOnTrigger(struct MailEditProc *proc);
int MAILSYS_HandleKeyInput(struct MailEditProc *proc);
int MAILSYS_HandleTouchInput(struct MailEditProc *proc);
int MAILSYS_HandleInput(struct MailEditProc *proc);
void MAILSYS_PrintMessageText(struct MailEditProc *proc, int msgId);
int MAILSYS_StepIncompleteNotice(struct MailEditProc *proc);
void MAILSYS_OpenConfirmMenu(struct MailEditProc *proc);
int MAILSYS_PollConfirmMenu(struct MailEditProc *proc);
int MAILSYS_StepQuitConfirm(struct MailEditProc *proc);
/* END mkheaders: generated region */

#endif
