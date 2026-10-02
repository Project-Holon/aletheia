/*
 * function: func_0217DA18
 * address: 0x0217DA18
 * packet: pkt_ov018_0217DA18
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
typedef unsigned int u32;
extern void func_020307B0(void *);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
void func_0217DA18(u32 *p)
{
    func_020307B0((void *)p[0xd0 / 4]);
    func_020307B0((void *)p[0xc8 / 4]);
    func_0204ADA4(p[3]);
    func_0204ADA4(p[2]);
    func_0204A8D4(p[1]);
    func_0204A8D4(p[5]);
    func_0204AFD8(p[4]);
    func_0204AFD8(p[6]);
}
