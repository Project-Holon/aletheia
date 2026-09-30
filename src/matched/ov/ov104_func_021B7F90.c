/*
 * function: func_021B7F90
 * address: 0x021B7F90
 * packet: pkt_ov104_021B7F90
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7DE0 0x021B7DE0 thumb ov104
 *   func_021B7DE4 0x021B7DE4 thumb ov104
 *   func_021B7DE8 0x021B7DE8 thumb ov104
 *   func_021B7DEC 0x021B7DEC thumb ov104
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C724 0x0201C724 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021B7DE0(void *);
extern int func_021B7DE4(void *);
extern int func_021B7DE8(void *);
extern int func_021B7DEC(void *);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u8);
extern void func_02045CAC(int,int,void *);
extern void func_0201C6FC(int,void *,s16,s16,void *,int);
extern int func_02045738(void *);
extern int func_02045740(void *);
extern u32 func_0201D304(void *,int,int);
extern u32 func_0201D42C(void *,int);
extern void func_0201C724(int,void *,s16,s16,void *,int,u16);
void func_021B7F90(u8 *p,void *a,int b,u16 c) { int bank; int font; int tag; u16 x; u16 y; bank=func_021B7DE8(a); font=func_021B7DE4(a); tag=func_021B7DE0(a); func_02043B5C(func_02045770(*(void **)p),*(u16 *)(p+0x10)); func_02045CAC(bank,b,*(void **)(p+0xc)); x=func_02045738(*(void **)p)*4; y=func_02045740(*(void **)p)*4; x-=(u16)(func_0201D304(*(void **)(p+0xc),tag,0)/2); y-=(u16)(func_0201D42C(*(void **)(p+0xc),tag)/2); func_0201C724(font,func_02045770(*(void **)(p+4)),(s16)x,(s16)y,*(void **)(p+0xc),tag,c); p[8]=1; }
