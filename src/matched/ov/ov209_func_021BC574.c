/*
 * function: func_021BC574
 * address: 0x021BC574
 * packet: pkt_ov209_021BC574
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Compiled extent ends at 021BC6C2; the remaining halfword is alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027628 0x02027628 thumb
 *   func_02027624 0x02027624 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02049740 0x02049740 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02049B40 0x02049B40 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_020275E4(void);
extern u32 func_02027628(void);
extern u32 func_02027624(void);
extern u32 func_0202762C(void);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
void func_021BC574(void)
{
    void *arc;
    arc=func_020490F4(159,107);
    func_02049B68(arc,48,0,0,128,107);
    func_02049B68(arc,49,4,0,160,107);
    func_02049658(arc,58,2,0,0,0,107);
    func_02049658(arc,56,3,0,0,0,107);
    func_02049658(arc,59,6,0,0,0,107);
    func_02049658(arc,57,7,0,0,0,107);
    func_020498F4(arc,62,3,0,0,0,107);
    func_020498F4(arc,69,5,0,0,0,107);
    func_020498F4(arc,63,7,0,0,0,107);
    ARC_TOOL_DeleteHandle(arc);
    arc=func_020490F4(func_020275E4(),107);
    func_02049740(arc,func_02027628(),1,0,0,107);
    func_02049B68(arc,func_02027624(),0,448,32,107);
    func_020498F4(arc,func_0202762C(),1,0,0,0,107);
    func_020413B0(1,0,21,32,3,14);
    func_02041B6C(1);
    ARC_TOOL_DeleteHandle(arc);
    func_02049B40(23,5,0,480,32,107);
    func_02049B40(23,5,4,480,32,107);
}
