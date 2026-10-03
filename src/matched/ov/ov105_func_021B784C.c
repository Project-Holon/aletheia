/*
 * function: func_021B784C
 * address: 0x021B784C
 * packet: pkt_ov105_021B784C
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_021B7A88 0x021B7A88 thumb ov105
 *   func_021B78F4 0x021B78F4 thumb ov105
 *   func_021B78E0 0x021B78E0 thumb ov105
 *   func_020056A0 0x020056A0 thumb
 *   d_021B89D8 0x021B89D8 data a4
 */
typedef unsigned char u8;
extern void func_02082BCC(void *,int,int);
typedef unsigned int   u32;
extern void func_0204335C(u32 keep);
extern void func_020433E0(const void *);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_021B7A88(void *,const void *,int);
extern void func_021B78F4(void *,int);
extern void func_021B78E0(void *);
extern void *func_020056A0(void (*)(void *),void *,int);
extern const u8 d_021B89D8[];
void func_021B784C(u8 *p,int a) {
 func_02082BCC(p,0,0xb0); func_0204335C(0); func_020433E0(d_021B89D8);
 func_0204363C(0); func_0204361C(); func_020434CC();
 func_021B7A88(p+4,d_021B89D8,a); func_021B78F4(p,a);
 *(void **)(p+0xac)=func_020056A0(func_021B78E0,p,0);
}
