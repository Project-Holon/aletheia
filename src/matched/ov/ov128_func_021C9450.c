/*
 * function: func_021C9450
 * address: 0x021C9450
 * packet: pkt_ov128_021C9450
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_020355D8 0x020355D8 arm
 *   func_021C93C0 0x021C93C0 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void func_020355D8(int);
extern int func_021C93C0(void *,int *,void *,int);
int func_021C9450(void *p,int *q,void *r) {
 if(*q==1 && (func_020362DC()&0xcf3)) {func_020355D8(0);*q=0;}
 if(func_020362DC()&2)return func_021C93C0(p,q,r,0);
 if(func_020362DC()&1024)return func_021C93C0(p,q,r,1);
 if(func_0203630C()&64)return func_021C93C0(p,q,r,2);
 if(func_0203630C()&128)return func_021C93C0(p,q,r,3);
 return 2;
}
