/*
 * function: func_021DDFE8
 * address: 0x021DDFE8
 * packet: pkt_ov171_021DDFE8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE114 0x021DE114 thumb ov171
 *   func_021DE144 0x021DE144 thumb ov171
 *   func_021DE2D4 0x021DE2D4 thumb ov171
 *   func_021DE80C 0x021DE80C thumb ov171
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021DE114(u8 *);
extern void func_021DE144(char *);
extern void func_021DE2D4(char *);
extern void func_021DE80C(char *);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
void func_021DDFE8(u8 *p)
{
    func_021DE114(p);
    func_021DE144((char *)p);
    func_021DE2D4((char *)p);
    func_021DE80C((char *)p);
    func_020434DC(16,1);
    func_02043598(16,1);
}
