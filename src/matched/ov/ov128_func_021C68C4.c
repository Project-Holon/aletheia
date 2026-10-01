/*
 * function: func_021C68C4
 * address: 0x021C68C4
 * packet: pkt_ov128_021C68C4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204B084 0x0204B084 arm
 *   func_0204A5AC 0x0204A5AC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern void func_0204B1CC(u32);
extern void func_0204B084(u32);
extern void func_0204A5AC(void);
void func_021C68C4(char *p)
{
    unsigned i;
    for(i=0;i<2;i++) func_0204A8D4(*(u32 *)(p+i*4+0x144));
    for(i=0;i<2;i++) func_0204ADA4(*(u32 *)(p+i*4+0x14c));
    for(i=0;i<2;i++) func_0204AFD8(*(u32 *)(p+i*4+0x154));
    func_0204B1CC(*(u32 *)(p+0x13c));
    func_0204B084(*(u32 *)(p+0x140));
    func_0204B1CC(*(u32 *)(p+0x138));
    func_0204A5AC();
}
