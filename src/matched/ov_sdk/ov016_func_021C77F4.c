/*
 * function: func_021C77F4
 * address:  0x021C77F4
 * packet:   pkt_ov016_021C77F4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene3 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6F38  0x021D6F38  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD1D4  0x021BD1D4  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E8C  0x021C0E8C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE5E4     0x021DE5E4  data
 *   g_021DB550     0x021DB550  data
 *   func_0207E51C  0x0207E51C  arm
 *   func_021C82FC  0x021C82FC  arm  ov016
 */

typedef struct MemSsea {
    unsigned char pad0[4];
    void *caret;
} MemSsea;

extern void func_021BD138();
extern void func_021D6F38();
extern void func_021D5CA8();
extern void func_021BD1D4();
extern void func_021D6090();
extern void func_021C0EA0();
extern void func_021C0E50();
extern void func_021C0E8C();
extern void func_021C0E40();
extern void func_021D6438();
extern void func_0207E51C();
extern void func_021C82FC();
extern MemSsea *g_021DE5E4;
extern unsigned char g_021DB550[];

void func_021C77F4(void)
{
    int prm;

    func_021BD138();
    func_021D6F38(g_021DE5E4->caret);
    func_021D5CA8(0);
    func_021BD1D4(g_021DB550, func_0207E51C);
    func_021D6090(1, 1);
    func_021D6090(0, 0x15);
    func_021C0EA0(&prm, 0);
    if (prm >= 3)
        prm++;
    func_021C0E50(2, 1);
    func_021C0E8C(0, prm + 3);
    func_021C0E40(func_021C82FC);
    func_021D6438((void *)0x021DE5E4);
}
