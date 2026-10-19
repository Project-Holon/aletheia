/*
 * function: WORLDTRADE_SEARCH_Init
 * address:  0x021FD924
 * packet:   pkt_021FD924
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_SEARCH_CreateStrings  0x021FE118  thumb
 *   WORLDTRADE_SEARCH_SetupBgPlanes  0x021FDBCC  thumb
 *   WORLDTRADE_SEARCH_LoadBgGraphics  0x021FDD00  thumb
 *   WORLDTRADE_SEARCH_CreateWindows  0x021FDF2C  thumb
 *   WORLDTRADE_SEARCH_CreateActors  0x021FDDA8  thumb
 *   WORLDTRADE_TITLE_ScrollBg  0x021FFFE8  thumb
 *   WORLDTRADE_TITLE_LoadSubBgSwap  0x02200B34  thumb
 *   WORLDTRADE_TITLE_CreateMenuWindow  0x02200BAC  thumb
 *   WORLDTRADE_INPUT_MenuCreate  0x021F9890  thumb
 *   WORLDTRADE_SEARCH_DrawFormLabels  0x021FF384  thumb
 *   WORLDTRADE_SEARCH_DrawHistoryHeader  0x021FF474  thumb
 *   WORLDTRADE_DEPOSIT_PrintName  0x021F7F9C  thumb
 *   WORLDTRADE_DEPOSIT_PrintModeLabelAligned  0x021F8098  thumb
 *   WORLDTRADE_DEPOSIT_FindLevelBracketIndex  0x021F886C  thumb
 *   WORLDTRADE_DEPOSIT_PrintLevelRange  0x021F8154  thumb
 *   WORLDTRADE_DEPOSIT_PrintMessageLine  0x021F8010  thumb
 *   WORLDTRADE_SEARCH_ScrollBgs  0x021FF50C  thumb
 *   WIPE_SYS_Start  0x0202208C  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 name;
    s8 mode;
    s8 key;
    s8 val;
} Rec;

typedef struct {
    void *w00;
    void *w04;
    void *obj;
    void *w0c;
    void *w10;
    void *w14;
    void *bank;
    void *names;
    void *w20;
    u32 w24;
    u32 w28;
    u32 arg;
} Init;

typedef struct {
    u8 pad0[0x10];
    u32 f10;
} Ctx;

typedef struct {
    u8 pad0[0x14];
    u32 f14;
} Aux;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x20 - 4];
    int kind;
    u8 pad24[4];
    u32 f28;
    u8 pad2C[0xB56 - 0x2C];
    Rec rec;
    u8 padB5C[0xB6C - 0xB5C];
    void *bank;
    void *names;
    u8 padB74[0xB7C - 0xB74];
    void *msg;
    u8 padB80[0xBF4 - 0xB80];
    void *cursor;
    void *mark;
    u8 padBFC[0xD2C - 0xBFC];
    void *btn[2];
    u8 padD34[0xD50 - 0xD34];
    u8 fD50[0xD90 - 0xD50];
    void *win[4];
    u8 padDA0[4];
    void *wDA4;
    u8 padDA8[0xDB0 - 0xDA8];
    void *wDB0;
    u8 padDB4[0xDD4 - 0xDB4];
    u8 fDD4[4];
    void *win2[2];
    u8 padDE0[4];
    void *menu;
    u8 padDE8[0xE00 - 0xDE8];
    Aux *aux;
    u8 padE04[0xE1A - 0xE04];
    u16 fE1A;
    u8 padE1C[0xEC0 - 0xE1C];
    void (*vblank)(void *);
    u8 padEC4[0xF84 - 0xEC4];
    u32 fF84;
    u8 padF88[0xFA0 - 0xF88];
    u8 fFA0[4];
    u8 padFA4[0x12E4 - 0xFA4];
    u32 f12E4;
} Work;

extern void WORLDTRADE_SEARCH_CreateStrings(u8 *p);
extern void WORLDTRADE_SEARCH_SetupBgPlanes(void);
extern void WORLDTRADE_SEARCH_LoadBgGraphics(void *p);
extern void WORLDTRADE_SEARCH_CreateWindows(Work *p);
extern void WORLDTRADE_SEARCH_CreateActors(Work *p);
extern void WORLDTRADE_TITLE_ScrollBg(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_TITLE_LoadSubBgSwap(u8 *p);
extern void WORLDTRADE_TITLE_CreateMenuWindow(u8 *p, u32 k);
extern void *WORLDTRADE_INPUT_MenuCreate(Init *init, u32 a, u32 b);
extern void WORLDTRADE_SEARCH_DrawFormLabels(void **win, void **win2, void *bank, void *g);
extern void WORLDTRADE_SEARCH_DrawHistoryHeader(void *win, void *bank, int flag, void *g);
extern void WORLDTRADE_DEPOSIT_PrintName(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);
extern void WORLDTRADE_DEPOSIT_PrintModeLabelAligned(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);
extern int WORLDTRADE_DEPOSIT_FindLevelBracketIndex(int key, int val, int which);
extern void WORLDTRADE_DEPOSIT_PrintLevelRange(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g);
extern void WORLDTRADE_DEPOSIT_PrintMessageLine(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g);
extern void WORLDTRADE_SEARCH_ScrollBgs(void *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

int WORLDTRADE_SEARCH_Init(Work *p)
{
    Init init;

    WORLDTRADE_SEARCH_CreateStrings((u8 *)p);
    WORLDTRADE_SEARCH_SetupBgPlanes();
    WORLDTRADE_SEARCH_LoadBgGraphics(p);
    WORLDTRADE_SEARCH_CreateWindows(p);
    WORLDTRADE_SEARCH_CreateActors(p);
    WORLDTRADE_TITLE_ScrollBg((u8 *)p, 0, 0);
    WORLDTRADE_TITLE_LoadSubBgSwap((u8 *)p);
    WORLDTRADE_TITLE_CreateMenuWindow((u8 *)p, 4);
    p->f12E4 = 0;
    init.w00 = p->fD50;
    init.w04 = p->fDD4;
    init.obj = p->mark;
    init.w0c = p->btn[0];
    init.w10 = p->btn[1];
    init.w14 = p->cursor;
    init.bank = p->bank;
    init.names = p->names;
    init.w20 = p->msg;
    init.w24 = p->ctx->f10;
    init.w28 = p->aux->f14;
    p->menu = WORLDTRADE_INPUT_MenuCreate(&init, 2, 1);
    WORLDTRADE_SEARCH_DrawFormLabels(p->win, p->win2, p->bank, p->fFA0);
    WORLDTRADE_SEARCH_DrawHistoryHeader(p->wDB0, p->bank, p->fE1A, p->fFA0);
    WORLDTRADE_DEPOSIT_PrintName(p->win[1], p->names, p->rec.name, 0, 0, 0x3C40, p->fFA0);
    WORLDTRADE_DEPOSIT_PrintModeLabelAligned(p->win[3], p->bank, p->rec.mode, 1, 0, 0, 0x3C40, p->fFA0);
    WORLDTRADE_DEPOSIT_PrintLevelRange(p->wDA4, p->bank, WORLDTRADE_DEPOSIT_FindLevelBracketIndex(p->rec.key, p->rec.val, 1), 0, 0, 0x3C40, 1, p->fFA0);
    WORLDTRADE_DEPOSIT_PrintMessageLine(p->win2[1], p->msg, p->bank, p->fF84, 0, 0, 0x3C40, p->fFA0);
    p->vblank = WORLDTRADE_SEARCH_ScrollBgs;
    if (p->kind == 0xd) {
        WIPE_SYS_Start((void *)3, 1, 1, 0, 6, 1, 0x48);
    }
    p->f28 = 0;
    return 1;
}
