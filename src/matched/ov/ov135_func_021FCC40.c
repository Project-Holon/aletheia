/*
 * function: WORLDTRADE_LIST_Init
 * address:  0x021FCC40
 * packet:   pkt_021FCC40
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_LIST_CreateStrings  0x021FD270  thumb
 *   WORLDTRADE_LIST_SetupBgPlanes  0x021FCF28  thumb
 *   GXx_GetMasterBrightness_  0x0207D55C  arm
 *   WORLDTRADE_TITLE_ScrollBg  0x021FFFE8  thumb
 *   WORLDTRADE_LIST_LoadBgGraphics  0x021FCFD8  thumb
 *   WORLDTRADE_LIST_CreateWindows  0x021FD104  thumb
 *   WORLDTRADE_LIST_CreateActors  0x021FD08C  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   WORLDTRADE_DETAIL_PrintMonInfo  0x021FC8CC  thumb
 *   WORLDTRADE_DETAIL_PrintMonName  0x021FCA8C  thumb
 *   WORLDTRADE_DETAIL_LoadMonGraphics  0x021FCB54  thumb
 *   WORLDTRADE_LIST_PrintLabel  0x021FD760  thumb
 *   WORLDTRADE_LIST_PrintHeader  0x021FD790  thumb
 *   WORLDTRADE_LIST_DrawSelectedRecord  0x021FD5F0  thumb
 *   WORLDTRADE_SUBLCD_MoveArrowToSlot  0x021FFD1C  thumb
 *   WORLDTRADE_LIST_VBlank  0x021FD8BC  thumb
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef volatile unsigned short vu16;

typedef struct {
    u8 pad0[0xEC];
    u8 rec[0x110 - 0xEC];
    u8 name[0x128 - 0x110];
} Entry;

typedef struct {
    u8 pad0[0x20];
    int kind;
    u8 pad24[4];
    u32 f28;
    u8 pad2C[0xD4 - 0x2C];
    int cur;
    u8 padD8[0x20C - 0xD8];
    Entry arr[8];
    u8 padB4C[0xB68 - 0xB4C];
    void *words;
    void *bank;
    void *names;
    u8 padB74[0xD3C - 0xB74];
    int scroll;
    u8 padD40[0xD50 - 0xD40];
    void *side[2];
    u8 padD58[0xD90 - 0xD58];
    void *win[7];
    void *pane2[2];
    void *title;
    u8 padDB8[0xDC0 - 0xDB8];
    void *pane3[2];
    void *hint;
    u8 padDCC[0xEC0 - 0xDCC];
    void (*vblank)(void *);
    u8 padEC4[0xFA0 - 0xEC4];
    u8 fFA0[4];
    u8 padFA4[0x12E4 - 0xFA4];
    u32 f12E4;
    u8 pad12E8[0x12FC - 0x12E8];
    u32 flag;
} Work;

extern void WORLDTRADE_LIST_CreateStrings(Work *p);
extern void WORLDTRADE_LIST_SetupBgPlanes(int y);
extern int GXx_GetMasterBrightness_(vu16 *reg);
extern void WORLDTRADE_TITLE_ScrollBg(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_LIST_LoadBgGraphics(u8 *p);
extern void WORLDTRADE_LIST_CreateWindows(Work *p);
extern void WORLDTRADE_LIST_CreateActors(Work *p);
extern void *POKE_TOOL_GetBoxParam(void *mon);
extern void WORLDTRADE_DETAIL_PrintMonInfo(void *bank, void *names, void *words, void **win, void *mon, void *rec, void *g);
extern void WORLDTRADE_DETAIL_PrintMonName(void *bank, void *pane, void *name, void *mon, void *pane2, void *g);
extern void WORLDTRADE_DETAIL_LoadMonGraphics(void *mon);
extern void WORLDTRADE_LIST_PrintLabel(void *bank, void *pane, u32 index, void *g, u16 color);
extern void WORLDTRADE_LIST_PrintHeader(void *bank, void *pane, u32 index, void *g);
extern void WORLDTRADE_LIST_DrawSelectedRecord(Work *p);
extern void WORLDTRADE_SUBLCD_MoveArrowToSlot(Work *p, int i, int dy);
extern void WORLDTRADE_LIST_VBlank(void *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

int WORLDTRADE_LIST_Init(Work *p)
{
    WORLDTRADE_LIST_CreateStrings(p);
    WORLDTRADE_LIST_SetupBgPlanes(-32 - p->scroll);
    if (GXx_GetMasterBrightness_((vu16 *)0x0400106C) == 0) {
        WORLDTRADE_TITLE_ScrollBg((u8 *)p, -32 - p->scroll, 1);
    } else {
        WORLDTRADE_TITLE_ScrollBg((u8 *)p, -32 - p->scroll, 0);
    }
    WORLDTRADE_LIST_LoadBgGraphics((u8 *)p);
    WORLDTRADE_LIST_CreateWindows(p);
    WORLDTRADE_LIST_CreateActors(p);
    WORLDTRADE_DETAIL_PrintMonInfo(p->bank, p->names, p->words, p->win, POKE_TOOL_GetBoxParam(&p->arr[p->cur]), p->arr[p->cur].rec, p->fFA0);
    WORLDTRADE_DETAIL_PrintMonName(p->bank, &p->win[7], p->arr[p->cur].name, &p->arr[p->cur], p->pane3, p->fFA0);
    WORLDTRADE_DETAIL_LoadMonGraphics(&p->arr[p->cur]);
    WORLDTRADE_LIST_PrintLabel(p->bank, &p->pane3[2], 0x53, p->fFA0, 0x440);
    WORLDTRADE_LIST_PrintLabel(p->bank, &p->title, 0x57, p->fFA0, 0x3C40);
    if (p->flag == 0) {
        WORLDTRADE_LIST_PrintHeader(p->bank, &p->side[0], 0x5E, p->fFA0);
        WORLDTRADE_LIST_PrintHeader(p->bank, &p->side[1], 0x73, p->fFA0);
    }
    WORLDTRADE_LIST_DrawSelectedRecord(p);
    WORLDTRADE_SUBLCD_MoveArrowToSlot(p, p->cur, -p->scroll);
    p->vblank = WORLDTRADE_LIST_VBlank;
    *(vu16 *)0x04000304 |= 0x8000;
    GFL_NET_RestartWithDefaultTimeout(1, 0x48);
    if (p->kind == 0x11) {
        if (GXx_GetMasterBrightness_((vu16 *)0x0400006C) == -16 && GXx_GetMasterBrightness_((vu16 *)0x0400106C) != -16) {
            WIPE_SYS_Start((void *)3, 1, 1, 0, 6, 1, 0x48);
        } else if (GXx_GetMasterBrightness_((vu16 *)0x0400006C) != -16 && GXx_GetMasterBrightness_((vu16 *)0x0400106C) == -16) {
            WIPE_SYS_Start((void *)4, 1, 1, 0, 6, 1, 0x48);
        } else {
            WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x48);
        }
    }
    p->f28 = 0;
    p->f12E4 = 0;
    p->flag = 0;
    return 1;
}
