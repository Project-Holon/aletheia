#ifndef GAME_OV010_FLD_FACEUP_H
#define GAME_OV010_FLD_FACEUP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fld_faceup.c, prototypes copied from their definitions. */

struct ScriptVm;
struct ScrcmdWork;
struct FaceUpEndWork;
struct GameEvent;
typedef struct FaceUpEndWork FaceUpEndWork;

int FLD_FACEUP_ScrCmdStart(struct ScriptVm *vm, struct ScrcmdWork *work);
int FLD_FACEUP_ScrCmdPrepareField(struct ScriptVm *vm, struct ScrcmdWork *work);
int FLD_FACEUP_ScrCmdWaitEnd(struct ScriptVm *vm, struct ScrcmdWork *work);
int FLD_FACEUP_Finish(FaceUpEndWork *work);
int FLD_FACEUP_EndEvent(struct GameEvent *event, int *seq);
/* END mkheaders: generated region */

#endif
