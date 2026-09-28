/*
 * function: func_021BD824
 * address:  0x021BD824
 * packet:   pkt_021BD824
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BDD5C 0x021BDD5C thumb
 *   func_021BDBA8 0x021BDBA8 thumb
 *   func_0204A5AC 0x0204A5AC arm
 */

extern void func_021BDD5C(void *);
extern void func_021BDBA8(void *);
extern void func_0204A5AC(void);

void func_021BD824(char *a)
{
    func_021BDD5C(a);
    func_021BDBA8(a);
    func_0204A5AC();
}