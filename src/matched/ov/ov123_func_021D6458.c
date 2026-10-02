/*
 * function: func_021D6458
 * address: 0x021D6458
 * packet: pkt_ov123_021D6458
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DA738 0x021DA738 data a4
 *   d_021DA748 0x021DA748 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Pair { int a,b; };
struct Point { s16 x,y; u16 f4; u8 f6,f7; };
extern const struct Pair d_021DA738, d_021DA748;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_0201BA68(int);
extern void *func_0204A6C8(void *, u32, u32, u32, u16);
extern void *func_0204B294(u32, void *, u32, u32, struct Point *, u16, u16);
extern void func_0204B92C(void *, u32);
extern void func_0204B3DC(void *, u32);
extern u32 func_0201BBE8(int);
extern void func_0204B6F4(void *, u32, u32);
extern void func_02049238(void *);
void func_021D6458(u8 *p, int n, int i)
{
    struct Pair a = d_021DA738;
    struct Pair b = d_021DA748;
    struct Point pt;
    void *h;
    h = func_020490F4(7, *(u16 *)(p+0x43c4));
    *(void **)(p+0x40) = func_0204A6C8(h,func_0201BA68(n),0,2,*(u16 *)(p+0x43c4));
    if(i==0) { pt.x=a.b; pt.y=b.b; }
    else { pt.x=a.a; pt.y=b.a; }
    pt.f4=0; pt.f6=3; pt.f7=1;
    *(void **)(p+0xa8) = func_0204B294(*(u32 *)(p+0xc),*(void **)(p+0x40),*(u32 *)(p+0x28),*(u32 *)(p+0x5c),&pt,(u16)i,*(u16 *)(p+0x43c4));
    func_0204B92C(*(void **)(p+0xa8),0);
    func_0204B3DC(*(void **)(p+0xa8),1);
    func_0204B6F4(*(void **)(p+0xa8),func_0201BBE8(n),1);
    func_02049238(h);
}
