/*
 * function: func_021B9874
 * address: 0x021B9874
 * packet: pkt_ov205_021B9874
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0204363C is inside src/matched/arm9/unit_0204361C.c but omitted from function:. Owner must list func_0204361C,func_0204363C,func_02043658 and regenerate its shard. tu --suggest-split leaves this caller out.
 * blocker: verified EXACT 28-byte ARM C copied from ov204_func_021BDC18.c, which cites wave62 B4 blocker-1.log:
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   void func_0204363C(u32 swap) {
 *     *(volatile u16 *)0x04000304 =
 *       (*(volatile u16 *)0x04000304 & ~0x8000) | (swap << 15);
 *   }
 * symbols:
 *   func_0204363C 0x0204363C arm
 *   func_0208068C 0x0208068C arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02080B98 0x02080B98 arm
 *   func_021B9970 0x021B9970 thumb ov205
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_020450F0 0x020450F0 arm
 *   func_0203101C 0x0203101C arm
 *   func_020457B0 0x020457B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct GfFont;struct MsgBank;struct WordSet;struct Tcbl;struct U16Vec;
extern void func_0204363C(u32);extern void func_0208068C(u32);extern void func_02082AC0(u32,u32,u32);extern void func_02080B98(void);extern void func_021B9970(u16);
extern struct GfFont *func_0201D7EC(int,int,int,int,u32);extern void func_02049B40(u32,u32,u32,u32,u32,u16);extern struct MsgBank *func_02045B38(u32,u32,u32,u32);extern struct WordSet *func_0201EC64(u32);extern void func_0201F5BC(u32,u32,u32,u32,u16);extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);extern struct Tcbl *func_0203101C(u32,u16,u32,u32);extern struct U16Vec *func_020457B0(u32,u32);
void func_021B9874(char *p) { func_0204363C(1);func_0208068C(511);func_02082AC0(0,0x6800000,0xa4000);func_02080B98();func_021B9970(*(u16 *)p);*(struct GfFont **)(p+0x10)=func_0201D7EC(23,0,0,0,*(u16 *)p);func_02049B40(23,5,0,416,32,*(u16 *)p);*(struct MsgBank **)(p+0x14)=func_02045B38(0,2,*(u16 *)(p+2),*(u16 *)p);*(struct WordSet **)(p+0x18)=func_0201EC64(*(u16 *)p);func_0201F5BC(0,1,12,0,*(u16 *)p);*(u32 *)(p+0x1c)=func_020450F0(0,2,18,27,4,13,1);*(struct Tcbl **)(p+0x24)=func_0203101C(*(u16 *)p,*(u16 *)p,10,32);*(struct U16Vec **)(p+12)=func_020457B0(1024,*(u16 *)p); }
