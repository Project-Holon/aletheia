/*
 * function: func_021B7908
 * address: 0x021B7908
 * packet: pkt_ov102_021B7908
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_0203F8F4 0x0203F8F4 arm
 * func_02045088 0x02045088 arm
 * func_0203FC28 0x0203FC28 arm
 * func_0203FCA0 0x0203FCA0 arm
 * func_020414AC 0x020414AC arm
 * func_02040588 0x02040588 arm
 * func_020490F4 0x020490F4 arm
 * func_02049B68 0x02049B68 arm
 * func_02049658 0x02049658 arm
 * func_020498F4 0x020498F4 arm
 * func_02040C14 0x02040C14 arm
 * func_02049740 0x02049740 arm
 * func_02049238 0x02049238 arm
 * func_020056A0 0x020056A0 thumb
 * func_021B7AAC 0x021B7AAC thumb ov102
 * d_021B8AC4 0x021B8AC4 data a4
 * d_021B8AEC 0x021B8AEC data a4
 * d_021B8B5C 0x021B8B5C data a4
 * d_021B8B0C 0x021B8B0C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 d_021B8AC4[], d_021B8AEC[], d_021B8B0C[];
extern const u32 d_021B8B5C[][8];
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(void *);
extern void func_0203FCA0(u32,const void *,u32);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern void func_02049658(void *,u32,u32,u32,u32,u32,u16);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02040C14(u32,u32,u32,u32);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_021B7AAC(void);
extern u32 func_020056A0(void (*)(void),void *,u32);
void func_021B7908(u32 *p,u16 heap)
{
    int i;
    u32 layer;
    void *arc;
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28(d_021B8AC4);
    for(i=0;i<8;i++) {
        layer=d_021B8AEC[i];
        func_0203FCA0((u8)layer,d_021B8B5C[i],(u8)d_021B8B0C[i]);
        func_020414AC(layer);
        func_02040588(layer,1);
    }
    arc=func_020490F4(94,heap);
    func_02049B68(arc,1,0,0,0,heap);
    func_02049B68(arc,1,4,0,0,heap);
    func_02049658(arc,0,3,0,0,0,heap);
    func_02049658(arc,0,6,0,0,0,heap);
    func_02049658(arc,48,4,0,0,0,heap);
    func_02049658(arc,42,2,0,0,0,heap);
    func_020498F4(arc,4,3,0,0,0,heap);
    func_020498F4(arc,4,6,0,0,0,heap);
    func_020498F4(arc,44,4,0,0,0,heap);
    func_020498F4(arc,43,2,0,0,0,heap);
    func_02040C14(5,0,1,0);
    p[0]=func_02049740(arc,49,5,0,0,heap);
    func_02049238(arc);
    p[1]=func_020056A0(func_021B7AAC,p,0);
}
