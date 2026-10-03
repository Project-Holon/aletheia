/*
 * function: func_021B9CE4
 * address: 0x021B9CE4
 * packet: pkt_ov110_021B9CE4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware DISPCNT words re-read at 9CF6/9D00 and 9D14/9D1C;
 *   BLDCNT halfwords at 04000050 and 04001050 are reset at 9CEC/9CF2.
 * abi: F7C4 live return is the bit test from its tail target ARM9 24158.
 * symbols:
 *   func_0204335C 0x0204335C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_021BA070 0x021BA070 thumb ov110
 *   func_021B9F34 0x021B9F34 thumb ov110
 *   func_021BBC5C 0x021BBC5C thumb ov110
 *   func_021BBD60 0x021BBD60 thumb ov110
 *   func_021BB290 0x021BB290 thumb ov110
 *   func_021BB328 0x021BB328 thumb ov110
 *   func_021BF844 0x021BF844 thumb ov110
 *   func_021BF8F4 0x021BF8F4 thumb ov110
 *   func_020498F4 0x020498F4 arm
 *   func_02049658 0x02049658 arm
 *   func_02040588 0x02040588 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021BF7C4 0x021BF7C4 thumb ov110
 *   func_021BF6D8 0x021BF6D8 thumb ov110
 *   func_021BAD68 0x021BAD68 thumb ov110
 *   func_021BAD2C 0x021BAD2C thumb ov110
 *   func_021BC990 0x021BC990 thumb ov110
 *   func_021BCB50 0x021BCB50 thumb ov110
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0207D46C 0x0207D46C arm
 *   func_02049238 0x02049238 arm
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204335C(unsigned);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_021BA070(u8 *);
extern void func_021B9F34(u8 *,void *);
extern u8 *func_021BBC5C(void *,u8 *,void *);
extern void func_021BBD60(u8 *,void *);
extern u8 *func_021BB290(void *,u8 *,void *);
extern void func_021BB328(u8 *,void *);
extern u8 *func_021BF844(void *,void *,void *);
extern void func_021BF8F4(u8 *);
extern void func_020498F4(u32,u32,u32,u32,u32,u32,u16);
extern void func_02049658(u32,u32,u32,u32,u32,u32,u16);
extern void func_02040588(u32,u32);
extern void func_02049BDC(u32,u32,u32,u32,u32,u32,u16);
extern int func_02061CA4(void *,u32,u32,int);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(u32);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_021BF7C4(u8 *);
extern u32 func_021BF6D8(u8 *);
extern void func_021BAD68(u8 *,int);
extern void func_021BAD2C(u8 *,int);
extern u8 *func_021BC990(u8 *,u8 *,void *);
extern void func_021BCB50(u8 *);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
extern void func_0207D46C(void);
extern void func_02049238(void *);
extern void func_021B9CBC(u8 *);
void func_021B9CE4(void *unused,u8 *p) {
    void *h;
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= ~0xe000;
    *(volatile u32 *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020434CC();
    func_02043588();
    *(volatile u32 *)0x04000000 &= ~0x1f00;
    *(volatile u32 *)0x04001000 &= ~0x1f00;
    h=func_020490F4(43,42);
    func_021BA070(p);
    func_021B9F34(p,h);
    *(u8 **)(*(u8 **)p+0x54)=func_021BBC5C(*(u8 **)p,*(u8 **)(p+4),*(void **)(p+8));
    func_021BBD60(*(u8 **)(*(u8 **)p+0x54),h);
    *(u8 **)(*(u8 **)p+0x58)=func_021BB290(*(u8 **)p,*(u8 **)(p+4),*(void **)(p+8));
    func_021BB328(*(u8 **)(*(u8 **)p+0x58),h);
    *(u8 **)(*(u8 **)p+0x5c)=func_021BF844(*(u8 **)p,*(u8 **)(p+4),*(void **)(p+8));
    func_021BF8F4(*(u8 **)(*(u8 **)p+0x5c));
    func_020498F4((u32)h,30,5,0,0,0,42);
    func_02049658((u32)h,18,5,0,0,0,42);
    func_020498F4((u32)h,31,6,0,0,0,42);
    func_02049658((u32)h,18,6,0,0,0,42);
    func_02040588(6,0);
    func_02049BDC((u32)h,4,4,128,160,32,42);
    *(u16 *)(*(u8 **)p+0x68)=0x294b;
    func_02061CA4((void *)31,188,(u32)(*(u8 **)p+0x68),2);
    *(u16 *)(*(u8 **)p+0x6a)=0x5694;
    func_02061CA4((void *)31,190,(u32)(*(u8 **)p+0x6a),2);
    func_02049658((u32)h,18,7,0,0,0,42);
    func_020498F4((u32)h,24,7,0,0,0,42);
    func_020413B0(7,0,0,32,32,5);
    *(u32 *)(*(u8 **)p+0x6c)=func_020450F0(7,3,5,26,7,5,1);
    func_02043B5C(func_02045770(*(u32 *)(*(u8 **)p+0x6c)),7);
    *(u32 *)(*(u8 **)p+0x70)=0;
    if(func_021BF7C4(*(u8 **)(p+4)) || func_021BF6D8(*(u8 **)(p+4))!=2) func_021BAD68(p,1);
    else func_021BAD68(p,0);
    func_021BAD2C(*(u8 **)p,0);
    *(u8 **)(*(u8 **)p+0x64)=func_021BC990(*(u8 **)p,*(u8 **)(p+4),*(void **)(p+8));
    func_021BCB50(*(u8 **)(*(u8 **)p+0x64));
    func_02040588(0,1);
    func_020434DC(16,1);
    func_02043598(16,1);
    func_0207D46C();
    func_02049658((u32)h,16,3,0,0,0,42);
    func_02049658((u32)h,17,3,96,0,0,42);
    func_02049238(h);
    func_021B9CBC(p);
}
