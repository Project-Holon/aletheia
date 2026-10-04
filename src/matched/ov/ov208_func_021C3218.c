/*
 * function: func_021C3218
 * address: 0x021C3218
 * packet: pkt_ov208_021C3218
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049B90 0x02049B90 arm
 *   func_020450F0 0x020450F0 arm
 *   func_021C32FC 0x021C32FC thumb ov208
 *   func_02045334 0x02045334 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_021C32FC(u16 *,u8 *,int);
struct Descriptor;
extern void func_02045334(struct Descriptor *);
void func_021C3218(u16 *heap,u8 *p,int key)
{
    func_02049B90(23,5,4,0,0,32,*heap);
    *(u32 *)(p+12)=func_020450F0(6,10,5,12,4,0,1);
    *(u32 *)(p+16)=0;
    func_021C32FC(heap,p,key);
    func_02045334((struct Descriptor *)*(u32 *)(p+12));
}
