#ifndef GAME_OV136_MAILTOOL_H
#define GAME_OV136_MAILTOOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mailtool.c, prototypes copied from their definitions. */

struct MailArgs;
struct MailToolProc;

#include "../types.h"

void *MAILTOOL_CreateWriteArgs(void *a, unsigned b, unsigned c, unsigned d, unsigned heap);
void *MAILTOOL_CreateArgsFromPartyMon(void *a, void *b, unsigned heap);
void *MAILTOOL_CreateArgsFromMail(void *a, void *b, unsigned heap);
u32 MAILTOOL_IsMailSent(struct MailArgs *args);
int MAILTOOL_StoreMailToPartyMon(struct MailArgs *args, void *mon);
void MAILTOOL_DeleteArgs(struct MailArgs *args);
int MAILTOOL_ProcInit(void *a, void *b, struct MailArgs *args);
int MAILTOOL_ProcMain(int unused, u32 *state, struct MailArgs *args, struct MailToolProc *proc);
int MAILTOOL_ProcExit(struct Proc *a, void *b, void *c, struct MailToolProc *proc);
void MAILTOOL_StartWordInput(struct MailToolProc *proc, struct MailArgs *args);
/* END mkheaders: generated region */

#endif
