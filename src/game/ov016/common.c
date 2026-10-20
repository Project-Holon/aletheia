/*
 * file:     common.c
 * unit:     yes
 * function: DWCi_Char, DWCi_CMNlLoadResource, DWCi_CMNlStep, DWCi_CMNlButton, DWCi_CMNlMsgDraw, DWCi_CMNlMsgNameDraw, DWCi_CMNlFontFlag
 * address:  0x021BD170
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Table lookup through the function-pointer table at 0x021DA04C.
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   strncpy  0x02094860  arm
 *   DWCi_Language  0x021c0ec8  arm  ov016
 *   gCommonWork  0x021de510  data
 *   sCommonLanguageCodes  0x021da044  data
 *   strncpy  0x02094860  arm
 *   DWCi_ARClReadEx  0x021d4b68  arm  ov016
 *   DC_FlushRange  0x020862f0  arm
 *   DWCi_ARClRelease  0x021d4c68  arm  ov016
 *   DWCi_GetParam_  0x021c0e64  arm  ov016
 *   DWCi_STEPlBegin  0x021d0040  arm  ov016
 *   DWCi_STEPlChange  0x021d05bc  arm  ov016
 *   DWCi_BTNlInit                    0x021BC9E4  arm
 *   DWCi_FNTlFormBgEx                0x021D5A58  arm
 *   DWCi_MSGlGet                     0x021C1030  arm
 *   DWCi_CMNlFontFlag                0x021BD3CC  arm
 *   DWCi_FNTlDrawRect                0x021D5E5C  arm
 *   DWCi_FNTlRenewBg                 0x021D5FC4  arm
 *   DWCiMsgCmn                       0x021DE598  data
 *   DWCi_FNTlDraw  0x021d5ccc  arm  ov016
 *   gCommentWork  0x021de598  data
 *   sCommonNamePosYByLanguage  0x021da06a  data
 *   sCommonNamePosByLanguage  0x021da068  data
 *   gDwcLanguageTable 0x021DA04C data
 */
#include "../../matched/arm9_sdk/libc/string.h"

#include "dwcutil_types.h"

extern char *strncpy(char *dest, const char *src, unsigned int n);
#include "dwcutil_main.h"
#include "archive.h"
#include "../arm9/os_cache.h"
#include "step.h"
#include "button.h"
typedef int bool_0;
#include "font.h"
#include "message.h"
int DWCi_CMNlFontFlag(void);
unsigned char *DWCi_Char(unsigned char *name);
void DWCi_CMNlLoadResource(char *file, void (*func)(const void *, u32, u32));
void DWCi_CMNlStep(int step);
void DWCi_CMNlButton(int kind);
void DWCi_CMNlMsgDraw(int msgId);
void DWCi_CMNlMsgNameDraw(unsigned short *name, int msgId);
extern unsigned char gCommonWork[];
extern const unsigned char sCommonLanguageCodes[];
extern void *DWCiMsgCmn;
extern int gCommentWork;
extern const COORD sCommonNamePosByLanguage[7];
extern int gDwcLanguageTable[];


unsigned char *DWCi_Char(unsigned char *name)
{
    int lang;

    strncpy((char *)gCommonWork, (const char *)name, 0x3f);
    if (name[5] == 'x')
        return gCommonWork;
    lang = DWCi_Language();
    if (name[5] == 'y' && lang != 0)
        return gCommonWork;
    gCommonWork[5] = sCommonLanguageCodes[lang];
    return gCommonWork;
}


void DWCi_CMNlLoadResource(char *file, void (*func)(const void *, u32, u32))
{
    char *n;
    unsigned long size;
    void *data;

    n = (char *)DWCi_Char((unsigned char *)file);
    data = DWCi_ARClReadEx(n, &size, 4);
    DC_FlushRange(data, size);
    func(data, 0, size);
    DWCi_ARClRelease(data);
}


void DWCi_CMNlStep(int step)
{
    int prm;

    DWCi_GetParam_((void **)&prm, 0);
    if (prm == 1)
        DWCi_STEPlBegin(step);
    else if (prm == 2)
        DWCi_STEPlChange(step);
}


void DWCi_CMNlButton(int kind)
{
    int prm;

    DWCi_GetParam_(0, (void **)&prm);
    if (prm == 1)
        DWCi_BTNlInit(kind);
}


void DWCi_CMNlMsgDraw(int msgId)
{
    void *canvas = DWCi_FNTlFormBgEx(0, 0);
    unsigned short *msg = (unsigned short *)DWCi_MSGlGet(DWCiMsgCmn, msgId);
    unsigned long flag = DWCi_CMNlFontFlag();

    DWCi_FNTlDrawRect(canvas, 0xd, 0x28, 0xe6, 0x70, 2, flag, msg);
    DWCi_FNTlRenewBg((sptr)canvas);
}


/*
 * sdk:      DWCi_CMNlMsgNameDraw (libdwcutil.TWL.HYB.a(common.o))
 */
void DWCi_CMNlMsgNameDraw(unsigned short *name, int msgId)
{
    unsigned short *msg;
    void *canvas;

    canvas = DWCi_FNTlFormBgEx(0, 0);
    msg = (short unsigned int *)DWCi_MSGlGet((void *)gCommentWork, msgId);
    DWCi_FNTlDrawRect(canvas, 13, 60, 230, 94, 2, DWCi_CMNlFontFlag(), msg);
    DWCi_FNTlDraw(canvas, sCommonNamePosByLanguage[DWCi_Language()].x, sCommonNamePosByLanguage[DWCi_Language()].y, 2, 13 + 508, name);
    DWCi_FNTlRenewBg((sptr)canvas);
}


int DWCi_CMNlFontFlag(void)
{
    return gDwcLanguageTable[DWCi_Language()];
}
