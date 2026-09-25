/*
 * function: func_021BA740
 * address:  0x021BA740
 * packet:   pkt_021BA740
 * region:   ov225
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_020307B0 0x020307B0 arm
 */

extern void func_02030EAC(void *);
extern void func_02041EE4(int, int, int);
extern void func_020307B0(void *);

void func_021BA740(char *p)
{
    func_02030EAC(*(void **)(p + 0x80));
    func_02041EE4(5, 3, 0);
    func_020307B0(p);
}
