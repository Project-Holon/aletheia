/*
 * function: func_0215EC80
 * address: 0x0215EC80
 * packet: pkt_ov010_0215EC80
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215F104 0x0215F104 thumb ov010
 */
extern int func_0215F104(void *, int);
typedef enum { B_FALSE, B_TRUE } Bool;
int func_0215EC80(void *p)
{
    return func_0215F104(p, 5) != 0 ? B_FALSE : B_TRUE;
}
