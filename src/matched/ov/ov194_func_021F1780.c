/*
 * function: func_021F1780
 * address: 0x021F1780
 * packet: pkt_ov194_021F1780
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two trailing zero alignment bytes at 021F1876; existing func_021F1878 begins immediately afterward.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049238 0x02049238 arm
 *   func_02040C14 0x02040C14 arm
 *   func_0201F5BC 0x0201F5BC thumb
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *,unsigned,unsigned,unsigned,unsigned,u16);
extern unsigned int func_02049658(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
typedef unsigned int   u32;
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049238(void *);
extern void func_02040C14(unsigned,unsigned,unsigned,unsigned);
extern void func_0201F5BC(unsigned,unsigned,unsigned,unsigned,u16);
void func_021F1780(int unused,u16 heap)
{
    void *p;
    p=func_020490F4(118,heap);
    func_02049B68(p,2,4,0,0,heap);
    func_02049658(p,1,5,0,0,0,heap);
    func_020498F4(p,3,5,0,0,0,heap);
    func_02049B68(p,2,0,0,0,heap);
    func_02049BDC(p,2,0,64,96,32,heap);
    func_02049BDC(p,2,0,64,128,32,heap);
    func_02049658(p,1,0,0,0,0,heap);
    func_020498F4(p,0,0,0,0,0,heap);
    func_020498F4(p,4,2,0,0,0,heap);
    func_02049238(p);
    p=func_020490F4(23,heap);
    func_02049B68(p,6,4,480,32,heap);
    func_02049238(p);
    func_02040C14(4,0,1,0);
    func_0201F5BC(4,1,14,0,heap);
}
