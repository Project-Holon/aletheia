/*
 * file:     comment.c
 * unit:     yes
 * function: func_021BD04C, func_021BD060, func_021BD138
 * address:  0x021BD04C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_CMNlLoadResource 0x021BD1D4  arm
 *   DWCi_FNTlFormBgEx     0x021D5A58  arm
 *   DWCi_MSGlGetEx        0x021C1048  arm
 *   DWCi_CMNlFontFlag     0x021BD3CC  arm
 *   DWCi_FNTlDrawRect     0x021D5E5C  arm
 *   DWCi_FNTlRenewBg      0x021D5FC4  arm
 *   Flag                  0x021DE50C  data  a1
 *   g_021DAC20            0x021DAC20  data  a1
 *   GXS_LoadBG0Scr        0x0207E944  arm
 *   g_021DE598            0x021DE598  data  a4
 *   DWCi_FNTlDeleteBgLcd 0x021D5CA8  arm
 */
void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
void *DWCi_FNTlFormBgEx(int lcd, int font);
unsigned short *DWCi_MSGlGetEx(void *msg, int id, int n, int num);
unsigned long DWCi_CMNlFontFlag(void);
void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, unsigned long flag, unsigned short *txt);
void DWCi_FNTlRenewBg(void *canvas);
void GXS_LoadBG0Scr(void);
void DWCi_FNTlDeleteBgLcd(int lcd);
void func_021BD04C(void);
int DWCi_COMMENTlDispEx(int messageId, int n, int num);
int DWCi_COMMENTlDelete(void);
extern unsigned char Flag;
extern char g_021DAC20[];
extern void *g_021DE598;

void func_021BD04C(void)
{
    *(unsigned char *)0x021DE50C = 0;
}


int DWCi_COMMENTlDispEx(int messageId, int n, int num)
{
    unsigned short *msg;
    void *canvas;

    if (Flag != 0) return 0;
    DWCi_CMNlLoadResource(g_021DAC20, (void (*)(void *, unsigned long, unsigned long))GXS_LoadBG0Scr);
    *(volatile unsigned int *)0x04001010 = 0x01920000;
    canvas = DWCi_FNTlFormBgEx(1, 0);
    msg = DWCi_MSGlGetEx(g_021DE598, messageId, n, num);
    DWCi_FNTlDrawRect(canvas, 0x14, 0, 0xd8, 0x40, 2, DWCi_CMNlFontFlag(), msg);
    DWCi_FNTlRenewBg(canvas);
    Flag = 1;
    return 1;
}


int DWCi_COMMENTlDelete(void)
{
    if (Flag == 0) return 0;
    DWCi_FNTlDeleteBgLcd(1);
    Flag = 0;
    return 1;
}
