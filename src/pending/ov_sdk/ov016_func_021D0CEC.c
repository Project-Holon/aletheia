/*
 * function: func_021D0CEC
 * address:  0x021D0CEC
 * packet:   pkt_ov016_021D0CEC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      DWCi_USBAPlEnd (libdwcutil.TWL.HYB.a usbap.o)
 *
 * symbols:
 *   func_0208EBE4  0x0208EBE4  arm
 *   func_0208F400  0x0208F400  arm
 *   func_0208F43C  0x0208F43C  arm
 *   func_021D7744  0x021D7744  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE654     0x021DE654  data
 *   g_021DE654_b   0x021DE654  data
 *   func_021D0DE0  0x021D0DE0  arm  ov016
 */

typedef struct {
    unsigned char pad0[0x13B8];
    unsigned short wmstate;
    unsigned char pad1[0x1B90 - 0x13BA];
    volatile int task;
    volatile unsigned char st;
} M;

extern int func_0208EBE4();
extern int func_0208F400();
extern int func_0208F43C();
extern void func_021D7744();
extern void func_021D6438();
extern M *g_021DE654;
extern M *g_021DE654_b;
extern void func_021D0DE0(void *arg);

int func_021D0CEC(void)
{
    int rs;
    g_021DE654->st = 1;
    func_0208EBE4(&g_021DE654->wmstate);
    if (g_021DE654->wmstate != 2) {
        rs = func_0208F400(func_021D0DE0);
        if (rs != 2)
            return 0;
        do {
            func_0208EBE4(&g_021DE654->wmstate);
        } while (g_021DE654->wmstate != 2);
    }
    rs = func_0208F43C(func_021D0DE0);
    if (rs != 2)
        return 0;
    {
        int t = g_021DE654->task;
        if (t != 0)
            func_021D7744(0);
    }
    while (g_021DE654->st != 2)
        ;
    func_021D6438(&g_021DE654_b);
    return 1;
}
