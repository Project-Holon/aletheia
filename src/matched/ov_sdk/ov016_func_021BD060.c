/*
 * function: DWCi_COMMENTlDispEx
 * address:  0x021BD060
 * packet:   pkt_ov016_021BD060
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_COMMENTlDispEx (libdwcutil.TWL.HYB.a comment.o)
 *
 * symbols:
 *   DWCi_CMNlLoadResource 0x021BD1D4  arm
 *   DWCi_FNTlFormBgEx     0x021D5A58  arm
 *   DWCi_MSGlGetEx        0x021C1048  arm
 *   DWCi_CMNlFontFlag     0x021BD3CC  arm
 *   DWCi_FNTlDrawRect     0x021D5E5C  arm
 *   DWCi_FNTlRenewBg      0x021D5FC4  arm
 *   Flag                  0x021DE50C  data  a1
 *   sCommentPathJtNullScr            0x021DAC20  data  a1
 *   GXS_LoadBG0Scr        0x0207E944  arm
 *   gCommentWork            0x021DE598  data  a4
 */

void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
void *DWCi_FNTlFormBgEx(int lcd, int font);
unsigned short *DWCi_MSGlGetEx(void *msg, int id, int n, int num);
unsigned long DWCi_CMNlFontFlag(void);
void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, unsigned long flag, unsigned short *txt);
void DWCi_FNTlRenewBg(void *canvas);
void GXS_LoadBG0Scr(void);
extern unsigned char Flag;
extern char sCommentPathJtNullScr[];
extern void *gCommentWork;

int DWCi_COMMENTlDispEx(int messageId, int n, int num)
{
    unsigned short *msg;
    void *canvas;

    if (Flag != 0) return 0;
    DWCi_CMNlLoadResource(sCommentPathJtNullScr, (void (*)(void *, unsigned long, unsigned long))GXS_LoadBG0Scr);
    *(volatile unsigned int *)0x04001010 = 0x01920000;
    canvas = DWCi_FNTlFormBgEx(1, 0);
    msg = DWCi_MSGlGetEx(gCommentWork, messageId, n, num);
    DWCi_FNTlDrawRect(canvas, 0x14, 0, 0xd8, 0x40, 2, DWCi_CMNlFontFlag(), msg);
    DWCi_FNTlRenewBg(canvas);
    Flag = 1;
    return 1;
}
