/*
 * function: func_021C5D68
 * address: 0x021C5D68
 * packet: pkt_ov136_021C5D68
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02008FA4 0x02008FA4 thumb
 *   func_02049658 0x02049658 arm
 *   func_02049B68 0x02049B68 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_020490F4(u32,u32);
extern u8 *func_02008FA4(void *);
extern void func_02049658(void *,void *,u32,u32,u32,u32,u32);
extern void func_02049B68(void *,void *,u32,u32,u32,u32);
extern void func_020498F4(void *,void *,u32,u32,u32,u32,u32);
extern void func_02049238(void *);
void func_021C5D68(u8 *p)
{
    void *h;
    u8 *q;
    h = func_020490F4(155,102);
    q = func_02008FA4(*(void **)(*(u8 **)(p+8) + 0x298 + p[31]*4));
    func_02049658(h,q+12,5,0,0,1,102);
    func_02049B68(h,q,4,0,64,102);
    func_020498F4(h,q+24,5,0,0,1,102);
    func_02049238(h);
}
