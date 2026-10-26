
struct TcbTask;
#ifndef GAME_OV110_PMSIV_TOOL_H
#define GAME_OV110_PMSIV_TOOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pmsiv_tool.c, prototypes copied from their definitions. */

struct PmsivBgScroll;
struct PmsivFade;

void PMSIV_BGSCROLL_Start(struct PmsivBgScroll *scroll, int layer, int axis, int step, int frames);
int PMSIV_BGSCROLL_Step(struct PmsivBgScroll *scroll);
void PMSIV_BGSCROLL_Task(struct TcbTask *task, void *arg);
void PMSIV_FADE_StartBlend(struct PmsivFade *fade, int firstPlanes, int secondPlanes, int start, int end, int frames);
int PMSIV_FADE_IsBlendDone(struct PmsivFade *fade);
void PMSIV_FADE_BlendTask(struct TcbTask *task, void *arg);
void PMSIV_FADE_StartBrightness(struct PmsivFade *fade, int plane, int start, int end, int frames);
int PMSIV_FADE_IsBrightnessDone(struct PmsivFade *fade);
void PMSIV_FADE_BrightnessTask(struct TcbTask *task, void *arg);
/* END mkheaders: generated region */

#endif
