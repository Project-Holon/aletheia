/*
 * function: func_021BD7F4
 * address:  0x021BD7F4
 * packet:   pkt_ov016_021BD7F4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ICONlEnd (libdwcutil.TWL.HYB.a(icon.o))
 *
 * symbols:
 *   func_021D7744  0x021D7744  arm  ov016
 *   func_021D6F38  0x021D6F38  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE558  0x021DE558  data
 *   g_021DE558_b  0x021DE558  data
 */

typedef struct MemIcon {
    void *obj;
    void *task;
    signed char type;
} MemIcon;

extern void func_021D7744(unsigned int idx, void *r4);
extern void func_021D6F38(unsigned int *obj);
extern void func_021D6438(MemIcon **mem);
extern MemIcon *g_021DE558;
extern MemIcon *g_021DE558_b;

void func_021BD7F4(void)
{
    if (g_021DE558 == 0)
        return;
    func_021D7744(0, g_021DE558->task);
    func_021D6F38(g_021DE558->obj);
    func_021D6438(&g_021DE558_b);
}
