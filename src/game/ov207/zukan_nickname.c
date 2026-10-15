/*
 * file:     zukan_nickname.c
 * unit:     yes
 * function: ZUKAN_NICKNAME_Create, ZUKAN_NICKNAME_Delete, ZUKAN_NICKNAME_Main, ZUKAN_NICKNAME_SetupScreen, ZUKAN_NICKNAME_GetResult, ZUKAN_NICKNAME_TransferPalette, ZUKAN_NICKNAME_InitKeyboard, ZUKAN_NICKNAME_DeleteKeyboard, ZUKAN_NICKNAME_UpdateInfoWindow
 * address:  0x0220B55C
 * region:   ov207
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   file_0220BC38 0x0220BC38 data a1
 *   func_02049B40 0x02049B40 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotMonName 0x0201EE84 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   func_020355C4 0x020355C4 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   func_020307B0 0x020307B0 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont 0x0203630C arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WORDSET_SetSlotMonSpecies 0x0201EEF4 thumb
 *   WORDSET_SetSlotBoxName 0x0201F164 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   overlay94 0x0000005E data
 *   BTLV_INPUT_CreateDefault 0x02202058 thumb ov094
 *   BTLV_INPUT_Delete 0x022021F4 thumb ov094
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_02034A5C 0x02034A5C arm
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb  arm9
 *   PALANM_Create  0x02021518  thumb  arm9
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb  arm9
 *   BTLV_INPUT_ChangeScreen  0x0220270C  thumb
 *   BTLV_INPUT_ProcessTouchInput  0x02202DC4  thumb
 *   BTLV_INPUT_UpdateInfoWindow  0x02202228  thumb
 *   d_0220BBEC     0x0220BBEC  data  ov207
 *   d_0220BBF8     0x0220BBF8  data  ov207
 */

typedef struct ZukanNicknameWork {
    unsigned short heapId;
    unsigned char pad2[2];
    void *titleStr;
    void *nameStr;
    unsigned int textId;
    unsigned int textParam;
    unsigned int display;
    unsigned int font;
    unsigned int gfx;
    unsigned int textId2;
    void *bmpWin;
    void *printStream;
    void *strbuf;
    void *lineBuf;
    void *tcbl;
    void *bmpWin2;
    int state;
    int mode;
    int counter;
    void *task;
    int pauseFlag;
    unsigned char soundEnabled;
    unsigned char pad51[3];
    void *input;
    void *palAnm;
} ZukanNicknameWork;

struct WordSet;
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct CharBuf;
struct Tcbl;
struct Rec;
struct Node;
struct Rec3;
struct S02031140;
struct Cfg;
struct S02021D50;
struct PalAnm;
struct PalAnmSlot;
struct Obj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int     s32;

typedef struct Obj Obj;

typedef struct {
    int v0;
    int v1;
    int v2;
} S3;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,int,int);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct WordSet *WORDSET_CreateDefault(u32);
extern void WORDSET_SetSlotMonName(struct WordSet *,u32,void *);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void WORDSET_CopyTaggedText(struct WordSet *,void *,void *);
extern void STRBUF_Delete(struct U16Vec *);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(u32);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern signed char MSG_SPEED_GetWait(void);
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void *BMP_MENUWORK_LoadFrameGfx(void *,u32,u32,u32);
extern u8 func_020355C4(void);
extern void *func_020056A0(u32,u32,u32);
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 func_020307B0(void *p);
extern void TCBL_Main(struct Tcbl *);
extern u32 PRINTSYS_PrintStreamGetState(void *);
extern u32 KEY_GetCont(void);
extern void func_020355D8(int a);
extern int TOUCHPANEL_GetCont(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void WORDSET_SetSlotMonSpecies(struct WordSet *,u32,void *);
extern void WORDSET_SetSlotBoxName(struct WordSet *,u32,u32,u32);
extern void BMP_MENUWORK_DrawWindow(void *,int,unsigned short,int);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern int func_02034AC4(int);
extern void *PALANM_Create(unsigned);
extern void PALANM_SetAutoTransfer(struct PalAnm *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern struct Obj *BTLV_INPUT_CreateDefault(int a, int b, int c, int d, int e, u16 k);
extern void BTLV_INPUT_Delete(Obj *);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,unsigned);
extern void PALANM_Delete(struct PalAnmSlot *);
extern void func_02034A5C(int);
extern void BTLV_INPUT_ChangeScreen(int *p, int n, S3 *s);
extern int  BTLV_INPUT_ProcessTouchInput(int *p, void *a, void *b);
extern void BTLV_INPUT_UpdateInfoWindow(int *p);
char *ZUKAN_NICKNAME_Create(u16 heap,u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g,u32 h);
void ZUKAN_NICKNAME_Delete(ZukanNicknameWork *p);
int ZUKAN_NICKNAME_Main(ZukanNicknameWork *p);
void ZUKAN_NICKNAME_SetupScreen(ZukanNicknameWork *p);
int ZUKAN_NICKNAME_GetResult(ZukanNicknameWork *p);
void ZUKAN_NICKNAME_TransferPalette(void *a, ZukanNicknameWork *p);
void ZUKAN_NICKNAME_InitKeyboard(ZukanNicknameWork *p);
void ZUKAN_NICKNAME_DeleteKeyboard(ZukanNicknameWork *p);
void ZUKAN_NICKNAME_UpdateInfoWindow(ZukanNicknameWork *a);
extern char file_0220BC38[];
extern char overlay94[];
extern char d_0220BBEC[];
extern char d_0220BBF8[];


/*
 * ABI: 0201CCE4 is a void forwarder in its matched source; caller stores live r0, so declare its observed word return.
 */
char *ZUKAN_NICKNAME_Create(u16 heap,u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g,u32 h)
{
    ZukanNicknameWork *p;
    struct WordSet *ws;
    struct MsgBank *bank;
    void *str;
    u8 enabled;
    p=(ZukanNicknameWork *) func_02030734(heap,0x5c,0,file_0220BC38,220);
    MI_CpuFill8(p,0,0x5c);
    p->heapId=heap;
    *(u32 *)&p->titleStr=a;
    *(u32 *)&p->nameStr=b;
    p->textId=c;
    p->textParam=d;
    p->display=e;
    p->font=f;
    p->gfx=g;
    p->textId2=h;
    p->state=0;
    p->mode=2;
    p->counter=0;
    func_02049B40(0x17,5,0,0x120,32,p->heapId);
    ws=WORDSET_CreateDefault(p->heapId);
    WORDSET_SetSlotMonName(ws,0,p->titleStr);
    bank=func_02045B38(0,2,0xea,p->heapId);
    str=func_02045EC0(bank,0xaf);
    p->strbuf=STRBUF_Create(64,p->heapId);
    WORDSET_CopyTaggedText(ws,p->strbuf,str);
    STRBUF_Delete(str);
    MSGDATA_Delete((struct Rec *)bank);
    WORDSET_DeleteStrbufED04(ws);
    p->bmpWin2=(void *)BMP_WIN_Create(3,0,0,1,1,9,0);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&p->bmpWin2),0);
    BMP_WIN_TransferChars(*(struct Descriptor * *)&p->bmpWin2);
    func_02041B6C(BMP_WIN_GetBgLayer(*(struct Descriptor * *)&p->bmpWin2));
    p->tcbl=TCBL_Create(p->heapId,p->heapId,1,0);
    p->bmpWin=(void *)BMP_WIN_Create(3,1,19,30,4,9,1);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&p->bmpWin),15);
    GF_FONT_SetTextColor(1,2,15);
    *(u32 *)&p->printStream=PRINTSYS_PrintStream((u32)p->bmpWin,0,0,(u32)p->strbuf,p->font,MSG_SPEED_GetWait(),(u32)p->tcbl,2,p->heapId,15);
    p->lineBuf=BMP_MENUWORK_LoadFrameGfx((void *)3,8,0,p->heapId);
    enabled=1;
    if(func_020355C4()!=0) enabled=0;
    p->soundEnabled=enabled;
    ZUKAN_NICKNAME_InitKeyboard(p);
    p->task=func_020056A0((u32)ZUKAN_NICKNAME_TransferPalette,(u32)p,1);
    return (char *)p;
}


/*
 * tail: two zero alignment bytes at 0x0220B72A before 0x0220B72C.
 */
void ZUKAN_NICKNAME_Delete(ZukanNicknameWork *p)
{
    ZUKAN_NICKNAME_DeleteKeyboard((ZukanNicknameWork *)p);
    func_02030EAC((struct Node *)p->task);
    PRINTSYS_PrintStreamDelete(p->printStream);
    BG_SYS_DeleteHalf(3, (u16)(u32)p->lineBuf, (u16)((u32)p->lineBuf >> 16));
    BMP_WIN_Delete((struct Descriptor *)p->bmpWin);
    STRBUF_Delete((struct U16Vec *)p->strbuf);
    TCBL_Destroy((struct S02031140 *)p->tcbl);
    BMP_WIN_Delete((struct Descriptor *)p->bmpWin2);
    func_020307B0(p);
}


/*
 * ABI: 02035C60/0201CCE4 matched void forwarders leave r0 live; this caller tests/stores it.
 */
int ZUKAN_NICKNAME_Main(ZukanNicknameWork *p)
{
    int done=0,flag;
    u32 value;
    struct WordSet *ws;
    switch(p->state) {
    case 0: break;
    case 1:
        TCBL_Main(*(struct Tcbl * *)&p->tcbl);
        value=PRINTSYS_PrintStreamGetState(p->printStream);
        if(value==2) {p->state=2;p->pauseFlag=1;break;}
        switch(value) {
        case 0:
            flag=0;
            if(KEY_GetCont()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetCont()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) PRINTSYS_PrintStreamShortWait(p->printStream,0);
            break;
        case 1:
            flag=0;
            if(KEY_GetTrg()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetTrg()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) {PRINTSYS_PrintStreamReleasePause(p->printStream);GFL_USE_PlaySeDefaultVolume(0x547);}
            break;
        }
        break;
    case 2:
        if(p->mode==2) break;
        if(p->mode==0) {
            if(*(u32 *)&p->nameStr==0) {p->state=5;break;}
            BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&p->bmpWin),15);
            PRINTSYS_PrintStreamDelete(p->printStream);
            STRBUF_Delete(*(struct U16Vec * *)&p->strbuf);
            ws=WORDSET_CreateDefault(p->heapId);
            WORDSET_SetSlotMonSpecies(ws,0,p->titleStr);
            WORDSET_SetSlotBoxName(ws,1,p->textId,p->textParam);
            p->strbuf=STRBUF_Create(64,p->heapId);
            WORDSET_CopyTaggedText(ws,p->strbuf,p->nameStr);
            WORDSET_DeleteStrbufED04(ws);
            *(u32 *)&p->printStream=PRINTSYS_PrintStream((u32)p->bmpWin,0,0,(u32)p->strbuf,p->font,MSG_SPEED_GetWait(),(u32)p->tcbl,2,p->heapId,15);
            p->state=3;
        } else p->state=5;
        break;
    case 3:
        TCBL_Main(*(struct Tcbl * *)&p->tcbl);
        value=PRINTSYS_PrintStreamGetState(p->printStream);
        if(value==2) {p->state=4;break;}
        switch(value) {
        case 0:
            flag=0;
            if(KEY_GetCont()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetCont()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) PRINTSYS_PrintStreamShortWait(p->printStream,0);
            break;
        case 1:
            flag=0;
            if(KEY_GetTrg()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetTrg()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) {PRINTSYS_PrintStreamReleasePause(p->printStream);GFL_USE_PlaySeDefaultVolume(0x547);}
            break;
        }
        break;
    case 4:
        ++p->counter;
        if(p->counter==60) p->state=5;
        break;
    case 5: done=1; break;
    }
    ZUKAN_NICKNAME_UpdateInfoWindow(p);
    return done;
}


void ZUKAN_NICKNAME_SetupScreen(ZukanNicknameWork *p){if(!p->state){struct Descriptor *d;unsigned flag=1;BMP_MENUWORK_DrawWindow(p->bmpWin,1,(int)p->lineBuf,8);d=*(struct Descriptor * *)&p->bmpWin;BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);func_02041B6C(BMP_WIN_GetBgLayer(d));p->state=flag;}}


/*
 * Extra: ARM9-free blocker getter for assigned 0220B0A4; ownership and SDK checks clear.
 */
int ZUKAN_NICKNAME_GetResult(ZukanNicknameWork *p)
{
    return p->mode;
}


void ZUKAN_NICKNAME_TransferPalette(void *a, ZukanNicknameWork *p){if(p->palAnm)PALANM_TransferPalettes(p->palAnm);}


void ZUKAN_NICKNAME_InitKeyboard(ZukanNicknameWork *p)
{
    func_02034AC4((int)overlay94);
    p->palAnm=PALANM_Create(p->heapId);
    PALANM_SetAutoTransfer(p->palAnm,1);
    PALANM_AllocSlotBuffers(p->palAnm,1,480,p->heapId);
    PALANM_AllocSlotBuffers(p->palAnm,3,480,p->heapId);
    p->input=BTLV_INPUT_CreateDefault((int)(void *)p->textId2,0,(int)(void *)p->palAnm,(int)(void *)p->font,(int)&p->soundEnabled,p->heapId);
    p->pauseFlag=0;
}


/*
 * lever: pooled FS overlay ID is the overlay94 linker symbol address, as in matched ov207 0220B048; literal 94 compiles as movs.
 */
void ZUKAN_NICKNAME_DeleteKeyboard(ZukanNicknameWork *p){BTLV_INPUT_Delete(*(Obj * *)&p->input);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&p->palAnm,1);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&p->palAnm,3);PALANM_Delete(*(struct PalAnmSlot * *)&p->palAnm);*(unsigned *)&p->palAnm=0;func_02034A5C((int)overlay94);}


void ZUKAN_NICKNAME_UpdateInfoWindow(ZukanNicknameWork *a)
{
    S3 s;

    switch (a->pauseFlag) {
    case 0:
    case 3:
        break;
    case 1:
        a->soundEnabled = (func_020355C4() == 0) ? 1 : 0;
        {
            int r5 = (int)func_02045B38(0, 2, 0xe9, ((ZukanNicknameWork *)a)->heapId);
            s.v0 = (int)func_02045EC0((struct MsgBank *)r5, 0);
            s.v1 = (int)func_02045EC0((struct MsgBank *)r5, 1);
            s.v2 = 1;
            BTLV_INPUT_ChangeScreen((int *)a->input, 4, &s);
            STRBUF_Delete((struct U16Vec *)s.v0);
            STRBUF_Delete((struct U16Vec *)s.v1);
            MSGDATA_Delete((struct Rec *)r5);
            a->pauseFlag = 2;
        }
        break;
    case 2:
        {
            int r5 = BTLV_INPUT_ProcessTouchInput((int *)a->input, d_0220BBEC, d_0220BBF8);
            if (r5 == -1)
                break;
            BTLV_INPUT_ChangeScreen((int *)a->input, 0, 0);
            a->pauseFlag = 3;
            if (r5 == 0)
                a->mode = 1;
            else
                a->mode = 0;
            func_020355D8(a->soundEnabled ? 0 : 1);
        }
        break;
    }
    BTLV_INPUT_UpdateInfoWindow((int *)a->input);
}
