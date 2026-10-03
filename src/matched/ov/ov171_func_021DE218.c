/*
 * function: func_021DE218
 * address: 0x021DE218
 * packet: pkt_ov171_021DE218
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204ADA4 0x0204ADA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0204ADA4(u32);
void func_021DE218(char *p,int i)
{
    if(*(u32 *)((u32)p+0xbe8+(u32)i*4)!=(u32)-1) {
        func_0204ADA4(*(u32 *)((u32)p+0xbe8+(u32)i*4));
        *(u32 *)((u32)p+0xbe8+(u32)i*4)=(u32)-1;
    }
}
