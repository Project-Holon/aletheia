/*
 * file:     unit_021B82C4.c
 * unit:     yes
 * function: func_021B82C4, func_021B82C8, func_021B82D0, func_021B82DC
 * address:  0x021B82C4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern int func_0215F428(int unused, int type);
extern void func_0215F454(unsigned int, unsigned char *, unsigned char);
extern int func_0215F644(int s);
asm void func_021B82C4(void);
int func_021B82C8(int unused, int type);
void func_021B82D0(unsigned int a, unsigned char *p, unsigned char c);
int func_021B82DC(int s);

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B82C4.c \
 *       --func func_021B82C4 --addr 0x021B82C4 --region ov016 --cc dsi/1.1p1 --thumb
 */
asm void func_021B82C4(void)
{
    bx lr
    lsl r0, r0, 0
}


/*
 * Thumb tail-call thunk into func_0215F428.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B82C8.c \
 *       --func func_021B82C8 --addr 0x021B82C8 --region ov016 --cc dsi/1.1p1 --thumb
 */
int func_021B82C8(int unused, int type)
{
    return func_0215F428(unused, type);
}


/*
 * Store c through p, then tail-call func_0215F454 with the same arguments.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B82D0.c \
 *       --func func_021B82D0 --addr 0x021B82D0 --region ov016 --cc dsi/1.1p1 --thumb
 */
void func_021B82D0(unsigned int a, unsigned char *p, unsigned char c)
{
    *p = c;
    func_0215F454(a, p, c);
}


int func_021B82DC(int s)
{
    return func_0215F644(s);
}
