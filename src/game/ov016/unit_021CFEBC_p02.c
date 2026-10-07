/*
 * file:     unit_021CFEBC_p02.c
 * unit:     yes
 * function: func_021CFFD0, func_021CFFF0, func_021D0014
 * address:  0x021CFFD0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
struct Obj;
typedef unsigned int   u32;

extern void func_02072F34(char *, unsigned int);
extern void func_02073018(struct Obj *o, u32 v, u32 w);
extern void func_02072E7C(void **r0, int fadeFrame);
void func_021CFFD0(unsigned int v);
void func_021CFFF0(unsigned int a, unsigned int b);
void func_021D0014(void);


/*
 * Tail-call func_02072F34 with the global object +0xa0 and the argument.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CFFD0.c \
 *       --func func_021CFFD0 --addr 0x021CFFD0 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CFFD0(unsigned int v)
{
    func_02072F34(*(char **)0x021DE648 + 0xa0, v);
}


/*
 * Tail-call func_02073018 with the global object +0xa0 and two arguments.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CFFF0.c \
 *       --func func_021CFFF0 --addr 0x021CFFF0 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CFFF0(unsigned int a, unsigned int b)
{
    func_02073018((struct Obj *)(*(char **)0x021DE648 + 0xa0), a, b);
}


void func_021D0014(void)
{
    func_02072E7C((void **)(*(char **)0x021DE648 + 0xa0), 0);
}
