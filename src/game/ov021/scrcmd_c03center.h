#ifndef GAME_OV021_SCRCMD_C03CENTER_H
#define GAME_OV021_SCRCMD_C03CENTER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_c03center.c, prototypes copied from their definitions. */

struct ScriptVm;
struct ScrcmdWork;
struct TcbTask;
struct CameraTurnTask;
typedef struct CameraTurnTask CameraTurnTask;

int SCRCMD_C03CENTER_TurnCameraToQuarter(struct ScriptVm *vm, struct ScrcmdWork *work);
void SCRCMD_C03CENTER_CameraTurnTaskMain(struct TcbTask *tcb, void *arg);
/* END mkheaders: generated region */

#endif
