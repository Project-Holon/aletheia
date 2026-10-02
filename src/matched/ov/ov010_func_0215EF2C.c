/*
 * function: func_0215EF2C
 * address: 0x0215EF2C
 * packet: pkt_ov010_0215EF2C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Enum constants preserve the zero-first return arm; int constants fold to the opposite polarity.
 * symbols:
 *   func_0215F104 0x0215F104 thumb ov010
 */
extern int func_0215F104(void *, int);
typedef enum { FALSE, TRUE } Bool;
int func_0215EF2C(void *p)
{
    return func_0215F104(p, 9) != 0 ? FALSE : TRUE;
}
