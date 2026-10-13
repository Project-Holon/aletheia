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
 *   CLACT_ExitSystem 0x0204A5AC arm
 */

extern void func_021BDD5C(char *p);
extern void func_021BDBA8(char *p);
extern void CLACT_ExitSystem(void);

void func_021BD824(char *a)
{
    func_021BDD5C(a);
    func_021BDBA8(a);
    CLACT_ExitSystem();
}