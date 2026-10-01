/*
 * function: func_021D7CAC
 * address: 0x021D7CAC
 * packet: pkt_ov131_021D7CAC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * blocker: ARM9 0x020275EC has no code witness at call offsets +0xFA and
 *   +0x168; Ilias owns it. No ARM9 C is embedded. tu --suggest-split leaves
 *   this single function OUT. Extent tail 021D7E82..021D7E84 is zero padding.
 * lever: Declare the byte loop counter before the per-cell pointer to
 *   reproduce r4/r5 allocation; all other concrete bytes were already right.
 * proof: i is initialized u8 bounded by 10. first/second preserve the
 *   complete word returned by 02017E88. Address scaling/addition is u32
 *   modulo arithmetic, without invented selector bounds. 0204AB84's own
 *   matched body writes all nine words before 0204B784 consumes each Rec.
 *   Both Point halfwords are initialized before each outgoing pointer.
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_020410D0 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02017E88 0x02017E88 thumb
 *   func_0204AB84 0x0204AB84 arm
 *   func_0204B784 0x0204B784 arm
 *   func_020275EC 0x020275EC thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Rec { u32 w[9]; };
struct Point { s16 x,y; };
extern void *func_021D6064(u8 *);
extern void func_020410D0(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_02041B6C(u32);
extern void func_02040AE0(u32,void *,u32);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern u32 func_02045730(void *);
extern void func_020409B4(u32);
extern u32 func_02017E88(void *,u32,u32);
extern void func_0204AB84(u32,struct Rec *);
extern void func_0204B784(void *,const struct Rec *);
extern u32 func_020275EC(u8);
extern void func_0204B6F4(void *,u32,u32);
extern void func_0204B404(void *,const struct Point *,u16);
extern void func_0204B3DC(void *,int);
extern void func_0204B84C(void *,u32);
extern void func_0204B878(void *,u16);
void func_021D7CAC(u8 *a,u8 *p)
{
    struct Rec r1,r2;
    struct Point point;
    u8 i;
    void *object;
    void *cell;
    u32 first,second;
    object=func_021D6064(a);
    if(*(u32 *)(a+0x38)==0) func_020410D0(2,0,0,32,24,*(u32 *)(p+0x4c)+12,0,0,32,32);
    else func_020410D0(2,0,0,32,24,*(u32 *)(p+0x54)+12,0,0,32,32);
    func_02041B6C(2);
    func_02040AE0(6,*(u8 **)(p+0x5c)+12,*(u32 *)(*(u8 **)(p+0x5c)+8));
    func_02041B6C(6);
    func_020410D0(5,0,0,32,3,*(u32 *)(p+0x64)+12,0,0,32,32);
    func_02041B6C(5);
    for(i=0;i<10;i++) {
        cell=*(void **)((p+i*4)+0xc);
        func_02045334(cell);
        func_02045374(cell);
        func_020409B4(func_02045730(cell));
    }
    cell=*(void **)(p+0x34);
    func_02045334(cell);
    func_02045374(cell);
    func_020409B4(func_02045730(cell));
    if(*(u32 *)(a+0x38)==0) {
        first=func_02017E88(object,174,0);
        second=func_02017E88(object,175,0);
        func_0204AB84(*(u32 *)((u32)a+first*4u+0x130u),&r1);
        func_0204B784(*(void **)(a+0x198),&r1);
        func_0204B6F4(*(void **)(a+0x198),func_020275EC(first),1);
        point.x=96;
        point.y=48;
        func_0204B404(*(void **)(a+0x198),&point,0);
        func_0204B3DC(*(void **)(a+0x198),1);
        func_0204B84C(*(void **)(a+0x198),1);
        if(first!=second) {
            func_0204AB84(*(u32 *)((u32)a+second*4u+0x130u),&r2);
            func_0204B784(*(void **)(a+0x19c),&r2);
            func_0204B6F4(*(void **)(a+0x19c),func_020275EC(second),1);
            point.x=130;
            point.y=48;
            func_0204B404(*(void **)(a+0x19c),&point,0);
            func_0204B3DC(*(void **)(a+0x19c),1);
            func_0204B84C(*(void **)(a+0x19c),1);
        } else func_0204B3DC(*(void **)(a+0x19c),0);
    } else {
        func_0204B3DC(*(void **)(a+0x198),0);
        func_0204B3DC(*(void **)(a+0x19c),0);
    }
    func_0204B878(*(void **)(a+0x178),3);
}
