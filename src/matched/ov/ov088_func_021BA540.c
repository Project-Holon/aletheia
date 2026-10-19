/*
 * function: STARTMENU_StateConnectPrompt
 * address:  0x021BA540
 * packet:   pkt_ov088_021BA540
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The two 0/-2 result tests are small switches: their compare chain puts
 * both bodies after a shared `b` to the tail, which the outer switch's
 * out-of-range `bhi` reuses. The countdown is `-= 1` (re-reads the byte).
 *
 * symbols:
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   STARTMENU_ShowRowActors  0x021BB9DC  thumb  ov088
 *   func_020090E0  0x020090E0  thumb
 *   STARTMENU_BeginFadeIn  0x021BC080  thumb  ov088
 *   STARTMENU_StartMessage  0x021BBF1C  thumb  ov088
 *   STARTMENU_OpenInfoWindow  0x021BBD80  thumb  ov088
 *   STARTMENU_UpdateMessage  0x021BBFA8  thumb  ov088
 *   BMP_MENU_ProcessYesNo  0x0201FEBC  thumb
 *   APP_ENV_IsWirelessAvailable  0x0202EB44  thumb
 *   STARTMENU_CloseInfoWindow  0x021BBE3C  thumb  ov088
 *   STARTMENU_HideMessageWindow  0x021BBF98  thumb  ov088
 *   KEY_GetTrg  0x020362DC  arm
 *   STARTMENU_OpenYesNoMenu  0x021BC024  thumb  ov088
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 */
#include "../include/Obj00339.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
struct PrintSys;
struct Sub020090B0Obj;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void STARTMENU_ShowRowActors(char *, int);
extern u8 func_020090E0(const struct Sub020090B0Obj *obj);
extern int STARTMENU_BeginFadeIn(char *p, int v);
extern void STARTMENU_StartMessage(char *p, u32 a1);
extern void STARTMENU_OpenInfoWindow(char *p);
extern int STARTMENU_UpdateMessage(char *p);
extern u32 BMP_MENU_ProcessYesNo(u8 *);
extern int APP_ENV_IsWirelessAvailable(void);
extern void STARTMENU_CloseInfoWindow(char *p);
extern void STARTMENU_HideMessageWindow(char *p);
extern u32 KEY_GetTrg(void);
extern void STARTMENU_OpenYesNoMenu(char *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

int STARTMENU_StateConnectPrompt(char *p)
{
    void *t;
    u32 r;
    switch (((struct Obj00339 *)p)->f12A) {
    case 0:
        BG_SYS_SetMainPlaneVisible(6, 0);
        STARTMENU_ShowRowActors(p, 0);
        if (func_020090E0(((struct Obj00339 *)p)->fC) == 0) {
            ((struct Obj00339 *)p)->f12C = 1;
            ((struct Obj00339 *)p)->f12A = 0;
            return STARTMENU_BeginFadeIn(p, 1);
        }
        ((struct Obj00339 *)p)->f12B = 8;
        ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        break;
    case 1:
        if (((struct Obj00339 *)p)->f12B != 0) {
            ((struct Obj00339 *)p)->f12B -= 1;
            break;
        }
        STARTMENU_StartMessage(p, 0x1a);
        STARTMENU_OpenInfoWindow(p);
        ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        break;
    case 2:
        if (STARTMENU_UpdateMessage(p) == 0) {
            STARTMENU_OpenYesNoMenu(p);
            ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        }
        break;
    case 3:
        r = BMP_MENU_ProcessYesNo(*(u8 * *)&((struct Obj00339 *)p)->f7C);
        switch (r) {
        case 0:
            if (APP_ENV_IsWirelessAvailable() == 0) {
                STARTMENU_StartMessage(p, 0x11);
                ((struct Obj00339 *)p)->f12A = 5;
            } else {
                ((struct Obj00339 *)p)->f12C = 0;
                ((struct Obj00339 *)p)->f12A = 4;
            }
            break;
        case (u32)-2:
            STARTMENU_StartMessage(p, 0x1b);
            ((struct Obj00339 *)p)->f12A = 7;
            break;
        }
        break;
    case 4:
        STARTMENU_CloseInfoWindow(p);
        STARTMENU_HideMessageWindow(p);
        ((struct Obj00339 *)p)->f12A = 0;
        return STARTMENU_BeginFadeIn(p, 1);
    case 5:
        if (STARTMENU_UpdateMessage(p) == 0)
            ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        break;
    case 6:
        if (KEY_GetTrg() & 3) {
            ((struct Obj00339 *)p)->f12C = 1;
            ((struct Obj00339 *)p)->f12A = 4;
        }
        break;
    case 7:
        if (STARTMENU_UpdateMessage(p) == 0) {
            STARTMENU_OpenYesNoMenu(p);
            ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        }
        break;
    case 8:
        r = BMP_MENU_ProcessYesNo(*(u8 * *)&((struct Obj00339 *)p)->f7C);
        switch (r) {
        case 0:
            ((struct Obj00339 *)p)->f12C = 1;
            ((struct Obj00339 *)p)->f12A = 4;
            break;
        case (u32)-2:
            STARTMENU_StartMessage(p, 0x1a);
            ((struct Obj00339 *)p)->f12A = 2;
            break;
        }
        break;
    }
    PRINTSYS_QUE_Main(((struct Obj00339 *)p)->f68);
    t = ((struct Obj00339 *)p)->f68;
    if (((struct Obj00339 *)p)->fF4 != 0 && PRINTSYS_QUE_IsExistTarget(t, BMP_WIN_GetBmp(((struct Obj00339 *)p)->fF0)) == 0) {
        BMP_WIN_TransferChars(((struct Obj00339 *)p)->fF0);
        ((struct Obj00339 *)p)->fF4 = 0;
    }
    return 7;
}
