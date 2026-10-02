/*
 * function: func_0217FBD0
 * address: 0x0217FBD0
 * packet: pkt_ov019_0217FBD0
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020470D0 0x020470D0 arm
 *   func_02046EFC 0x02046EFC arm
 */

typedef unsigned int u32;
struct Tagged;
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
void func_0217FBD0(char *p)
{
    func_020470D0(*(u32 **)(p+0xc8));
    func_020470D0(*(u32 **)(p+0xcc));
    func_02046EFC(*(struct Tagged **)(p+0xc8));
    func_02046EFC(*(struct Tagged **)(p+0xcc));
    *(u32 *)(p+0xc8)=0;
    *(u32 *)(p+0xcc)=0;
}
