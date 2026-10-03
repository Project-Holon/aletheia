/*
 * function: func_021D5128
 * address: 0x021D5128
 * packet: pkt_ov123_021D5128
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: sole callback blocker ov123 021D5120 filed and verified before
 * caller recheck; ABS32 at +01E0 now resolves through its matched shard.
 * volatile: display register 04001000 read/write at 021D5198/021D519C.
 * interface: 0203159C leaves its allocation result in r0, which is used
 * throughout this caller; its legacy matched definition is void.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D534 0x0207D534 arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_02030734 0x02030734 arm
 *   func_0203101C 0x0203101C arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0203D34C 0x0203D34C arm
 *   func_020355D8 0x020355D8 arm
 *   func_021D5120 0x021D5120 thumb ov123
 *   func_021D424C 0x021D424C thumb ov123
 *   func_021D4884 0x021D4884 thumb ov123
 *   func_021D4A04 0x021D4A04 thumb ov123
 *   func_021D4244 0x021D4244 thumb ov123
 *   d_021DA9F0 0x021DA9F0 data a4
 *   d_021DA680 0x021DA680 data a4
 *   d_021DA658 0x021DA658 data a4
 *   d_021DAA20 0x021DAA20 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Config { u32 words[4]; };
extern const struct Config d_021DA680;
extern const u32 d_021DA9F0[], d_021DA658[];
extern const char d_021DAA20[];
extern void func_0203064C(void *,u32,u32);
extern char *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,u8,u32);
struct Bank;
struct R;
struct Tcbl;
extern void func_0204363C(u32 swap);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const void *);
extern void func_0203FC28(const void *);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204A48C(const void *,const void *,u32);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_020056A0(void *,void *,int);
extern void func_021D5120(void);
extern void func_021D424C(char *);
extern void func_021D4884(char *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32,u32,u32,u32);
extern u32 func_0201C440(void *);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_0202208C(void *,u32,u32,u16,u32,u32,u32);
extern void func_021D4244(char *,void *,int);
extern void func_021D4A04(char *);
extern void func_0203D34C(u32,u32);
extern void func_020355D8(u8 v);
int func_021D5128(void *a,int b,u8 *q)
{
    char *p;
    int bright;
    int color;
    struct Config cfg;
    func_0203064C((void *)1,31,0x18000);
    p=func_0203159C(a,0x2b4,31);
    func_02082BCC(p,0,0x2b4);
    *(u16 *)(p+0xc)=31;
    *(u32 *)(p+0x260)=*(u32 *)(q+4); *(u32 *)(p+0x264)=*(u32 *)q;
    func_0204363C(1);
    if(*(int *)(q+0x2c8)) bright=16; else bright=-16;
    func_0207D534((void *)0x0400006c,bright); func_0207D534((void *)0x0400106c,bright);
    *(volatile u32 *)0x04001000|=0x10000; func_0207D46C();
    func_0203F8F4(*(u16 *)(p+0xc)); func_02045088(*(u16 *)(p+0xc)); func_0201DD60();
    func_020433E0(d_021DA9F0);
    cfg=d_021DA680; func_0203FC28(&cfg);
    func_02043534(0); func_020435F4(0);
    func_0204A48C(d_021DA658,d_021DA9F0,*(u16 *)(p+0xc));
    *(void **)(p+0x2ac)=func_0204B100(40,0,*(u16 *)(p+0xc));
    *(void **)(p+0x2b0)=func_020056A0(func_021D5120,p,0);
    func_021D424C(p); func_021D4884(p);
    *(void **)(p+0x280)=func_02030734(*(u16 *)(p+0xc),0x200,0,d_021DAA20,0x5a6);
    *(void **)(p+0x284)=func_02030734(*(u16 *)(p+0xc),0x200,0,d_021DAA20,0x5a7);
    *(void **)(p+0x230)=func_0203101C(*(u16 *)(p+0xc),*(u16 *)(p+0xc),3,0);
    *(u32 *)(p+0x22c)=func_02028590(15,0,1,*(u16 *)(p+0xc));
    *(u32 *)(p+0x234)=func_0201C440((void *)(u32)*(u16 *)(p+0xc));
    *(void **)(p+0x254)=func_02027F60(5,9,*(u32 *)(p+0x30),*(u32 *)(p+0x234),*(u16 *)(p+0xc));
    func_0207D63C((void *)0x04001050,4,1,15,4);
    color=0; if(*(int *)(q+0x2c8)) color=0x7fff;
    func_0202208C(0,1,1,color,6,1,*(u16 *)(p+0xc));
    *(u32 *)(q+0x2c8)=0; func_020435F4(31);
    func_021D4244(p,func_021D4A04,0x5bf);
    *(void **)(p+0x258)=q;
    func_0203D34C(0,*(u16 *)(p+0xc)); func_020355D8(1);
    return 1;
}
