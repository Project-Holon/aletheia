/*
 * function: func_021F2394
 * address: 0x021F2394
 * packet: pkt_ov194_021F2394
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045A98 0x02045A98 arm
 *   func_021F233C 0x021F233C thumb ov194
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_02045A98(void);
extern void func_021F233C(char *);
void func_021F2394(u8 *p) {if(*(u16 *)(p+30)) {*(u16 *)(p+30)=0;*(u16 *)(p+*(u16 *)(p+30)*2)=func_02045A98();*(u32 *)(p+40)=1;}func_021F233C((char *)p);}
