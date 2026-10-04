/*
 * function: func_021B8138
 * address: 0x021B8138
 * packet: pkt_ov103_021B8138
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: 2-byte zero padding before the next labelled function.
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
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int func_021B8004(void *); extern int func_021B8000(void *); extern int func_021B7FFC(void *); extern int func_021B8008(void *);
struct Descriptor;
extern void *func_02045770(struct Descriptor *); extern void func_02043B5C(int,u8); extern void func_02045CAC(int,int,int); extern void func_0201C6EC(int); extern void func_0201C6FC(int,int,s16,s16,int,int);
void func_021B8138(u8 *p,void *q,int c,int x,s16 y) { int a,b,d; a=func_021B8004(q); b=func_021B8000(q); d=func_021B7FFC(q); func_02043B5C((int)func_02045770((struct Descriptor *)*(int *)p),*(u16 *)(p+16)); func_02045CAC(a,c,*(int *)(p+12)); func_0201C6EC(b); func_0201C6FC(b,(int)func_02045770((struct Descriptor *)*(int *)(p+4)),x,y,*(int *)(p+12),d); p[8]=1; }
