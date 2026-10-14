#ifndef OV136_MAIL_TYPES_H
#define OV136_MAIL_TYPES_H

/*
 * Mail screens (overlay 136). One struct per object:
 *   MailArgs      0x1C  caller's request and result (write a mail or view one)
 *   MailDraft     0x34  editable copy of a mail (heap 0x63/0x64 owner: MailToolProc / MailEditProc)
 *   MailToolProc  0x20  process that runs the mail edit screen and the easy chat input (heap 0x63)
 *   MailEditProc  0x15C process of the mail edit/view screen (heap 0x64)
 *   MailBoxProc   0x34  process of the mail box list screen (heap 0x65)
 *   MailBoxView   0x370 screen resources of the mail box list (heap 0x66)
 */

#include "../arm9/pms_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;

struct Mail;
struct Strbuf;
struct PmsiParam;
struct PmsDraw;
struct MsgData;
struct GfFont;
struct PalAnm;
struct PrintQue;
struct ClactUnit;
struct AppTaskMenuRes;
struct AppTaskMenu;
struct AppTaskMenuWin;
struct Tcbl;
struct BmpWin;
struct SaveControl;
struct MailData;
struct GameData;
struct BgWinFrm;
struct ClactActor;
struct WordSet;
struct PrintStream;
struct TouchSelect;

/* Request and result of the mail screens (0x1C). */
struct MailArgs {
    /* 0x00 */ u16 mode;               /* 1 = write a mail, 0 = view one */
    /* 0x02 */ u8 pad_02[2];
    /* 0x04 */ u32 sent;               /* result: 1 when the player sent the mail, 0 otherwise */
    /* 0x08 */ u32 callerParam;        /* argument b of MAILTOOL_CreateWriteArgs, stored and never read here */
    /* 0x0C */ u16 reserved0C;         /* always 0 */
    /* 0x0E */ u8 monIndex;            /* argument c, passed on to func_02008F48 */
    /* 0x0F */ u8 designId;            /* initial paper design (0..11) in write mode */
    /* 0x10 */ struct SaveControl *saveControl;
    /* 0x14 */ struct Mail *mail;
    /* 0x18 */ struct MailData *mailData;
};

/* Editable copy of a mail (0x34). */
struct MailDraft {
    /* 0x00 */ u16 result;             /* edit result: slot index, 4 = send, 0xFFFF = cancel; input mode before the screen runs */
    /* 0x02 */ u8 selectedSlot;        /* sentence slot chosen on the edit screen (3 = closing word) */
    /* 0x03 */ u8 selectedSub;         /* cursor sub-position stored with the selection */
    /* 0x04 */ u32 writerId;
    /* 0x08 */ u8 pad_08;
    /* 0x09 */ u8 language;
    /* 0x0A */ u8 version;
    /* 0x0B */ u8 design;              /* paper design 0..11 */
    /* 0x0C */ struct Strbuf *writerName;
    /* 0x10 */ u8 pad_10[6];
    /* 0x16 */ struct PmsData message[3];
    /* 0x2E */ u8 slotEnabled[3];      /* 1 when the design has a sentence slot there */
    /* 0x31 */ u8 pad_31;
    /* 0x32 */ u16 messageId;          /* closing easy-chat word */
};

/* Process of the mail tool (0x20). */
struct MailToolProc {
    /* 0x00 */ u32 heapId;
    /* 0x04 */ u8 pad_04[4];
    /* 0x08 */ struct PmsiParam *pmsiParam;
    /* 0x0C */ u8 pad_0C[4];
    /* 0x10 */ struct MailDraft *draft;
    /* 0x14 */ struct PmsData sentence;  /* scratch sentence handed to the easy chat screen */
    /* 0x1C */ void *procSys;
};

/* Window slot: BMP window and a flag the print code sets. */
struct MailWinSlot {
    struct BmpWin *win;
    u8 flag;
    u8 pad_05[3];
};

/* Entry record read by APP_TASKMENU_OpenMenu and APP_TASKMENU_WIN_Create. */
struct MailMenuEntry {
    struct Strbuf *text;
    u16 color;
    u16 pad_06;
    int selected;
};

struct MailMenuTemplate {
    u32 heapId;
    u8 count;
    u8 pad_05[3];
    struct MailMenuEntry *items;
    u32 zero;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
};

/* Process of the mail edit screen (0x15C). */
struct MailEditProc {
    /* 0x000 */ u32 heapId;
    /* 0x004 */ u32 step;
    /* 0x008 */ u16 subStep;
    /* 0x00A */ u8 inputMode;          /* 0 = touch, 1 = keys */
    /* 0x00B */ u8 mode;               /* screen mode: index of the handler table (0 edit, 1 write, 2 send dialog, 3 cancel dialog) */
    /* 0x00C */ u8 prevMode;
    /* 0x00D */ u8 pad_0D[3];
    /* 0x010 */ int dialogActive;
    /* 0x014 */ u8 pad_14;
    /* 0x015 */ s8 textSpeed;
    /* 0x016 */ u8 cursor;
    /* 0x017 */ u8 cursorSub;
    /* 0x018 */ u8 blinkWeight;
    /* 0x019 */ u8 blinkDown;
    /* 0x01A */ u8 highlightSlot;
    /* 0x01B */ u8 blinkSlot;
    /* 0x01C */ struct MailDraft *draft;
    /* 0x020 */ struct MsgData *msgData;
    /* 0x024 */ struct GfFont *font;
    /* 0x028 */ u8 pad_28[0x0C];
    /* 0x034 */ struct Strbuf *msgBuf;
    /* 0x038 */ struct PalAnm *palAnm;
    /* 0x03C */ void (*onKeyInput)(void *);
    /* 0x040 */ void (*onTouchInput)(void *);
    /* 0x044 */ struct BmpWin *win[7];
    /* 0x060 */ struct MailWinSlot slot[6];
    /* 0x090 */ u8 pad_90[8];
    /* 0x098 */ struct PrintQue *printQue;
    /* 0x09C */ void *printStream;
    /* 0x0A0 */ struct ClactUnit *clactUnit;
    /* 0x0A4 */ u8 pad_A4[0x50];
    /* 0x0F4 */ void *blinkTaskMem;
    /* 0x0F8 */ void *blinkTaskList;
    /* 0x0FC */ void *blinkTask;
    /* 0x100 */ struct Tcbl *tcbl;
    /* 0x104 */ void *vblankTask;
    /* 0x108 */ struct AppTaskMenuRes *taskMenuRes;
    /* 0x10C */ struct AppTaskMenu *dialogMenu;
    /* 0x110 */ struct MailMenuEntry dialogEntry[2];
    /* 0x128 */ struct AppTaskMenuWin *sendButton;
    /* 0x12C */ struct AppTaskMenuWin *cancelButton;
    /* 0x130 */ struct MailMenuEntry buttonEntry[2];
    /* 0x148 */ struct PmsDraw *pmsDraw;
    /* 0x14C */ struct PmsData closingWord;
    /* 0x154 */ struct ClactUnit *pmsClactUnit;
    /* 0x158 */ struct PrintQue *pmsPrintQue;
};


/* Caller's request of the mail box list (first two words; the caller owns the block). */
struct MailBoxArgs {
    /* 0x00 */ struct GameData *gameData;
    /* 0x04 */ u32 result;             /* 0 = left by the back button, 1 = left by the close button */
};

/* Process of the mail box list screen (0x34). */
struct MailBoxProc {
    /* 0x00 */ struct MailData *mailData;
    /* 0x04 */ struct MailBoxArgs *args;
    /* 0x08 */ struct MailBoxView *view;
    /* 0x0C */ u8 pad_0C[4];
    /* 0x10 */ void *childArgs;        /* argument block of the party list or mail screen run as child */
    /* 0x14 */ int childIndex;         /* which child screen: index of the child tables */
    /* 0x18 */ struct GfFont *font;
    /* 0x1C */ u16 page;
    /* 0x1E */ u8 selectedColumn;      /* cursor position on the page, 0..9 */
    /* 0x1F */ u8 selectedMail;        /* index of the mail in view->mails */
    /* 0x20 */ u8 partyResult;         /* exit code of the party list (6 = a Pokemon was chosen) */
    /* 0x21 */ u8 partyIndex : 7;      /* party slot chosen to take or return the mail */
    /* 0x21 */ u8 bagFull : 1;         /* the bag has no room for the item */
    /* 0x22 */ u16 itemId;             /* item of the selected mail */
    /* 0x24 */ int hasMail;            /* result of MAILTOOL_HasMail */
    /* 0x28 */ int nextState;
    /* 0x2C */ void *vblankTask;
    /* 0x30 */ void *procSys;
};

/* Blink of the selected mail or of a button (8 bytes). */
struct MailBoxFlash {
    /* 0x00 */ u8 isWindow : 1;        /* 1 = BG layer, 0 = actor */
    /* 0x00 */ u8 target : 7;          /* BG layer or actor index */
    /* 0x01 */ u8 paletteFirst : 4;
    /* 0x01 */ u8 paletteSecond : 4;
    /* 0x02 */ u8 state;
    /* 0x03 */ u8 count;
    /* 0x04 */ u8 x;
    /* 0x05 */ u8 y;
    /* 0x06 */ u8 w;
    /* 0x07 */ u8 h;
};

/* Screen resources of the mail box list (0x370). */
struct MailBoxView {
    /* 0x000 */ struct BgWinFrm *frames;
    /* 0x004 */ u8 blankTile[2][0x20];     /* tiles copied from the frame graphics, used as blit sources */
    /* 0x044 */ struct BmpWin *win[0x20];
    /* 0x0C4 */ struct MailWinSlot slot[0x20];
    /* 0x1C4 */ struct PrintQue *printQue;
    /* 0x1C8 */ struct PrintStream *printStream;
    /* 0x1CC */ struct Tcbl *tcbl;
    /* 0x1D0 */ struct MsgData *msgData;
    /* 0x1D4 */ struct WordSet *wordSet;
    /* 0x1D8 */ struct Strbuf *msgBuf;
    /* 0x1DC */ u8 pad_1DC;
    /* 0x1DD */ u8 waitForInput;           /* message finishes on a key or touch (1) or at once (0) */
    /* 0x1DE */ u8 pad_1DE[2];
    /* 0x1E0 */ int menuKind;              /* index of the menu handler table */
    /* 0x1E4 */ u8 pad_1E4[8];
    /* 0x1EC */ struct ClactUnit *clactUnit;
    /* 0x1F0 */ struct ClactActor *actor[8];
    /* 0x210 */ int charRes[8];
    /* 0x230 */ int paletteRes[8];
    /* 0x250 */ int cellRes[8];
    /* 0x270 */ u8 pad_270[0x20];
    /* 0x290 */ void *arcHandle;
    /* 0x294 */ struct TouchSelect *select;
    /* 0x298 */ struct Mail *mails[20];
    /* 0x2E8 */ u8 listIndex[20];          /* mail index shown at each list position (0xFF = empty) */
    /* 0x2FC */ u16 mailCount;
    /* 0x2FE */ u16 lastPage;
    /* 0x300 */ struct MailBoxFlash flash;
    /* 0x308 */ int fadeTarget;            /* state entered when the screen fade ends */
    /* 0x30C */ struct AppTaskMenuRes *taskMenuRes;
    /* 0x310 */ struct AppTaskMenu *taskMenu;
    /* 0x314 */ struct MailMenuEntry fourEntry[4];
    /* 0x344 */ struct MailMenuEntry twoEntry[2];
    /* 0x35C */ struct PmsDraw *pmsDraw;
    /* 0x360 */ struct PmsData closingWord;
    /* 0x368 */ struct ClactUnit *pmsClactUnit;
    /* 0x36C */ struct PrintQue *pmsPrintQue;
};

typedef char MailArgsSizeCheck[(sizeof(struct MailArgs) == 0x1C) ? 1 : -1];
typedef char MailDraftSizeCheck[(sizeof(struct MailDraft) == 0x34) ? 1 : -1];
typedef char MailToolProcSizeCheck[(sizeof(struct MailToolProc) == 0x20) ? 1 : -1];
typedef char MailEditProcSizeCheck[(sizeof(struct MailEditProc) == 0x15C) ? 1 : -1];
typedef char MailBoxProcSizeCheck[(sizeof(struct MailBoxProc) == 0x34) ? 1 : -1];
typedef char MailBoxFlashSizeCheck[(sizeof(struct MailBoxFlash) == 8) ? 1 : -1];
typedef char MailBoxViewSizeCheck[(sizeof(struct MailBoxView) == 0x370) ? 1 : -1];

/* Cross-file functions of the mail edit screen. */
struct MailDraft *MAILSYS_CreateMessage(struct Mail *mail, unsigned heap);
void MAILSYS_DeleteMessage(struct MailDraft *draft);
void MAILSYS_WriteMessageToMail(struct Mail *mail, struct MailDraft *draft);
void MAILSYS_ResetCursorBlend(struct MailEditProc *proc);
void MAILVIEW_HideAllPlanes(void);
void MAILVIEW_VBlankTask(void *task, struct MailEditProc *proc);
int MAILVIEW_SetupStep(struct MailEditProc *proc);
int MAILVIEW_Teardown(struct MailEditProc *proc);
void MAILVIEW_SetVramBanks(void);
void MAILVIEW_InitBgs(struct MailEditProc *proc);
void MAILVIEW_FreeBgs(struct MailEditProc *proc);
void MAILVIEW_LoadGraphics(struct MailEditProc *proc);
void MAILVIEW_FreeGraphics(struct MailEditProc *proc);
void MAILVIEW_CreateWindows(struct MailEditProc *proc);
void MAILVIEW_CreateButtons(struct MailEditProc *proc);
void MAILVIEW_DeleteWindows(struct MailEditProc *proc);
void MAILVIEW_PrintSentences(struct MailEditProc *proc);
void MAILVIEW_InitActorSystem(struct MailEditProc *proc);
void MAILVIEW_ExitActorSystem(struct MailEditProc *proc);
void MAILVIEW_CreatePmsDraw(struct MailEditProc *proc);

#endif
