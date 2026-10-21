/*
 * file:     intro_cmd.c
 * unit:     yes
 * function: INTRO_CMD_CmdFade, INTRO_CMD_CmdBrightnessSet, INTRO_CMD_CmdBrightnessChange, INTRO_CMD_CmdBrightnessWait, INTRO_CMD_CmdBgmChange, INTRO_CMD_CmdBgmWait, INTRO_CMD_CmdBgmFadeOut, INTRO_CMD_CmdBgmFadeIn, INTRO_CMD_CmdSe, INTRO_CMD_CmdSeStop, INTRO_CMD_CmdWaitInput, INTRO_CMD_CmdSetMsgBank, INTRO_CMD_CmdSub, INTRO_CMD_CmdPrintText, INTRO_CMD_CmdDrawWindowBorder, INTRO_CMD_CmdAddSlot, INTRO_CMD_CmdSetVanishFlag, INTRO_CMD_CmdSetSlotAnim, INTRO_CMD_CmdGetSlotAnimFinished, INTRO_CMD_CmdClearSlotAnimFinished, INTRO_CMD_CmdMoveSlot, INTRO_CMD_CmdSlotAlpha, INTRO_CMD_CmdPrintAndMepachi, INTRO_CMD_CmdSaveStart, INTRO_CMD_CmdSavePause, INTRO_CMD_CmdSaveResume, INTRO_CMD_CmdSaveNoOp, INTRO_CMD_CmdSaveTimeIcon, INTRO_CMD_CmdSetAppliedFlag, INTRO_CMD_CmdSetConfig, INTRO_CMD_CmdMoveVoice, INTRO_CMD_CmdParticle, INTRO_CMD_CmdSetVisible, INTRO_CMD_CmdSetAnimFrame, INTRO_CMD_CmdUpdateIntro, INTRO_CMD_CmdAnimMode, INTRO_CMD_CmdUpdateAnimFrame, INTRO_CMD_CmdDrawTile, INTRO_CMD_CmdSetTile, INTRO_CMD_CreateActors, INTRO_CMD_DeleteActors, INTRO_CMD_CmdActorFadeIn, INTRO_CMD_CmdActorFadeOut, INTRO_CMD_CmdCheckConfig, INTRO_CMD_CmdSetWordSet, INTRO_CMD_Create, INTRO_CMD_Delete, INTRO_CMD_Main, INTRO_CMD_AddCommand, INTRO_CMD_RunCommands, INTRO_CMD_ClearCommand, INTRO_CMD_GetScenarioRow
 * address:  0x021BE328
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from intro_cmd.c by tools/splitfile.py.
 *
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   BRIGHTNESS_ChangeRequest 0x02023EF4 thumb
 *   BRIGHTNESS_IsFinished 0x02024004 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_SetSeSlotVolume 0x020062BC thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 *   gIntroCmdHandlerTable 0x021C09D4 data a4
 *   INTRO_G3D_AddPokemonSlot 0x021BF67C thumb ov204
 *   INTRO_G3D_SetSlotMepachi 0x021BF7CC thumb ov204
 *   gIntroMcssArg 0x021BFFE4 data a1
 *   INTRO_G3D_SetVanishFlag 0x021BF720 thumb ov204
 *   INTRO_G3D_SetSlotAnim 0x021BF744 thumb ov204
 *   INTRO_G3D_GetSlotAnimFinished 0x021BF77C thumb ov204
 *   INTRO_G3D_ClearSlotAnimFinished 0x021BF788 thumb ov204
 *   INTRO_G3D_MoveSlot 0x021BF804 thumb ov204
 *   INTRO_G3D_SetSlotAlpha 0x021BF794 thumb ov204
 *   SAVE_CONTROL_INTR_Start 0x021BD2B0 thumb
 *   SAVE_CONTROL_INTR_Pause 0x021BD368 thumb ov088
 *   SAVE_CONTROL_INTR_IsPausedOrFinished 0x021BD380 thumb ov088
 *   SAVE_CONTROL_INTR_Resume 0x021BD374 thumb ov088
 *   SAVE_CONTROL_INTR_NoOp 0x021BD39C thumb ov088
 *   SAVE_CONTROL_INTR_IsFinished 0x021BD3A0 thumb ov088
 *   CONFIG_SetTextLanguage 0x020083EC thumb
 *   MYSTATUS_SetSex 0x0200854C thumb
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb
 *   PM_VOICE_Start  0x02006A64  thumb
 *   PM_VOICE_IsSlotActive  0x02006BD0  thumb
 *   INTRO_G3D_MoveSlot1  0x021BF864  thumb ov204
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   INTRO_PARTICLE_StartEffect 0x021BFCE8 thumb ov204
 *   INTRO_G3D_SetVisible 0x021BFAE4 thumb
 *   INTRO_G3D_SetAnimFrame 0x021BFBC8 thumb
 *   INTRO_G3D_UpdateIntro 0x021BFA40 thumb ov204
 *   INTRO_G3D_SetAnimMode 0x021BFAE8 thumb ov204
 *   INTRO_G3D_UpdateAnimMode 0x021BFB2C thumb ov204
 *   KEY_GetTrg 0x020362DC arm
 *   INTRO_G3D_UpdateAnimFrame 0x021BFBA0 thumb ov204
 *   BG_SYS_DrawTileSub 0x020411E8 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   MYSTATUS_GetSex 0x02008550 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   INTRO_GRAPHIC_GetClactOwner 0x021BDD78 thumb ov204
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   gIntroActorPos 0x021BFFCC data a2
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_GetActorObjMode 0x0204B6E4 arm
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   gIntroCmdSite 0x021C0AAC data a1
 *   GFL_HEAP_Free 0x020307B0 arm
 *   gIntroCmdCommandTable 0x021C09D8 data a4
 *   gIntroScenarioTables 0x021C0AB8 data a4
 *   gIntroSite 0x021C0AE4 data a1
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   BRIGHTNESS_Set  0x02023F60  thumb  arm9
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb  arm9
 *   INTRO_MSG_Create 0x021BF0A0 thumb ov204
 *   INTRO_MSG_Delete 0x021BF1A4 thumb ov204
 *   INTRO_MSG_SetMsgBank 0x021BF204 thumb ov204
 *   INTRO_MSG_Main 0x021BF228 thumb ov204
 *   INTRO_MSG_PrintText 0x021BF23C thumb ov204
 *   INTRO_MSG_DrawWindowBorder 0x021BF2D4 thumb ov204
 *   INTRO_MSG_GetPrintState 0x021BF2E0 thumb ov204
 *   INTRO_MSG_UpdatePrint 0x021BF2F4 thumb ov204
 *   INTRO_MSG_GetWordSet 0x021BF55C thumb ov204
 *   INTRO_MSG_StartTimeIcon 0x021BF560 thumb ov204
 *   INTRO_MSG_DeleteTimeIcon 0x021BF580 thumb ov204
 *   INTRO_MCSS_AddSlot 0x021BF624 thumb ov204
 */
#include "intro_types.h"
#include "../sdk_ioreg.h"

struct MyStatus;

struct Actor;

#include "../types.h"

#include "../bool_types.h"
enum { B_FALSE, B_TRUE };

typedef struct {u16 v[12];} IntroActorPos;

#include "../arm9/fade.h"


#include "../arm9/brightness.h"



#include "../arm9/gfl_use.h"




extern void GFL_USE_PlaySeDefaultVolume(unsigned),GFL_USE_SetSeSlotVolume(int,unsigned),GFL_USE_SetSeSlotParams(int,unsigned,unsigned,unsigned);



#include "../arm9/touchpanel.h"

#include "../arm9/key.h"

#include "intro_g3d.h"







struct SaveControlIntr;

#include "../ov088/save_control_intr.h"






#include "../arm9/config.h"

extern void MYSTATUS_SetSex(struct MyStatus*,u32);



#include "../arm9/pm_voice.h"



#include "../arm9/g2.h"

#include "intro_particle.h"







#include "../arm9/bg_sys.h"




#include "../arm9/arc_tool.h"
struct MyStatus;

extern u32 MYSTATUS_GetSex(const struct MyStatus *mystatus);

#include "../arm9/clact.h"




#include "intro_graphic.h"









#include "../arm9/wordset.h"

#include "../arm9/gfl_heap_wrap.h"


int INTRO_CMD_CmdFade(char *p,int *state,int *q);

u32 INTRO_CMD_CmdBrightnessSet(u32 a, u32 b, u32 *c);

int INTRO_CMD_CmdBrightnessChange(int ctx, int unused, int *src);

int INTRO_CMD_CmdBrightnessWait(void);

u32 INTRO_CMD_CmdBgmChange(u32 a, u32 b, u32 *c);

u32 INTRO_CMD_CmdBgmWait(void);

int INTRO_CMD_CmdBgmFadeOut(int a, int b, int *p);

int INTRO_CMD_CmdBgmFadeIn(int a, int b, int *p);

int INTRO_CMD_CmdSe(char *p,int *state,unsigned *q);

int INTRO_CMD_CmdSeStop(int a, int b, int *p);

u32 INTRO_CMD_CmdWaitInput(void);

int INTRO_CMD_CmdSetMsgBank(char *p,int *state,unsigned *q);

int INTRO_CMD_CmdSub(char *p,int *state,int *q);

int INTRO_CMD_CmdPrintText(char *p,int *state,unsigned *q);

int INTRO_CMD_CmdDrawWindowBorder(char *p,int *state,int *q);

int INTRO_CMD_CmdAddSlot(char *p, int unused, unsigned *q);

int INTRO_CMD_CmdSetVanishFlag(char *p,int *state,int *q);

int INTRO_CMD_CmdSetSlotAnim(char *p,int *state,unsigned *q);

unsigned INTRO_CMD_CmdGetSlotAnimFinished(char *p,int *state,unsigned *q);

int INTRO_CMD_CmdClearSlotAnimFinished(char *p,int *state,unsigned *q);

int INTRO_CMD_CmdMoveSlot(char *p,int *state,int *q);

int INTRO_CMD_CmdSlotAlpha(char *p, int *state, unsigned *q);

int INTRO_CMD_CmdPrintAndMepachi(char *p, int *state, unsigned *q);

int INTRO_CMD_CmdSaveStart(char *a);

int INTRO_CMD_CmdSavePause(char *p,int *state,unsigned *q);

int INTRO_CMD_CmdSaveResume(char *a);

int INTRO_CMD_CmdSaveNoOp(char *a);

int INTRO_CMD_CmdSaveTimeIcon(char *p, int *state);

int INTRO_CMD_CmdSetAppliedFlag(u8*p,u32 unused,u32*q);

int INTRO_CMD_CmdSetConfig(u8*p,u32 unused,u32*q);

int INTRO_CMD_CmdMoveVoice(u8 *p, u32 *q);

int INTRO_CMD_CmdParticle(u8*p,u32 unused,u32*q);

int INTRO_CMD_CmdSetVisible(char *a, int b, int *p);

int INTRO_CMD_CmdSetAnimFrame(char *a, int b, int *p);

int INTRO_CMD_CmdUpdateIntro(u8*p);

int INTRO_CMD_CmdAnimMode(char *p,u32 *q);

int INTRO_CMD_CmdUpdateAnimFrame(u8*p);

int INTRO_CMD_CmdDrawTile(IntroCmdWork *p,u32 *q);

int INTRO_CMD_CmdSetTile(void *p,u32 *q);

int INTRO_CMD_CreateActors(char *p);

int INTRO_CMD_DeleteActors(char *p);

int INTRO_CMD_CmdActorFadeIn(char *p, unsigned *state, unsigned *q);

int INTRO_CMD_CmdActorFadeOut(char *p, unsigned *state, unsigned *q);

int INTRO_CMD_CmdCheckConfig(u8*p);

void INTRO_CMD_CmdSetWordSet(u8*p,u32 a);

char *INTRO_CMD_Create(void *a, unsigned b, unsigned c, char *d, unsigned e, unsigned short heap);

void INTRO_CMD_Delete(u8*p);

int INTRO_CMD_Main(char *p);

int INTRO_CMD_AddCommand(IntroCmdWork *p, IntroCommand *q);

int INTRO_CMD_RunCommands(IntroCmdWork *p);

void INTRO_CMD_ClearCommand(IntroCmdWork *p, u8 i);

IntroCommand *INTRO_CMD_GetScenarioRow(u32 n);

#include "intro_msg.h"











#include "intro_mcss.h"

extern const char gIntroMcssArg[];

extern const IntroActorPos gIntroActorPos;

extern const char gIntroCmdSite[];

extern const u32 gIntroScenarioTables[];

int INTRO_CMD_CmdFade(char *p,int *state,int *q){switch(*state){case 0:FADE_Start(q[0],q[1],q[2],q[3]);(*state)++;break;case 1:if(FADE_IsActive()==0)return 1;break;}return 0;}

/*
 * Addresses are Black-image addresses.
 */
u32 INTRO_CMD_CmdBrightnessSet(u32 a, u32 b, u32 *c)
{
    BRIGHTNESS_Set((s16)*c, 0x1d, 1);
    return 1;
}

int INTRO_CMD_CmdBrightnessChange(int ctx, int unused, int *src)
{
    BRIGHTNESS_ChangeRequest((unsigned char)src[0], (short)src[1], (short)src[2], 0x1d, 1);
    return 1;
}

int INTRO_CMD_CmdBrightnessWait(void) {BRIGHTNESS_IsFinished(1);return 1;}

u32 INTRO_CMD_CmdBgmChange(u32 ctx, u32 unused, u32 *src)
{
    GFL_USE_CancelChangeAndPlayBgm(*src, 0xffff);
    return 1;
}

u32 INTRO_CMD_CmdBgmWait(void)
{
    if (GFL_USE_IsBgmPlaying() != 0) {
        return 1;
    }
    return 0;
}

int INTRO_CMD_CmdBgmFadeOut(int a, int b, int *p)
{
    GFL_USE_FadeOutBgm((unsigned short)*p);
    return 1;
}

int INTRO_CMD_CmdBgmFadeIn(int a, int b, int *p)
{
    GFL_USE_FadeInBgmFull((unsigned short)*p);
    return 1;
}

int INTRO_CMD_CmdSe(char *p,int *state,unsigned *q){int i;GFL_USE_PlaySeDefaultVolume(q[0]);i=GFL_USE_GetSeSlot(q[0]);if(q[1])GFL_USE_SetSeSlotVolume(i,q[1]);if(q[2])GFL_USE_SetSeSlotParams(i,-1,-1,q[2]);return 1;}

int INTRO_CMD_CmdSeStop(int a, int b, int *p)
{
    GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(*p));
    return 1;
}

u32 INTRO_CMD_CmdWaitInput(void)
{
    if (TOUCHPANEL_GetTrg() != 0 || KEY_GetTrg() != 0) {
        return 1;
    }
    return 0;
}

int INTRO_CMD_CmdSetMsgBank(char *p,int *state,unsigned *q){IntroCmdWork *work=(IntroCmdWork *)p;INTRO_MSG_SetMsgBank(work->msg,q[0],q[1]);return 1;}

extern int (*const gIntroCmdHandlerTable[])(char *,int);

int INTRO_CMD_CmdSub(char *p,int *state,int *q){gIntroCmdHandlerTable[q[0]](p,q[1]);return 1;}

int INTRO_CMD_CmdPrintText(char *p,int *state,unsigned *q){IntroCmdWork *work=(IntroCmdWork *)p;switch(*state){case 0:INTRO_MSG_PrintText(work->msg,(void *)q[0],q[1]);(*state)++;break;case 1:if(INTRO_MSG_UpdatePrint(work->msg))return 1;break;}return 0;}

int INTRO_CMD_CmdDrawWindowBorder(char *p,int *state,int *q){IntroCmdWork *work=(IntroCmdWork *)p;INTRO_MSG_DrawWindowBorder((u8 *)work->msg);return 1;}

int INTRO_CMD_CmdAddSlot(char *p, int unused, unsigned *q)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    if (q[1] == 0) {
        INTRO_MCSS_AddSlot(work->mcss, q[2], q[3], 0, (void *)gIntroMcssArg, q[0]);
        INTRO_G3D_SetSlotMepachi(work->mcss, q[0], 1);
    } else {
        INTRO_G3D_AddPokemonSlot(work->mcss, q[2], q[3], 0x1000, q[1], q[0]);
    }
    return 1;
}

int INTRO_CMD_CmdSetVanishFlag(char *p,int *state,int *q){IntroCmdWork *work=(IntroCmdWork *)p;INTRO_G3D_SetVanishFlag(work->mcss,q[1],q[0]);return 1;}

/*
 * follower: tail-call stub 0x021BE53C included; function_starts seed.
 */
int INTRO_CMD_CmdSetSlotAnim(char *p,int *state,unsigned *q){IntroCmdWork *work=(IntroCmdWork *)p;INTRO_G3D_SetSlotAnim(work->mcss,(unsigned char)q[0],q[1],q[2]);return 1;}

unsigned INTRO_CMD_CmdGetSlotAnimFinished(char *p,int *state,unsigned *q){IntroCmdWork *work=(IntroCmdWork *)p;return INTRO_G3D_GetSlotAnimFinished(work->mcss,q[0]);}

int INTRO_CMD_CmdClearSlotAnimFinished(char *p,int *state,unsigned *q){IntroCmdWork *work=(IntroCmdWork *)p;INTRO_G3D_ClearSlotAnimFinished((u8 *)work->mcss,q[0]);return 1;}

int INTRO_CMD_CmdMoveSlot(char *p,int *state,int *q){IntroCmdWork *work=(IntroCmdWork *)p;return INTRO_G3D_MoveSlot(work->mcss,(unsigned char)q[0],q[1],q[2]);}

int INTRO_CMD_CmdSlotAlpha(char *p, int *state, unsigned *q)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    switch (*state) {
    case 0:
        if (q[1] != 0)
            INTRO_G3D_SetSlotAlpha(work->mcss, q[0], (unsigned char)1);
        else
            INTRO_G3D_SetSlotAlpha(work->mcss, q[0], (unsigned char)31);
        INTRO_G3D_SetVanishFlag(work->mcss, 1, q[0]);
        state[1] = 31;
        ++*state;
        break;
    case 1:
        state[1] -= 2;
        if (state[1] <= 0) {
            INTRO_G3D_SetSlotAlpha(work->mcss, q[0], (unsigned char)31);
            INTRO_G3D_SetVanishFlag(work->mcss, q[1], q[0]);
            return 1;
        }
        if (q[1] == 1)
            INTRO_G3D_SetSlotAlpha(work->mcss, q[0], (unsigned char)(31 - state[1]));
        else if (q[1] == 0)
            INTRO_G3D_SetSlotAlpha(work->mcss, q[0], (unsigned char)state[1]);
        break;
    }
    return 0;
}

int INTRO_CMD_CmdPrintAndMepachi(char *p, int *state, unsigned *q)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    uptr index = q[0];
    unsigned other = q[1];
    switch (*state) {
    case 0:
        INTRO_MSG_PrintText(work->msg, (void *)index, q[2]);
        ++*state;
        break;
    case 1:
        if (INTRO_MSG_UpdatePrint(work->msg) != 0) {
            INTRO_G3D_SetSlotMepachi(work->mcss, other, 1);
            return 1;
        }
        switch (INTRO_MSG_GetPrintState(work->msg)) {
        case 1:
            INTRO_G3D_SetSlotMepachi(work->mcss, other, 1);
            state[1] = 0;
            break;
        case 0:
            INTRO_G3D_SetSlotMepachi(work->mcss, other, state[1] % 12 < 6 ? 1 : 0);
            state[1]++;
            break;
        case 2:
            break;
        }
        break;
    }
    return 0;
}

int INTRO_CMD_CmdSaveStart(char *a)
{
    IntroCmdWork *work = (IntroCmdWork *)a;
    SAVE_CONTROL_INTR_Start(work->saveControl);
    return 1;
}

int INTRO_CMD_CmdSavePause(char *p,int *state,unsigned *q){IntroCmdWork *work=(IntroCmdWork *)p;switch(*state){case 0:SAVE_CONTROL_INTR_Pause(work->saveControl);(*state)++;break;case 1:if(SAVE_CONTROL_INTR_IsPausedOrFinished(work->saveControl)==1)return 1;break;}return 0;}

int INTRO_CMD_CmdSaveResume(char *a)
{
    IntroCmdWork *work = (IntroCmdWork *)a;
    SAVE_CONTROL_INTR_Resume((struct SaveControlIntr *)work->saveControl);
    return 1;
}

/*
 * UNBLOCKED: 0x021BD39C is now an EXACT entry in layout/matched/ov088 (the
 * only overlay in the window that does not overlap the caller's ov204), so
 * the bl gIntroSite resolves as matched and the verdict promoted to EXACT.
 */
int INTRO_CMD_CmdSaveNoOp(char *a)
{
    IntroCmdWork *work = (IntroCmdWork *)a;
    SAVE_CONTROL_INTR_NoOp((void *)((sptr)work->saveControl));
    return 1;
}

int INTRO_CMD_CmdSaveTimeIcon(char *p, int *state)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    switch (*state) {
    case 0:
        if (SAVE_CONTROL_INTR_IsFinished(work->saveControl) == 1)
            return 1;
        INTRO_MSG_PrintText(work->msg, (void *)5, 0);
        ++*state;
        break;
    case 1:
        if (INTRO_MSG_UpdatePrint(work->msg) == 1) {
            INTRO_MSG_StartTimeIcon(work->msg);
            ++*state;
        }
        break;
    case 2:
        if (SAVE_CONTROL_INTR_IsFinished(work->saveControl) == 1) {
            INTRO_MSG_DeleteTimeIcon(work->msg);
            return 1;
        }
        break;
    }
    return 0;
}

int INTRO_CMD_CmdSetAppliedFlag(u8*p,u32 unused,u32*q){IntroCmdWork *work=(IntroCmdWork *)p;u16*obj=(u16 *)((IntroArgs *)work->args)->appliedFlag;Bool flag;if(*q==0)flag=B_FALSE;else flag=B_TRUE;CONFIG_SetTextLanguage((struct Config *)obj,flag);return 1;}

/*
 * prototype: 0200854C widened to u32: original has no byte truncation; its u8 prototype added a shift pair.
 */
int INTRO_CMD_CmdSetConfig(u8*p,u32 unused,u32*q){IntroCmdWork *work=(IntroCmdWork *)p;struct MyStatus*obj=((IntroArgs *)work->args)->myStatus;Bool flag;if(*q==0)flag=B_FALSE;else flag=B_TRUE;MYSTATUS_SetSex(obj,flag);return 1;}

int INTRO_CMD_CmdMoveVoice(u8 *p, u32 *q)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    switch (*q) {
    case 0:
        if (q[1] == 3) {
            q[1] = 0;
            (*q)++;
        } else {
            q[1] = q[1] + 1;
        }
        break;
    case 1:
        if (INTRO_G3D_MoveSlot1(work->mcss, 0x1000, 0xFFFF4800) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x7F5);
            (*q)++;
        }
        break;
    case 2:
        if (GFL_USE_IsAnySeBusy() == 0) {
            INTRO_G3D_SetSlotAnim(work->mcss, 1, 0, 1);
            PM_VOICE_Start(((IntroArgs *)work->args)->voiceId);
            (*q)++;
        }
        break;
    case 3:
        if (PM_VOICE_IsSlotActive(((IntroArgs *)work->args)->voiceId) == 0) {
            *q = 0;
            return 1;
        }
        break;
    }
    return 0;
}

int INTRO_CMD_CmdParticle(u8*p,u32 unused,u32*q){IntroCmdWork *work=(IntroCmdWork *)p;G2x_SetBlendAlpha_((void*)REG_BLDCNT_ADDR,1,9,0,0);INTRO_PARTICLE_StartEffect(work->particle,q[0],q[1],0);return 1;}

int INTRO_CMD_CmdSetVisible(char *a, int b, int *p)
{
    IntroCmdWork *work = (IntroCmdWork *)a;
    INTRO_G3D_SetVisible(work->g3d, *p);
    return 1;
}

int INTRO_CMD_CmdSetAnimFrame(char *a, int b, int *p)
{
    IntroCmdWork *work = (IntroCmdWork *)a;
    INTRO_G3D_SetAnimFrame(work->g3d, *p);
    return 1;
}

int INTRO_CMD_CmdUpdateIntro(u8*p){IntroCmdWork *work=(IntroCmdWork *)p;if(INTRO_G3D_UpdateIntro(work->g3d))return 1;return 0;}

/*
 * lever: load the case-2 object once before q[1]'s comparison and reuse
 *   it in both arms; repeated arm loads gave 220 bytes/80 different.
 */
int INTRO_CMD_CmdAnimMode(char *p,u32 *q)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    struct MyStatus *obj;
    switch (*q) {
    case 0:
        INTRO_G3D_SetAnimMode(work->g3d,0);
        *q=4;
        break;
    case 1:
        if (KEY_GetTrg()&16) {
            if (q[1]!=1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                INTRO_G3D_SetAnimMode(work->g3d,2);
                q[1]=1;
                *q=4;
            }
        } else if (KEY_GetTrg()&32) {
            if (q[1]!=0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                INTRO_G3D_SetAnimMode(work->g3d,1);
                q[1]=0;
                *q=4;
            }
        } else if (KEY_GetTrg()&1) {
            GFL_USE_PlaySeDefaultVolume(0x54D);
            (*q)++;
        }
        break;
    case 2:
        obj=((IntroArgs *)work->args)->myStatus;
        if (q[1]==0) {
            MYSTATUS_SetSex(obj,0);
            INTRO_G3D_SetAnimMode(work->g3d,3);
        } else {
            MYSTATUS_SetSex(obj,1);
            INTRO_G3D_SetAnimMode(work->g3d,4);
        }
        (*q)++;
        break;
    case 3:
        if (INTRO_G3D_UpdateAnimMode(work->g3d)!=0) return 1;
        break;
    case 4:
        if (INTRO_G3D_UpdateAnimMode(work->g3d)!=0) *q=1;
        break;
    }
    return 0;
}

int INTRO_CMD_CmdUpdateAnimFrame(u8*p){IntroCmdWork *work=(IntroCmdWork *)p;if(INTRO_G3D_UpdateAnimFrame((int *)work->g3d))return 1;return 0;}

/*
 * lever: unsigned integer p+0xA8 at the first paired call, member address
 *   at the second, keeps equivalent addresses apart; pointer-only was 364
 *   bytes/275 different, this spelling EXACT380 (existing distinct-arithmetic idiom).
 */
int INTRO_CMD_CmdDrawTile(IntroCmdWork *p,u32 *q)
{
    switch (*q) {
    case 0:
        BG_SYS_SetPlaneVisible(2,1);
        BG_SYS_DrawTileSub(2,0,8,64,2,(const void *)((uptr)p->data),0,8,64,32);
        BG_SYS_MarkTileDirty(2);
        (*q)++;
        break;
    case 1:
        BG_SYS_DrawTileSub(2,0,7,64,1,(const void *)((uptr)p+0xA8),0,7,64,32);
        BG_SYS_DrawTileSub(2,0,10,64,1,(const void *)((uptr)p->data),0,10,64,32);
        BG_SYS_MarkTileDirty(2);
        (*q)++;
        break;
    case 2:
        BG_SYS_DrawTileSub(2,0,6,64,1,(const void *)((uptr)p+0xA8),0,6,64,32);
        BG_SYS_DrawTileSub(2,0,11,64,1,(const void *)((uptr)p->data),0,11,64,32);
        BG_SYS_MarkTileDirty(2);
        (*q)++;
        break;
    case 3:
        BG_SYS_DrawTileSub(2,0,5,64,1,(const void *)((uptr)p+0xA8),0,5,64,32);
        BG_SYS_DrawTileSub(2,0,12,64,1,(const void *)((uptr)p->data),0,12,64,32);
        BG_SYS_MarkTileDirty(2);
        (*q)++;
        break;
    case 4:
        BG_SYS_DrawTileSub(2,0,4,64,1,(const void *)((uptr)p+0xA8),0,4,64,32);
        BG_SYS_DrawTileSub(2,0,13,64,1,(const void *)((uptr)p->data),0,13,64,32);
        BG_SYS_MarkTileDirty(2);
        *q=0;
        return 1;
    }
    return 0;
}

/*
 * extent: two bytes of zero alignment at 0x021BEBEA.
 */
int INTRO_CMD_CmdSetTile(void *p,u32 *q)
{
    switch (*q) {
    case 0:
        BG_SYS_SetTileEntry(2,0,0,7,64,1,0);
        BG_SYS_SetTileEntry(2,0,0,16,64,1,0);
        BG_SYS_MarkTileDirty(2);
        (*q)++;
        break;
    case 1:
        BG_SYS_SetTileEntry(2,0,0,8,64,1,0);
        BG_SYS_SetTileEntry(2,0,0,15,64,1,0);
        BG_SYS_MarkTileDirty(2);
        (*q)++;
        break;
    case 2:
        BG_SYS_SetTileEntry(2,0,0,6,64,1,0);
        BG_SYS_SetTileEntry(2,0,0,14,64,1,0);
        BG_SYS_MarkTileDirty(2);
        (*q)++;
        break;
    case 3:
        BG_SYS_SetTileEntry(2,0,0,5,64,1,0);
        BG_SYS_SetTileEntry(2,0,0,13,64,1,0);
        BG_SYS_MarkTileDirty(2);
        (*q)++;
        break;
    case 4:
        BG_SYS_SetPlaneVisible(2,0);
        *q=0;
        return 1;
    }
    return 0;
}

int INTRO_CMD_CreateActors(char *p)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    IntroActorPos local;
    void *arc;
    u32 i;
    char *row;
    arc=ARC_TOOL_CreateHandle(170,work->heapId);
    if(MYSTATUS_GetSex((struct MyStatus *)(((IntroArgs *)work->args)->myStatus))==0){
        work->charHandle[0].ptr=(void *)CLACT_RegisterCharacter(arc,6,0,0,work->heapId);
        work->palHandle[0].ptr=(void *)CLACT_RegisterPalette(arc,7,0,0,work->heapId);
        work->cellAnimHandle[0].ptr=(void *)CLACT_RegisterCellAnim(arc,5,4,work->heapId);
    }else{
        work->charHandle[0].ptr=(void *)CLACT_RegisterCharacter(arc,10,0,0,work->heapId);
        work->palHandle[0].ptr=(void *)CLACT_RegisterPalette(arc,11,0,0,work->heapId);
        work->cellAnimHandle[0].ptr=(void *)CLACT_RegisterCellAnim(arc,9,8,work->heapId);
    }
    work->charHandle[1].ptr=(void *)CLACT_RegisterCharacter(arc,17,0,0,work->heapId);
    work->palHandle[1].ptr=(void *)CLACT_RegisterPalette(arc,18,0,32,work->heapId);
    work->cellAnimHandle[1].ptr=(void *)CLACT_RegisterCellAnim(arc,16,15,work->heapId);
    work->charHandle[2].ptr=(void *)CLACT_RegisterCharacter(arc,21,0,0,work->heapId);
    work->palHandle[2].ptr=(void *)CLACT_RegisterPalette(arc,22,0,64,work->heapId);
    work->cellAnimHandle[2].ptr=(void *)CLACT_RegisterCellAnim(arc,20,19,work->heapId);
    ARC_TOOL_DeleteHandle(arc);
    local=gIntroActorPos;
    for(i=0;i<3;i++){
        row=p+i*4;
        work->actor[i]=(void *)CLACT_CreateActor((void *)INTRO_GRAPHIC_GetClactOwner((char *)work->display),(uptr)work->charHandle[i].ptr,(uptr)work->palHandle[i].ptr,(uptr)work->cellAnimHandle[i].ptr,(const struct ActorInitParam *)((char *)&local+i*8),0,work->heapId);
        CLACT_SetActorDrawEnable(work->actor[i],0);
    }
    return 1;
}

int INTRO_CMD_DeleteActors(char *p)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    unsigned i;
    for (i = 0; i < 3; i++) {
        CLACT_ReleaseCharacter(work->charHandle[i].id);
        CLACT_ReleasePalette(work->palHandle[i].id);
        CLACT_ReleaseCellAnim(work->cellAnimHandle[i].id);
        CLACT_DeleteActor(work->actor[i]);
    }
    return 1;
}

static inline void change_alpha(int a, int b)
{
    *(volatile unsigned short *)0x04000052 = (unsigned short)(a | (b << 8));
}

int INTRO_CMD_CmdActorFadeIn(char *p, unsigned *state, unsigned *q)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    unsigned i;
    switch (*state) {
    case 0:
        G2x_SetBlendAlpha_((unsigned int *)REG_BLDCNT_ADDR, 0, 12, 0, 16);
        CLACT_SetActorObjMode(work->actor[q[0]], 1);
        CLACT_SetActorDrawEnable(work->actor[q[0]], 1);
        ++*state;
        break;
    case 16:
        for (i = 0; i < 3; i++) {
            if (CLACT_GetActorObjMode(work->actor[i]) == 1)
                CLACT_SetActorObjMode(work->actor[i], 0);
        }
        *state = 0;
        return 1;
    default:
        ++*state;
        change_alpha(*state, 16 - *state);
        break;
    }
    return 0;
}

/*
 * volatile: hardware BLDALPHA write at 021BEEDC.
 */
int INTRO_CMD_CmdActorFadeOut(char *p, unsigned *state, unsigned *q)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    unsigned i;
    switch (*state) {
    case 0:
        G2x_SetBlendAlpha_((unsigned int *)REG_BLDCNT_ADDR, 0, 12, 16, 0);
        for (i = 0; i < 3; i++)
            CLACT_SetActorObjMode(work->actor[i], 1);
        ++*state;
        break;
    case 16:
        for (i = 0; i < 3; i++) {
            CLACT_SetActorObjMode(work->actor[i], 0);
            CLACT_SetActorDrawEnable(work->actor[i], 0);
        }
        *state = 0;
        return 1;
    default:
        ++*state;
        change_alpha(16 - *state, *state);
        break;
    }
    return 0;
}

int INTRO_CMD_CmdCheckConfig(u8*p){IntroCmdWork *work=(IntroCmdWork *)p;if(!MYSTATUS_GetSex((struct MyStatus *)(((IntroArgs *)work->args)->myStatus)))return 1;return 0;}

void INTRO_CMD_CmdSetWordSet(u8*p,u32 a){IntroCmdWork *work=(IntroCmdWork *)p;struct WordSet*q=(struct WordSet *)INTRO_MSG_GetWordSet(work->msg);WORDSET_SetSlotMyStatus(q,a,((IntroArgs *)work->args)->myStatus);}

char *INTRO_CMD_Create(void *a, unsigned b, unsigned c, char *d, unsigned e, unsigned short heap)
{
    IntroCmdWork *work = GFL_HEAP_Alloc(heap, 0x10d8, 1, gIntroCmdSite, 0x6f2);
    work->heapId = heap;
    work->args = d;
    work->mcss = (void *)c;
    work->g3d = a;
    work->particle = (void *)b;
    work->display = (void *)e;
    work->saveControl = ((IntroArgs *)d)->saveControl;
    work->msg = INTRO_MSG_Create(heap);
    return (char *)work;
}

void INTRO_CMD_Delete(u8*p){IntroCmdWork *work=(IntroCmdWork *)p;INTRO_MSG_Delete(work->msg);GFL_HEAP_Free(work);}

extern int (*const gIntroCmdCommandTable[])(void *, void *, void *);

int INTRO_CMD_Main(char *p)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    INTRO_MSG_Main(work->msg);
    if (INTRO_CMD_RunCommands(work) == 0) {
        char *base = p;
        int i;
        base += 0x40;
        for (i = 0; i < 9; i++) {
            IntroCommand *row = INTRO_CMD_GetScenarioRow(work->scenarioId) + work->rowIndex;
            if (row->tag == 1) {
                gIntroCmdCommandTable[row->tag](p, base + i * 12, row->data);
                row = INTRO_CMD_GetScenarioRow(work->scenarioId);
            }
            if (row->tag == 0x34)
                return 0;
            ++work->rowIndex;
            if (!INTRO_CMD_AddCommand(work, row))
                break;
        }
    }
    return 1;
}

int INTRO_CMD_AddCommand(IntroCmdWork *p, IntroCommand *q)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (p->commands[i] == 0)
        {
            p->commands[i] = q;
            break;
        }
    }
    return q->tail.bits.flag;
}

extern int (*const gIntroCmdCommandTable[])(void *, void *, void *);

int INTRO_CMD_RunCommands(IntroCmdWork *p)
{
    int result = 0;
    int i;
    for (i = 0; i < 8; i++) {
        IntroCommand *q = p->commands[i];
        if (q) {
            if (!gIntroCmdCommandTable[q->tag](p, &p->slots[i], q->data)) result = 1;
            else INTRO_CMD_ClearCommand(p, i);
        }
    }
    return result;
}

void INTRO_CMD_ClearCommand(IntroCmdWork *p, u8 i)
{
    p->commands[i] = 0;
    p->slots[i].data[0] = 0;
    p->slots[i].data[1] = 0;
}

IntroCommand *INTRO_CMD_GetScenarioRow(u32 n){return *(IntroCommand **)((uptr)gIntroScenarioTables+n*4);}
