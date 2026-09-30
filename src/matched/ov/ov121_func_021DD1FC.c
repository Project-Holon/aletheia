/*
 * function: func_021DD1FC
 * address: 0x021DD1FC
 * packet: pkt_ov121_021DD1FC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_021DA280 0x021DA280 thumb ov121
 *   func_020307B0 0x020307B0 arm
 */
extern void func_0204B3B4(void *);
extern void func_0204A8D4(void *);
extern void func_0204AFD8(void *);
extern void func_0204ADA4(void *);
extern void func_021DA280(void *);
extern void func_020307B0(void *);
void func_021DD1FC(void **p)
{
    func_0204B3B4(p[8]);
    func_0204A8D4(p[5]);
    func_0204AFD8(p[6]);
    func_0204ADA4(p[4]);
    func_0204B3B4(p[7]);
    func_0204A8D4(p[2]);
    func_0204AFD8(p[3]);
    func_0204ADA4(p[1]);
    func_021DA280(p[0]);
    func_020307B0(p);
}
