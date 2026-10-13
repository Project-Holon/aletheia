/*
 * file:     unit_021C7CE4.c
 * unit:     yes
 * function: func_021C7CE4, func_021C7D00, func_021C7D80, func_021C80B8
 * address:  0x021C7CE4
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
 *   initGraphics                     0x021C7D00  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   procInit                         0x021C80B8  arm
 *   func_021BD1D4  0x021BD1D4  arm
 *   DWCi_GetParam2_                     0x021c0ea0  arm
 *   DWCi_Language                       0x021c0ec8  arm
 *   DWCi_FNTlFormBgEx                   0x021d5a58  arm
 *   DWCi_MSGlGet                        0x021c1030  arm
 *   OS_SNPrintf                         0x02084f80  arm
 *   DWCi_STRlConvertStringAsciiToUnicode 0x021d722c arm
 *   DWCi_FNTlDrawStringEx               0x021d5db0  arm
 *   DWCi_CMNlFontFlag                   0x021bd3cc  arm
 *   DWCi_FNTlDrawRect                   0x021d5e5c  arm
 *   DWCi_FNTlRenewBg                    0x021d5fc4  arm
 *   ErrorCode                           0x021de5e8  data
 *   FONT_TBL                            0x021da5f0  data
 *   DWCiMsgCmn                          0x021de598  data
 *   @20980                              0x021db57c  data
 *   C_CODE                              0x021da600  data
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021D603C  0x021D603C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C80F4  0x021C80F4  arm  ov016
 */
typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

struct tagCOORD {
    unsigned short x;
    unsigned short y;
};

extern void DWCi_ChangeScene(void (*scene)(void));
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void DWCi_GetParam2_(void *a, void *b);
extern int DWCi_Language(void);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern u16 *DWCi_MSGlGet(void *msg, int id);
extern int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
extern int DWCi_STRlConvertStringAsciiToUnicode(u16 *dst, char *src, int len);
extern void DWCi_FNTlDrawStringEx(void *canvas, int x, int y, int color, int interval,
                                  u16 *txt, int font);
extern unsigned long DWCi_CMNlFontFlag(void);
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color,
                              unsigned long flag, u16 *txt);
extern void DWCi_FNTlRenewBg(void *canvas);
extern void func_021D55A4();
extern void func_021D603C(int lcd, int plane);
extern void func_021C0E40(unsigned int v);
extern void func_021C80F4();
void DWCi_SceneSetError(void);
void func_021C7D00(void);
void drawMessage(void);
void func_021C80B8(void);
extern unsigned int DWCiMsgCmn;

static void initGraphics(void);

static void drawMessage(void);

static void procInit(void);


void DWCi_SceneSetError(void)
{
	initGraphics();
	drawMessage();
	DWCi_ChangeScene(procInit);
}


void func_021C7D00(void)
{
    func_021BD1D4((void *)0x021DB568, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}

static int ErrorCode = 0;

static const unsigned char FONT_TBL[7] = { 0, 1, 1, 1, 1, 1, 0 };

/*
 * The vendor .rodata has this rectangle between FONT_TBL and C_CODE. No code
 * reads it: the DWCi_FNTlDrawRect call below uses the same values as
 * constants. The vendor symbol list does not name it.
 */
static const struct tagRECT { unsigned short x, y, w, h; } R_MSG = { 0xd, 0x3c, 0xe6, 0x5e };

static const struct tagCOORD C_CODE[7] = {
    { 0x62, 0x22 }, { 0x62, 0x22 }, { 0x3d, 0x22 }, { 0x65, 0x22 },
    { 0x6c, 0x22 }, { 0x34, 0x22 }, { 0x4e, 0x22 }
};


static inline void drawStr(void *canvas, int x, int y, int color, int interval, u16 *txt, int font)
{
    DWCi_FNTlDrawStringEx(canvas, x, y, color, interval, txt, font);
}


void drawMessage(void)
{
    u16 *msg;
    void *canv;
    int id;
    int prm;
    u16 buf[8];
    char tmpbuf[8];

    id = 0;
    DWCi_GetParam2_(0, &prm);
    if (-20099 <= ErrorCode)
        id = 0;
    else if (-20100 <= ErrorCode)
        id = 2;
    else if (-20101 <= ErrorCode)
        id = 0x13;
    else if (-20107 <= ErrorCode)
        id = 2;
    else if (-20108 <= ErrorCode)
        id = 0x12;
    else if (-20109 <= ErrorCode)
        id = 2;
    else if (-20110 <= ErrorCode)
        id = 3;
    else if (-20999 <= ErrorCode)
        id = 2;
    else if (-22999 <= ErrorCode)
        id = 0;
    else if (-23999 <= ErrorCode)
        id = 0x13;
    else if (-49999 <= ErrorCode)
        id = 0;
    else if (-50002 <= ErrorCode)
        id = 7;
    else if (-50003 <= ErrorCode)
        id = 5;
    else if (-50098 <= ErrorCode)
        id = 0;
    else if (-50099 <= ErrorCode) {
        if (prm == 2)
            id = 5;
        else
            id = 7;
    }
    else if (-51098 <= ErrorCode)
        id = 0;
    else if (-51099 <= ErrorCode) {
        if (prm == 2)
            id = 5;
        else
            id = 8;
    }
    else if (-51102 <= ErrorCode)
        id = 9;
    else if (-51103 <= ErrorCode)
        id = 5;
    else if (-51199 <= ErrorCode)
        id = 0;
    else if (-51299 <= ErrorCode)
        id = 0x14;
    else if (-51302 <= ErrorCode)
        id = 0x15;
    else if (-51303 <= ErrorCode)
        id = 4;
    else if (-51999 <= ErrorCode)
        id = 0;
    else if (-52002 <= ErrorCode)
        id = 0xa;
    else if (-52003 <= ErrorCode)
        id = 0x16;
    else if (-52099 <= ErrorCode)
        id = 0;
    else if (-52103 <= ErrorCode)
        id = 0xb;
    else if (-52199 <= ErrorCode)
        id = 0;
    else if (-52203 <= ErrorCode)
        id = 0xb;
    else if (-52299 <= ErrorCode)
        id = 0;
    else if (-52399 <= ErrorCode)
        id = 2;
    else if (-52999 <= ErrorCode)
        id = 0;
    else if (-53299 <= ErrorCode)
        id = 2;

    canv = DWCi_FNTlFormBgEx(0, FONT_TBL[DWCi_Language()]);
    msg = DWCi_MSGlGet((void *)DWCiMsgCmn, id);
    OS_SNPrintf(tmpbuf, 8, "%d", -ErrorCode);
    DWCi_STRlConvertStringAsciiToUnicode(buf, tmpbuf, 8);
    drawStr(canv, C_CODE[DWCi_Language()].x, C_CODE[DWCi_Language()].y, 2, 10, buf, 0);
    DWCi_FNTlDrawRect(canv, 0xd, 0x3c, 0xe6, 0x5e, 2, DWCi_CMNlFontFlag(), msg);
    DWCi_FNTlRenewBg(canv);
}


/*
 * sdk:      procInit (libdwcutil.TWL.HYB.a sceneseterror.o)
 */
void func_021C80B8(void)
{
    func_021D55A4(2, 0, 0x15, 8);
    func_021D603C(0, 0x15);
    func_021C0E40((unsigned int)func_021C80F4);
}
