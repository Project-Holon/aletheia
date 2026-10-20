#ifndef GAME_OV137_GURU2_H
#define GAME_OV137_GURU2_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of guru2.c, prototypes copied from their definitions. */

struct Guru2Param;
struct Guru2Entry;
struct Guru2Session;
struct Guru2PartyListParam;
struct Guru2Comm;

int GURU2_EntryProcInit(void *obj,int seq,struct Guru2Param *param);
int GURU2_EntryProcMain(void *obj,int seq,int parentWork,struct Guru2Entry *p);
int GURU2_EntryProcExit(void *obj,int seq,int parentWork,struct Guru2Entry *p);
struct Guru2Session *GURU2_SessionCreate(struct Guru2Param *param,int heap);
void GURU2_SessionDestroy(struct Guru2Session *p);
unsigned int GURU2_SessionGetArgs(struct Guru2Session *p);
int GURU2_EntryStateStartReceipt(struct Guru2Entry *p);
struct Guru2PartyListParam *GURU2_PartyListArgsCreate(struct Guru2Entry *p,int listType,int cursor);
int GURU2_EntryStateOpenPartyList(struct Guru2Entry *p);
int GURU2_EntryStateAfterPartyList(struct Guru2Entry *p);
int GURU2_EntryStateReopenPartyList(struct Guru2Entry *p);
int GURU2_EntryStateFinish(struct Guru2Entry *p);
int GURU2_EntryStateDestroySession(struct Guru2Entry *p);
void *GURU2_GetUnionApp(struct Guru2Comm *p);
/* END mkheaders: generated region */

#endif
