/*
 * function: func_021D614C
 * address: 0x021D614C
 * packet: pkt_ov123_021D614C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: 02049990 stack argument 4 is u16 here: the original explicitly
 * truncates it at 021D6184/021D6186 and the three later call sites.
 * interface: 02049F78 forwards its third word unchanged to 02062A98's
 * void **out; original 021D61C2 supplies p+0x18, so the extern names it.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049F78 0x02049F78 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021D6404 0x021D6404 thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(void *,u32);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern u32 func_02049990(void *,u32,u32,u32,u16,u32,u32,u16);
extern void *func_02049F78(void *,int,void **,u16);
extern void *func_0204A6C8(void *,u32,u32,u32,u16);
extern void *func_0204AC18(void *,u32,u32,u32,u32,u32,u16);
extern void *func_0204AF28(void *,u32,u32,u16);
extern void func_02049238(void *);
extern void func_021D6404(u8 *);
void func_021D614C(u8 *p)
{
    void *h;
    h=func_020490F4((void *)143,*(u16 *)(p+0x43c4));
    func_02049B68(h,2,4,0,0,*(u16 *)(p+0x43c4));
    *(u32 *)p=func_02049740(h,8,4,0,0,*(u16 *)(p+0x43c4));
    func_02049990(h,21,4,0,*(u32 *)p,0,0,*(u16 *)(p+0x43c4));
    func_02049990(h,24,7,0,*(u32 *)(p+4),0,0,*(u16 *)(p+0x43c4));
    *(void **)(p+0x1c)=func_02049F78(h,2,(void **)(p+0x18),*(u16 *)(p+0x43c4));
    func_02049B68(h,2,0,0,0,*(u16 *)(p+0x43c4));
    *(u32 *)(p+4)=func_02049740(h,8,0,0,0,*(u16 *)(p+0x43c4));
    func_02049990(h,23,0,0,*(u32 *)(p+4),0,0,*(u16 *)(p+0x43c4));
    func_02049990(h,24,1,0,*(u32 *)(p+4),0,0,*(u16 *)(p+0x43c4));
    *(void **)(p+0x38)=func_0204A6C8(h,9,0,2,*(u16 *)(p+0x43c4));
    *(void **)(p+0x20)=func_0204AC18(h,3,2,96,0,4,*(u16 *)(p+0x43c4));
    *(void **)(p+0x54)=func_0204AF28(h,12,25,*(u16 *)(p+0x43c4));
    *(void **)(p+0x3c)=func_0204A6C8(h,10,0,2,*(u16 *)(p+0x43c4));
    *(void **)(p+0x24)=func_0204AC18(h,4,2,224,0,0,*(u16 *)(p+0x43c4));
    *(void **)(p+0x58)=func_0204AF28(h,13,26,*(u16 *)(p+0x43c4));
    func_021D6404(p); func_02049238(h);
}
