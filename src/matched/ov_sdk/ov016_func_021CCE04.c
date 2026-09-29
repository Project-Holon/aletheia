/*
 * function: func_021CCE04
 * address:  0x021CCE04
 * packet:   pkt_ov016_021CCE04
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      button (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CCE04.c \n *       --func func_021CCE04 --addr 0x021CCE04 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021BCB14  0x021BCB14  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021CD108  0x021CD108  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE614     0x021DE614  data
 *   func_021CCE58  0x021CCE58  arm  ov016
 */

extern int func_021BCB14(void);
extern void func_021CFFAC(int no);
extern void func_021CD108(void);
extern void func_021C0E40(void (*scene)(void));
typedef struct { signed char last; signed char cur; unsigned char flag; void *screen; } FocusState;
extern FocusState g_021DE614;
extern void func_021CCE58(void);

void func_021CCE04(void)
{
    switch (func_021BCB14()) {
    case 0:
        func_021CFFAC(7);
        break;
    case 1:
        func_021CFFAC(6);
        func_021CD108();
        g_021DE614.flag = 1;
        break;
    default:
        return;
    }
    func_021C0E40(func_021CCE58);
}
