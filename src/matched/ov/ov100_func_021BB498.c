/*
 * function: IRCBATTLEMATCH_ProcMain
 * address:  0x021BB498
 * packet:   pkt_ov100_021BB498
 * region:   ov100
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GX_LoadBGPltt(void *, int, int);
extern void APP_TASKMENU_UpdateMenu(u8 *);
extern void APP_TASKMENU_WIN_Update(u8 *);
extern void BG_SYS_ChangeScrollImmediate(u32, u32, u32);
extern void CLACT_DrawSystem(void);
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 func_0200FB24(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern void WIPE_SetBrightnessFadeOut(u32, u32);
u32 IRCBATTLEMATCH_ProcMain(u32 a, u32 b, u32 c, u8 *p)
{
    void (*cb)(u8 *) = *(void (**)(u8 *))(p + 0x248);
    u32 ret = 1;
    u32 flag;
    if ((*(volatile u32 *)0x02FFFC3C & 7) == 1) {
        GX_LoadBGPltt(p + *(u16 *)(p + 0x240) * 32, 0, 0x20);
        *(u16 *)(p + 0x240) = *(u16 *)(p + 0x240) + 1;
        if (*(u16 *)(p + 0x240) == 9) {
            flag = ret;
            goto L;
        }
        if (*(u16 *)(p + 0x240) >= 0x12) *(u16 *)(p + 0x240) = 0;
    }
    flag = 0;
L:
    *(u32 *)(p + 0xCEC) = flag;
    if (cb) {
        cb(p);
        if (*(u32 *)(p + 0x248)) ret = 0;
    }
    if (*(u32 *)(p + 0xCC0)) APP_TASKMENU_UpdateMenu(*(u8 **)(p + 0xCC0));
    if (*(u32 *)(p + 0xCE0)) APP_TASKMENU_WIN_Update(*(u8 **)(p + 0xCE0));
    if (*(u32 *)(p + 0xCE4)) APP_TASKMENU_WIN_Update(*(u8 **)(p + 0xCE4));
    BG_SYS_ChangeScrollImmediate(4, 3, *(u32 *)(p + 0xC9C));
    *(u32 *)(p + 0xC9C) = *(u32 *)(p + 0xC9C) - 1;
    CLACT_DrawSystem();
    PRINTSYS_QUE_Main((struct PrintSys *)(*(u8 **)(p + 0xCB8)));
    if (func_0200FB24()) {
        GFL_NET_ERR_RequestScreen();
        *(u32 *)(*(u8 **)(p + 0x244) + 0x1C) = 12;
        ret = 1;
        WIPE_SetBrightnessFadeOut(0, 0);
        WIPE_SetBrightnessFadeOut(1, 0);
    }
    return ret;
}
