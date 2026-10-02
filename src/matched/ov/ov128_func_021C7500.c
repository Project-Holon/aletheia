/*
 * function: func_021C7500
 * address: 0x021C7500
 * packet: pkt_ov128_021C7500
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C6B38 0x021C6B38 thumb ov128
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 */
typedef unsigned char u8;
extern void func_021C6B38(u8 *);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern void func_02041B6C(unsigned);
extern void func_020456F8(void *);
extern u8 func_02045730(void *);
void func_021C7500(u8 *p,u8 *q)
{
    void *obj;
    func_021C6B38(q);
    func_02041300(2,0,0,0,32,24,16);
    func_02041B6C(2);
    func_02041300(3,0,0,0,32,24,16);
    func_02041B6C(3);
    obj=*(void **)(p+12);
    func_020456F8(obj);
    func_02041B6C(func_02045730(obj));
}
