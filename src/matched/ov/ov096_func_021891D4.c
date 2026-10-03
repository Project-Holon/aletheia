/*
 * function: func_021891D4
 * address: 0x021891D4
 * packet: pkt_ov096_021891D4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021891F4 0x021891F4 thumb ov096
 */
typedef struct Obj Obj;
extern int func_021891F4(int, Obj *, int);
int func_021891D4(int a, Obj * b)
{
    func_021891F4(a, b, 2);
    return *(int *)((unsigned int)b + 0xc4);
}
