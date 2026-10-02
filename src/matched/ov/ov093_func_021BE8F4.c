/*
 * function: func_021BE8F4
 * address: 0x021BE8F4
 * packet: pkt_ov093_021BE8F4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *);
extern void func_021D75EC(int,u32);
extern void func_021D70F0(u8 *,int);
extern void func_021D7540(int);
void func_021BE8F4(u8 *p,u8 *a)
{
    func_021D74F8(3968);
    func_021D75EC(3,func_021D5440(a));
    func_021D70F0(p,7);
    func_021D7540(3971);
}
