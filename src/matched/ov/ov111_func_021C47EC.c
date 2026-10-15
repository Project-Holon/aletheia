/*
 * function: VIEWER_MAIN_Draw
 * address:  0x021C47EC
 * packet:   pkt_ov111_021C47EC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_MAIN_ResetBgSlot  0x021C479C  thumb  ov111
 *   VIEWER_TEXT_Draw  0x021C60CC  thumb  ov111
 *   PMS_DRAW_Main  0x0202DBC4  thumb
 *   VIEWER_TEXT_DrawPage  0x021C6874  thumb  ov111
 *   VIEWER_MAIN_UploadBg  0x021C58E0  thumb  ov111
 *   VIEWER_TEXT_DrawWindow  0x021C636C  thumb  ov111
 *   VIEWER_MAIN_UploadBgBuf  0x021C5ACC  thumb  ov111
 *   VIEWER_MAIN_UpdateRows  0x021C4B74  thumb  ov111
 *   VIEWER_TEXT_FlushWindow  0x021C631C  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct Info Info;

typedef struct {
    u8 pad0[4];
    void *bg[7];
    u8 pad20[8];
    Info *info;
    u8 pix[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x32B0 - 0x3038];
    void *f32B0;
    u8 pad32B4[0x32C8 - 0x32B4];
    u8 phase;
    u8 pad32C9[0x32E2 - 0x32C9];
    s16 scroll;
} Work;

extern void VIEWER_MAIN_ResetBgSlot(Work *p);
extern void VIEWER_TEXT_Draw(Work *p, void **bg, Info *info);
extern void PMS_DRAW_Main(u8 *p);
extern void VIEWER_TEXT_DrawPage(Work *p, int scroll, int flush, int idx);
extern void VIEWER_MAIN_UploadBg(Work *p);
extern void VIEWER_TEXT_DrawWindow(Work *p, void **bg, Info *info);
extern void VIEWER_MAIN_UploadBgBuf(u32 bg, const void *src, int mode);
extern void VIEWER_MAIN_UpdateRows(Work *p, int flag);
extern void VIEWER_TEXT_FlushWindow(Work *p, void **bg);

void VIEWER_MAIN_Draw(Work *p)
{
    VIEWER_MAIN_ResetBgSlot(p);
    VIEWER_TEXT_Draw(p, p->bg, p->info);
    PMS_DRAW_Main(p->f32B0);
    if (p->f3034 == 0) {
        VIEWER_TEXT_DrawPage(p, p->scroll, 0, 0);
        VIEWER_MAIN_UploadBg(p);
    } else {
        VIEWER_TEXT_DrawWindow(p, p->bg, p->info);
        VIEWER_MAIN_UploadBgBuf(7, p->pix, p->phase);
    }
    VIEWER_MAIN_UpdateRows(p, p->f3034);
    VIEWER_TEXT_FlushWindow(p, p->bg);
}
