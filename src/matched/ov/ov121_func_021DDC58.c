/*
 * function: func_021DDC58
 * address: 0x021DDC58
 * packet: pkt_ov121_021DDC58
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * lever: initialize resource after the first guard; const source orders loads before stack argument stores.
 * symbols:
 *   func_021DC064 0x021DC064 thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021DC064(void *p);
extern void *func_020490F4(unsigned int id, u16 heap);
typedef unsigned int   u32;
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
extern void func_02049238(void *);
void func_021DDC58(const unsigned *p,void *context,u16 heap)
{
    int which=0;
    int resource;
    u16 id;
    void *arc;
    if (p[0]>=4) which=4;
    resource=26;
    if (p[0]<=3) resource=27;
    id=func_021DC064(context);
    arc=func_020490F4(34,heap);
    func_02049BDC(arc,4,which,id*32,p[2]*32,32,heap);
    func_02049658(arc,13,p[0],0,0,0,heap);
    func_020498F4(arc,(u16)resource,p[0],0,0,0,heap);
    func_020413B0((u8)p[0],0,0,34,24,p[2]);
    func_020409B4((u8)p[0]);
    func_02049238(arc);
}
