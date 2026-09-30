/*
 * function: func_021B8074
 * address: 0x021B8074
 * packet: pkt_ov103_021B8074
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: The third register parameter is u8: its full-word spill reload stays after the stack-argument stores.
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
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int func_021B8004(void *); extern int func_021B8000(void *); extern int func_021B7FFC(void *); extern int func_021B8008(void *);
extern int func_02045770(int); extern void func_02043B5C(int,u8); extern void func_02045CAC(int,int,int); extern void func_0201C6EC(int); extern void func_0201C6FC(int,int,s16,s16,int,int);
extern void func_02082BCC(void *,int,int); extern unsigned func_020450F0(unsigned,unsigned,unsigned,unsigned,u8,u8,u8); extern int func_020457B0(int,u16); extern void func_02045334(int); extern void func_02045374(int); extern int func_02045730(int); extern void func_020409B4(int);
void func_021B8074(u8 *p,int a,int b,u8 c,u8 d,u8 e,u8 f,u16 g,u8 h,u16 i) {int q; func_02082BCC(p,0,20); *(u16 *)(p+16)=g; *(int *)p=func_020450F0(a,b,c,d,e,f,h); *(int *)(p+12)=func_020457B0(255,i); *(int *)(p+4)=*(int *)p; p[8]=0; func_02043B5C(func_02045770(*(int *)p),*(u16 *)(p+16)); q=*(int *)p; func_02045334(q); func_02045374(q); func_020409B4(func_02045730(q)); }
