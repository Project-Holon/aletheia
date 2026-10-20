#ifndef GAME_OV106_IRC_RANKING_H
#define GAME_OV106_IRC_RANKING_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of irc_ranking.c, prototypes copied from their definitions. */

struct ProcSys;
struct IrcRankingWork;
struct IrcSeq;
struct Unit;
struct TcbTask;
struct BmpWin;
struct Strbuf;
struct GfFont;
struct Bmp;
typedef struct IrcRankingWork IrcRankingWork;
typedef struct IrcSeq IrcSeq;

#include "../types.h"

int IRC_RANKING_ProcInit(struct ProcSys *procSys, u32 unused, void **args);
int IRC_RANKING_ProcExit(struct ProcSys *procSys, int unused, int *exitMode, IrcRankingWork *work);
int IRC_RANKING_ProcMain(int a, int b, int c, IrcRankingWork *work);
void IRC_RANKING_SeqInit(IrcSeq *seq, IrcRankingWork *work, void (*func)(IrcSeq *, int *, IrcRankingWork *));
void IRC_RANKING_SeqClear(IrcSeq *seq);
void IRC_RANKING_SeqRun(IrcSeq *seq);
u32 IRC_RANKING_SeqIsDone(IrcSeq *seq);
void IRC_RANKING_SeqSetFunc(IrcSeq *seq, void (*func)(IrcSeq *, int *, IrcRankingWork *));
void IRC_RANKING_SeqFinish(IrcSeq *seq);
void IRC_RANKING_SeqFadeIn(IrcSeq *seq, int *step, IrcRankingWork *work);
void IRC_RANKING_SeqFadeOut(IrcSeq *seq, int *step, IrcRankingWork *work);
void IRC_RANKING_SeqBrowse(IrcSeq *seq, int *step, IrcRankingWork *work);
void IRC_RANKING_SeqScrollToLatest(IrcSeq *seq, int *step, IrcRankingWork *work);
void IRC_RANKING_Draw(IrcRankingWork *work);
struct Unit *IRC_RANKING_GetClactUnit(IrcRankingWork *work);
void IRC_RANKING_DisplayVBlankTask(struct TcbTask *task, void *taskWork);
void IRC_RANKING_ListScrollTask(struct TcbTask *task, void *taskWork);
void IRC_RANKING_ClearRowScreens(u16 *screens);
void IRC_RANKING_WriteRowScreen(u16 *screens, u32 bgId, int y, u8 style);
void IRC_RANKING_PrintCentered(struct BmpWin *win, struct Strbuf *text, void *myStatus, struct GfFont *font);
void IRC_RANKING_CopyBmpTiles(struct Bmp *srcBmp, struct Bmp *dstBmp, int srcX, int srcY, u16 dstX, u16 dstY, u16 width, u16 height);
/* END mkheaders: generated region */

#endif
