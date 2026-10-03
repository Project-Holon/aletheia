/*
 * function: func_021C81C8
 * address: 0x021C81C8
 * packet: pkt_ov128_021C81C8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C8100 0x021C8100 thumb ov128
 *   func_020355D8 0x020355D8 arm
 *   func_021C7F14 0x021C7F14 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021C8100(s16 *,void *,void *,int *);
extern void func_020355D8(u8);
extern int func_021C7F14(s16 *,u8 *,u8 *);
int func_021C81C8(s16 *p,u8 *q,u8 *r) {int changed=0;int ret=func_021C8100(p,q,r,&changed);if(changed) {func_020355D8(1);*(int *)q=1;return ret;}return func_021C7F14(p,q,r);}
