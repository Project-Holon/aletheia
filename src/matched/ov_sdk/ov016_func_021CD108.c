/*
 * function: func_021CD108
 * address:  0x021CD108
 * packet:   pkt_ov016_021CD108
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dispPush (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD108.c \n *       --func func_021CD108 --addr 0x021CD108 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021CE7B0  0x021CE7B0  arm  ov016
 *   g_021DA7D4     0x021DA7D4  data
 *   g_021DE614     0x021DE614  data
 */

typedef struct { signed char last; signed char cur; unsigned char flag; void *screen; } FocusState;
extern FocusState g_021DE614;
typedef struct { unsigned char b[4]; } Palette4;
extern Palette4 g_021DA7D4;
extern void func_021CE7B0(void *src, int sColor, int dColor);

void func_021CD108(void)
{
    Palette4 palette = g_021DA7D4;
    func_021CE7B0(g_021DE614.screen, palette.b[g_021DE614.cur], palette.b[g_021DE614.cur]);
}
