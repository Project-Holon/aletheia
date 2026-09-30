/*
 * function: func_021B7DE4
 * address: 0x021B7DE4
 * packet: pkt_ov105_021B7DE4
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7CA0 0x021B7CA0 thumb ov105
 *   func_021B7CA4 0x021B7CA4 thumb ov105
 *   func_021B7CA8 0x021B7CA8 thumb ov105
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int func_021B7CA0(void *);
extern int func_021B7CA4(void *);
extern int func_021B7CA8(void *);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u8);
extern void func_02045CAC(int,int,void *);
extern void func_0201C6FC(int,void *,s16,s16,void *,int);
void func_021B7DE4(u8 *p,void *a,int b,int x,s16 y) {
 int bank; int font; int tag;
 bank=func_021B7CA8(a); font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_02043B5C(func_02045770(*(void **)p),*(u16 *)(p+0x10));
 func_02045CAC(bank,b,*(void **)(p+0xc));
 func_0201C6FC(font,func_02045770(*(void **)(p+4)),(s16)x,y,*(void **)(p+0xc),tag); p[8]=1;
}
