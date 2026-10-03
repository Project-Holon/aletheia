/*
 * function: func_021B8100
 * address: 0x021B8100
 * packet: pkt_ov103_021B8100
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two-byte zero alignment padding follows the compiled body.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02045770(int); extern int func_0201C6C4(int,int); extern void func_02045334(int);
int func_021B8100(u8 *p,u8 *q) {int a; a=*(int *)(q+8); if(p[8]!=0) {if(func_0201C6C4(a,func_02045770(*(int *)(p+4)))==0) {func_02045334(*(int *)(p+4));p[8]=0;}} if(p[8]==0)return 1;return 0;}
