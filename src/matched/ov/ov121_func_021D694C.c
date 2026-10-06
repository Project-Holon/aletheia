/*
 * function: func_021D694C
 * address: 0x021D694C
 * packet: pkt_ov121_021D694C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02040B94 0x02040B94 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u16 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
typedef unsigned char  u8;
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
void func_021D694C(u16 *p,int mode)
{
    u16 heap=(*p&0x7fff)|0x8000;
    void *arc;
    switch (mode) {
    case 0:
        arc=func_020490F4(34,heap);
        func_02049B68(arc,6,0,0,0,heap);
        func_02049B68(arc,6,4,0,128,heap);
        func_02049B68(arc,7,4,32,32,heap);
        func_02049658(arc,15,3,0,0,0,heap);
        func_02049658(arc,15,7,0,0,0,heap);
        func_020498F4(arc,31,3,0,0,0,heap);
        func_020498F4(arc,31,7,0,0,0,heap);
        func_02049238(arc);
        arc=func_020490F4(23,heap);
        func_02049B68(arc,5,0,480,32,heap);
        func_02049B68(arc,5,4,480,32,heap);
        func_02049238(arc);
        func_0201F5BC(1,10,14,0,heap);
        func_0201F5BC(0,1,13,0,heap);
        func_02040B94(1,32,0,heap);
        func_02040B94(0,32,0,heap);
        break;
    case 1:
        arc=func_020490F4(34,heap);
        func_02049B68(arc,6,4,0,192,heap);
        func_02049658(arc,15,6,0,0,0,heap);
        func_020498F4(arc,21,6,0,0,0,heap);
        func_02049238(arc);
        break;
    case 2:
        arc=func_020490F4(34,heap);
        func_02049658(arc,11,2,0,0,0,heap);
        func_020498F4(arc,28,2,0,0,0,heap);
        func_02049238(arc);
        break;
    }
}
