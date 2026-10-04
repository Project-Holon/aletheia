/*
 * function: func_021CCE78
 * address:  0x021CCE78
 * packet:   pkt_ov016_021CCE78
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CCE78.c \n *       --func func_021CCE78 --addr 0x021CCE78 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BCAE4  0x021BCAE4  arm  ov016
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE614     0x021DE614  data
 *   func_021CCEE4  0x021CCEE4  arm  ov016
 */

extern int func_021D5580(int lcd);
extern void func_021BCAE4(void);
extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021C0E40(unsigned int v);
typedef struct { signed char last; signed char cur; unsigned char flag; void *screen; } FocusState;
extern FocusState g_021DE614;
extern void func_021CCEE4(void);

void func_021CCE78(void)
{
    if (func_021D5580(1))
        return;
    if (g_021DE614.flag)
        func_021BCAE4();
    func_021D55A4(3, 1, 1, 8);
    func_021D55A4(3, 0, 20, 8);
    func_021C0E40((unsigned int)func_021CCEE4);
}
