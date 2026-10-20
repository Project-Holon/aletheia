/*
 * file:     comment.c
 * unit:     yes
 * function: DWCi_COMMENTlInit, DWCi_COMMENTlDispEx, DWCi_COMMENTlDelete
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
 *   sCommentPathJtNullScr            0x021DAC20  data  a1
 *   GXS_LoadBG0Scr        0x0207E944  arm
 *   gCommentWork            0x021DE598  data  a4
 *   DWCi_FNTlDeleteBgLcd 0x021D5CA8  arm
 */
#include "common.h"
typedef int bool_0;
#include "font.h"
#include "message.h"
#include "../arm9/gx_load2d.h"
void DWCi_COMMENTlInit(void);
int DWCi_COMMENTlDispEx(int messageId, int n, int num);
int DWCi_COMMENTlDelete(void);
extern unsigned char Flag;
extern char sCommentPathJtNullScr[];
extern void *gCommentWork;


void DWCi_COMMENTlInit(void)
{
    *(unsigned char *)0x021DE50C = 0;
}


int DWCi_COMMENTlDispEx(int messageId, int n, int num)
{
    unsigned short *msg;
    void *canvas;

    if (Flag != 0) return 0;
    DWCi_CMNlLoadResource(sCommentPathJtNullScr, GXS_LoadBG0Scr);
    *(volatile unsigned int *)0x04001010 = 0x01920000;
    canvas = DWCi_FNTlFormBgEx(1, 0);
    msg = DWCi_MSGlGetEx(gCommentWork, messageId, n, num);
    DWCi_FNTlDrawRect(canvas, 0x14, 0, 0xd8, 0x40, 2, DWCi_CMNlFontFlag(), msg);
    DWCi_FNTlRenewBg((sptr)canvas);
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
