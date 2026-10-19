/*
 * file:     br_fade.c
 * unit:     yes
 * function: BR_FADE_Create, BR_FADE_Delete, BR_FADE_Update, BR_FADE_Start, BR_FADE_StartTimed, BR_FADE_GetResult, BR_FADE_CaptureHwPalettes, BR_FADE_SetBlendColor, BR_FADE_BlendFull, BR_FADE_SetBlendLevel, BR_FADE_LoadPalette, BR_FADE_StepFadeBgA, BR_FADE_StepFadeBgB, BR_FADE_StepBlend, BR_FADE_StepPalette, BR_FADE_StepSubPlane3, BR_FADE_GetStepFunc
 * address:  0x021FE6C0
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_proc_sys.c, br_btn.c, br_graphic.c, br_util.c, br_net.c, BR_MEMBER_COUNT_GetU16Count.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_FADE_Create 0x021FE6C0 thumb ov186
 *   BR_FADE_CaptureHwPalettes 0x021FE7B4 thumb ov186
 *   BR_FADE_SetBlendColor 0x021FE7F4 thumb ov186
 *   BR_FADE_BlendFull 0x021FE7F8 thumb ov186
 *   BR_FADE_SetBlendLevel 0x021FE840 thumb ov186
 *   BR_FADE_Delete 0x021FE734 thumb ov186
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   BR_FADE_Update 0x021FE768 thumb ov186
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BR_FADE_LoadPalette 0x021FE8E8 thumb ov186
 *   BG_SYS_SetMainPlaneVisible   0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible   0x02043598  arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   d_02200D6C 0x02200D6C data a1
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   PALANM_RequestFullTransfer 0x02021F08 thumb
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   PALANM_LoadHandlePaletteToSlotAt 0x02021660 thumb
 *   FADE_GetSpeed 0x0204E6E0 arm
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "br_types.h"

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

extern int FADE_IsActive(void);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

struct PalAnmSlot;

struct S02021D50;

extern void * MI_CpuFill8(void *,u32,u32);

extern void *PALANM_Create(unsigned);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);

extern void PALANM_SetAutoTransfer(struct PalAnmSys *o, int v);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,u32);

extern unsigned int PALANM_Delete(void *);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);

extern void PALANM_BlendChannelMask(unsigned, unsigned, unsigned short, unsigned, unsigned);

extern void PALANM_RequestFullTransfer(struct PalAnmSys *o, int v);

extern void PALANM_TransferPalettes(struct S02021D50 *p);

extern void G2x_SetBlendAlpha_(unsigned int *reg, unsigned int a, unsigned int b, unsigned int c, unsigned int d);

extern void PALANM_LoadHandlePaletteToSlotAt(struct PalAnmSlot *,void *,u32,u32,u32,u32,u16,u16);

extern int FADE_GetSpeed(void);



struct BrFade *BR_FADE_Create(unsigned heapId);

void BR_FADE_Delete(struct BrFade *fade);

void BR_FADE_Update(struct BrFade *fade);

void BR_FADE_Start(void *fade, int stepIndex, int planeMask, int direction);

void BR_FADE_StartTimed(struct BrFade *fade,u32 stepIndex,u32 planeMask,u32 direction,u32 durationParam);

int BR_FADE_GetResult(struct BrFade *fade);

void BR_FADE_CaptureHwPalettes(struct BrFade *fade);

void BR_FADE_SetBlendColor(struct BrFade *fade,u16 blendColor);

void BR_FADE_BlendFull(struct BrFade *fade, int planeMask);

void BR_FADE_SetBlendLevel(int unused, int planeMask, int level);

void BR_FADE_LoadPalette(struct BrFade *fade,void *archive,u32 fileId,u32 slot,u32 offset,u32 count,u16 heapId);

int BR_FADE_StepFadeBgA(struct BrFade *fade, int *state);

int BR_FADE_StepFadeBgB(struct BrFade *fade, int *state);

int BR_FADE_StepBlend(struct BrFade *fade,int *state);

int BR_FADE_StepPalette(struct BrFade *fade,int *state);

int BR_FADE_StepSubPlane3(struct BrFade *fade,int *state);

void *BR_FADE_GetStepFunc(unsigned index);

extern const char d_02200D6C[];

struct BrFade *BR_FADE_Create(unsigned heapId)
{
    struct BrFade *fade = GFL_HEAP_Alloc(heapId, 0x40, 0, d_02200D6C, 0x62);
    MI_CpuFill8(fade, 0, 0x40);
    fade->unused3C = 0xFFFF;
    fade->palAnm = PALANM_Create(heapId);
    PALANM_AllocSlotBuffers((void *)fade->palAnm, 0, 0x200, heapId);
    PALANM_AllocSlotBuffers((void *)fade->palAnm, 2, 0x1C0, heapId);
    PALANM_AllocSlotBuffers((void *)fade->palAnm, 1, 0x200, heapId);
    PALANM_AllocSlotBuffers((void *)fade->palAnm, 3, 0x1C0, heapId);
    PALANM_SetAutoTransfer((void *)fade->palAnm, 1);
    return fade;
}

/*
 * extent: two zero alignment bytes at 0x021FE766 follow; no follower.
 * ABI: 02021540's legacy source declares void(void), but this caller loads r0 from p+0x20 at 021FE758; its tail-forward target 020307B0 saves and reads r0. Preserve that pointer argument.
 */
void BR_FADE_Delete(struct BrFade *fade) { PALANM_FreeSlotBuffers((struct PalAnmSlot *)fade->palAnm,2); PALANM_FreeSlotBuffers((struct PalAnmSlot *)fade->palAnm,0); PALANM_FreeSlotBuffers((struct PalAnmSlot *)fade->palAnm,3); PALANM_FreeSlotBuffers((struct PalAnmSlot *)fade->palAnm,1); PALANM_Delete(fade->palAnm); GFL_HEAP_Free(fade); }

void BR_FADE_Update(struct BrFade *fade)
{
    int (*step)(struct BrFade *, void *);

    step = (int (*)(struct BrFade *, void *))fade->step;
    if (step != 0) {
        fade->done = step(fade, &fade->state);
        if (fade->done != 0)
            fade->step = 0;
    }
}

void BR_FADE_Start(void *fade, int stepIndex, int planeMask, int direction)
{
    BR_FADE_StartTimed((struct BrFade *)fade, stepIndex, planeMask, direction, 0);
}

void BR_FADE_StartTimed(struct BrFade *fade,u32 stepIndex,u32 planeMask,u32 direction,u32 durationParam) { fade->planeMask=planeMask; fade->durationParam=durationParam; fade->direction=direction; fade->step=BR_FADE_GetStepFunc(stepIndex); fade->done=0; fade->state=0; }

/*
 * Unlabelled ov186 leaf hidden in a word run: loads the word its argument
 * points at.  Matched to supply the `matched` witness for the two pending
 * ov184 callers (BR_DOWNLOAD_StepFadeIn, BR_DOWNLOAD_StepClose).
 */
int BR_FADE_GetResult(struct BrFade *fade)
{
    return fade->done;
}

/*
 * lever: plain literals 512 and 448; mwcc derives 448 from the held 512 itself. Twin shape: matched ov197 0220C980 call to PALANM_CopyHwPaletteToSlot.
 */
void BR_FADE_CaptureHwPalettes(struct BrFade *fade)
{
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)fade->palAnm, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)fade->palAnm, 2, 0, 448);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)fade->palAnm, 1, 0, 512);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)fade->palAnm, 3, 0, 448);
}

void BR_FADE_SetBlendColor(struct BrFade *fade,u16 blendColor) { fade->blendColor=blendColor; }

void BR_FADE_BlendFull(struct BrFade *fade, int planeMask)
{
    if (planeMask & 1)
        PALANM_BlendChannelMask((unsigned)fade->palAnm, 0, 0xBFFF, 16, fade->blendColor);
    if (planeMask & 2)
        PALANM_BlendChannelMask((unsigned)fade->palAnm, 1, 0xBFFF, 16, fade->blendColor);
    PALANM_RequestFullTransfer(fade->palAnm, 1);
    PALANM_TransferPalettes((struct S02021D50 *)fade->palAnm);
}

void BR_FADE_SetBlendLevel(int unused, int planeMask, int level)
{
    if (planeMask & 1) {
        G2x_SetBlendAlpha_((unsigned int *)0x04000050, 7, 31, level, 16 - level);
        if (level == 0) {
            BG_SYS_SetMainPlaneVisible(1, 0);
            BG_SYS_SetMainPlaneVisible(2, 0);
            BG_SYS_SetMainPlaneVisible(4, 0);
        } else {
            BG_SYS_SetMainPlaneVisible(1, 1);
            BG_SYS_SetMainPlaneVisible(2, 1);
            BG_SYS_SetMainPlaneVisible(4, 1);
        }
    }
    if (planeMask & 2) {
        G2x_SetBlendAlpha_((unsigned int *)0x04001050, 3, 7, level, 16 - level);
        if (level == 0) {
            BG_SYS_SetSubPlaneVisible(1, 0);
            BG_SYS_SetSubPlaneVisible(2, 0);
        } else {
            BG_SYS_SetSubPlaneVisible(1, 1);
            BG_SYS_SetSubPlaneVisible(2, 1);
        }
    }
}

void BR_FADE_LoadPalette(struct BrFade *fade,void *archive,u32 fileId,u32 slot,u32 offset,u32 count,u16 heapId) { PALANM_LoadHandlePaletteToSlotAt((struct PalAnmSlot *)fade->palAnm,archive,fileId,heapId,slot,count,offset,0); }

/*
 * Three-state fade task.  start/end are assigned only for direction == 0 or 1:
 * the original passes callee-saved r5 and entry r2 unset on any other
 * value, exactly what C locals left unassigned on that path give
 * (docs/idioms/switch-arms-tail-merge.md).  The earlier DIFF note
 * initialised them to 16/0 and could not lose the extra moves.
 */
int BR_FADE_StepFadeBgA(struct BrFade *fade, int *state)
{
    u32 mask;
    s32 start, end;
    switch (*state) {
    case 0:
        mask = 0;
        if (fade->planeMask & 1) mask |= 1;
        if (fade->planeMask & 2) mask |= 2;
        if (fade->direction == 0) {
            start = 16;
            end = 0;
        } else if (fade->direction == 1) {
            start = 0;
            end = 16;
        }
        FADE_Start(mask, start, end, fade->durationParam);
        *state = 1;
        break;
    case 1:
        if (FADE_IsActive() == 0) *state = 2;
        break;
    case 2:
        return 1;
    }
    return 0;
}

/*
 * Twin of BR_FADE_StepFadeBgA with mask bits 4/8.  start/end are assigned only
 * for direction == 0 or 1; the original forwards entry r1/r2 unset on any
 * other value (docs/idioms/switch-arms-tail-merge.md).  98 bytes; the
 * last two bytes of the 100-byte extent are alignment padding (00 00).
 */
int BR_FADE_StepFadeBgB(struct BrFade *fade, int *state)
{
    u32 mask;
    s32 start, end;
    switch (*state) {
    case 0:
        mask = 0;
        if (fade->planeMask & 1) mask |= 4;
        if (fade->planeMask & 2) mask |= 8;
        if (fade->direction == 0) {
            start = 16;
            end = 0;
        } else if (fade->direction == 1) {
            start = 0;
            end = 16;
        }
        FADE_Start(mask, start, end, fade->durationParam);
        *state = 1;
        break;
    case 1:
        if (FADE_IsActive() == 0) *state = 2;
        break;
    case 2:
        return 1;
    }
    return 0;
}

/*
 * volatile: 021FEA84 and 021FEACC write the engine-A/B blend coefficients.
 * abi: E6E0's r0 return is consumed.
 */
int BR_FADE_StepBlend(struct BrFade *fade,int *state)
{
    switch(*state) {
    case 0: {
        int evA,evB,duration;
        if(fade->direction==0){evA=0;evB=16;}
        else if(fade->direction==1){evA=16;evB=0;}
        if(fade->planeMask&1)G2x_SetBlendAlpha_((unsigned int *)0x04000050,7,31,evA,evB);
        if(fade->planeMask&2)G2x_SetBlendAlpha_((unsigned int *)0x04001050,3,7,evA,evB);
        fade->frame=0;
        duration=fade->durationParam;
        if(duration==0)duration=16/FADE_GetSpeed();
        fade->frameCount=duration;
        *state=1;
        break;
    }
    case 1: {
        int evA,evB;
        if(fade->direction==0){evB=(fade->frame<<4)/fade->frameCount;evA=16-evB;}
        else if(fade->direction==1){evA=(fade->frame<<4)/fade->frameCount;evB=16-evA;}
        if(fade->planeMask&1) {
            *(volatile u16 *)0x04000052=evB|(evA<<8);
            if(evB==0){BG_SYS_SetMainPlaneVisible(1,0);BG_SYS_SetMainPlaneVisible(2,0);BG_SYS_SetMainPlaneVisible(4,0);}
            else{BG_SYS_SetMainPlaneVisible(1,1);BG_SYS_SetMainPlaneVisible(2,1);BG_SYS_SetMainPlaneVisible(4,1);}
        }
        if(fade->planeMask&2) {
            *(volatile u16 *)0x04001052=evB|(evA<<8);
            if(evB==0){BG_SYS_SetSubPlaneVisible(1,0);BG_SYS_SetSubPlaneVisible(2,0);}
            else{BG_SYS_SetSubPlaneVisible(1,1);BG_SYS_SetSubPlaneVisible(2,1);}
        }
        if((fade->frame)++ >= fade->frameCount)*state=2;
        break;
    }
    case 2:return 1;
    }
    return 0;
}

/*
 * note: 2026-10-05 the older draft used 0x3fff for both calls of the first pair and 0xbfff for both of the second. The listing pairs them as (2,0x3fff) (0,0xbfff) (3,0x3fff) (1,0xbfff). Variable level is read uninitialised when direction is not 0 or 1 (original behaviour, kept).
 */
int BR_FADE_StepPalette(struct BrFade *fade,int *state)
{
    switch(*state) {
    case 0: {
        int duration;
        fade->frame=0;
        duration=fade->durationParam;
        if(duration==0)duration=16/FADE_GetSpeed();
        fade->frameCount=duration;
        PALANM_RequestFullTransfer(fade->palAnm,1);
        *state=1;
        break;
    }
    case 1: {
        int level;
        if(fade->direction==0)level=(u8)(16-(fade->frame<<4)/fade->frameCount);
        else if(fade->direction==1)level=(u8)((fade->frame<<4)/fade->frameCount);
        if(fade->planeMask==15) {
            PALANM_BlendChannelMask((u32)fade->palAnm,1,0x3000,level,0xffff);
        } else {
            if(fade->planeMask&1) {
                PALANM_BlendChannelMask((u32)fade->palAnm,2,0x3fff,level,fade->blendColor);
                PALANM_BlendChannelMask((u32)fade->palAnm,0,0xbfff,level,fade->blendColor);
            }
            if(fade->planeMask&2) {
                PALANM_BlendChannelMask((u32)fade->palAnm,3,0x3fff,level,fade->blendColor);
                PALANM_BlendChannelMask((u32)fade->palAnm,1,0xbfff,level,fade->blendColor);
            }
        }
        PALANM_TransferPalettes((struct S02021D50 *)fade->palAnm);
        if((fade->frame)++ >= fade->frameCount)*state=2;
        break;
    }
    case 2:return 1;
    }
    return 0;
}

/*
 * lever: A duration local updated by the zero arm shares the final store, removing the extra branch (248 to 244 B).
 * volatile: 021FECBC writes the engine-B blend register at 04001052.
 * abi: 0204E6E0 returns the word loaded into r0 despite its asm void declaration.
 */
int BR_FADE_StepSubPlane3(struct BrFade *fade,int *state)
{
    switch(*state) {
    case 0: {
        int start,end,evA,evB,duration;
        if(fade->direction==0){start=16;end=0;}
        else if(fade->direction==1){start=0;end=16;}
        if(fade->direction==0){evA=0;evB=16;}
        else if(fade->direction==1){evA=16;evB=0;}
        FADE_Start(4,start,end,fade->durationParam);
        G2x_SetBlendAlpha_((unsigned int *)0x04001050,3,7,evA,evB);
        fade->frame=0;
        duration=fade->durationParam;
        if(duration==0)duration=16/FADE_GetSpeed();
        fade->frameCount=duration;
        *state=1;
        break;
    }
    case 1: {
        int evA,evB;
        int done=1;
        if(fade->direction==0){evA=(fade->frame<<4)/fade->frameCount;evB=16-evA;}
        else if(fade->direction==1){evB=(fade->frame<<4)/fade->frameCount;evA=16-evB;}
        *(volatile u16 *)0x04001052=evA|(evB<<8);
        if(evA==0)BG_SYS_SetSubPlaneVisible(3,0);else BG_SYS_SetSubPlaneVisible(3,1);
        done&=((fade->frame)++ >= fade->frameCount);
        if(done & !FADE_IsActive())*state=2;
        break;
    }
    case 2:return 1;
    }
    return 0;
}

void *BR_FADE_GetStepFunc(unsigned stepIndex)
{
    switch (stepIndex) {
    case 0: return (void *)BR_FADE_StepFadeBgA;
    case 1: return (void *)BR_FADE_StepFadeBgB;
    case 2: return (void *)BR_FADE_StepBlend;
    case 3: return (void *)BR_FADE_StepPalette;
    case 4: return (void *)BR_FADE_StepSubPlane3;
    }
    return 0;
}
