/*
 * function: func_021D6CD8
 * address: 0x021D6CD8
 * packet: pkt_ov123_021D6CD8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: narrow the helper result through a named u16 local before the call.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Point { s16 x,y; u16 f4; u8 f6,f7; };
extern void *func_020490F4(unsigned int id, u16 heap);
struct Obj;
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern void *func_0204A6C8(void *,u32,u32,u32,u16);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02049238(void *);
void func_021D6CD8(u8 *p)
{
    struct Point pt;
    void *h;
    u16 n;
    h=func_020490F4(7,*(u16 *)(p+0x43c4));
    n=func_0201BABC(1,0,0,0);
    *(void **)(p+0x44)=func_0204A6C8(h,n,0,0,*(u16 *)(p+0x43c4));
    pt.x=133; pt.y=128; pt.f4=0; pt.f6=3; pt.f7=2;
    *(void **)(p+0xb4)=func_0204B294((void *)*(u32 *)(p+0xc),(u32)*(void **)(p+0x44),*(u32 *)(p+0x28),*(u32 *)(p+0x5c),&pt,0,*(u16 *)(p+0x43c4));
    func_0204B92C(*(void **)(p+0xb4),0);
    func_0204B3DC(*(void **)(p+0xb4),0);
    func_02049238(h);
}
