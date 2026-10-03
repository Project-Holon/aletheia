/*
 * function: func_021B7FC8
 * address: 0x021B7FC8
 * packet: pkt_ov103_021B7FC8
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0201ED04(void *); extern void func_02045C04(void *); extern void func_0201C4C0(void *); extern void func_0201D83C(void *); extern void func_02082BCC(void *,int,u32);
void func_021B7FC8(u8 *p) {func_0201ED04(*(void **)(p+12));func_02045C04(*(void **)(p+4));func_0201C4C0(*(void **)(p+8));func_0201D83C(*(void **)p);func_02082BCC(p,0,16);}
