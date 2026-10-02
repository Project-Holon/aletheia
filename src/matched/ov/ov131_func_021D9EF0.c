/*
 * function: func_021D9EF0
 * address: 0x021D9EF0
 * packet: pkt_ov131_021D9EF0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021DA0AE follow the 446-byte body.
 * proof: i is a byte, i*24 <=6120. first/second remain full-word u32
 * results; unsigned address multiply/add preserve original modulo-2^32
 * lsl/add without invented selector bounds. 0204AB84 writes all nine words
 * before 0204B784 reads them; both Point halfwords are stored before use.
 * symbols:
 *   func_02041570 0x02041570 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020409E0 0x020409E0 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020410D0 0x020410D0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DB964 0x021DB964 thumb ov131
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   func_0204AB84 0x0204AB84 arm
 *   func_0204B784 0x0204B784 arm
 *   func_020275EC 0x020275EC thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B84C 0x0204B84C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {u32 w[9];} Rec;
typedef struct {s16 x,y;} Point;
extern void func_02041570(int,u16);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern u8 func_02045730(void *);
extern void func_020409B4(int);
extern void func_020409E0(u32,const void *,u32,u32);
extern void func_02040AE0(u32,void *,u32);
extern void func_02041B6C(int);
extern void func_020410D0(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_0204B3DC(void *,u32);
extern void func_021DB964(u8 *,void *,u8 *);
extern void *func_021D6064(u8 *);
extern u32 func_02017E88(void *,u32,u32);
extern void func_0204AB84(u32,Rec *);
extern void func_0204B784(void *,const Rec *);
extern u32 func_020275EC(u8);
extern void func_0204B6F4(void *,u32,u32);
extern void func_0204B404(void *,const Point *,u32);
extern void func_0204B84C(void *,u32);
void func_021D9EF0(u8 *a,u8 *p)
{
    Rec r1,r2;
    Point point;
    u8 i;
    void *cell;
    void *object;
    u32 first,second;
    func_02041570(4,0);
    for(i=8;i<=11;i++) {
        cell=*(void **)((p+i*4)+0x5c);
        func_02045334(cell);
        func_02045374(cell);
        func_020409B4(func_02045730(cell));
    }
    i=0;
    func_020409E0(6,*(u8 **)(p+0x44)+12,*(u32 *)(*(u8 **)(p+0x44)+8),0);
    func_02040AE0(6,*(u8 **)(p+0x44)+12,*(u32 *)(*(u8 **)(p+0x44)+8));
    func_02041B6C(6);
    func_020410D0(5,0,0,32,3,(u32)(*(u8 **)(p+0x54)+12),0,0,32,32);
    func_02041B6C(5);
    func_0204B3DC(*(void **)(p+0x90),0);
    func_0204B3DC(*(void **)(p+0x94),1);
    for(;i<p[0x2b];i++) func_021DB964(a,p,(p+0xb0)+i*24);
    object=func_021D6064(a);
    first=func_02017E88(object,174,0);
    second=func_02017E88(object,175,0);
    func_0204AB84(*(u32 *)(((u32)a+first*4u)+0x130u),&r1);
    func_0204B784(*(void **)(a+0x198),&r1);
    func_0204B6F4(*(void **)(a+0x198),func_020275EC(first),1);
    point.x=208;
    point.y=120;
    func_0204B404(*(void **)(a+0x198),&point,0);
    func_0204B3DC(*(void **)(a+0x198),1);
    func_0204B84C(*(void **)(a+0x198),0);
    if(first!=second) {
        func_0204AB84(*(u32 *)(((u32)a+second*4u)+0x130u),&r2);
        func_0204B784(*(void **)(a+0x19c),&r2);
        func_0204B6F4(*(void **)(a+0x19c),func_020275EC(second),1);
        point.x=240;
        point.y=120;
        func_0204B404(*(void **)(a+0x19c),&point,0);
        func_0204B3DC(*(void **)(a+0x19c),1);
        func_0204B84C(*(void **)(a+0x19c),0);
    } else func_0204B3DC(*(void **)(a+0x19c),0);
}
