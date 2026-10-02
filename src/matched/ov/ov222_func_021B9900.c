/*
 * function: func_021B9900
 * address: 0x021B9900
 * packet: pkt_ov222_021B9900
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero alignment bytes at 021B995E; no follower.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02049658(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_020498F4(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02049238(unsigned);
extern void func_020409B4(unsigned);
void func_021B9900(char*p)
{
    void *h;
    h=func_020490F4(0xca,*(u16*)p);
    func_02049B68(h,2,0,0,0x1e0,*(u16*)p);
    func_02049658(h,5,1,0,0,0,*(u16*)p);
    func_020498F4(h,7,1,0,0,0,*(u16*)p);
    func_02049238(h);
    func_020409B4(1);
}
