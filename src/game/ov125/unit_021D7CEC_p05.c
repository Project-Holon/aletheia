/*
 * file:     unit_021D7CEC_p05.c
 * unit:     yes
 * function: func_021D858C, func_021D8598
 * address:  0x021D858C
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D8B44  0x021D8B44  arm ov125
 *   func_021D7770  0x021D7770  arm
 */
extern void func_021D8B44(void);
extern void func_021D7770(int, int, int);
void func_021D858C(void);
void func_021D8598(int a, int b, int c);


/*
 * ARM tail call: ldr ip, =target; bx ip.
 */
void func_021D858C(void)
{
    func_021D8B44();
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D8598(int a, int b, int c)
{
    func_021D7770(b, c, a);
}
