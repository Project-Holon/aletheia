/*
 * function: drawMessage
 * address:  0x021C7D80
 * packet:   pkt_ov016_021C7D80
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  Wave8 fixed the whole -50xxx threshold cluster and the prm-2000
 *           arm: the image pools base -49999 (not -50063) and derives every
 *           sibling by `sub`, so lines 104-112 are -49999/-50002/-50003/
 *           -50098/-50099 and the `prm-2000` arm is the constant -51999.
 *           With those, plus if/else instead of `?:` in the two prm arms and
 *           a named `ypos` for the second C_CODE lookup, 479 concrete bytes
 *           drop to 19.  Remaining residual is the DrawStringEx tail only:
 *           the image keeps y in r6 and uses r3 for the second language index
 *           (`lsl r3,r0,#2` ... `mov r2,r6` last), ours frees r6 early
 *           (`mov r2,r6; lsl r6,r0,#2`) and schedules `mov r0,r8` one slot
 *           earlier.  Tried inline both arg orders, u16/int/block/top locals
 *           for x and y, named lang, const C_CODE - all inert or worse; this
 *           is the front end's scratch-register/schedule choice (cf.
 *           idioms/a-front-end-hoists-a-base-copy-to-fold-an-argument-load.md).
 *
 * opus (2026-10-01): DWARF has no `ypos` (or `err`) local, so the original is a
 *           single DrawStringEx call; the image still evaluates the y argument
 *           (C_CODE+2, first DWCi_Language call) before x. dsi/1.1p1 evaluates
 *           the inline form left to right (x first, 3 blocks), so `ypos` stands
 *           in for the 4.0.0.1025 argument order. Inert: block-scoped ypos,
 *           ypos declared first, u16 ypos, `(&C_CODE[l])->y`; an x temp or a
 *           comma form grows the body to 828 B.
 * lane03 (2026-10-01): stand-in locals gone: `err` is ErrorCode read in each
 *           test (CSE'd to one load) and the y temp is `id` (dead after
 *           DWCi_MSGlGet); locals declared in DWARF order. Our DWARF now equals
 *           the object's (tmpbuf/buf/prm slots, id r5). Still 19 B, the same
 *           DrawStringEx tail: ours copies y to r2 first and reuses r6 for the
 *           x index; the image keeps r6 and indexes in r3. Inert: a getx()
 *           inline (828 B), (u16)/(int) casts on a single-call y.
 * lane15 (2026-10-01): 19 -> 17 B. sdkobj lists ErrorCode, FONT_TBL, C_CODE
 *           and the "%d" literal (@20980) as data locals of sceneseterror.o, so
 *           they are file statics here (`static const` C_CODE/FONT_TBL, static
 *           ErrorCode, a string literal). Still the same tail: ours copies y to
 *           r2 before the x index (r6), the image indexes in r3 and copies late.
 *           Inert: `id & 0xffff`, (u16)/(int) casts on either arg, `id = L();
 *           id = C_CODE[id].y`, an assignment inside the call (18).
 * w3 lane26 (2026-10-01): still 17 B. sceneseterror.o has no align-32 section
 *           (no asm-mode lever). Inert: DWCiMsgCmn as void * without the cast,
 *           void ** GetParam2_ prototype, C_CODE extern const (17) / non-const
 *           (19, x load moves past the stm), `(&C_CODE[..])->x`, raw u16 read for
 *           x, comma/if-bound id; dsi/1.2 gives the same 17. The index temp takes
 *           y's freed r6 (ours) instead of scratch r3 (image).
 * w4 (2026-10-01): EXACT. Vendor .debug_line puts both DWCi_Language calls and
 *           the DrawStringEx on one statement (line 208), so no y temp. The call
 *           goes through a static inline wrapper: inline arguments are evaluated
 *           last to first (idioms/an-inline-wrappers-arguments-are-evaluated-last-
 *           to-first.md), giving y (call+load) before x and y held in r6.
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
 *   @20980                              0x021db57c  data
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
static int ErrorCode = 0;
static const unsigned char FONT_TBL[7] = {0};
extern unsigned int DWCiMsgCmn;
static const struct tagCOORD C_CODE[7] = {0};

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
