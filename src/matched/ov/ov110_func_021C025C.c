/*
 * function: PMS_SELECT_GRAPHIC_ProcMain
 * address: 0x021C025C
 * packet: pkt_ov110_021C025C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: Owner ARM9 Thumb 0x02024910 at +0052 lacks an outside witness; no owner C matched or embedded.
 * blocker: ov110 Thumb 0x021C0250 at +006C,+018A,+01A6,+01D2 lacks an outside witness; held while ARM9 also blocks.
 * ABI: 02031330 tail-forwards the full-word result and object argument of matched 020313EC.
 * symbols:
 *   PROCSYS_Main 0x02031330 arm
 *   PMS_WORD_GetSaveEntry 0x02024910 thumb
 *   PMSI_PARAM_IsComplete 0x02024464 thumb
 *   PMS_SELECT_GRAPHIC_SetResult 0x021C0250 thumb ov110
 *   PMS_SELECT_GRAPHIC_ShowTouchBar 0x021C132C thumb ov110
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   PMS_SELECT_GRAPHIC_IsPrintDone 0x021C022C thumb ov110
 *   PMS_SELECT_GRAPHIC_StepList 0x021C133C thumb ov110
 *   PMS_SELECT_GRAPHIC_HideTouchBar 0x021C1440 thumb ov110
 *   PMS_SELECT_GRAPHIC_StepOpenRowMenu 0x021C1450 thumb ov110
 *   PMS_SELECT_GRAPHIC_StepRowMenu 0x021C1484 thumb ov110
 *   PMS_SELECT_GRAPHIC_StepCloseRowMenu 0x021C14E0 thumb ov110
 *   PMS_SELECT_GRAPHIC_Teardown 0x021C05B0 thumb ov110
 *   func_02034A5C 0x02034A5C arm
 *   PMS_SELECT_GRAPHIC_StepOpenEditScreen 0x021C154C thumb ov110
 *   PMS_SELECT_GRAPHIC_StepCloseEditScreen 0x021C15B4 thumb ov110
 *   func_02034AC4 0x02034AC4 arm
 *   PMS_SELECT_GRAPHIC_Setup 0x021C0490 thumb ov110
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   PMS_SELECT_GRAPHIC_FlushRowWindows 0x021C1154 thumb ov110
 *   PMS_SELECT_GRAPHIC_UpdateDraw 0x021C0C38 thumb ov110
 *   PMS_SELECT_GRAPHIC_UpdateScene 0x021C1704 thumb ov110
 *   ov067_id 0x00000043 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 PROCSYS_Main(void *);
typedef signed int     s32;
struct Cfg;
struct Descriptor;
struct PrintSys;
struct T;
extern void *PMS_WORD_GetSaveEntry(char *p, int idx);
extern int PMSI_PARAM_IsComplete(struct T *p, u32 a1);
extern void PMS_SELECT_GRAPHIC_SetResult(int *,u8 *,int);
extern int PMS_SELECT_GRAPHIC_ShowTouchBar(void *,u8 *);
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern int PMS_SELECT_GRAPHIC_IsPrintDone(u8 *);
extern int PMS_SELECT_GRAPHIC_StepList(void *,u8 *);
extern int PMS_SELECT_GRAPHIC_HideTouchBar(void *,u8 *);
extern int PMS_SELECT_GRAPHIC_StepOpenRowMenu(void *,u8 *);
extern int PMS_SELECT_GRAPHIC_StepRowMenu(void *,u8 *);
extern int PMS_SELECT_GRAPHIC_StepCloseRowMenu(void *,u8 *);
extern void PMS_SELECT_GRAPHIC_Teardown(char *p);
extern void func_02034A5C(s32 handle);
extern int PMS_SELECT_GRAPHIC_StepOpenEditScreen(int *,u8 *);
extern int PMS_SELECT_GRAPHIC_StepCloseEditScreen(int *,u8 *);
extern int func_02034AC4(s32 handle);
extern void PMS_SELECT_GRAPHIC_Setup(u8 *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void PMS_SELECT_GRAPHIC_FlushRowWindows(char *p);
extern void PMS_SELECT_GRAPHIC_UpdateDraw(u8 *);
extern void PMS_SELECT_GRAPHIC_UpdateScene(u8 *p);
extern char ov067_id[];
int PMS_SELECT_GRAPHIC_ProcMain(void *unused,int *q,void *unused2,u8 *p)
{
    u32 running;
    void *window;
    running=PROCSYS_Main(*(void **)(p+0xac));
    if(running==1) return 0;
    switch(*q) {
    case 0:
        if(!PMSI_PARAM_IsComplete(PMS_WORD_GetSaveEntry(*(void **)(p+0x20),0),*(u16 *)(p+4))) {
            p[0x95]=0;
            PMS_SELECT_GRAPHIC_SetResult(q,p,13);
        } else PMS_SELECT_GRAPHIC_SetResult(q,p,1);
        break;
    case 1:
        if(PMS_SELECT_GRAPHIC_ShowTouchBar(p+0x9c,p)) PMS_SELECT_GRAPHIC_SetResult(q,p,2);
        break;
    case 2:
        FADE_Start(3,16,0,0);
        PMS_SELECT_GRAPHIC_SetResult(q,p,3);
        break;
    case 3:
        if(!FADE_IsActive()) PMS_SELECT_GRAPHIC_SetResult(q,p,4);
        break;
    case 4:
        if(PMS_SELECT_GRAPHIC_IsPrintDone(p) && PMS_SELECT_GRAPHIC_StepList(p+0x9c,p))
            PMS_SELECT_GRAPHIC_SetResult(q,p,*(int *)(p+0xa0));
        break;
    case 5:
        FADE_Start(3,0,16,0);
        PMS_SELECT_GRAPHIC_SetResult(q,p,6);
        break;
    case 6:
        if(!FADE_IsActive()) PMS_SELECT_GRAPHIC_SetResult(q,p,7);
        break;
    case 7:
        if(PMS_SELECT_GRAPHIC_HideTouchBar(p+0x9c,p)) PMS_SELECT_GRAPHIC_SetResult(q,p,16);
        break;
    case 8:
        if(PMS_SELECT_GRAPHIC_StepOpenRowMenu(p+0x9c,p)) PMS_SELECT_GRAPHIC_SetResult(q,p,9);
        break;
    case 9:
        if(PMS_SELECT_GRAPHIC_StepRowMenu(p+0x9c,p)) PMS_SELECT_GRAPHIC_SetResult(q,p,10);
        break;
    case 10:
        if(PMS_SELECT_GRAPHIC_StepCloseRowMenu(p+0x9c,p)) PMS_SELECT_GRAPHIC_SetResult(q,p,*(int *)(p+0xa0));
        break;
    case 11:
        if(PMS_SELECT_GRAPHIC_IsPrintDone(p)) {
            FADE_Start(3,0,16,0);
            PMS_SELECT_GRAPHIC_SetResult(q,p,12);
        }
        break;
    case 12:
        if(!FADE_IsActive()) PMS_SELECT_GRAPHIC_SetResult(q,p,13);
        break;
    case 13:
        PMS_SELECT_GRAPHIC_Teardown((char *)p);
        func_02034A5C((s32)ov067_id);
        PMS_SELECT_GRAPHIC_SetResult(q,p,14);
        return 0;
    case 14:
        if(PMS_SELECT_GRAPHIC_StepOpenEditScreen((int *)(p+0x9c),p)) PMS_SELECT_GRAPHIC_SetResult(q,p,15);
        return 0;
    case 15:
        if(running!=1 && PMS_SELECT_GRAPHIC_StepCloseEditScreen((int *)(p+0x9c),p)) {
            func_02034AC4((u32)ov067_id);
            PMS_SELECT_GRAPHIC_Setup(p);
            PMS_SELECT_GRAPHIC_SetResult(q,p,1);
        }
        return 0;
    case 16:
        return 1;
    }
    PRINTSYS_QUE_Main(*(void **)(p+0x5c));
    if(*(u32 *)(p+0x4c)) {
        if(!PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(*(u32 *)(p+0x5c)),BMP_WIN_GetBmp(*(void **)(p+0x48)))) {
            window=*(void **)(p+0x48);
            BMP_WIN_TransferChars(window);
            BMP_WIN_MakeScreen(window);
            func_02041B6C(BMP_WIN_GetBgLayer(window));
            *(u32 *)(p+0x4c)=0;
        }
    }
    PMS_SELECT_GRAPHIC_FlushRowWindows((char *)p);
    PMS_SELECT_GRAPHIC_UpdateDraw(p);
    PMS_SELECT_GRAPHIC_UpdateScene(*(void **)(p+0x50));
    return 0;
}
