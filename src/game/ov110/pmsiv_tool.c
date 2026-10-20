/*
 * file:     pmsiv_tool.c
 * unit:     yes
 * function: PMSIV_BGSCROLL_Start, PMSIV_BGSCROLL_Step, PMSIV_BGSCROLL_Task, PMSIV_FADE_StartBlend, PMSIV_FADE_IsBlendDone, PMSIV_FADE_BlendTask, PMSIV_FADE_StartBrightness, PMSIV_FADE_IsBrightnessDone, PMSIV_FADE_BrightnessTask
 * address:  0x021BC78C
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pmsiv_edit.c by tools/splitfile.py.
 *
 * symbols:
 *   TCB_DeleteTask 0x02030EAC arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   PMSIV_FADE_StartBrightness 0x021BC8FC thumb ov110
 *   PMSIV_FADE_IsBrightnessDone 0x021BC93C thumb ov110
 *   PMSIV_BGSCROLL_Start 0x021BC78C thumb ov110
 *   PMSIV_BGSCROLL_Step 0x021BC7DC thumb ov110
 *   PMSIV_FADE_StartBlend 0x021BC868 thumb ov110
 *   PMSIV_FADE_IsBlendDone 0x021BC898 thumb ov110
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   BG_SYS_GetChannelScrollX 0x02041648 arm
 *   BG_SYS_GetChannelScrollY 0x02041664 arm
 *   PMS_INPUT_VIEW_AddVBlankTask 0x021B9BA4 thumb ov110
 */
#include "pms_input_data_shared_types.h"
#include "pms_input_view_shared_types.h"
#include "pmsiv_edit_shared_types.h"

#include "../arm9/tcb_list.h"

#include "../arm9/bg_sys.h"

#include "../arm9/g2.h"



#include "pms_input_view.h"



void PMSIV_BGSCROLL_Start(struct PmsivBgScroll *scroll, int layer, int axis, int step, int frames);

int PMSIV_BGSCROLL_Step(struct PmsivBgScroll *scroll);

void PMSIV_BGSCROLL_Task(void *task, void *arg);

void PMSIV_FADE_StartBlend(struct PmsivFade *fade, int firstPlanes, int secondPlanes, int start, int end, int frames);

int PMSIV_FADE_IsBlendDone(struct PmsivFade *fade);

void PMSIV_FADE_BlendTask(void *task, void *arg);

void PMSIV_FADE_StartBrightness(struct PmsivFade *fade, int plane, int start, int end, int frames);

int PMSIV_FADE_IsBrightnessDone(struct PmsivFade *fade);

void PMSIV_FADE_BrightnessTask(void *task, void *arg);

void PMSIV_BGSCROLL_Start(struct PmsivBgScroll *scroll, int layer, int axis, int step, int frames)
{
    scroll->layer = layer;
    if (axis == 0) {
        scroll->current = BG_SYS_GetChannelScrollX(layer);
        scroll->axis = 0;
    } else {
        scroll->current = BG_SYS_GetChannelScrollY(layer);
        scroll->axis = 3;
    }
    scroll->target = (scroll->current + step) & 511;
    scroll->current <<= 12;
    scroll->step = (step << 12) / frames;
    scroll->framesLeft = frames;
    scroll->state = 0;
}

int PMSIV_BGSCROLL_Step(struct PmsivBgScroll *scroll)
{
    switch (scroll->state) {
    case 0:
        scroll->task = PMS_INPUT_VIEW_AddVBlankTask(PMSIV_BGSCROLL_Task, scroll, 0);
        ++scroll->state;
        break;
    case 1:
        if (scroll->framesLeft == 0) {
            TCB_DeleteTask(scroll->task);
            ++scroll->state;
            return 1;
        }
        break;
    case 2: return 1;
    }
    return 0;
}

void PMSIV_BGSCROLL_Task(void *task, void *arg)
{
    struct PmsivBgScroll *scroll = arg;
    if (scroll->framesLeft) {
        scroll->current += scroll->step;
        BG_SYS_ChangeScrollImmediate((u8)(scroll->layer), (u8)(scroll->axis), (int)(scroll->current >> 12));
        --scroll->framesLeft;
    } else {
        BG_SYS_ChangeScrollImmediate((u8)(scroll->layer), (u8)(scroll->axis), (int)(scroll->target));
    }
}

void PMSIV_FADE_StartBlend(struct PmsivFade *fade, int firstPlanes, int secondPlanes, int start, int end, int frames)
{
    fade->planeMask = firstPlanes;
    fade->secondPlaneMask = secondPlanes;
    fade->framesLeft = frames;
    fade->current = start;
    fade->step = (end - start) / frames;
    fade->target = end;
    fade->done = 0;
    fade->task = PMS_INPUT_VIEW_AddVBlankTask(PMSIV_FADE_BlendTask, fade, 0);
}

int PMSIV_FADE_IsBlendDone(struct PmsivFade *fade)
{
    if (fade->done == 0) {
        if (fade->framesLeft == 0) {
            TCB_DeleteTask(fade->task);
            fade->done += 1;
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}

void PMSIV_FADE_BlendTask(void *task, void *arg)
{
    struct PmsivFade *fade = arg;
    int level;
    if (fade->framesLeft != 0) {
        fade->current += fade->step;
        level = fade->current >> 3;
        fade->framesLeft -= 1;
    } else {
        level = fade->target >> 3;
    }
    if (level > 16) level = 16;
    G2x_SetBlendAlpha_((void *)0x04000050, fade->planeMask, fade->secondPlaneMask, level, 16 - level);
}

/*
 * lever: difference of stored fixed-point fields prevents shift factoring.
 */
void PMSIV_FADE_StartBrightness(struct PmsivFade *fade, int plane, int start, int end, int frames)
{
    G2x_SetBlendBrightness_(0x4000050, plane, start);
    fade->planeMask = plane;
    fade->framesLeft = frames;
    fade->current = start << 12;
    fade->target = end << 12;
    fade->step = (fade->target - fade->current) / frames;
    fade->done = 0;
    fade->task = PMS_INPUT_VIEW_AddVBlankTask(PMSIV_FADE_BrightnessTask, fade, 0);
}

int PMSIV_FADE_IsBrightnessDone(struct PmsivFade *fade)
{
    if (fade->done == 0) {
        if (fade->framesLeft == 0) {
            TCB_DeleteTask(fade->task);
            ++fade->done;
            return 1;
        }
    } else return 1;
    return 0;
}

/*
 * follower: callback PMSIV_FADE_BrightnessTask included in unit; function_starts seed.
 */
void PMSIV_FADE_BrightnessTask(void *task, void *arg)
{
    struct PmsivFade *fade = arg;
    int value;
    if (fade->framesLeft) {
        fade->current += fade->step;
        value = fade->current >> 12;
        --fade->framesLeft;
    } else value = fade->target >> 12;
    G2x_SetBlendBrightness_(0x4000050, fade->planeMask, value);
}
