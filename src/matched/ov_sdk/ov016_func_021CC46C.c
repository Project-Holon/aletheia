/*
 * function: dispFocus
 * address:  0x021CC46C
 * packet:   pkt_ov016_021CC46C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_FOCUSlDisp4                 0x021bd4c8 arm
 *   DWCi_FOCUSlDisp                  0x021bd41c arm
 *   FocusPos                         0x021de60c data
 *   R_FOCUS                          0x021da77c data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetselectap), symbol dispFocus (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CC46C.c \
 *       --func dispFocus --addr 0x021CC46C --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

/* scenesetselectap.o .rodata at 0x021DA77C */
extern const RECT R_FOCUS[7];

/* scenesetselectap.o .bss at 0x021DE60C */
extern unsigned char FocusPos;

extern void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);
extern void DWCi_FOCUSlDisp(int kind, int x0, int x1, int y);

static void dispFocus(void)
{
    if (FocusPos < 4) {
        DWCi_FOCUSlDisp4(R_FOCUS[FocusPos].l, R_FOCUS[FocusPos].r, R_FOCUS[FocusPos].t, R_FOCUS[FocusPos].b);
    } else {
        DWCi_FOCUSlDisp(0, R_FOCUS[FocusPos].l, R_FOCUS[FocusPos].r, R_FOCUS[FocusPos].t);
    }
}
