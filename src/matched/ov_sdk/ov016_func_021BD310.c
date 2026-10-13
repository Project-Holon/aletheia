/*
 * function: DWCi_CMNlMsgNameDraw
 * address:  0x021BD310
 * packet:   pkt_ov016_021BD310
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CMNlMsgNameDraw (libdwcutil.TWL.HYB.a(common.o))
 *
 * symbols:
 *   DWCi_FNTlFormBgEx  0x021d5a58  arm  ov016
 *   DWCi_MSGlGet  0x021c1030  arm  ov016
 *   DWCi_CMNlFontFlag  0x021bd3cc  arm  ov016
 *   DWCi_FNTlDrawRect  0x021d5e5c  arm  ov016
 *   func_021C0EC8  0x021c0ec8  arm  ov016
 *   DWCi_FNTlDraw  0x021d5ccc  arm  ov016
 *   DWCi_FNTlRenewBg  0x021d5fc4  arm  ov016
 *   gCommentWork  0x021de598  data
 *   sCommonNamePosYByLanguage  0x021da06a  data
 *   sCommonNamePosByLanguage  0x021da068  data
 */

typedef struct tagCOORD { unsigned short x, y; } COORD;

extern int gCommentWork;
extern const COORD sCommonNamePosByLanguage[7];
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern unsigned int DWCi_MSGlGet(unsigned int *p, unsigned int idx);
extern int DWCi_CMNlFontFlag(void);
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, unsigned long flag, unsigned short *txt);
extern unsigned char func_021C0EC8(void);
extern void DWCi_FNTlDraw(void *canvas, int x, int y, int color, unsigned long flag, unsigned short *txt);
extern void DWCi_FNTlRenewBg(int x);

void DWCi_CMNlMsgNameDraw(unsigned short *name, int msgId)
{
    unsigned short *msg;
    void *canvas;

    canvas = DWCi_FNTlFormBgEx(0, 0);
    msg = (short unsigned int *)DWCi_MSGlGet((void *)gCommentWork, msgId);
    DWCi_FNTlDrawRect(canvas, 13, 60, 230, 94, 2, DWCi_CMNlFontFlag(), msg);
    DWCi_FNTlDraw(canvas, sCommonNamePosByLanguage[func_021C0EC8()].x, sCommonNamePosByLanguage[func_021C0EC8()].y, 2, 13 + 508, name);
    DWCi_FNTlRenewBg((int)canvas);
}
