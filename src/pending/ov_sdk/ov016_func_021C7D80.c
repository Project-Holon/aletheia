/*
 * function: drawMessage
 * address:  0x021C7D80
 * packet:   pkt_ov016_021C7D80
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  Error->id arm chain, frame layout (tmpbuf sp+0x10 / prm sp+0x18 /
 *           buf sp+0x1c) and every threshold constant reproduce; the compared
 *           ErrorCode value lands in r0 where the original keeps it in r1
 *           (threshold temp r1 vs r0), so every chain compare differs by
 *           register only.  Tried: direct `ErrorCode`, `int err` local first
 *           and last, signed/unsigned field types.  Tail also evaluates the
 *           two `C_CODE[DWCi_Language()]` arguments in the opposite order
 *           (original computes .x first into r6, then .y into r1).  Looks
 *           like an allocator/eval-order divergence, not source shape.
 *
 * sdk:      drawMessage (libdwcutil.TWL.HYB.a sceneseterror.o)
 *
 * symbols:
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
 *   d_021DB57C                          0x021db57c  data
 *   C_CODE                              0x021da600  data
 */

typedef unsigned short u16;

struct tagCOORD {
    unsigned short x;
    unsigned short y;
};

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
extern int ErrorCode;
extern unsigned char FONT_TBL[];
extern unsigned int DWCiMsgCmn;
extern char d_021DB57C[];
extern struct tagCOORD C_CODE[];

void drawMessage(void)
{
    int err;
    u16 buf[8];
    int prm;
    char tmpbuf[8];
    int id;
    void *canv;
    u16 *msg;

    id = 0;
    DWCi_GetParam2_(0, &prm);
    err = ErrorCode;
    if (-20099 <= err)
        id = 0;
    else if (-20100 <= err)
        id = 2;
    else if (-20101 <= err)
        id = 0x13;
    else if (-20107 <= err)
        id = 2;
    else if (-20108 <= err)
        id = 0x12;
    else if (-20109 <= err)
        id = 2;
    else if (-20110 <= err)
        id = 3;
    else if (-20999 <= err)
        id = 2;
    else if (-22999 <= err)
        id = 0;
    else if (-23999 <= err)
        id = 0x13;
    else if (-50063 <= err)
        id = 0;
    else if (-50066 <= err)
        id = 7;
    else if (-50067 <= err)
        id = 5;
    else if (-50162 <= err)
        id = 0;
    else if (-50163 <= err)
        id = (prm == 2) ? 5 : 7;
    else if (-51098 <= err)
        id = 0;
    else if (-51099 <= err)
        id = (prm == 2) ? 5 : 8;
    else if (-51102 <= err)
        id = 9;
    else if (-51103 <= err)
        id = 5;
    else if (-51199 <= err)
        id = 0;
    else if (-51299 <= err)
        id = 0x14;
    else if (-51302 <= err)
        id = 0x15;
    else if (-51303 <= err)
        id = 4;
    else if (prm - 2000 <= err)
        id = 0;
    else if (-52002 <= err)
        id = 0xa;
    else if (-52003 <= err)
        id = 0x16;
    else if (-52099 <= err)
        id = 0;
    else if (-52103 <= err)
        id = 0xb;
    else if (-52199 <= err)
        id = 0;
    else if (-52203 <= err)
        id = 0xb;
    else if (-52299 <= err)
        id = 0;
    else if (-52399 <= err)
        id = 2;
    else if (-52999 <= err)
        id = 0;
    else if (-53299 <= err)
        id = 2;

    canv = DWCi_FNTlFormBgEx(0, FONT_TBL[DWCi_Language()]);
    msg = DWCi_MSGlGet((void *)DWCiMsgCmn, id);
    OS_SNPrintf(tmpbuf, 8, d_021DB57C, -ErrorCode);
    DWCi_STRlConvertStringAsciiToUnicode(buf, tmpbuf, 8);
    DWCi_FNTlDrawStringEx(canv, C_CODE[DWCi_Language()].y, C_CODE[DWCi_Language()].x, 2, 10,
                          buf, 0);
    DWCi_FNTlDrawRect(canv, 0xd, 0x3c, 0xe6, 0x5e, 2, DWCi_CMNlFontFlag(), msg);
    DWCi_FNTlRenewBg(canv);
}
