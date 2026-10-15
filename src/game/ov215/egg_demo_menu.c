/*
 * file:     egg_demo_menu.c
 * unit:     yes
 * function: EGG_DEMO_MENU_FadeInBgm, EGG_DEMO_MENU_Create, EGG_DEMO_MENU_Delete, EGG_DEMO_MENU_Main, EGG_DEMO_MENU_Draw, EGG_DEMO_MENU_SetText, EGG_DEMO_MENU_WaitText, EGG_DEMO_MENU_InitDialog, EGG_DEMO_MENU_Noop, EGG_DEMO_MENU_ProcessDialog, EGG_DEMO_MENU_CreateDialog, EGG_DEMO_MENU_InitGraphics
 * address:  0x021F604C
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   func_02045B38 0x02045B38 arm
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Main 0x020310C4 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   WORDSET_SetSlotMonName 0x0201EE84 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   BG_SYS_CreateRun 0x0203FA08 arm
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021F71A4 0x021F71A4 data a2
 */

#include "egg_demo_types.h"

struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Tcbl;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
struct Cfg;
struct WordSet;
struct WinDat;
struct BmpMenu;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int     s32;

extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void *BMP_MENUWORK_LoadFrameGfx(void *a0, u32 a1, u32 a2, u32 a3);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void func_02041B6C(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void TCBL_Main(struct Tcbl *p);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern void WORDSET_SetSlotMonName(struct WordSet *p, u32 i, void *mon);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(void *,unsigned,unsigned,void *,unsigned,unsigned,void *,unsigned,u16,u16);
extern unsigned PRINTSYS_PrintStreamGetState(void *);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern u32 BG_SYS_CreateRun(u32 layer, u32 size, u32 top);
extern unsigned BMP_MENU_ProcessYesNo(u8 *);
extern struct BmpMenu *BMP_MENU_CreateYesNo(const struct WinDat *,unsigned short,unsigned char,unsigned char,unsigned short);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16,int,int,int,int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned,unsigned);
void EGG_DEMO_MENU_FadeInBgm(void);
void EGG_DEMO_MENU_Create(int unused,char *p);
void EGG_DEMO_MENU_Delete(void *unused,char *p);
void EGG_DEMO_MENU_Main(void *unused, char *p);
void EGG_DEMO_MENU_Draw(void *unused, char *p);
void EGG_DEMO_MENU_SetText(char *object,char *p,unsigned entry);
int EGG_DEMO_MENU_WaitText(void *unused,char *p);
void EGG_DEMO_MENU_InitDialog(int unused, unsigned char *q);
void EGG_DEMO_MENU_Noop(int a0, char *a1);
void EGG_DEMO_MENU_ProcessDialog(void *unused, char *p);
int EGG_DEMO_MENU_CreateDialog(int a,char *p);
int EGG_DEMO_MENU_GetDialogResult(int a,char *p);
void EGG_DEMO_MENU_InitGraphics(void);
extern const u16 d_021F71A4[];


void EGG_DEMO_MENU_FadeInBgm(void)
{
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(0x3c);
}

void EGG_DEMO_MENU_Create(int unused,char *work)
{
    func_02049B40(23,5,0,32,32,((struct EggDemoWork *)work)->heapId);
    ((struct EggDemoWork *)work)->windowSub=(void *)BMP_WIN_Create(1,0,0,1,1,1,0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct EggDemoWork *)work)->windowSub)),0);
    BMP_WIN_TransferChars((struct Descriptor *)((struct EggDemoWork *)work)->windowSub);
    ((struct EggDemoWork *)work)->window=(void *)BMP_WIN_Create(1,1,19,30,4,1,0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct EggDemoWork *)work)->window)),15);
    BMP_WIN_TransferChars((struct Descriptor *)((struct EggDemoWork *)work)->window);
    ((struct EggDemoWork *)work)->frameGfx=(u32)BMP_MENUWORK_LoadFrameGfx((void *)1,2,0,((struct EggDemoWork *)work)->heapId);
    ((struct EggDemoWork *)work)->msgBank=func_02045B38(0,3,260,((struct EggDemoWork *)work)->heapId);
    ((struct EggDemoWork *)work)->tcbl=TCBL_Create(((struct EggDemoWork *)work)->heapId,((struct EggDemoWork *)work)->heapId,1,0);
    GF_FONT_SetTextColor(1,2,15);
    func_02041B6C(1);
    ((struct EggDemoWork *)work)->printStream=0;
    ((struct EggDemoWork *)work)->textBuf=0;
    ((struct EggDemoWork *)work)->vblankFlag=0;
    func_02040588(1,0);
}

void EGG_DEMO_MENU_Delete(void *unused,char *work)
{
    if(((struct EggDemoWork *)work)->printStream) PRINTSYS_PrintStreamDelete(((struct EggDemoWork *)work)->printStream);
    if(((struct EggDemoWork *)work)->textBuf) STRBUF_Delete(((struct EggDemoWork *)work)->textBuf);
    TCBL_Destroy(((struct EggDemoWork *)work)->tcbl);
    MSGDATA_Delete(((struct EggDemoWork *)work)->msgBank);
    BG_SYS_DeleteHalf(1,(u16)((struct EggDemoWork *)work)->frameGfx,(u16)(((struct EggDemoWork *)work)->frameGfx>>16));
    BMP_WIN_Delete(((struct EggDemoWork *)work)->window);
    BMP_WIN_Delete(((struct EggDemoWork *)work)->windowSub);
}

void EGG_DEMO_MENU_Main(void *unused, char *work)
{
    TCBL_Main(((struct EggDemoWork *)work)->tcbl);
}

void EGG_DEMO_MENU_Draw(void *unused, char *work)
{
    void *win;
    BMP_MENUWORK_DrawWindow(((struct EggDemoWork *)work)->window, 0, (u16)(((struct EggDemoWork *)work)->frameGfx), 2);
    win = ((struct EggDemoWork *)work)->window;
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_020409B4(BMP_WIN_GetBgLayer(win));
}

/*
 * evidence: CCE4 return widened because original stores live r0 after call.
 */
void EGG_DEMO_MENU_SetText(char *args,char *work,unsigned entry)
{
    void *text,*words,*buffer;
    BMP_Clear(BMP_WIN_GetBmp(((struct EggDemoWork *)work)->window),15);
    if(((struct EggDemoWork *)work)->printStream) PRINTSYS_PrintStreamDelete(((struct EggDemoWork *)work)->printStream);
    if(((struct EggDemoWork *)work)->textBuf) STRBUF_Delete(((struct EggDemoWork *)work)->textBuf);
    text=func_02045EC0(((struct EggDemoWork *)work)->msgBank,entry);
    words=GF_FONT_Create_EC64(((struct EggDemoWork *)work)->heapId);
    WORDSET_SetSlotMonName(words,0,((struct EggDemoArgs *)args)->mon);
    buffer=STRBUF_Create(256,((struct EggDemoWork *)work)->heapId);
    ((struct EggDemoWork *)work)->textBuf=buffer;
    WORDSET_CopyTaggedText(words,buffer,text);
    WORDSET_DeleteStrbufED04(words);
    STRBUF_Delete(text);
    ((struct EggDemoWork *)work)->printStream=PRINTSYS_PrintStream(((struct EggDemoWork *)work)->window,0,0,((struct EggDemoWork *)work)->textBuf,(unsigned int)((struct EggDemoWork *)work)->font,MSG_SPEED_GetWait(),((struct EggDemoWork *)work)->tcbl,2,((struct EggDemoWork *)work)->heapId,15);
}

int EGG_DEMO_MENU_WaitText(void *unused,char *work)
{
    int result=0;
    switch(PRINTSYS_PrintStreamGetState(((struct EggDemoWork *)work)->printStream)) {
    case 0:
        if((KEY_GetCont()&3)!=0 || TOUCHPANEL_GetCont()!=0)
            PRINTSYS_PrintStreamShortWait(((struct EggDemoWork *)work)->printStream,0);
        break;
    case 1:
        if((KEY_GetTrg()&3)!=0 || TOUCHPANEL_GetTrg()!=0)
            PRINTSYS_PrintStreamReleasePause(((struct EggDemoWork *)work)->printStream);
        break;
    case 2:
        result=1;
        break;
    }
    return result;
}


void EGG_DEMO_MENU_InitDialog(int unused, unsigned char *work)
{
    int h = BG_SYS_CreateRun(1, 0x500, 1);

    BG_SYS_DeleteHalf(1, h, 0x500);
    ((struct EggDemoWork *)work)->winDat[0] = 1;
    ((struct EggDemoWork *)work)->winDat[1] = 0x18;
    ((struct EggDemoWork *)work)->winDat[2] = 0xd;
    ((struct EggDemoWork *)work)->winDat[3] = 1;
    ((struct EggDemoWork *)work)->bgLayerId = h;
    ((struct EggDemoWork *)work)->dialogResult = 2;
}

void EGG_DEMO_MENU_Noop(int a0, char *a1)
{

}

void EGG_DEMO_MENU_ProcessDialog(void *unused, char *work)
{
    unsigned result;
    int flag;
    switch (((struct EggDemoWork *)work)->dialogState) {
    case 0:
        break;
    case 1:
        result = BMP_MENU_ProcessYesNo(*(u8 * *)&((struct EggDemoWork *)work)->bmpMenu);
        if (result != 0xffffffff) {
            if (result == 0) flag = 1;
            else flag = 0;
            ((struct EggDemoWork *)work)->dialogResult = flag;
            ((struct EggDemoWork *)work)->dialogState = 2;
        }
        break;
    }
}

int EGG_DEMO_MENU_CreateDialog(int unused,char *work){*(struct BmpMenu * *)&((struct EggDemoWork *)work)->bmpMenu=BMP_MENU_CreateYesNo((const struct WinDat *)(work+0x70),((struct EggDemoWork *)work)->frameGfx,2,0,((struct EggDemoWork *)work)->heapId);((struct EggDemoWork *)work)->dialogResult=2;((struct EggDemoWork *)work)->dialogState=1;return 1;}

/*
 * extent: includes cleared tiny follower EGG_DEMO_MENU_GetDialogResult; no further code included.
 */
int EGG_DEMO_MENU_GetDialogResult(int unused,char *work){return ((struct EggDemoWork *)work)->dialogResult;}

static inline void SetPriority(int priority)
{
    *(volatile u16 *)0x04000008=(u16)((*(volatile u16 *)0x04000008 & ~3)|(priority<<0));
}

/*
 * volatile: hardware 021F6336,6342,634E,6358,6362,636E,6392.
 */
void EGG_DEMO_MENU_InitGraphics(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1,1);
    SetPriority(0);
    *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060 & ~0x3002)|2);
    *(volatile u16 *)0x04000060 &= ~0x3010;
    *(volatile u16 *)0x04000060 &= ~0x3004;
    *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060 & ~0x3000)|8);
    *(volatile u16 *)0x04000060 &= ~0x3020;
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,0x7FFF,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((u8)i,d_021F71A4+i*4);
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
