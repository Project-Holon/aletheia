/*
 * function: func_021DE12C
 * address: 0x021DE12C
 * packet: pkt_ov183_021DE12C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned short u16;
extern void func_0204B3B4(void *);
extern void func_02082BCC(void *, int, unsigned);
void func_021DE12C(char *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        if (*(void **)(slot + 4)) {
            func_0204B3B4(*(void **)(slot + 4));
            *(void **)(slot + 4) = 0;
        }
    }
    func_0204B3B4(*(void **)p);
    func_02082BCC(p, 0, 20);
}
