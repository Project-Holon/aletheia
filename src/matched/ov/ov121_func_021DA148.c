/*
 * function: func_021DA148
 * address: 0x021DA148
 * packet: pkt_ov121_021DA148
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202020C(void *,u16 *,u16 *);
extern void func_0201F868(void *);
extern void func_0201F7A8(void *,u32);
extern void func_020456F8(void *);
extern void func_020452E8(void *);
extern void func_020307B0(void *);
void func_021DA148(u8 *p) { func_0202020C(*(void **)(p+16),0,0); func_0201F868(*(void **)(p+20)); func_0201F7A8(*(void **)p,0); func_020456F8(*(void **)p); func_020452E8(*(void **)p); func_020307B0(p); }
