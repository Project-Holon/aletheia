/*
 * function: func_021DDCF8
 * address: 0x021DDCF8
 * packet: pkt_ov121_021DDCF8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_021DC064 0x021DC064 thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_021DC064(void *);
extern void *func_020490F4(unsigned,u16);
extern void func_02049BDC(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_020413B0(u8,u8,u8,u8,u8,u8);
extern void func_020409B4(u8);
extern void func_02049238(void *);
void func_021DDCF8(unsigned *p,void *context,u16 heap)
{
    int which=0;
    u16 id;
    void *arc;
    if (p[0]>=4) which=4;
    id=func_021DC064(context);
    arc=func_020490F4(34,heap);
    func_02049BDC(arc,4,which,id*32,p[2]*32,32,heap);
    func_020413B0(p[0],0,0,34,24,p[2]);
    func_020409B4(p[0]);
    func_02049238(arc);
}
