/*
 * file:     unit_021BD170_p02.c
 * unit:     yes
 * function: func_021BD264, func_021BD29C, func_021BD310
 * address:  0x021BD264
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
 *   func_021C0EC8  0x021c0ec8  arm  ov016
 *   func_021D5CCC  0x021d5ccc  arm  ov016
 *   func_021D5FC4  0x021d5fc4  arm  ov016
 *   g_021DE598  0x021de598  data
 *   g_021DA06A  0x021da06a  data
 *   g_021DA068  0x021da068  data
 */
typedef struct tagCOORD { unsigned short x, y; } COORD;

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
extern unsigned char func_021C0EC8(void);
extern void func_021D5CCC(void *canvas, int x, int y, int color, unsigned long flag, unsigned short *txt);
extern void func_021D5FC4(int x);
void DWCi_CMNlButton(int kind);
void DWCi_CMNlMsgDraw(int msgId);
void func_021BD310(unsigned short *name, int msgId);
extern void *DWCiMsgCmn;
extern int g_021DE598;
extern const COORD g_021DA068[7];


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
