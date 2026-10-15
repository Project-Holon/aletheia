/*
 * file:     intro_msg.c
 * unit:     yes
 * function: INTRO_MSG_Create, INTRO_MSG_Delete, INTRO_MSG_SetMsgBank, INTRO_MSG_Main, INTRO_MSG_PrintText, INTRO_MSG_DrawWindowBorder, INTRO_MSG_GetPrintState, INTRO_MSG_UpdatePrint, INTRO_MSG_InitMenuDesc, INTRO_MSG_CreateMenuList, INTRO_MSG_DrawMenuList, INTRO_MSG_MainMenuList, INTRO_MSG_GetMenuChoice, INTRO_MSG_GetWordSet, INTRO_MSG_StartTimeIcon, INTRO_MSG_DeleteTimeIcon
 * address:  0x021BF0A0
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
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_SetSeSlotVolume 0x020062BC thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   gIntroSite 0x021C0AE4 data a1
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   TCBL_Create 0x0203101C arm
 *   func_02049B40 0x02049B40 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   APP_KEYCURSOR_CreateDefault 0x02028590 thumb
 *   TIME_ICON_Alloc 0x0202EF60 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   func_02045B38 0x02045B38 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont  0x0203630C  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   func_02020D10 0x02020D10 thumb
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   func_020056BC 0x020056BC thumb
 *   TIME_ICON_Start 0x0202EF98 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 */
#include "intro_types.h"

struct Cfg;

struct CharBuf;

struct Descriptor;

struct GfFont;

struct Tcbl;

struct U16Vec;

struct S02031140;

struct Rec3;

struct PrintSys;

struct MsgBank;

struct Ctx;

struct Src;

/*
 * The menu template handed to BMP_MENULIST_Create. Field names follow the
 * arm9 BmpMenuList record (arm9/bmp_menulist.c), which sees this 0x34-byte
 * block as 13 words.
 */
typedef struct IntroMsgMenuTemplate {
    void *items;
    void *onCursor;
    void *drawHook;
    void *win;
    u16 count;
    u16 rows;
    u8 sepX;
    u8 itemX;
    u8 cursorX;
    u8 originY:4, letterColor:4;
    u8 bgColor:4, shadowColor:4;
    u8 unused19;
    u16 mode3:3, lineGap:4, pageKeys:2, mode6:6, cursorOff:1;
    u32 userData;
    u16 cursorW;
    u16 rowH;
    u32 pad24;
    void *target;
    void *printer;
    void *textParam;
} IntroMsgMenuTemplate;

/*
 * The intro message work (0x48 allocated). Created by INTRO_MSG_Create,
 * freed by INTRO_MSG_Delete.
 */
typedef struct IntroMsgWork {
    unsigned short heapId;   /* 0x00 */
    unsigned char pad_2[2];
    void *printSys;          /* 0x04: PRINTSYS_QUE_Create result */
    void *wordSet;           /* 0x08: WORDSET_CreateDefault result */
    void *msgBank;           /* 0x0C: func_02045B38 result */
    void *font;              /* 0x10: GF_FONT_Create result */
    void *printStream;       /* 0x14: PRINTSYS_PrintStream result */
    void *tcbl;              /* 0x18: TCBL_Create result */
    void *textWin;           /* 0x1C: BMP_WIN_Create result (text window) */
    void *keyCursor;         /* 0x20: APP_KEYCURSOR_CreateDefault result */
    void *menuList;          /* 0x24: BMP_MENULIST_Create result */
    void *menuWork;          /* 0x28: BMP_MENUWORK_Create result */
    int menuState;           /* 0x2C: BMP_MENULIST_Main result */
    void *menuDesc;          /* 0x30: BMP_WIN descriptor */
    unsigned char menuFlag;  /* 0x34 */
    unsigned char pad_35[3];
    void *menuWin;           /* 0x38: BMP_WIN_Create result (menu window) */
    void *strbuf1;           /* 0x3C: STRBUF_Create result */
    void *strbuf2;           /* 0x40: STRBUF_Create result */
    void *timeIcon;          /* 0x44: TIME_ICON_Alloc result */
} IntroMsgWork;

extern void GFL_USE_PlaySeDefaultVolume(unsigned),GFL_USE_SetSeSlotVolume(int,unsigned),GFL_USE_SetSeSlotParams(int,unsigned,unsigned,unsigned);

extern int TOUCHPANEL_GetTrg(void);

extern u32 KEY_GetTrg(void);

extern void func_02041B6C(u32);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *sitePath, u16 tag);

extern u32 func_020307B0(void *p);

extern struct WordSet *WORDSET_CreateDefault(u32 heap);

extern u32 PRINTSYS_QUE_Create(void *p);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void *APP_KEYCURSOR_CreateDefault(u32,u32,u32,u32);

extern struct Obj *TIME_ICON_Alloc(u32 heap);

extern int APP_KEYCURSOR_Delete(int);

extern void STRBUF_Delete(struct U16Vec *);

extern unsigned int GF_FONT_Delete(void *ptr);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern unsigned int BMP_WIN_Delete(struct Descriptor *d);

extern void TCBL_Destroy(struct S02031140 *);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern unsigned int MSGDATA_Delete(struct Rec *rec);

extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern void TCBL_Main(struct Tcbl*);

extern u32 PRINTSYS_QUE_Main(struct PrintSys*);

extern signed char MSG_SPEED_GetWait(void);

extern void GF_FONT_SetTextColor(unsigned int, unsigned int, unsigned int);

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern void *PRINTSYS_PrintStream(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short, unsigned short);

extern void BMP_MENUWORK_DrawWindow(void *, int, int, int);

extern void BMP_MENUWORK_DrawWindowBorder(void*,u32);

extern u32 PRINTSYS_PrintStreamGetState(void *p);

extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);

extern void PRINTSYS_PrintStreamReleasePause(void *p);

extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);

extern unsigned int KEY_GetCont(void);

extern int TOUCHPANEL_GetCont(void);

extern void *MI_CpuFill8(void *,int,u32);

extern void *BMP_MENUWORK_Create(u32,u32);

extern void BMP_MENUWORK_AddStrItem(struct Slot *table, u32 a, u32 b, u32 tag);

extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);

extern void func_02020CF8(struct Obj *p, int heap);

extern void BG_SYS_PushTile(u32 index);

extern void func_02020D10(u8 *p, u32 v);

extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);

extern u32 BMP_MENUWORK_Delete(void *p);

extern int BMP_MENULIST_Main(struct Obj *);

extern u32 func_020056BC(void);

extern void TIME_ICON_Start(u8 *,u32,u32,u8,u8);

extern void TIME_ICON_Delete(u8 *);

char *INTRO_MSG_Create(u16 heap);

void INTRO_MSG_Delete(char *p);

void INTRO_MSG_SetMsgBank(char *p, unsigned a, unsigned short b);

void INTRO_MSG_Main(u8*p);

void INTRO_MSG_PrintText(char *p, void *a, int flag);

void INTRO_MSG_DrawWindowBorder(u8*p);

u32 INTRO_MSG_GetPrintState(u8*p);

int INTRO_MSG_UpdatePrint(char *a);

int *INTRO_MSG_InitMenuDesc(char *p, int v);

void INTRO_MSG_CreateMenuList(char *p,u32 *entries,u32 count,int flag);

void INTRO_MSG_DrawMenuList(char *p);

void INTRO_MSG_MainMenuList(u8 *p);

int INTRO_MSG_GetMenuChoice(u8 *p,int *out);

int INTRO_MSG_GetWordSet(u8 *p);

void INTRO_MSG_StartTimeIcon(u8 *p);

void INTRO_MSG_DeleteTimeIcon(u8 *p);

extern const char gIntroSite[];

char *INTRO_MSG_Create(u16 heap)
{
    IntroMsgWork *p;
    void *obj;
    p=func_02030734(heap,72,1,gIntroSite,129);
    p->heapId=heap;
    p->wordSet=WORDSET_CreateDefault(heap);
    p->printSys=(void *)PRINTSYS_QUE_Create((void *)heap);
    p->tcbl=TCBL_Create(p->heapId,p->heapId,2,0);
    func_02049B40(23,5,0,320,32,heap);
    BMP_MENUWORK_LoadCharAndPltt(1,7,9,0,heap);
    BMP_MENUWORK_LoadCharAndPltt(1,16,8,1,heap);
    p->font=GF_FONT_Create(23,0,1,0,p->heapId);
    p->strbuf1=STRBUF_Create(1600,p->heapId);
    p->strbuf2=STRBUF_Create(1600,p->heapId);
    p->menuWin=(void *)BMP_WIN_Create(1,22,13,9,4,10,1);
    BMP_Clear(BMP_WIN_GetBmp(p->menuWin),0);
    obj=p->menuWin;
    BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_02041B6C(BMP_WIN_GetBgLayer(obj));
    p->textWin=(void *)BMP_WIN_Create(1,1,19,30,4,10,1);
    p->keyCursor=APP_KEYCURSOR_CreateDefault(15,1,1,p->heapId);
    p->timeIcon=TIME_ICON_Alloc(p->heapId);
    return (char *)p;
}

void INTRO_MSG_Delete(char *p)
{
    IntroMsgWork *work = (IntroMsgWork *)p;
    INTRO_MSG_DeleteTimeIcon((u8 *)p);
    APP_KEYCURSOR_Delete((int)work->keyCursor);
    STRBUF_Delete((struct U16Vec *)work->strbuf1);
    STRBUF_Delete((struct U16Vec *)work->strbuf2);
    GF_FONT_Delete(work->font);
    if (work->printStream != 0)
        PRINTSYS_PrintStreamDelete((struct Rec3 *)work->printStream);
    BMP_WIN_Delete((struct Descriptor *)work->textWin);
    if (work->menuWin)
        BMP_WIN_Delete((struct Descriptor *)work->menuWin);
    TCBL_Destroy((struct S02031140 *)work->tcbl);
    PRINTSYS_QUE_Delete(work->printSys);
    if (work->msgBank)
        MSGDATA_Delete(work->msgBank);
    WORDSET_DeleteStrbufED04(work->wordSet);
    func_020307B0(p);
}

void INTRO_MSG_SetMsgBank(char *p, unsigned a, unsigned short b)
{
    IntroMsgWork *work = (IntroMsgWork *)p;
    if (work->msgBank != 0)
    {
        MSGDATA_Delete(work->msgBank);
    }
    work->msgBank = func_02045B38(a, 2, b, work->heapId);
}

void INTRO_MSG_Main(u8*p){IntroMsgWork *work=(IntroMsgWork*)p;TCBL_Main(work->tcbl);PRINTSYS_QUE_Main(work->printSys);}

/*
 * Caller consumes 0201CCE4's live r0 result; return declared pointer despite callee's void source.
 */
void INTRO_MSG_PrintText(char *p, void *a, int flag)
{
    IntroMsgWork *work = (IntroMsgWork *)p;
    unsigned int value = MSG_SPEED_GetWait();
    void *desc = work->textWin;
    BMP_Clear(BMP_WIN_GetBmp(desc), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    func_02045CAC(work->msgBank, (unsigned int)a, work->strbuf1);
    WORDSET_CopyTaggedText(work->wordSet, work->strbuf2, work->strbuf1);
    work->printStream = PRINTSYS_PrintStream((unsigned int)desc, 4, 0, (unsigned int)work->strbuf2, (unsigned int)work->font, value, (unsigned int)work->tcbl, 0xFFFF, work->heapId, 15);
    if (flag == 0)
        BMP_MENUWORK_DrawWindow(desc, 1, 7, 9);
    else
        BMP_MENUWORK_DrawWindow(desc, 1, 16, 8);
    BMP_WIN_TransferChars(desc);
    BMP_WIN_MakeScreen(desc);
    func_02041B6C(BMP_WIN_GetBgLayer(desc));
}

void INTRO_MSG_DrawWindowBorder(u8*p){IntroMsgWork *work=(IntroMsgWork*)p;BMP_MENUWORK_DrawWindowBorder(work->textWin,0);}

u32 INTRO_MSG_GetPrintState(u8*p){IntroMsgWork *work=(IntroMsgWork*)p;u32 a=(u32)work->printStream;if(a==0){return 2;}else{return PRINTSYS_PrintStreamGetState((void *)a);}}

int INTRO_MSG_UpdatePrint(char *a)
{
    IntroMsgWork *work = (IntroMsgWork *)a;
    if (work->printStream != 0) {
        APP_KEYCURSOR_Update((struct Ctx *)work->keyCursor, work->printStream,
                      work->textWin);

        switch (PRINTSYS_PrintStreamGetState(work->printStream)) {
        case 2:
            PRINTSYS_PrintStreamDelete((struct Rec3 *)work->printStream);
            work->printStream = 0;
            return 1;
        case 1:
            if (KEY_GetTrg() == 1 || KEY_GetTrg() == 2
                || TOUCHPANEL_GetTrg() != 0) {
                PRINTSYS_PrintStreamReleasePause(work->printStream);
                GFL_USE_PlaySeDefaultVolume(0x547);
            }
            break;
        case 0:
            if ((KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0)
                PRINTSYS_PrintStreamShortWait((struct Rec *)work->printStream, 0);
            break;
        }
        return 0;
    }
    return 0;
}

int *INTRO_MSG_InitMenuDesc(char *p, int v)
{
    IntroMsgWork *work = (IntroMsgWork *)p;
    work->menuDesc = (void *)v;
    work->menuFlag = 0;
    return (int *)(&work->menuDesc);
}

/*
 * Owner unit_02045C44.c omits func_02045CAC from function:; singleton TU
 * --suggest-split leaves this caller out. the integrator owns that unit.
 * prior fixed-flag ARM9-45CAC.log, using the owner's unit declarations:
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest) {
 *   u32 size; struct MsgEntry *e;
 *   if (index >= bank->file->count) { STRBUF_Clear(dest); return; }
 *   func_02046180(bank);
 *   if (bank->resident == 0) {
 *     u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *     func_0204960C(bank->stream, pos + (index * 8 + 4));
 *     ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache); e = &bank->cache;
 *   } else { e = (struct MsgEntry *)((u8 *)bank->base + 4) + index; }
 *   if (bank->resident == 0) {
 *     void *buf; size = e->len * 2;
 *     buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),
 *                       size, 0, MSGDATA_AllocSite, 0xd6);
 *     if (buf != 0) {
 *       func_0204960C(bank->stream, e->off + (bank->origin
 *                     + bank->file->langOff[bank->langIndex]));
 *       ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *       STRBUF_SetChars(dest, buf, e->len); func_020307B0(buf);
 *     }
 *   } else { STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len); }
 *   func_02045E04(dest, index);
 * }
 * lever: u16 heap local places its word home at sp+8; u32 swaps it with
 * the entry pointer at sp+12, leaving seven differing concrete bytes.
 */
/*
 * Lever: the menu block is kept as a live char * (state) so the block
 * accesses stay on state and the other fields on p; a single work pointer
 * DIFFs (16 bytes short).
 */
void INTRO_MSG_CreateMenuList(char *p,u32 *entries,u32 count,int flag)
{
    IntroMsgWork *work = (IntroMsgWork *)p;
    IntroMsgMenuTemplate config;
    char *state;
    void *obj;
    u16 heap;
    u32 i;
    state=p+36;
    heap=work->heapId;
    obj=work->menuWin;
    MI_CpuFill8(state,0,12);
    *(void **)(state+4)=BMP_MENUWORK_Create(count,heap);
    for(i=0;i<count;i++){
        func_02045CAC(work->msgBank,*(u32 *)((char *)entries+i*8),(void *)work->strbuf1);
        BMP_MENUWORK_AddStrItem((struct Slot *)((char *)*(void **)(state+4)+i*8),(u32)work->strbuf1,*(u32 *)((char *)entries+i*8+4),heap);
    }
    MI_CpuFill8(&config,0,52);
    config.items=*(void **)(state+4);config.win=obj;
    config.count=count;config.rows=5;config.sepX=0;config.itemX=16;config.cursorX=0;
    config.originY=2;config.letterColor=1;config.bgColor=15;config.shadowColor=2;
    config.mode3=0;config.lineGap=0;config.pageKeys=1;config.mode6=0;config.cursorOff=0;
    config.userData=0;config.cursorW=16;config.rowH=16;config.pad24=0;
    config.target=INTRO_MSG_InitMenuDesc(p,(int)obj);config.printer=work->printSys;config.textParam=work->font;
    *(void **)state=BMP_MENULIST_Create((struct Src *)(&config),0,0,heap);
    func_02020CF8(*(void **)state,(u32)heap);
    BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);BG_SYS_PushTile((u8)BMP_WIN_GetBgLayer(obj));
    BMP_MENUWORK_DrawWindow(obj,1,7,9);
    if(flag)func_02020D10(*(void **)state,0);
    else func_02020D10(*(void **)state,1);
}

/*
 * Trailing two bytes are zero alignment padding.
 * Lever: the menu block is kept as a live char * (block) so the window
 * accesses stay on p and the menu accesses on block; a single work pointer
 * DIFFs.
 */
void INTRO_MSG_DrawMenuList(char *p)
{
    IntroMsgWork *work = (IntroMsgWork *)p;
    char *block = p + 0x24;
    BMP_MENUWORK_DrawWindowBorder(work->menuWin, 0);
    BMP_Clear(BMP_WIN_GetBmp(work->menuWin), 0);
    BMP_WIN_TransferChars(work->menuWin);
    BMP_MENULIST_Delete(*(void **)block, 0, 0);
    BMP_MENUWORK_Delete(*(void **)(block + 4));
    MI_CpuFill8(block, 0, 12);
}

/*
 * Lever: the menu block is kept as a live char * (q) so the state store
 * stays at q+8; a work pointer DIFFs (2 bytes short).
 */
void INTRO_MSG_MainMenuList(u8 *p)
{
    char *q=(char *)p+36;
    *(int *)(q + 8)=BMP_MENULIST_Main(*(struct Obj * *)q);
}

/*
 * lever: A switch with -1 before -2 preserves the outlined return order.
 */
int INTRO_MSG_GetMenuChoice(u8 *p,int *out)
{
    IntroMsgWork *work = (IntroMsgWork *)p;
    int v=work->menuState;
    switch(v){case -1:return 0;case -2:return 2;}
    if(out!=0)*out=v;
    return 1;
}

int INTRO_MSG_GetWordSet(u8 *p)
{
    IntroMsgWork *work = (IntroMsgWork *)p;
    return (int)work->wordSet;
}

void INTRO_MSG_StartTimeIcon(u8 *p)
{
    IntroMsgWork *work = (IntroMsgWork *)p;
    TIME_ICON_Start((u8 *)work->timeIcon,func_020056BC(),(u32)work->textWin,15,16);
}

void INTRO_MSG_DeleteTimeIcon(u8 *p)
{
    IntroMsgWork *work = (IntroMsgWork *)p;
    if(work->timeIcon!=0){TIME_ICON_Delete((u8 *)work->timeIcon);work->timeIcon=0;}
}
