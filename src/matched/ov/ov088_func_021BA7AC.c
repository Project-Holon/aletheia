/*
 * function: STARTMENU_StateInfoMessage
 * address:  0x021BA7AC
 * packet:   pkt_ov088_021BA7AC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_ENV_IsRunOnTwl  0x0202EB0C  thumb
 *   STARTMENU_OpenNoticeWindow  0x021BBE48  thumb  ov088
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   STARTMENU_CloseDescWindow  0x021BBD10  thumb  ov088
 *   STARTMENU_RowTileY  0x021BB840  thumb  ov088
 *   STARTMENU_PaintRowPalette  0x021BB810  thumb  ov088
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 */
#include "../include/Obj00263.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
struct PrintSys;
extern u32 APP_ENV_IsRunOnTwl(void);
extern void STARTMENU_OpenNoticeWindow(char *p);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void STARTMENU_CloseDescWindow(char *p, int mode);
extern int STARTMENU_RowTileY(char *p, int y);
extern void STARTMENU_PaintRowPalette(void *p, u8 row, int y, int pal);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

int STARTMENU_StateInfoMessage(char *p)
{
    void *t;
    if (APP_ENV_IsRunOnTwl() == 1) {
        switch (((struct Obj00263 *)p)->f12A) {
        case 0:
            STARTMENU_OpenNoticeWindow(p);
            ((struct Obj00263 *)p)->f12A = ((struct Obj00263 *)p)->f12A + 1;
            break;
        case 1:
            if (PRINTSYS_QUE_IsFinished(((struct Obj00263 *)p)->f68) == 1)
                ((struct Obj00263 *)p)->f12A = ((struct Obj00263 *)p)->f12A + 1;
            break;
        case 2:
            if (KEY_GetTrg() & 3) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                STARTMENU_CloseDescWindow(p, 0);
                STARTMENU_PaintRowPalette(p, *(u8 *)(p + ((struct Obj00263 *)p)->f128 + 0x120),
                              STARTMENU_RowTileY(p, ((struct Obj00263 *)p)->f12F), 2);
                ((struct Obj00263 *)p)->f12A = 0;
                return 5;
            }
            break;
        }
        PRINTSYS_QUE_Main(((struct Obj00263 *)p)->f68);
        t = ((struct Obj00263 *)p)->f68;
        if (((struct Obj00263 *)p)->fF4 != 0 && PRINTSYS_QUE_IsExistTarget(t, BMP_WIN_GetBmp(((struct Obj00263 *)p)->fF0)) == 0) {
            BMP_WIN_TransferChars(((struct Obj00263 *)p)->fF0);
            ((struct Obj00263 *)p)->fF4 = 0;
        }
        return 9;
    }
    ((struct Obj00263 *)p)->f129 = *(u8 *)(p + ((struct Obj00263 *)p)->f128 + 0x120);
    return 11;
}
