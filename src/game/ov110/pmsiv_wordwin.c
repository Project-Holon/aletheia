/*
 * file:     pmsiv_wordwin.c
 * unit:     yes
 * function: PMSIV_WORDWIN_Create, PMSIV_WORDWIN_Delete, PMSIV_WORDWIN_Setup, PMSIV_WORDWIN_CreateActors, PMSIV_WORDWIN_DrawList, PMSIV_WORDWIN_DrawListFrom, PMSIV_WORDWIN_StartOpen, PMSIV_WORDWIN_IsOpen, PMSIV_WORDWIN_StartClose, PMSIV_WORDWIN_FinishClose, PMSIV_WORDWIN_SetVisible, PMSIV_WORDWIN_SetCursorCell, PMSIV_WORDWIN_Scroll, PMSIV_WORDWIN_UpdateScroll, PMSIV_WORDWIN_GetThumb, PMSIV_WORDWIN_SetThumbRow, PMSIV_WORDWIN_SetThumbY, PMSIV_WORDWIN_GetThumbRow, PMSIV_WORDWIN_ClearRows, PMSIV_WORDWIN_ResetScroll, PMSIV_WORDWIN_DrawCell, PMSIV_WORDWIN_StartPickAnim, PMSIV_WORDWIN_IsPickAnimDone
 * address:  0x021BF844
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pms_input.c, pmsiv_wordwin.c, pms_select_graphic.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   PMS_INPUT_GetUiInputModePtr 0x021BF6D4 thumb ov110
 *   PMSIV_WORDWIN_Create 0x021BF844 thumb ov110
 *   PMSIV_WORDWIN_Setup 0x021BF8F4 thumb ov110
 *   func_02040588 0x02040588 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PMSIV_WORDWIN_Delete 0x021BF8BC thumb ov110
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMS_INPUT_GetCursorPos 0x021BF724 thumb ov110
 *   PMSIV_WORDWIN_DrawList 0x021BF9F0 thumb ov110
 *   PMSIV_WORDWIN_StartOpen 0x021BFAA0 thumb ov110
 *   PMSIV_WORDWIN_IsOpen 0x021BFB58 thumb ov110
 *   PMSIV_WORDWIN_SetCursorCell 0x021BFC64 thumb ov110
 *   PMSIV_WORDWIN_SetThumbRow 0x021BFDB0 thumb ov110
 *   PMSIV_WORDWIN_SetVisible 0x021BFC20 thumb ov110
 *   PMSIV_WORDWIN_StartClose 0x021BFB7C thumb ov110
 *   PMSIV_WORDWIN_FinishClose 0x021BFBA0 thumb ov110
 *   PMSIV_WORDWIN_IsPickAnimDone 0x021C00FC thumb ov110
 *   PMSIV_WORDWIN_Scroll 0x021BFCA4 thumb ov110
 *   PMSIV_WORDWIN_UpdateScroll 0x021BFD60 thumb ov110
 *   PMSIV_WORDWIN_DrawListFrom 0x021BFA40 thumb ov110
 *   PMSIV_WORDWIN_StartPickAnim 0x021C00AC thumb ov110
 *   PMSIV_WORDWIN_GetThumb 0x021BFD94 thumb ov110
 *   PMSIV_WORDWIN_SetThumbY  0x021BFE24  thumb  ov110
 *   PMSIV_WORDWIN_GetThumbRow  0x021BFE60  thumb  ov110
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   STRBUF_Create 0x020457B0 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   func_02040618 0x02040618 arm
 *   func_020409B4 0x020409B4 arm
 *   PMS_INPUT_VIEW_GetFont 0x021BAC44 thumb ov110
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   PMS_INPUT_VIEW_GetUiRes 0x021BAC64 thumb ov110
 *   PMS_INPUT_VIEW_CreateActor 0x021BAC78 thumb ov110
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   PMSIV_BGSCROLL_Start 0x021BC78C thumb ov110
 *   PMSIV_BGSCROLL_Step 0x021BC7DC thumb ov110
 *   PMSIV_FADE_StartBlend 0x021BC868 thumb ov110
 *   PMSIV_FADE_IsBlendDone 0x021BC898 thumb ov110
 *   func_0207D63C 0x0207D63C arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   func_02041300 0x02041300 arm
 *   PMS_INPUT_VIEW_GetCursorRes 0x021BAC50 thumb ov110
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   BMP_FillRect 0x02043AF4 arm
 *   gPmsivWordwinFileName 0x021C3C84 data a1
 *   BG_SYS_InitRun 0x02040B94 arm
 *   PMS_INPUT_VIEW_LoadBgPalette 0x021BAD2C thumb ov110
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_SetActorPos 0x0204B528 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   BMP_Blit 0x020439A0 arm
 *   PMS_INPUT_GetListItemCount 0x021BF734 thumb ov110
 *   PMS_INPUT_GetListWord 0x021BF758 thumb ov110
 *   PMS_INPUT_GetScrollRange 0x021BF7EC thumb ov110
 */
#include "pms_input_types.h"
#include "pmsiv_wordwin_types.h"
#include "pms_input_view_shared_types.h"

struct Pt { u16 x, y; };

struct PtS { short x, y; };

struct PmsPos3 { int x, y, z; };

#define IO_U16(addr) (*(volatile u16 *)(addr))

#define IO_U32(addr) (*(volatile unsigned int *)(addr))

#define REG_DISPCNT_ADDR 0x04000000

#define REG_WIN0H_ADDR 0x04000042

#define REG_WIN0V_ADDR 0x04000046

#define REG_WININ_ADDR 0x04000048

#define REG_WINOUT_ADDR 0x0400004a

#define REG_BLDCNT_ADDR 0x04000050

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void BMP_WIN_TransferChars(struct Descriptor *);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void func_020409B4(u32);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void PRINTSYS_Print(void *, short, short, void *, void *);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

extern u32 CLACT_GetActorDrawEnable(struct Obj *p);

extern u16 CLACT_GetActorAnimSeq(struct Obj *p);

extern void CLACT_SetActorBgPriority(void *,int);

extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

typedef enum { FALSE, TRUE } BOOL;

typedef enum { PLANE_NONE=0, PLANE_ALL=31 } Plane;

typedef enum { WINDOW_NONE=0, WINDOW_0=1, WINDOW_1=2, WINDOW_OBJ=4 } Window;

extern void CLACT_DeleteActor(struct Obj *);

extern void STRBUF_Delete(struct U16Vec *);

extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

extern void func_02041300(unsigned,int,int,int,u8,u8,u8);

extern void func_0207D63C(void *,int,int,int,int);

extern void func_02040618(u32,u32,u32);

extern void func_0201DD68(void);

extern void BMP_Blit(struct Bmp *, struct Bmp *, u32, u32, int, int, u32, u32, u32);

extern void PMS_INPUT_VIEW_GetUiRes(struct PmsInputView *view, struct PmsPos3 *out, int x, int y);

extern void BMP_WIN_MakeScreen(struct Descriptor *window);

extern u32 PMS_INPUT_VIEW_GetFont(struct PmsInputView *view);

extern struct Obj *PMS_INPUT_VIEW_CreateActor(struct PmsInputView *view, struct PmsPos3 *pos, short x, short y, unsigned int a, int mode);

extern void PMS_INPUT_VIEW_GetCursorRes(struct PmsInputView *view, struct PmsPos3 *out, int i);

extern void PMS_INPUT_VIEW_LoadBgPalette(struct PmsInputView *view, int enable);

extern void PMSIV_BGSCROLL_Start(struct PmsivBgScroll *scroll, int layer, int axis, int step, int frames);

extern int PMSIV_BGSCROLL_Step(struct PmsivBgScroll *scroll);

extern void PMSIV_FADE_StartBlend(struct PmsivFade *fade, int firstPlanes, int secondPlanes, int start, int end, int frames);

extern int PMSIV_FADE_IsBlendDone(struct PmsivFade *fade);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct PtS *delta, u32 which);

extern u32 CLACT_IsActorAnimActive(struct Obj *actor);

extern void CLACT_GetActorSurfacePos(struct Obj *actor, struct PtS *out, u16 space);

extern void CLACT_SetActorPos(struct Obj *actor, const struct Pt *pos);

extern const char gPmsivWordwinFileName[];

unsigned int *PMS_INPUT_GetUiInputModePtr(PmsInput *input);

u8 PMS_INPUT_GetBrowseMode(PmsInput *input);

u16 PMS_INPUT_GetCursorPos(PmsInput *input);

u32 PMS_INPUT_GetListItemCount(PmsInput *input);

void PMS_INPUT_GetListWord(PmsInput *input,u32 a,int b);

void PMS_INPUT_GetScrollRange(const PmsInput *input, u16 *topRow, u16 *maxTopRow);

struct PmsivWordwin *PMSIV_WORDWIN_Create(struct PmsInputView *view, PmsInput *input, struct PmsInputData *wordData);

void PMSIV_WORDWIN_Delete(struct PmsivWordwin *p);

void PMSIV_WORDWIN_Setup(struct PmsivWordwin *p);

void PMSIV_WORDWIN_CreateActors(struct PmsivWordwin *p);

void PMSIV_WORDWIN_DrawList(struct PmsivWordwin *p);

void PMSIV_WORDWIN_DrawListFrom(struct PmsivWordwin *p,unsigned a);

void PMSIV_WORDWIN_StartOpen(struct PmsivWordwin *p);

int PMSIV_WORDWIN_IsOpen(struct PmsivWordwin *p);

void PMSIV_WORDWIN_StartClose(struct PmsivWordwin *p);

int PMSIV_WORDWIN_FinishClose(struct PmsivWordwin *p);

void PMSIV_WORDWIN_SetVisible(struct PmsivWordwin *p, unsigned visible);

void PMSIV_WORDWIN_SetCursorCell(struct PmsivWordwin *p, unsigned i);

void PMSIV_WORDWIN_Scroll(struct PmsivWordwin *p,int amount);

int PMSIV_WORDWIN_UpdateScroll(struct PmsivWordwin *p);

u32 PMSIV_WORDWIN_GetThumb(struct PmsivWordwin *p,struct PtS *out);

void PMSIV_WORDWIN_SetThumbRow(struct PmsivWordwin *p,unsigned a,unsigned n);

void PMSIV_WORDWIN_SetThumbY(struct PmsivWordwin *p,int y);

unsigned PMSIV_WORDWIN_GetThumbRow(struct PmsivWordwin *p, unsigned n);

void PMSIV_WORDWIN_ClearRows(struct PmsivWordwin *p,int amount);

void PMSIV_WORDWIN_ResetScroll(struct PmsivWordwin *p);

void PMSIV_WORDWIN_DrawCell(struct PmsivWordwin *p, u32 n, u32 y);

void PMSIV_WORDWIN_StartPickAnim(struct PmsivWordwin *p, unsigned i);

int PMSIV_WORDWIN_IsPickAnimDone(struct PmsivWordwin *p);

/* Allocates the word window and its two bitmap windows. */
struct PmsivWordwin *PMSIV_WORDWIN_Create(struct PmsInputView *view, PmsInput *input, struct PmsInputData *wordData) {
    struct PmsivWordwin *p=func_02030734(42,160,0,gPmsivWordwinFileName,154);
    p->view=view; p->input=input; p->wordData=wordData;
    p->wordText=STRBUF_Create(32,42);
    p->listWindow=(void *)BMP_WIN_Create(2,3,0,26,32,13,1);
    p->wrapWindow=(void *)BMP_WIN_Create(2,0,0,12,4,13,1);
    p->cursor=0; p->cursorWasVisible=0;
    p->uiInputMode=PMS_INPUT_GetUiInputModePtr(p->input);
    return p;
}

/* Frees the actors, the text and the windows. */
void PMSIV_WORDWIN_Delete(struct PmsivWordwin *p) {
    if(p->cursor) CLACT_DeleteActor(p->cursor);
    if(p->scrollThumb) CLACT_DeleteActor(p->scrollThumb);
    if(p->wordText) STRBUF_Delete(p->wordText);
    BMP_WIN_Delete(p->wrapWindow);
    BMP_WIN_Delete(p->listWindow);
    func_020307B0(p);
}

/* Clears the list window and creates the actors. */
void PMSIV_WORDWIN_Setup(struct PmsivWordwin *p) {
    BG_SYS_InitRun(2,32,0,42);
    func_02041300(2,0,0,0,32,32,13);
    BMP_Clear(BMP_WIN_GetBmp(p->listWindow),0);
    BMP_WIN_MakeScreen(p->listWindow);
    BMP_WIN_TransferChars(p->listWindow);
    func_020409B4(2); PMSIV_WORDWIN_CreateActors(p); func_02040588(2,0);
}

/* Creates the cursor, the scroll thumb and the ten decoration actors. */
void PMSIV_WORDWIN_CreateActors(struct PmsivWordwin *p) {
    struct PmsPos3 t;
    struct PmsPos3 s;
    int i;
    int z;
    i=0;
    PMS_INPUT_VIEW_GetUiRes(p->view,&t,0,0);
    p->cursor=PMS_INPUT_VIEW_CreateActor(p->view,&t,62,24,4,1);
    CLACT_SetActorAnimSeq(p->cursor,8);
    CLACT_SetActorDrawEnable(p->cursor,0);
    p->scrollThumb=PMS_INPUT_VIEW_CreateActor(p->view,&t,244,18,5,1);
    CLACT_SetActorAnimSeq(p->scrollThumb,18);
    CLACT_SetActorDrawEnable(p->scrollThumb,0);
    z=i;
    for(;i<10;i++) {
        PMS_INPUT_VIEW_GetCursorRes(p->view,&s,z);
        p->items[i]=PMS_INPUT_VIEW_CreateActor(p->view,&s,z,z,z,1);
        CLACT_SetActorAnimSeq(p->items[i],i);
        CLACT_SetActorDrawEnable(p->items[i],z);
        CLACT_SetActorBgPriority(p->items[i],1);
    }
}

/* Redraws the first 16 cells of the list. */
void PMSIV_WORDWIN_DrawList(struct PmsivWordwin *p) {
    unsigned y,i,n;
    BMP_Clear(BMP_WIN_GetBmp(p->listWindow),0);
    PMSIV_WORDWIN_ResetScroll(p);
    n=PMS_INPUT_GetListItemCount(p->input);
    if(n>16) n=16;
    i=0;
    y=p->originY;
    for(;i<n;i++) {
        PMSIV_WORDWIN_DrawCell(p,i,y);
        if(i&1) y+=24;
    }
    BMP_WIN_TransferChars(p->listWindow);
}

/* Redraws the list from one row. */
void PMSIV_WORDWIN_DrawListFrom(struct PmsivWordwin *p,unsigned a) {
    unsigned y,i,n;
    BMP_Clear(BMP_WIN_GetBmp(p->listWindow),0);
    PMSIV_WORDWIN_ResetScroll(p);
    p->firstShown=a*2;
    n=PMS_INPUT_GetListItemCount(p->input);
    if(n>16) n=16;
    i=0;
    y=p->originY;
    for(;i<n;i++) {
        PMSIV_WORDWIN_DrawCell(p,p->firstShown+i,y);
        if(i&1) y+=24;
    }
    BMP_WIN_TransferChars(p->listWindow);
}

static inline void inside(Plane wnd,BOOL effect) {
    unsigned tmp=(IO_U16(REG_WININ_ADDR) & ~0x3f00) | ((unsigned)wnd<<8);
    if(effect) tmp|=0x2000;
    IO_U16(REG_WININ_ADDR)=tmp;
}

static inline void outside(Plane wnd,BOOL effect) {
    unsigned tmp=(IO_U16(REG_WINOUT_ADDR) & ~0x3f) | (unsigned)wnd;
    if(effect) tmp|=0x20;
    IO_U16(REG_WINOUT_ADDR)=tmp;
}

static inline void wndpos(int x1,int y1,int x2,int y2) {
    IO_U16(REG_WIN0H_ADDR)=(x1<<8)|x2;
    IO_U16(REG_WIN0V_ADDR)=(y1<<8)|y2;
}

static inline void visible(Window wnd) {
    IO_U32(REG_DISPCNT_ADDR)=(IO_U32(REG_DISPCNT_ADDR) & ~0xe000) | (wnd<<13);
}

/* Starts the window effect that opens the list. */
void PMSIV_WORDWIN_StartOpen(struct PmsivWordwin *p) {
    PMS_INPUT_VIEW_LoadBgPalette(p->view,1);
    func_0207D63C((void *)REG_BLDCNT_ADDR,4,63,0,16);
    func_02040588(2,1);
    inside(31,1);
    p->savedWinOut.raw=*(volatile u8 *)REG_WINOUT_ADDR;
    p->savedDispWindows=(IO_U32(REG_DISPCNT_ADDR) & 0xe000)>>13;
    outside(27,1);
    wndpos(0,0,255,168);
    visible(2);
    p->fadeBusy=0;
    PMSIV_FADE_StartBlend(&p->fade,4,63,0,124,12);
}

/* Whether the open effect is done. */
int PMSIV_WORDWIN_IsOpen(struct PmsivWordwin *p) {
    if(p->fadeBusy==0) {
        if(PMSIV_FADE_IsBlendDone(&p->fade)) return 1;
        else return 0;
    } else return 1;
}

/* Starts the window effect that closes the list. */
void PMSIV_WORDWIN_StartClose(struct PmsivWordwin *p) {
    p->fadeBusy=0;
    PMSIV_FADE_StartBlend(&p->fade,4,63,124,0,12);
}

static inline void outside_b(int wnd,int effect) {
    unsigned tmp=IO_U16(REG_WINOUT_ADDR) & ~0x3f;
    tmp|=wnd;
    if(effect) tmp|=0x20;
    IO_U16(REG_WINOUT_ADDR)=tmp;
}

static inline void visible_b(int window) {
    IO_U32(REG_DISPCNT_ADDR)=(IO_U32(REG_DISPCNT_ADDR) & ~0xe000) | (window<<13);
}

/* Ends the close effect and restores the window registers. */
int PMSIV_WORDWIN_FinishClose(struct PmsivWordwin *p) {
    int i;
    if(p->fadeBusy==0) {
    if(PMSIV_FADE_IsBlendDone(&p->fade)) {
        for(i=0;i<10;i++) CLACT_SetActorDrawEnable(p->items[i],0);
        func_02040588(2,0);
        outside_b(p->savedWinOut.bits.plane,p->savedWinOut.bits.effect);
        visible_b(p->savedDispWindows);
        return 1;
    }
    } else return 1;
    return 0;
}

/* Shows or hides the cursor and the scroll thumb. */
void PMSIV_WORDWIN_SetVisible(struct PmsivWordwin *p, unsigned visible) {
    if (visible) {
        if (*p->uiInputMode==0) CLACT_SetActorDrawEnable(p->cursor,1);
        else CLACT_SetActorDrawEnable(p->cursor,0);
        CLACT_SetActorDrawEnable(p->scrollThumb, PMS_INPUT_GetListItemCount(p->input)>14 ? 1 : 0);
    } else {
        CLACT_SetActorDrawEnable(p->cursor,visible);
        CLACT_SetActorDrawEnable(p->scrollThumb,0);
    }
}

/* Puts the cursor on a list cell. */
void PMSIV_WORDWIN_SetCursorCell(struct PmsivWordwin *p, unsigned i) {
    struct PtS pos;
    if (i != -1) {
        pos.x = 0x70*(i&1)+0x3e;
        pos.y = 0x18*((i>>1)+1);
        CLACT_AddActorSurfacePos(p->cursor, &pos, 0);
        CLACT_SetActorAnimSeq(p->cursor, 8);
    }
}

/* Scrolls the list by rows and draws the new rows. */
void PMSIV_WORDWIN_Scroll(struct PmsivWordwin *p,int amount) {
    int count,i;
    u8 newy;
    int newstart,start,step;
    u8 y;
    PMSIV_WORDWIN_ClearRows(p,amount);
    count=amount*2;
    start=p->firstShown;
    newstart=start+count;
    step=24*amount;
    newy=(u8)(p->originY+step);
    if(amount<0) {
        start=newstart;
        y=newy;
        count=-count;
        amount=-amount;
    } else {
        y=(u8)(p->originY+192);
        start+=16;
        if(count+start>PMS_INPUT_GetListItemCount(p->input)) count--;
    }
    for(i=0;i<count;i++) {
        PMSIV_WORDWIN_DrawCell(p,start+i,y);
        if(i&1) y+=24;
    }
    p->originY=newy;
    p->firstShown=newstart;
    BMP_WIN_TransferChars(p->listWindow);
    BMP_WIN_MakeScreen(p->listWindow);
    PMSIV_BGSCROLL_Start(&p->scroll,2,1,step,amount);
}

/* Finishes a scroll step and moves the scroll thumb. */
int PMSIV_WORDWIN_UpdateScroll(struct PmsivWordwin *p) { u16 x,y; if(PMSIV_BGSCROLL_Step(&p->scroll)) { PMS_INPUT_GetScrollRange(p->input,&x,&y); PMSIV_WORDWIN_SetThumbRow(p,x,y); return 1; } return 0; }

/* Reads the scroll thumb position and visibility. */
u32 PMSIV_WORDWIN_GetThumb(struct PmsivWordwin *p,struct PtS *out) { u32 result; result=CLACT_GetActorDrawEnable(p->scrollThumb); CLACT_GetActorSurfacePos(p->scrollThumb,out,0); return result; }

/* Puts the scroll thumb at the position of a row. */
void PMSIV_WORDWIN_SetThumbRow(struct PmsivWordwin *p,unsigned a,unsigned n) {
    struct PtS pos;
    short lo,hi;
    pos.x=244;
    if(a==0) { pos.y=18; goto apply; }
    else if(a==n) { pos.y=149; goto apply; }
    else if(n==0) goto low;
    else {
        lo=132*a/(n+1)+18;
        hi=132*(a+1)/(n+1)+17;
        pos.y=(lo+hi)/2;
        if(pos.y<18) { pos.y=18; goto apply; }
        else {
            if(pos.y>149) { pos.y=149; goto apply; }
        }
    }
    goto apply;
low: pos.y=18;
apply:
    CLACT_AddActorSurfacePos(p->scrollThumb, &pos, 0);
}

/* Puts the scroll thumb at a height, clamped to the bar. */
void PMSIV_WORDWIN_SetThumbY(struct PmsivWordwin *p,int y) { struct PtS pos; CLACT_GetActorSurfacePos(p->scrollThumb,&pos,0); pos.y=y; if(pos.y<18) pos.y=18; if(pos.y>149) pos.y=149; CLACT_AddActorSurfacePos(p->scrollThumb, &pos, 0); }

/* Row that matches the scroll thumb position. */
unsigned PMSIV_WORDWIN_GetThumbRow(struct PmsivWordwin *p, unsigned n)
{
    int i;
    unsigned result;
    struct PtS pos;
    short y;
    PMSIV_WORDWIN_GetThumb(p, &pos);
    if (n == 0) goto zero;
    else {
        y = pos.y;
        do {
            if (y == 18) { result = 0; goto end; }
            else if (y == 149) result = n;
            else {
                for (i = 0; i <= n; i = (short)(i + 1)) {
                    short lo, hi;
                    lo = 132 * (unsigned)i / (n + 1) + 18;
                    hi = 132 * (unsigned)(i + 1) / (n + 1) + 17;
                    if (lo > hi) hi = lo;
                    if (lo <= y && y <= hi) { result = (int)i; break; }
                }
            }
            goto end;
        } while (0);
        goto zero;
    }
    goto end;
zero: result = 0;
end:
    return result;
}

/* Clears the bitmap rows that scroll into view. */
void PMSIV_WORDWIN_ClearRows(struct PmsivWordwin *p,int amount) {
    int start,end;
    if(amount>0) {
        start=(u8)(p->originY+192);
        end=(u8)(start+24*amount);
    } else {
        end=p->originY;
        start=(u8)(end+24*amount);
    }
    if(start<end) {
        BMP_FillRect(BMP_WIN_GetBmp(p->listWindow),(short)0,(short)start,(u16)208,(u16)(end-start),(u8)0);
    } else {
        BMP_FillRect(BMP_WIN_GetBmp(p->listWindow),(short)0,(short)start,(u16)208,(u16)(256-start),(u8)0);
        BMP_FillRect(BMP_WIN_GetBmp(p->listWindow),(short)0,(short)0,(u16)208,(u16)end,(u8)0);
    }
}

/* Resets the scroll offset of the list window. */
void PMSIV_WORDWIN_ResetScroll(struct PmsivWordwin *p) { p->originY=0; p->firstShown=0; func_02040618(2,3,8); }

/* Draws one list cell at a height. */
void PMSIV_WORDWIN_DrawCell(struct PmsivWordwin *p, u32 n, u32 y)
{
    u32 font;
    struct Pt pos;
    u32 wrap, x;
    struct Bmp *dest;
    font = PMS_INPUT_VIEW_GetFont(p->view);
    if (n < 2 || n >= PMS_INPUT_GetListItemCount(p->input)) return;
    if (!PMS_INPUT_GetBrowseMode(p->input) && PMS_INPUT_GetCursorPos(p->input) == 11) {
        x = 24 + 112 * ((n - 2) & 1);
        n = n - 2;
        pos.x = x;
        pos.y = y - 8;
        CLACT_SetActorPos(p->items[n], &pos);
        CLACT_SetActorDrawEnable(p->items[n], 1);
        return;
    }
    PMS_INPUT_GetListWord(p->input, n - 2, (int)(p->wordText));
    func_0201DD68();
    if (y <= 240) {
        PRINTSYS_Print(BMP_WIN_GetBmp(p->listWindow), 112 * ((n - 2) & 1), y, p->wordText, (void *)font);
    } else {
        wrap = 256 - y;
        BMP_Clear(BMP_WIN_GetBmp(p->wrapWindow), 0);
        PRINTSYS_Print(BMP_WIN_GetBmp(p->wrapWindow), 0, 0, p->wordText, (void *)font);
        n = 112 * ((n - 2) & 1);
        dest = BMP_WIN_GetBmp(p->wrapWindow);
        BMP_Blit(dest, BMP_WIN_GetBmp(p->listWindow), 0, 0, n, y, 96, wrap, 65535);
        dest = BMP_WIN_GetBmp(p->wrapWindow);
        BMP_Blit(dest, BMP_WIN_GetBmp(p->listWindow), 0, wrap, n, 0, 96, 16 - wrap, 65535);
    }
}

/* Starts the animation of the cursor on the picked cell. */
void PMSIV_WORDWIN_StartPickAnim(struct PmsivWordwin *p, unsigned i) {
    struct PtS pos;
    p->cursorWasVisible=CLACT_GetActorDrawEnable(p->cursor);
    CLACT_SetActorDrawEnable(p->cursor,1);
    if (i != -1) {
        pos.x=0x70*(i&1)+0x3e;
        pos.y=0x18*((i>>1)+1);
        CLACT_AddActorSurfacePos(p->cursor, &pos, 0);
        CLACT_SetActorAnimSeq(p->cursor,0x1c);
    }
}

/* Ends the pick animation when it is done. */
int PMSIV_WORDWIN_IsPickAnimDone(struct PmsivWordwin *p) { if(CLACT_GetActorAnimSeq(p->cursor)!=28) return 1; if(!CLACT_IsActorAnimActive(p->cursor)) { CLACT_SetActorDrawEnable(p->cursor,p->cursorWasVisible); CLACT_SetActorAnimSeq(p->cursor,8); p->cursorWasVisible=0; return 1; } return 0; }
