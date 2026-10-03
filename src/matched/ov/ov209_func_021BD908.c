/*
 * function: func_021BD908
 * address: 0x021BD908
 * packet: pkt_ov209_021BD908
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B688 0x0204B688 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;extern void func_0204B688(struct Actor *,u32);
void func_021BD908(char *p,u32 idx,u32 flag) {if(flag==1) func_0204B688(*(struct Actor **)(p+idx*4+0xa74),1);else func_0204B688(*(struct Actor **)(p+idx*4+0xa74),0);}
