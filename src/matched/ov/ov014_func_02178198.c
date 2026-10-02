/*
 * function: func_02178198
 * address: 0x02178198
 * packet: pkt_ov014_02178198
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02178138 0x02178138 thumb ov014
 *   func_0217814C 0x0217814C thumb ov014
 *   func_021781BC 0x021781BC thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02178138(int);
extern void func_0217814C(int);
extern int func_021781BC(void);
void func_02178198(void *arg)
{
    int result = ((u16 *)arg)[1];
    if (result != 0) {
        func_0217814C(result);
        func_02178138(9);
        return;
    }
    if (func_021781BC() == 0)
        func_02178138(9);
}
