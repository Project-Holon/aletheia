/*
 * function: func_02184968
 * address: 0x02184968
 * packet: pkt_ov219_02184968
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sub_020450F0 0x020450F0 arm
 *   sub_02045770 0x02045770 arm
 *   sub_02043B5C 0x02043B5C arm
 *   sub_02045374 0x02045374 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;struct CharBuf;struct Cfg;
extern u32 sub_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *sub_02045770(struct Descriptor*);
extern void sub_02043B5C(struct CharBuf*,u8);
extern void sub_02045374(struct Cfg*);
u32 func_02184968(const u8 *p,int flag){u32 q;q=sub_020450F0(p[0],p[1],p[2],p[3],p[4],p[5],1);sub_02043B5C((struct CharBuf*)sub_02045770((struct Descriptor*)q),15);if(flag==1)sub_02045374((struct Cfg*)q);return q;}
