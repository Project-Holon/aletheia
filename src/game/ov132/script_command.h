
struct TcbTask;
#ifndef GAME_OV132_SCRIPT_COMMAND_H
#define GAME_OV132_SCRIPT_COMMAND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of script_command.c, prototypes copied from their definitions. */

struct ScriptTask;
struct ScriptCommandMsg;
typedef struct ScriptCommandMsg ScriptCommandMsg;

int SCRIPT_COMMAND_CmdCameraTo224(void *unused, char *ctx);
int SCRIPT_COMMAND_CmdCameraTo0(void *unused, char *ctx);
int SCRIPT_COMMAND_CmdSetCameraPos(void *unused, char *ctx);
void SCRIPT_COMMAND_TaskCameraPos(struct TcbTask *unused, void *arg);
int SCRIPT_COMMAND_CmdSetCameraTarget(void *unused, char *ctx);
void SCRIPT_COMMAND_TaskCameraTarget(struct TcbTask *unused, void *arg);
int SCRIPT_COMMAND_CmdSkipArg(void *unused,char *p);
int SCRIPT_COMMAND_CmdShowButton(int unused, char **ctx);
int SCRIPT_COMMAND_CmdHideButton(void *unused, void **ctx);
int SCRIPT_COMMAND_GetActorMask(char *p, int requestedMask);
int SCRIPT_COMMAND_CmdSetActorFrame(int unused, char *p);
int SCRIPT_COMMAND_CmdSetActorVisible(int unused, char *p);
int SCRIPT_COMMAND_CmdSetActorPos(int unused,char *p);
int SCRIPT_COMMAND_CmdAddActorPos(int unused,char *p);
void SCRIPT_COMMAND_TaskActorMove(struct TcbTask *unused, void *arg);
int SCRIPT_COMMAND_CmdActorAnimRestart(int unused, char *p);
int SCRIPT_COMMAND_CmdActorAnimPause(int unused, char *p);
int SCRIPT_COMMAND_CmdSetActorFlag(int unused, char *p);
int SCRIPT_COMMAND_CmdSetActorScale(int unused, char *p);
int SCRIPT_COMMAND_CmdSetActorLight(int unused, char *p);
int SCRIPT_COMMAND_CmdPositionAnim(int unused, char *p);
int SCRIPT_COMMAND_CmdSetSelection(int unused,char *p);
int SCRIPT_COMMAND_CmdClearSelection(int unused,char *p);
int SCRIPT_COMMAND_CmdLoadRankAnim(int unused,char *p);
int SCRIPT_COMMAND_CmdLoadAnimMember(int unused,char *p);
int SCRIPT_COMMAND_CmdStartShake(int unused, char *p);
void SCRIPT_COMMAND_TaskShake(struct TcbTask *unused, void *arg);
int SCRIPT_COMMAND_CmdRotateActor(int unused,char *p);
void SCRIPT_COMMAND_TaskRotate(struct TcbTask *unused, void *arg);
int SCRIPT_COMMAND_CmdCompareScores(int unused, ScriptCommandMsg *ctx);
int SCRIPT_COMMAND_CmdSetFlags(int unused, char *p);
int SCRIPT_COMMAND_CmdAddEntry(int unused,char *p);
int SCRIPT_COMMAND_CmdFreeEntry(int unused,char *p);
int SCRIPT_COMMAND_CmdShowEntry(int unused,char *p);
int SCRIPT_COMMAND_CmdHideEntry(int unused,char *p);
int SCRIPT_COMMAND_CmdSetEntryTarget(int unused,char *p);
void SCRIPT_COMMAND_TaskEntryTarget(struct TcbTask *unused, void *arg);
int SCRIPT_COMMAND_CmdSetAnimSlot(int unused,char *p);
int SCRIPT_COMMAND_CmdFreeAnimSlot(int unused,char *p);
int SCRIPT_COMMAND_CmdStartEffect(int unused, char *p);
int SCRIPT_COMMAND_CmdKillEffect(int unused,char *p);
int SCRIPT_COMMAND_CmdMoveEffect(int unused,char *p);
void SCRIPT_COMMAND_TaskMoveEffect(struct TcbTask *unused, void *arg);
int SCRIPT_COMMAND_CmdSetChar(int unused,char **p);
int SCRIPT_COMMAND_CmdFreeChar(int unused,char *p);
int SCRIPT_COMMAND_CmdSetCharPos(int unused,char *p);
void SCRIPT_COMMAND_TaskCharMove(struct TcbTask *unused, void *arg);
int SCRIPT_COMMAND_CmdCharFollowActor(int unused,char *p);
void SCRIPT_COMMAND_TaskCharFollow(struct TcbTask *unused, void *arg);
int SCRIPT_COMMAND_CmdSetCharColor(int unused,char **p);
int SCRIPT_COMMAND_CmdPrintText(int unused,char *p);
int SCRIPT_COMMAND_CmdClearText(void *unused, void **ctx);
int SCRIPT_COMMAND_CmdSetTextColor(int unused,char *p);
int SCRIPT_COMMAND_CmdInstallBgm(int unused, char **ctx);
int SCRIPT_COMMAND_CmdStartSeq(int unused, char **ctx);
int SCRIPT_COMMAND_CmdStopSeq(int unused, char **ctx);
int SCRIPT_COMMAND_CmdReplaceWave(int unused,char *p);
int SCRIPT_COMMAND_CmdPlayBgm(int unused, char **ctx);
int SCRIPT_COMMAND_CmdStopBgm(int unused, char **ctx);
/* END mkheaders: generated region */

#endif
