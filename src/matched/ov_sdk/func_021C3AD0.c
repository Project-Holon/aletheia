/*
 * function: func_021C3AD0
 * address:  0x021C3AD0
 * packet:   pkt_021C3AD0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The final func_021C0E50(0, 1) is written in both arms: the original emits
 * it once per arm, not merged before the branch.
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm
 *   func_021BCB58  0x021BCB58  arm
 *   func_021D5CA8  0x021D5CA8  arm
 *   func_021BD138  0x021BD138  arm
 *   func_021D6090  0x021D6090  arm
 *   func_021C0E50  0x021C0E50  arm
 *   func_021C0E40  0x021C0E40  arm
 *   g_021DE5B8     0x021DE5B8  data
 *   func_021C2A3C  0x021C2A3C  arm
 *   func_021C35F0  0x021C35F0  arm
 */

typedef unsigned char u8;

extern int  func_021D5580(int x);
extern int  func_021BCB58(void);
extern void func_021D5CA8(int x);
extern void func_021BD138(void);
extern void func_021D6090(int a, int b);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern u8   g_021DE5B8[];
extern void func_021C2A3C(void);
extern void func_021C35F0(void);

void func_021C3AD0(void)
{
    if (func_021D5580(0) != 0)
        return;
    if (g_021DE5B8[0] == 0) {
        if (func_021D5580(1) != 0)
            return;
    }
    if (func_021BCB58() == 0)
        return;
    func_021D5CA8(0);
    if (g_021DE5B8[0] == 0) {
        func_021BD138();
        func_021D6090(1, 1);
    }
    func_021D6090(0, 0x15);
    if (g_021DE5B8[0] == 0) {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C2A3C);
    } else {
        func_021C0E50(0, 1);
        func_021C0E40((unsigned int)func_021C35F0);
    }
}
