/*
 * function: func_021DE014
 * address:  0x021DE014
 * packet:   pkt_021DE014
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DE884  0x021DE884  thumb  ov171
 *   func_021DE368  0x021DE368  thumb  ov171
 *   func_021DE258  0x021DE258  thumb  ov171
 *   func_0204A5AC  0x0204A5AC  arm
 */

extern void func_021DE884(int *);
extern void func_021DE368(int *);
extern void func_021DE258(int *);
extern void func_0204A5AC(void);

void func_021DE014(int *p)
{
    func_021DE884(p);
    func_021DE368(p);
    func_021DE258(p);
    func_0204A5AC();
}
