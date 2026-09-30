/*
 * function: func_021D6D5C
 * address: 0x021D6D5C
 * packet: pkt_ov123_021D6D5C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Point { s16 x,y; u16 f4; u8 f6,f7; };
extern void *func_020490F4(u32,u32);
extern u32 func_02020E60(int,int);
extern void *func_0204AC18(void *,u32,u32,u32,u32,u32,u16);
extern void *func_0204A6C8(void *,u32,u32,u32,u16);
extern void *func_0204AF28(void *,u32,u32,u16);
extern void func_02049238(void *);
extern void *func_0204B294(u32,void *,u32,u32,struct Point *,u16,u16);
extern void func_0204B92C(void *,u32);
extern void func_0204B3DC(void *,u32);
void func_021D6D5C(u8 *p)
{
    struct Point pt;
    void *h;
    h=func_020490F4(25,*(u16 *)(p+0x43c4));
    *(void **)(p+0x34)=func_0204AC18(h,func_02020E60(1,2),0,256,0,1,*(u16 *)(p+0x43c4));
    *(void **)(p+0x50)=func_0204A6C8(h,func_02020E60(1,1),0,0,*(u16 *)(p+0x43c4));
    *(void **)(p+0x6c)=func_0204AF28(h,1,0,*(u16 *)(p+0x43c4));
    func_02049238(h);
    pt.x=156; pt.y=28; pt.f4=0; pt.f6=0; pt.f7=2;
    *(void **)(p+0xb8)=func_0204B294(*(u32 *)(p+0xc),*(void **)(p+0x50),*(u32 *)(p+0x34),*(u32 *)(p+0x6c),&pt,0,*(u16 *)(p+0x43c4));
    func_0204B92C(*(void **)(p+0xb8),0);
    func_0204B3DC(*(void **)(p+0xb8),0);
}
