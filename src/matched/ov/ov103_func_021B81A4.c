/*
 * function: func_021B81A4
 * address: 0x021B81A4
 * packet: pkt_ov103_021B81A4
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Narrow each dimension after shifting right, then subtract from the u16 coordinates.
 * symbols:
 *   func_021B8004 0x021B8004 thumb ov103
 *   func_021B8000 0x021B8000 thumb ov103
 *   func_021B7FFC 0x021B7FFC thumb ov103
 *   func_021B8008 0x021B8008 thumb ov103
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6EC 0x0201C6EC thumb
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
extern int func_021B8004(void *); extern int func_021B8000(void *); extern int func_021B7FFC(void *); extern int func_021B8008(void *);
extern int func_02045770(int); extern void func_02043B5C(int,u8); extern void func_02045CAC(int,int,int); extern void func_0201C6EC(int); extern void func_0201C6FC(int,int,s16,s16,int,int);
extern int func_02045738(int); extern int func_02045740(int); extern int func_0201D304(int,int,int); extern int func_0201D42C(int,int); extern void func_0201C724(int,int,s16,s16,int,int,int);
void func_021B81A4(u8 *p,void *q,int c) {int a,b,d; u16 x,y; a=func_021B8004(q); b=func_021B8000(q); d=func_021B7FFC(q); func_02043B5C(func_02045770(*(int *)p),*(u16 *)(p+16)); func_02045CAC(a,c,*(int *)(p+12)); x=func_02045738(*(int *)p)*4; y=func_02045740(*(int *)p)*4; x-=(u16)(func_0201D304(*(int *)(p+12),d,0)>>1); y-=(u16)(func_0201D42C(*(int *)(p+12),d)>>1); func_0201C6EC(b); func_0201C724(b,func_02045770(*(int *)(p+4)),x,y,*(int *)(p+12),d,0x3dc4); p[8]=1; }
