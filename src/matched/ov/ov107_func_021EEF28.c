/*
 * function: func_021EEF28
 * address: 0x021EEF28
 * packet: pkt_ov107_021EEF28
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: Hardware MMIO read/write at 021EEF3A..021EEF78; display and power registers.
 * symbols:
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02040588 0x02040588 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   func_021EF0D0 0x021EF0D0 thumb ov107
 *   d_021F6C10 0x021F6C10 data a4
 *   d_021F6B00 0x021F6B00 data a4
 *   d_021F6B50 0x021F6B50 data a4
 *   d_021F6B70 0x021F6B70 data a4
 *   d_021F6B90 0x021F6B90 data a4
 *   d_021F6BB0 0x021F6BB0 data a4
 *   d_021F6BD0 0x021F6BD0 data a4
 *   d_021F6BF0 0x021F6BF0 data a4
 *   d_021F6B10 0x021F6B10 data a4
 *   d_021F6B30 0x021F6B30 data a4
 *   d_020A1448 0x020A1448 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct DispVram; struct DispConfig; struct BgTemplate; struct Bank;
struct Cfg { u32 prefix[4];u16 dimensions[6]; };
extern const struct Cfg d_020A1448;
extern const struct DispVram d_021F6C10;
extern struct DispConfig d_021F6B00;
extern const struct BgTemplate d_021F6B50,d_021F6B70,d_021F6B90,d_021F6BB0,d_021F6BD0,d_021F6BF0,d_021F6B10,d_021F6B30;
extern void func_020434CC(void),func_02043588(void);
extern void func_0202223C(u32,u32);
extern u32 func_02022224(void *);
extern void func_020433E0(const struct DispVram *);
extern void func_0203F8F4(u16),func_02045088(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_021EF0D0(const struct BgTemplate *,u32,u32);
extern void func_02040588(u32,u32);
extern void func_0204A48C(const struct Cfg *,u32,u32);
extern struct Bank *func_0204B100(int,u8,u32);
extern void func_0204B270(struct Bank *);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
void func_021EEF28(u8 *p) {
 struct Cfg cfg;
 func_020434CC();func_02043588();
 *(volatile u32 *)0x04000000 &= 0xffffe0ff;
 *(volatile u32 *)0x04001000 &= 0xffffe0ff;
 func_0202223C(0,0);func_0202223C(1,0);
 func_02022224((void *)0);func_02022224((void *)1);
 *(volatile u16 *)0x04000050=0;
 *(volatile u16 *)0x04001050=0;
 *(volatile u16 *)0x04000304 |= 0x8000;
 func_020433E0(&d_021F6C10);
 func_0203F8F4(*(u16 *)p);func_02045088(*(u16 *)p);
 func_0203FC28(&d_021F6B00);
 func_021EF0D0(&d_021F6B50,0,0);func_021EF0D0(&d_021F6B70,1,0);
 func_021EF0D0(&d_021F6B90,2,0);func_021EF0D0(&d_021F6BB0,3,0);
 func_021EF0D0(&d_021F6BD0,4,0);func_021EF0D0(&d_021F6BF0,5,0);
 func_021EF0D0(&d_021F6B10,6,0);func_021EF0D0(&d_021F6B30,7,0);
 if(!p[0x28])func_02040588(6,1);else func_02040588(6,0);
 cfg=d_020A1448;cfg.dimensions[0]=64;
 func_0204A48C(&cfg,(u32)&d_021F6C10,*(u16 *)p);
 *(struct Bank **)(p+0x6c)=func_0204B100(8,0,*(u16 *)p);
 func_0204B270(*(struct Bank **)(p+0x6c));
 func_020434DC(16,1);func_02043598(16,1);
}
