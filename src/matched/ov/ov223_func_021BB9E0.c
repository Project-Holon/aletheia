/*
 * function: PSEL_GRAPHIC_Init
 * address: 0x021BB9E0
 * packet: pkt_ov223_021BB9E0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PSEL_GRAPHIC_Create 0x021BC3F0 thumb ov223
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   func_020056A0 0x020056A0 thumb
 *   PSEL_Task 0x021B9740 thumb ov223
 *   PSEL_CreateG3dUtil 0x021B9830 thumb ov223
 *   PSEL_CreateBmpWindows 0x021BAAB8 thumb ov223
 *   PSEL_CreateWin 0x021BAE00 thumb ov223
 *   PSEL_CreateTaskRes 0x021BB38C thumb ov223
 * 0201C440's pointer parameter is used as the full-width heap id here;
 * the original forwards its ldrh result unchanged to the wrapper.
 */
#include "../include/Obj00739.h"
typedef unsigned short u16;
struct GfFont;
extern void *PSEL_GRAPHIC_Create(int, int);
extern struct GfFont *GF_FONT_Create(int, int, int, int, unsigned);
extern unsigned PRINTSYS_QUE_Create(void *);
extern void BG_SYS_SetVisibleLayer(int, u16);
extern void *func_020056A0(void (*)(void *, char *), void *, int);
extern void PSEL_Task(void *, char *);
extern void PSEL_CreateG3dUtil(char *);
extern void PSEL_CreateBmpWindows(u16 *p);
extern void PSEL_CreateWin(char *p);
extern void PSEL_CreateTaskRes(char *p);
int PSEL_GRAPHIC_Init(char *p)
{
    ((struct Obj00739 *)p)->f14 = PSEL_GRAPHIC_Create(1, ((struct Obj00739 *)p)->f0);
    *(struct GfFont * *)&((struct Obj00739 *)p)->f18 = GF_FONT_Create(23, 0, 0, 0, ((struct Obj00739 *)p)->f0);
    ((struct Obj00739 *)p)->f1C = PRINTSYS_QUE_Create((void *)(unsigned)((struct Obj00739 *)p)->f0);
    BG_SYS_SetVisibleLayer(0, 2);
    BG_SYS_SetVisibleLayer(1, 3);
    BG_SYS_SetVisibleLayer(2, 1);
    BG_SYS_SetVisibleLayer(3, 0);
    BG_SYS_SetVisibleLayer(4, 3);
    BG_SYS_SetVisibleLayer(5, 2);
    BG_SYS_SetVisibleLayer(6, 1);
    BG_SYS_SetVisibleLayer(7, 0);
    ((struct Obj00739 *)p)->f20 = func_020056A0(PSEL_Task, p, 1);
    ((struct Obj00739 *)p)->f24 = 0;
    PSEL_CreateG3dUtil(p);
    PSEL_CreateBmpWindows((u16 *)p);
    PSEL_CreateWin(p);
    PSEL_CreateTaskRes(p);
    return 2;
}
