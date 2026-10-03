/*
 * function: func_021B78EC
 * address: 0x021B78EC
 * packet: pkt_ov104_021B78EC
 * region: ov104
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
 *   func_021B7B2C 0x021B7B2C thumb ov104
 *   func_021B7994 0x021B7994 thumb ov104
 *   func_021B7980 0x021B7980 thumb ov104
 *   func_020056A0 0x020056A0 thumb
 *   d_021B8F78 0x021B8F78 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const void *);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_021B7B2C(void *,const void *,int);
extern void func_021B7994(void *,int);
extern void func_021B7980(void *);
extern void *func_020056A0(void (*)(void *),void *,int);
extern const u8 d_021B8F78[];
void func_021B78EC(u8 *p,int a) { func_02082BCC(p,0,0xbc); func_0204335C(0); func_020433E0(d_021B8F78); func_0204363C(0); func_0204361C(); func_020434CC(); func_021B7B2C(p+4,d_021B8F78,a); func_021B7994(p,a); *(void **)(p+0xb8)=func_020056A0(func_021B7980,p,0); }
