/*
 * function: func_021DFF70
 * address: 0x021DFF70
 * packet: pkt_ov137_021DFF70
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0203D34C 0x0203D34C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(u32,u32,u32,u32,u16);
extern int func_0204ABF0(u32,u32,u32,u32,u16);
extern int func_0204AF28(u32,u32,u32,u32);
extern void func_02049238(u32);
extern void func_0203D34C(int,u16);
void func_021DFF70(u8 *p)
{
    void *arc;
    arc = func_020490F4(184,114);
    *(int *)(p+3436) = func_0204A6C8(arc,6,0,0,114);
    *(int *)(p+3440) = func_0204ABF0(arc,0,0,0,114);
    *(int *)(p+3444) = func_0204AF28(arc,10,14,114);
    func_02049238(arc);
    func_0203D34C(1,114);
}
