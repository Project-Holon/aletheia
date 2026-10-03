/*
 * function: func_021D98C0
 * address: 0x021D98C0
 * packet: pkt_ov121_021D98C0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
extern void func_0204B084(void *),func_0204B1CC(void *),func_0204A5AC(void),func_02082BCC(void *,int,unsigned);
void func_021D98C0(u8 *p) {
    func_0204B084(*(void **)(p+4));
    func_0204B1CC(*(void **)p);
    func_0204A5AC();
    func_02082BCC(p,0,8);
}
