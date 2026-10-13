/*
 * file:     common_1.c
 * unit:     yes
 * function: func_021BD170, func_021BD1D4, func_021BD214, func_021BD264, func_021BD29C, func_021BD310
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
 * symbols:
 *   func_02094860  0x02094860  arm
 *   func_021C0EC8  0x021c0ec8  arm  ov016
 *   g_021DE510  0x021de510  data
 *   g_021DA044  0x021da044  data
 *   strncpy  0x02094860  arm
 *   func_021D4B68  0x021d4b68  arm  ov016
 *   func_020862F0  0x020862f0  arm
 *   func_021D4C68  0x021d4c68  arm  ov016
 *   func_021C0E64  0x021c0e64  arm  ov016
 *   func_021D0040  0x021d0040  arm  ov016
 *   func_021D05BC  0x021d05bc  arm  ov016
 *   DWCi_GetParam_                   0x021C0E64  arm
 *   DWCi_BTNlInit                    0x021BC9E4  arm
 *   DWCi_FNTlFormBgEx                0x021D5A58  arm
 *   DWCi_MSGlGet                     0x021C1030  arm
 *   DWCi_CMNlFontFlag                0x021BD3CC  arm
 *   DWCi_FNTlDrawRect                0x021D5E5C  arm
 *   DWCi_FNTlRenewBg                 0x021D5FC4  arm
 *   DWCiMsgCmn                       0x021DE598  data
 *   func_021D5A58  0x021d5a58  arm  ov016
 *   func_021C1030  0x021c1030  arm  ov016
 *   func_021BD3CC  0x021bd3cc  arm  ov016
 *   func_021D5E5C  0x021d5e5c  arm  ov016
 *   func_021D5CCC  0x021d5ccc  arm  ov016
 *   func_021D5FC4  0x021d5fc4  arm  ov016
 *   g_021DE598  0x021de598  data
 *   g_021DA06A  0x021da06a  data
 *   g_021DA068  0x021da068  data
 */
#include "../../matched/arm9_sdk/libc/string.h"

typedef struct tagCOORD { unsigned short x, y; } COORD;

extern char *strncpy(char *d, const char *s, unsigned long n);
extern int func_021C0EC8(void);
extern void *func_021D4B68(char *path, unsigned long *size, int alignment);
extern void func_020862F0(void *startAddr, unsigned long nBytes);
extern void func_021D4C68(void *file);
extern void func_021C0E64(void **param0, void **param1);
extern void func_021D0040(int step);
extern void func_021D05BC(int step);
extern void DWCi_GetParam_(void **param0, void **param1);
extern void DWCi_BTNlInit(int kind);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern unsigned short *DWCi_MSGlGet(void *msg, int id);
extern unsigned long DWCi_CMNlFontFlag(void);
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color,
                              unsigned long flag, unsigned short *txt);
extern void DWCi_FNTlRenewBg(void *canvas);
extern void *func_021D5A58(int lcd, int font);
extern unsigned int func_021C1030(unsigned int *p, unsigned int idx);
extern int func_021BD3CC(void);
extern void func_021D5E5C(void *canvas, int x, int y, int w, int h, int color, unsigned long flag, unsigned short *txt);
extern void func_021D5CCC(void *canvas, int x, int y, int color, unsigned long flag, unsigned short *txt);
extern void func_021D5FC4(int x);
unsigned char *func_021BD170(unsigned char *name);
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
void func_021BD214(int step);
void DWCi_CMNlButton(int kind);
void DWCi_CMNlMsgDraw(int msgId);
void func_021BD310(unsigned short *name, int msgId);
extern unsigned char g_021DE510[];
extern const unsigned char g_021DA044[];
extern void *DWCiMsgCmn;
extern int g_021DE598;
extern const COORD g_021DA068[7];



unsigned char *func_021BD170(unsigned char *name)
{
    int lang;

    strncpy((char *)g_021DE510, (char *)name, 0x3f);
    if (name[5] == 'x')
        return g_021DE510;
    lang = func_021C0EC8();
    if (name[5] == 'y' && lang != 0)
        return g_021DE510;
    g_021DE510[5] = g_021DA044[lang];
    return g_021DE510;
}




void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long))
{
    char *n;
    unsigned long size;
    void *data;

    n = (char *)func_021BD170((unsigned char *)file);
    data = func_021D4B68(n, &size, 4);
    func_020862F0(data, size);
    func(data, 0, size);
    func_021D4C68(data);
}




void func_021BD214(int step)
{
    int prm;

    func_021C0E64((void **)&prm, 0);
    if (prm == 1)
        func_021D0040(step);
    else if (prm == 2)
        func_021D05BC(step);
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
    unsigned short *msg = DWCi_MSGlGet(DWCiMsgCmn, msgId);
    unsigned long flag = DWCi_CMNlFontFlag();

    DWCi_FNTlDrawRect(canvas, 0xd, 0x28, 0xe6, 0x70, 2, flag, msg);
    DWCi_FNTlRenewBg(canvas);
}



/*
 * sdk:      DWCi_CMNlMsgNameDraw (libdwcutil.TWL.HYB.a(common.o))
 */
void func_021BD310(unsigned short *name, int msgId)
{
    unsigned short *msg;
    void *canvas;

    canvas = func_021D5A58(0, 0);
    msg = (short unsigned int *)func_021C1030((void *)g_021DE598, msgId);
    func_021D5E5C(canvas, 13, 60, 230, 94, 2, func_021BD3CC(), msg);
    func_021D5CCC(canvas, g_021DA068[func_021C0EC8()].x, g_021DA068[func_021C0EC8()].y, 2, 13 + 508, name);
    func_021D5FC4((int)canvas);
}
