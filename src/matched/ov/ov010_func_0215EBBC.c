/*
 * function: func_0215EBBC
 * address: 0x0215EBBC
 * packet: pkt_ov010_0215EBBC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215F104 0x0215F104 thumb ov010
 */
extern int func_0215F104(int a0, int a1);
typedef enum { B_FALSE, B_TRUE } Bool;
int func_0215EBBC(void *p)
{
    return func_0215F104((int)p, 3) != 0 ? B_FALSE : B_TRUE;
}
