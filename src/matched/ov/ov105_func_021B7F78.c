/*
 * function: func_021B7F78
 * address: 0x021B7F78
 * packet: pkt_ov105_021B7F78
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding before func_021B8008
 * symbols:
 *   func_021B7CA0 0x021B7CA0 thumb ov105
 *   func_021B7CA4 0x021B7CA4 thumb ov105
 *   func_021B7CA8 0x021B7CA8 thumb ov105
 *   func_021B7CAC 0x021B7CAC thumb ov105
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201EF6C 0x0201EF6C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int func_021B7CA0(void *);
extern int func_021B7CA4(void *);
extern int func_021B7CA8(void *);
extern void *func_021B7CAC(void *);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u8);
extern void *func_02045EC0(int,int);
extern void func_0201F250(void *,void *,void *);
extern void func_02045808(void *);
extern void func_0201C6FC(int,void *,s16,s16,void *,int);
extern void func_0201EFA4(void *,u16,int,int,int,int);
extern void func_0201F02C(void *,int,void *);
extern void func_0201EF6C(void *,int,int,int,int);
void func_021B7F78(u8 *p, void *a, int b, u8 *c, u8 *d)
{
 void *msg; int bank; void *text; int font; int tag;
 func_02043B5C(func_02045770(*(void **)p),*(u16 *)(p+0x10));
 msg=func_021B7CAC(a); bank=func_021B7CA8(a);
 func_0201F02C(msg,0,d+12); func_0201F02C(msg,1,c+12);
 text=func_02045EC0(bank,b);
 func_0201F250(msg,*(void **)(p+0xc),text); func_02045808(text);
 font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_0201C6FC(font,func_02045770(*(void **)(p+4)),0,0,*(void **)(p+0xc),tag);
 p[8]=1;
}
