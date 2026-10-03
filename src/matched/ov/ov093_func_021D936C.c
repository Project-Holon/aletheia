/*
 * function: func_021D936C
 * address: 0x021D936C
 * packet: pkt_ov093_021D936C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern int func_021D775C(int);
typedef unsigned char  u8;
extern int func_021C8288(u8 *p);
extern int func_021D7D6C(int);
extern int func_021D76BC(int, unsigned int);
void func_021D936C(int a, void *b, int c, int *d)
{
    int v;
    if (c == func_021D775C(4) && func_021C8288(b) == 1) {
        v = func_021D775C(0x1d);
        if (func_021D7D6C(v) || v == 0xe) *d = func_021D76BC(0x41, 1);
    }
}
