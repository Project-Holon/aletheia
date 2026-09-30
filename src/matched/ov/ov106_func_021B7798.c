/*
 * function: func_021B7798
 * address: 0x021B7798
 * packet: pkt_ov106_021B7798
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9360 0x021B9360 thumb ov106
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_021B8304 0x021B8304 thumb ov106
 *   func_021B8FC4 0x021B8FC4 thumb ov106
 *   func_021B8D9C 0x021B8D9C thumb ov106
 *   func_021B78AC 0x021B78AC thumb ov106
 *   func_021B807C 0x021B807C thumb ov106
 *   func_021B8D5C 0x021B8D5C thumb ov106
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02025588 0x02025588 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02012704 0x02012704 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned char u8;
extern void func_021B9360(void *);
extern void func_021B71C0(void *);
extern void func_021B8304(void *);
extern void func_021B8FC4(void *);
extern void func_021B8D9C(void *);
extern void func_021B78AC(void *);
extern void func_021B807C(void *);
extern void func_021B8D5C(void *);
extern void func_0204ADA4(void *);
extern void func_02025588(void *);
extern void func_02045C04(void *);
extern void func_0201D83C(void *);
extern void func_0201C4C0(void *);
extern void func_02012704(void *);
extern void func_020315D4(void *);
extern void func_020306F0(int);
int func_021B7798(void *a,int b,int *state,u8 *p)
{
 int i;
 for(i=0;i<4;i++)func_021B9360(*(void **)(p+0x62C+i*4));
 func_0204ADA4(*(void **)(p+0x644));
 func_021B71C0(*(void **)(p+0x614));
 func_021B8304(p+0x38);
 func_021B8FC4(p+0x600); func_021B8D9C(p+0x5D4);func_021B78AC(p+0x28);
 func_02025588(*(void **)(p+0x624));func_021B807C(p);func_021B8D5C(*(void **)(p+0x63C));
 func_02045C04(*(void **)(p+0x620));func_0201D83C(*(void **)(p+0x618));func_0201C4C0(*(void **)(p+0x61C));
 if(*state==0)func_02012704(*(void **)(p+0x628));
 func_020315D4(a);func_020306F0(67);return 1;
}
