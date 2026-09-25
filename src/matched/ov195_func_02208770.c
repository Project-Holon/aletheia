/*
 * function: func_02208770
 * address:  0x02208770
 * packet:   pkt_02208770
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02208B54 0x02208B54 thumb
 *   func_02208A6C 0x02208A6C thumb
 *   func_02208994 0x02208994 thumb
 *   func_020307B0 0x020307B0 arm
 */

extern void func_02208B54(void *);
extern void func_02208A6C(void *);
extern void func_02208994(int);
extern void func_020307B0(void *);

void func_02208770(char *a)
{
    func_02208B54(a);
    func_02208A6C(a);
    func_02208994(*(int *)(a + 0x10));
    func_020307B0(a);
}