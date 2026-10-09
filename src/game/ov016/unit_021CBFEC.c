/*
 * file:     unit_021CBFEC.c
 * function: input
 * address:  0x021CBFEC
 * packet:   pkt_ov016_021CBFEC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_TPlCheckTrigger             0x021d696c arm
 *   DWCi_BTNlSet                     0x021bcb28 arm
 *   dispFocus                        0x021cc46c arm
 *   DWCi_IPTlCheckTrigger            0x021d6824 arm
 *   DWCi_IPTlCheckRepeat             0x021d6864 arm
 *   moveFocus                        0x021cc4e8 arm
 *   R_TOUCH                          0x021da744 data
 *   FocusPos                         0x021de60c data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetselectap), symbol input (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CBFEC.c \
 *       --func input --addr 0x021CBFEC --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;
typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

/* scenesetselectap.o .rodata at 0x021DA744 */
extern const RECT R_TOUCH[7];

/* scenesetselectap.o .bss at 0x021DE60C */
extern unsigned char FocusPos;

extern bool DWCi_TPlCheckTrigger(RECT *r);
extern void DWCi_BTNlSet(int idx);
extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern bool DWCi_IPTlCheckRepeat(unsigned short input);

static void dispFocus(void);
static void moveFocus(int dir);

static void input(void)
{
    int i;

    for (i = 0; (unsigned int)i < 7; i++) {
        if (DWCi_TPlCheckTrigger((RECT *)&R_TOUCH[i])) {
            DWCi_BTNlSet(1);
            FocusPos = i;
            dispFocus();
            return;
        }
    }
    if (DWCi_IPTlCheckTrigger(1)) {
        DWCi_BTNlSet(1);
    } else if (DWCi_IPTlCheckTrigger(2)) {
        DWCi_BTNlSet(0);
    } else if (DWCi_IPTlCheckRepeat(0x40)) {
        moveFocus(1);
    } else if (DWCi_IPTlCheckRepeat(0x80)) {
        moveFocus(3);
    } else if (DWCi_IPTlCheckRepeat(0x20)) {
        moveFocus(0);
    } else if (DWCi_IPTlCheckRepeat(0x10)) {
        moveFocus(2);
    }
}
