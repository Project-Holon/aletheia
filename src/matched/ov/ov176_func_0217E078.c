/*
 * function: func_0217E078
 * address: 0x0217E078
 * packet: pkt_ov176_0217E078
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   func_02157E8C 0x02157E8C thumb ov010
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200F83C 0x0200F83C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0200FB24(void);
extern int func_02157E8C(int a0);
extern u32 func_0200FBB0(void);
extern void func_0200F83C(void);
int func_0217E078(u8 *p) {if(func_0200FB24()!=0) {if(*(void **)(p+0x1018)!=0) {func_02157E8C((int)(*(void **)(p+0x1018)));*(void **)(p+0x1018)=0;}func_0200FBB0();func_0200F83C();return 1;}return 0;}
